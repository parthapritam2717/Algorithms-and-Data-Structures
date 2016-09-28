#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include <queue>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include <iomanip>

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
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,s,n) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,s,n) for(ll i=(n)-1;i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define debugl(i,st,arr) forl(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();++(i))
#define forcr(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();++(i))
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
int main(){
        int t;
        cin>>t;
        for(int jj=0;jj<t;++jj){
                int n;
                si(n);
                vi list1;
                fori(j,0,n){
                        int tem;
                        si(tem);
                        list1.pb(tem);
                }
                if(n<=2){
                    cout<<"0"<<endl;
                }
                else{
                    int pi=0;
                    vi lsl(n,0);
                    vi lgr(n,0);
                    // for the left
                    set<int> h;
                    h.insert(list1[0]);
                    for(int i=1;i<n;++i){
                        h.insert(list1[i]);
                        set<int>::iterator f=h.find(list1[i]);
                        if(f==h.begin()){
                            lsl[i]=0;
                        }
                        else{
                            --f;
                            lsl[i]=*f;
                        }

                    }
                    h.clear();
                    h.insert(list1[n-1]);
                    for(int i=n-2;i>=0;--i){
                        // now lets find the value for lgr
                        h.insert(list1[i]);
                        set<int>::reverse_iterator f=h.rbegin();
                        if(*f==list1[i]){
                            lgr[i]=0;
                        }
                        else{
                            lgr[i]=*f;
                        }
                    }

                    for(int i=0;i<n;++i){
                        cout<<lsl[i]<<" ";
                    }
                    cout<<endl;
                    for(int i=0;i<n;++i){
                        cout<<lgr[i]<<" ";
                    }
                    cout<<endl;
                    for(int i=1;i<n-1;++i){
                        if(lsl[i]*lgr[i]*list1[i]>pi){
                            pi=lsl[i]*lgr[i]*list1[i];
                        }
                    }
                    cout<<pi<<endl;

                }
            }

    return 0;

}

