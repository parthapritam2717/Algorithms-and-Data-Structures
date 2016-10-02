/*http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/*/
/*very similar question is the dungeon princess question in leetcode*/
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
int dp[100][100];
int getCost(vvi &arr,int i,int j,int n,int m){
    if(i>=n || j>=n){
        return INT_MAX;
    }
    if(i==n-1 && j==m-1){
        if(arr[i][j]<0){
            return arr[i][j]*-1+1;
        }
        else{
            return 1;// if positive we need min 1 to reach this node
        }
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left=getCost(arr,i+1,j,n,m);
    int right=getCost(arr,i,j+1,n,m);
    int req=min(left,right);
    if(arr[i][j]>=req){
        dp[i][j]=1;
    }
    else{
        dp[i][j]=req-arr[i][j];// how much extra we need in order to move to the next cube
    }
    return dp[i][j];
}


int main()
{
    //std::ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vvi arr(n,vi (n,0));
    fori(i,0,n){
        fori(j,0,n){
            cin>>arr[i][j];
        }
    }
    cout<<getCost(arr,0,0,n,n);
    return 0;
}


