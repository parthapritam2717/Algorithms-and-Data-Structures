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
ofstream fout("output.txt");

int unionFind(vi &parent,int x){
    if(parent[x]==-1){
        return x;
    }
    return unionFind(parent,parent[x]);

}
void unionMerge(vi &parent,int a,int b){
    int aset=unionFind(parent,a);
    int bset=unionFind(parent,b);
    parent[aset]=bset;
}


void Kruskal(vector<pair<int,pii> > &g,int v){
    vi parent(v,-1);
    sort(g.begin(),g.end());
    int e=0;
    int weight_total=0;
    vector<pii> mst;
    while(e<v){
        // pick the lowest weight edge chack if if dosent form a cycle with the edges already included in the mst
        int source=g[e].S.F;
        int dest=g[e].S.S;
        if(unionFind(parent,source)==unionFind(parent,dest)){
            e++;continue;// we cant pich this edge as it forms a cycle
        }
        else{
            mst.pb(g[e].S);
            weight_total+=g[e].F;
            //now i will have to combine the set source and dest
            unionMerge(parent,source,dest);
            e++;
        }
    }
    cout<<weight_total<<endl;


}
int main()
{
    int e,v;
    fin>>v>>e;
    vector<pair<int,pii> > graph;// this is the representation of our graph
    fori(i,0,e){
        int w,u,v;
        fin>>u>>v>>w;
        graph.pb(mp(w,mp(u,v)));
    }
    Kruskal(graph,v);
    return 0;
}

