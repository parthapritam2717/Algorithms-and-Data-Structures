/*http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/*/
//count the min number of coins to make a particular value
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
int getMinCount(vi &arr,int V){
    vi T(V+1,INT_MAX);
    T[0]=0;
    for(int v=1;v<=V;++v){
        for(int j=0;j<arr.size();++j){
            if(arr[j]<=v){
                int sub_res=T[v-arr[j]];
                if(sub_res!=INT_MAX && sub_res+1<T[v]){
                    T[v]=sub_res+1;
                }
            }
        }
    }
    return T[V];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int v;
    cin>>v;//this is the value we want to generate
    int n;
    cin>>n;
    vi arr(n,0);
    fori(i,0,n){
            cin>>arr[i];
    }
    cout<<getMinCount(arr,v)<<endl;
    return 0;
}


