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
ifstream fin("input");
//ofstream fout("output.txt");0

int dp[50][50];
int getMin(string s,int l,int r){
    if(l>r){
        return INT_MAX;
    }
    if(l==r){
        return 0;
    }
    if(l==r-1){
        return (s[l]==s[r])?0:1;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(s[l]==s[r]){
        dp[l][r]=getMin(s,l+1,r-1);
    }
    else{
        dp[l][r]=1+min(getMin(s,l+1,r),getMin(s,l,r-1));
    }
    return dp[l][r];

}
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    fin>>t;
    fin.ignore();
    while(t--){
        memset(dp,-1,sizeof(dp));
        string s;
        fin>>s;
        // return the minimum number of insertion to convert the given string to palindrome
        cout<<getMin(s,0,s.size()-1)<<endl;
    }
    return 0;
}


