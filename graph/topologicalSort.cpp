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

void calc_indegree(vector<list<int> > &graph,vi &in_deg){
    for(int i=0;i<graph.size();++i){
        for(list<int>::iterator j=graph[i].begin();j!=graph[i].end();++j){
            in_deg[*j]++;
        }
    }
}


void find_topology(vector<list<int> > &graph,vi &in_deg){
    // find all the nodes with indegree 0 and add to a queue
    queue<int> q;
    for(int i=0;i<in_deg.size();++i){
        if(in_deg[i]==0){
            q.push(i);
        }
    }
    vi topology;// this vector will strore the sorting  order
    int visited=0;// this value will be used at the end if we can successfully build a topologiaca sorting for this graph
    while(!q.empty()){
        int u=q.front();
        q.pop();
        visited++;
        topology.pb(u);
        for(list<int>::iterator j=graph[u].begin();j!=graph[u].end();++j){
            in_deg[*j]--;
            if(in_deg[*j]==0){
                q.push(*j);
            }
        }
    }
    if(visited!=in_deg.size()){
        cout<<"Topological sort not possible!"<<endl;
    }
    else{
        for(int i=0;i<topology.size();++i){
            cout<<topology[i]<<" ";
        }
        cout<<endl;
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
    vi in_degree(n,0); //this array will store the indegree for all the nodes in the graph
    calc_indegree(graph,in_degree); // this function will calculate the indegree for all the nodes
    // now the topological sorting
    find_topology(graph,in_degree);
    return 0;
}

