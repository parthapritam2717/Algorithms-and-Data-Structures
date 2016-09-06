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
inline void fastRead_int(ll &x) {
    register int c = getchar_unlocked();
    x = 0;
    ll neg = 0;

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
    si(t);
    fori(i,0,t){
            ll n;
            fastRead_int(n);
            vl list1;
            vl neg;
            ll zzz=0;
            forl(j,0,n){
                    ll tem;
                    fastRead_int(tem);
                    list1.pb(tem);
                    if(tem>=0){
                         zzz+=tem;
                    }

                    if(tem<0){
                        neg.pb(j);
                    }
            }
            ll over=-INF;
            ll mini=-INF;
            for(vl::iterator ii=neg.begin();ii!=neg.end();++ii){
                ll ind=*ii;
                ll maxi=-INF;
                ll sum=0;
                for(ll z=0;z<n;z++){
                    if(list1[z]>mini){
                        mini=list1[z];
                    }
                    if(z!=ind){
                        sum+=list1[z];
                        //cout<<"s1="<<sum<<endl;
                        if(sum>=maxi){
                            maxi=sum;
                            if(sum<list1[z]){
                                maxi=list1[z];
                            }
                           //cout<<"maxi="<<maxi<<endl;
                            continue;
                        }
                        else if(sum<0){
                            sum=0;
                            continue;
                        }

                    }
                    else{
                        sum+=0;
                    }
                }
                if(maxi>over){
                    over=maxi;
                }
            }
            if(neg.size()==0){
                over=zzz;
            }
            else if(neg.size()==n){
                over=mini;
            }
            Pl(over);nl();
    }
    return 0;

}



