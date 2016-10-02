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
int dp[50][3];

int W=50;
int knapsack(int n,int w,vi &wt,vi &val){
    if(n<0){
        return 0;
    }
    if(dp[w][n]!=-1){
        //cout<<"here"<<endl;
        return dp[w][n];
    }
    if(wt[n]>w){
        dp[w][n]=knapsack(n-1,w,wt,val);
    }
    else{
        dp[w][n]=max(val[n]+knapsack(n-1,w-wt[n],wt,val),knapsack(n-1,w,wt,val));
    }
    return dp[w][n];
}
int main()
{
    //std::ios::sync_with_stdio(false);
    vi wt(3);
    wt[0]=10;wt[1]=20;wt[2]=30;
    vi val(3);
    val[0]=60;val[1]=100;val[2]=120;
    memset(dp,-1,sizeof(dp));
    dp[W-1][2]=max(val[2]+knapsack(1,W-wt[2],wt,val),knapsack(1,W,wt,val));
    cout<<dp[W-1][2]<<endl;
    return 0;
}



