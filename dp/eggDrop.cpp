/*http://www.practice.geeksforgeeks.org/problem-page.php?pid=162*/
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
int dp[300][300];// this table will contain the data for the n and x
int getTrial(int n,int k){
    //cout<<n<<" "<<k<<endl;
    if(k==0 || k==1){
        return k;
    }
    if(n==1){
        return k;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int mini=INT_MAX;
    for(int x=1;x<=k;++x){
        int res=max(getTrial(n-1,x-1),getTrial(n,k-x));// since we want to minimise the number of trials in the worst case we need the max of the two and then we add 1 to count the trial
        mini=min(res,mini);
    }
    //cout<<mini<<endl;
    dp[n][k]=mini+1;
    return dp[n][k];
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
            memset(dp,-1,sizeof(dp));
            int n,k;
            cin>>n>>k;
            cout<<getTrial(n,k)<<endl;
    }
    return 0;
}

