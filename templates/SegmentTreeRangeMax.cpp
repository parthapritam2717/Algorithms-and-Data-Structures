/*segment tree to find the min of a given range */
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef unordered_map<int,int> umap;
typedef map<long long,long long> omap;
typedef multimap<long long,long long> mmap;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define all(v) v.begin(),v.end()
#define Pi(x) printf("%d", x)
#define Pl(x) printf("%lld", x)
#define os() printf(" ")
#define nl() printf("\n");
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,s,n) for(ll i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define debugl(i,st,arr) forl(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();++(i))
#define forcr(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();++(i))
int getMidIndex(int s1,int s2){
    return s1+(s2-s1)/2;
}

int constructSTUtil(vi arr, int starts, int ends, int *st, int scurrent){
    /*If there is only one element in the segment store it in current node of the segment tree and return */

    if(starts==ends){
            (st)[scurrent]=arr[starts];
            return arr[starts];
    }
    // if more than one node present then recurse for left subtree and right subtree  and store the sum of values in this node
    int mid=getMidIndex(starts,ends);
    (st)[scurrent]=max(constructSTUtil(arr,starts,mid,st,2*scurrent+1),constructSTUtil(arr,mid+1,ends,st,scurrent*2+2));
    return (st)[scurrent];
}



int *constructSegmentTree(vi list1,int n){
    // calc the height of the tree
    int height=(int)ceil(log2(n));
    // now lets calc the amount of space needed for the tree
    int maxSize=2*(int)pow(2,height)-1;
    int *sTree= new  int[maxSize] ();
    // now the actual utility function which will construct the segmented tree
    constructSTUtil(list1,0,n-1,sTree,0);
    return sTree;
}


/*parameters for the sum utility function*/
/*st->pointer for segment tree
si->index of current node in the segment tree initially 0 is passed as root index is always 0 which is implemented in the array
ss and se->starting and ending index of the segment
qs and qe->starting and ending index of query range*/

int getMinUtil(int *st,int ss,int se,int qs,int qe,int si){
    if(qs<=ss && qe>=se){
        return st[si];
    }
    // if no overlap
    if(se<qs || ss>qe){
        return INT_MAX;
    }
    // now the case of partial overlap we will recusiveley find the sum
    int mid=getMidIndex(ss,se);
    return max(getMinUtil(st,ss,mid,qs,qe,si*2+1),getMinUtil(st,mid+1,se,qs,qe,si*2+2));
}

int getMin(int *sTree,int sizeOfTree,int r1,int r2){
    // we will have to make use of an utility functions which will help us find the sum recursively
    if(r1<0 || r2>sizeOfTree-1|| r1>r2){
        cout<<"Invalid Input!!\n";
        return -1;
    }
    return getMinUtil(sTree,0,sizeOfTree-1,r1,r2,0);
}



void updateValueUtil(int *st,int ss,int se,int index,int diff,int si){
    // Base Case: If the input index lies outside the range of
    // this segment
    if (index < ss || index > se){
        return;
    }
    st[si]+=diff;
    if(se!=ss){
        int mid=getMidIndex(ss,se);
        updateValueUtil(st,ss,mid,index,diff,2*si+1);
        updateValueUtil(st,mid+1,se,index,diff,2*si+2);
    }

}

void updateValue(vi *list1,int *st,int sizeOfTree,int index,int newValue){
    if(index<0 || index>sizeOfTree-1){
         cout<<"Invalid Input!!\n";
        return ;
    }
    int diff=newValue-(*list1)[index];
    (*list1)[index]+=diff;
    updateValueUtil(st,0,sizeOfTree-1,index,diff,0);

}


int main(){

            int n,m;
            si(n);
            vi list1;
            fori(j,0,n){
                    int tem;
                    si(tem);
                    list1.pb(tem);
            }
            // now lets construct the segment tree
            int *segmentTree=constructSegmentTree(list1,n);
            // now lets do some queries to see if our result are good
            cout<<getMin(segmentTree,n,0,2);
            // now lets update the values of the
            delete [] segmentTree;
    return 0;

}





