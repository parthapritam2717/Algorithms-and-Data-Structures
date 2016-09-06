#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include <iomanip>

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
#define PI 3.14159265
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
int find_lis(vector<int> &arr){
    vi m(arr.size(),INT_MAX);
    int len=1;
    if(arr.size()==0){
        return 0;
    }
    else{
        int n=arr.size();
        m[0]=arr[0];
        for(int i=1;i<n;++i){
            if(arr[i]<m[0]){
                m[0]=arr[i];
            }
            else if(arr[i]>m[len-1]){
                m[len]=arr[i];
                len++;
            }
            else{
                // find the lower bound of A[i] and then
                int start=0;
                int endi=len-1;
                int ans=0;
                while(start<=endi){
                    int mid=(start+endi)/2;
                    if(m[mid]<arr[i]){
                         start=mid+1;
                    }
                    else{
                        // we need the lower bound (i.e the value which is equal to or greater than the value
                        endi=mid-1;
                        ans=mid;
                    }

                }
                m[ans]=arr[i];
            }


        }

    }
    return len;
}

int main(){
   int n;
   cin>>n;
   vi arr(n,0);
   for(int i=0;i<n;++i){
        cin>>arr[i];

    }
    cout<<"LIS length is="<<find_lis(arr);
           return 0;

}



