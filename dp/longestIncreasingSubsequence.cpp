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
int LIS(vi &arr){
    int n=arr.size();
    int lis[n];
    memset(lis,0,sizeof(lis));
    fori(i,0,n){
        // every charactre is a 1 length lIS
        lis[i]=1;
    }
    fori(i,1,n){
        fori(j,0,i){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }
    int maxi=1;
    fori(i,0,n){
        if(lis[i]>maxi){
            maxi=lis[i];
        }
    }
    return maxi;
}
int main()
{
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        vi arr(n,0);
        fori(i,0,n){
            cin>>arr[i];
        }
        cout<<LIS(arr)<<endl;
        return 0;
}


