/*Steps included in this algorithm are Kosaraju
1. apply topology dfs
2. reverse the edges in the graph(transpose grap)
3. one by one pop each element from graph and apply dfs .Each node visted will be in the same scc
*/
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

void transpose_graph(vector<list<int> > &Tgraph,vector<list<int> > &graph){
    for(int i=0;i<graph.size();++i){
        for(list<int>::iterator j=graph[i].begin();j!=graph[i].end();++j){
            Tgraph[*j].pb(i);
        }
    }
}
void topology_dfs(stack<int> &s,vector<list<int> > &graph,vector<bool> &vis,int u){
    vis[u]=1;
    for(list<int>::iterator j=graph[u].begin();j!=graph[u].end();++j){
        if(vis[*j]==0){
            topology_dfs(s,graph,vis,*j);
        }
    }
    s.push(u);
}
void dfs(vector<list<int> > &Tgraph,vector<bool> &vis,int u){
    vis[u]=1;
    cout<<u<<"->";
    for(list<int>::iterator j=Tgraph[u].begin();j!=Tgraph[u].end();++j){
        if(vis[*j]==0){
            dfs(Tgraph,vis,*j);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<list<int> > graph(n);
    for(int i=0;i<e;++i){
        int u,v;
        cin>>u>>v;
        graph[u].pb(v); //0 based indexing of the graphs
    }
    vector<bool> vis(n,0);
    stack<int> s;
    fori(i,0,n){
        if(vis[i]==0){
            topology_dfs(s,graph,vis,i);
        }
    }
    vector<list<int> > Tgraph(n);
    transpose_graph(Tgraph,graph);
    fill(vis.begin(),vis.end(),0);
    while(!s.empty()){
        int u=s.top();
        s.pop();
        if(vis[u]==0){
            dfs(Tgraph,vis,u);
            cout<<"NULL"<<endl;
        }
    }
}



