/*http://www.practice.geeksforgeeks.org/problem-page.php?pid=153*/

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
int dp[200];
int findMin(vi &arr,int i,int n){
   // cout<<i<<" "<<arr[i]<<endl;
    if(arr[i]==0){
        return 200000;
    }
    if(i>=n){
        return 0;
    }
    if(i+arr[i]>=n){
        return 1;
    }
    if(dp[i]!=200000){
        return dp[i];
    }
    for(int j=i+1;j<=i+arr[i] && j<=n;++j){
        dp[i]=min(dp[i],findMin(arr,j,n));
    }
    dp[i]+=1;
    return dp[i];
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;
        vi arr(n,0);
        fill_n(dp,n+1,200000);
        fori(i,0,n){
            cin>>arr[i];
            //cout<<arr[i]<<" ";
        }
        //cout<<endl;
       int ans=findMin(arr,0,n-1);
        if(ans!=200000){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}


