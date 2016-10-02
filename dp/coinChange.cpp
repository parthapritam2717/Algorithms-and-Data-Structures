/*coin change problem using memoization and simple to understand*/
http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
#include <bits/stdc++.h>
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

#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,n,s) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,n,s) for(ll i=(n)-1;i>=(s);--i)
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
#define INF 8944674407370955161LL
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
int dp[3][4];
int sum(vi &arr,int n,int k){
    if(n<0 && k>0){
        return 0;
    }
    if(k==0){
        return 1;
    }
    if(k<0){
        return 0;
    }
    if(dp[n][k]!=-1){
        cout<<"am here"<<endl;
        return dp[n][k];
    }
    dp[n][k]=sum(arr,n-1,k)+sum(arr,n,k-arr[n]);
    return dp[n][k];
}


int main()
{
    memset(dp,-1,sizeof(dp));
    vi arr(3,0);
    arr[0]=1;arr[1]=2;arr[2]=3;
    dp[2][3]=sum(arr,1,4)+sum(arr,2,4-arr[2]);
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


