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
int getPalin(string &s){
    int n=s.size();
    bool T[n][n];
    memset(T,0,sizeof(T));
    // lets first update the size 1 and size 2 palindromes
    int maxi=1;int mstart=1;
    fori(i,0,n){
        T[i][i]=1;
    }
    // lets cjeck the size 2 palindromes
    fori(i,0,n-1){
        if(s[i]==s[i+1]){
            T[i][i+1]=1;
            if(maxi<2){
                maxi=2;
                int mstart=i;
            }
        }
    }
    // now check the lengths for k>=3
    fori(len,3,n+1){
        fori(i,0,n-len+1){
            int j=i+len-1;
            if(T[i+1][j-1] && s[i]==s[j]){
                T[i][j]=1;
                if(len>maxi){
                    maxi=len;
                    mstart=i;
                }
            }
        }
    }
    //cout<<mstart<<endl;
    //cout<<s<<endl;
    fori(i,mstart,mstart+maxi){
        cout<<s[i];
    }
    cout<<endl;
    return maxi;
}
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    cout<<getPalin(s)<<endl;
    return 0;
}


