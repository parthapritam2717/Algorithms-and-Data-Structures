/*Given an array of non-negative integers. Find the largest multiple of 3 that can be formed from array elements*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include <queue>
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
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}


void printGreatest(vi &list1){
    sort(list1.rbegin(),list1.rend());
    int sum=0;
    vi q1,q2,q0;
    for(int i=0;i<list1.size();++i){
        sum+=list1[i];
        int x=list1[i]%3;
        switch(x){
            case 0:q0.pb(list1[i]);
                    break;
            case 1:q1.pb(list1[i]);break;
            case 2:q2.pb(list1[i]);break;
            default:break;
        }
    }
    if(sum%3==0){
        for(int i=0;i<list1.size();++i){
            cout<<list1[i]<<" ";
        }
        cout<<endl;
    }
    else if(sum%3==1){
        // two test cases to handle
        if(q1.size()==0 && q2.size()<2){
            cout<<"Not possible!!";
            return ;
        }
        else if(q1.size()>=1){
            q1.pop_back();
        }
        else{
            q2.pop_back();
            q2.pop_back();
        }
        for(vi::iterator i=q2.begin();i!=q2.end();++i){
            q0.pb(*i);
        }
         for(vi::iterator i=q1.begin();i!=q1.end();++i){
            q0.pb(*i);
        }
        sort(q0.rbegin(),q0.rend());
        for(int i=0;i<q0.size();++i){
            cout<<q0[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        // remainder must have been 2
        if(q2.size()==0 && q1.size()<2){
            cout<<"Not possible!!";
            return ;
        }
        else if(q2.size()>=1){
            q2.pop_back();
        }
        else{
            q1.pop_back();
            q1.pop_back();
        }
        for(vi::iterator i=q2.begin();i!=q2.end();++i){
            q0.pb(*i);
        }
         for(vi::iterator i=q1.begin();i!=q1.end();++i){
            q0.pb(*i);
        }
        sort(q0.rbegin(),q0.rend());
        for(int i=0;i<q0.size();++i){
            cout<<q0[i]<<" ";
        }
        cout<<endl;
        return;
    }

}
int main(){
    int t;
    si(t);
    fori(i,0,t){
            int n;
            si(n);
            vi list1;
            fori(j,0,n){
                    int tem;
                    si(tem);
                    list1.pb(tem);
            }
            // now the processing
            printGreatest(list1);

    }
    return 0;

}



