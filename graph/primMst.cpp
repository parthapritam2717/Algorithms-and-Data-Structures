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
void prims_mst(vector<list<pii> > &g,int src){
    int n=g.size();
    vector<bool> vis(n,0);
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MAX);
    priority_queue<pii,vector<pii>, greater<pii> > pq;
    pq.push(mp(0,src));// pair of weight and node
    key[src]=0;
    int sum_weight=0;
    while(!pq.empty()){
        int u=pq.top().S;
        vis[u]=1;
        pq.pop();
        sum_weight+=key[u];
        list<pii>::iterator j=g[u].begin();
        for(j;j!=g[u].end();++j){
            int v=(*j).F;
            int weight=(*j).S;
            if(vis[v]==0 && key[v]>weight){
                key[v]=weight;
                pq.push(mp(weight,v));
                parent[v]=u;
            }


        }
    }
    // now we will print the weight the mst
    for(int i=1;i<n;++i){
        cout<<parent[i]<<"->"<<i<<endl;
    }
    // now how to find the weight total of the mst
    cout<<sum_weight<<endl;

}

int main()
{
    //std::ios::sync_with_stdio(false);
    int n,e;
    fin>>n>>e;// all nodes should be connected for an mst to be made
    vector<list<pii> > graph(n);
    for(int i=0;i<e;++i){
        int u,v,w;
        fin>>u>>v>>w;
        graph[u].pb(mp(v,w)); //0 based indexing of the graphs
        graph[v].pb(mp(u,w));
        //cout<<u<<" "<<v<<" "<<w<<endl;
    }
    int s;
    fin>>s;
    prims_mst(graph,s);
    return 0;
}


