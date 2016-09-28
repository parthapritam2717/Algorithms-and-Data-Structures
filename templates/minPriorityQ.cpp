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


bool comp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int t;
    si(t);
    fori(i,0,t){
            int n,k;
            si(n);
            si(k);
            vector<vector<int> > arr(n,vector<int> (k,0));
            for(int i=0;i<n;++i){
                for(int j=0;j<k;++j){
                    cin>>arr[i][j];
                }
            }
            // now need to merge these n arrays into a single array
            vi ans;
            //priority_queue<int,vector<int>,greater<int> > q;
            priority_queue<pair<int,pair<int,int > > ,vector<pair< int,pair<int, int > > >, greater<pair<int,pair<int,int> > > >q;
            for(int i=0;i<n;++i){
            //q.push(arr[i][0]);
                pair<int,int> l(i,0);
                q.push(pair<int,pair<int,int> > (arr[i][0],l));
            }
            for(int i=0;i<n*k;++i){
                int index1=q.top().second.first;
                int index2=q.top().second.second;
                ans.pb(q.top().first);
                ans.pop();
                if(index2==arr[index1].size()-1){
                    pair<int,int> l(i,0);
                    q.push(pair<int,pair<int,int> > (INT_MAX,l));
                }
                else{
                    pair<int,int> l(i,0);
                    q.push(pair<int,pair<int,int> > (INT_MAX,l));
                }
            }
    }
    return 0;

}



