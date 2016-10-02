/*In this program we will use segmented sieve to calculate the prime numbers betwwen 1 and n where n is in the range 10^12*/

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
vector<ll> p;// this vector will store the primes
void sieve(int n){
    // this function uses normal sieve to calculate the primes between 1 dna root n
    vector<bool> prime(n+1,0);
    for(int i=2;i*i<n;++i){
        if(prime[i]==0){
            for(int j=i+i;j<n;j+=i){
                prime[j]=1;
            }
        }
    }
    // now we will collect all the primes
    fori(i,2,n){
        if(prime[i]==0){
            //cout<<"p="<<i<<endl;
            p.pb(i);
        }
    }
}


void segmentedSieve(ll n){
    int limit=sqrt(n)+1;
    sieve(limit);
    ll low=limit;
    ll high=2*limit;
    vector<ll> P(p);
    while(low<n){
        vector<bool> arr(limit+1,0);
        for(int i=0;i<p.size();++i){
            // use all prime is p array and make all multiples of this p array as non prme
            int lowlim=floor(low/p[i])*p[i];
            if(lowlim<low){
                lowlim+=p[i];
            }
            for(int j=lowlim;j<high;j+=p[i]){
                arr[j-low]=1;
            }

        }
        for(int j=low;j<high;++j){
                if(arr[j-low]==0){
                    P.pb(j);
                }
        }
        low=low+limit;
        high=high+limit;
        if(high>=n){
            high=n;
        }
    }
    // now lets print all the primes
    for(vector<ll>::iterator j=P.begin();j!=P.end();++j){
        cout<<*j<<endl;
    }
}
int main()
{
    segmentedSieve(100000000);
    return 0;
}


