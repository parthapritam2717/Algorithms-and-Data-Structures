/*This program calculates the amount of time required to rot apples , rotten apple can rot adjacent good apples in 1 second  1 adjacent apple in any of the 4
direction.
2- rotten
1- fresh
0- no apple*/
/*http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/*/


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
vi next_x({0,0,-1,1});
vi next_y({-1,1,0,0});
int r,c;
bool isdelim(pii temp){
    if(temp.first==temp.second && temp.second==-1){
        return 1;
    }
    return 0;
}
bool isvalid(int i,int j){
    if(i<0 || i>=r || j<0 || j>=c){
        return 0;
    }
    return 1;
}

int main()
{
    //std::ios::sync_with_stdio(false);

    cin>>r>>c;
    vvi graph(r,vi (c,0));
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>graph[i][j];
        }
    }
    // graph input over
    int ans=0;

    /*Apply level order traversal with bfs and at each level we will keep on adding the neighboring apples*/
    queue<pii> q;// to perform bfs
    // find all rotten apples and add them to the queue
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(graph[i][j]==2){
            //cout<<i<<" "<<j<<endl;
                q.push(mp(i,j));
            }
        }
    }
    // now we will insert a delim
    q.push(mp(-1,-1));
    //cout<<q.size()<<endl;
    while(!q.empty()){
    //cout<<q.size()<<endl;
        bool flag=1;// to make sure that we only increase and for a given level at most once
        while(!isdelim(q.front())){
                pii t=q.front();
                for(int k=0;k<4;++k){
                    if(isvalid(t.first+next_x[k],t.second+next_y[k]) && graph[t.first+next_x[k]][t.second+next_y[k]]==1){
                        if(flag){
                            ans++;
                            flag=0;
                        }
                        graph[t.first+next_x[k]][t.second+next_y[k]]=2;
                        pii N(mp(t.first+next_x[k],t.second+next_y[k]));
                        //now push the new item to the queue
                        q.push(N);
                    }
                }
                q.pop();
        }
        q.pop();// pop the delim
        // now if we have some rotten apples in the current frame then we will separate the level with a delim
        if(!q.empty()){
            q.push(pii(mp(-1,-1)));
        }
    }
    // now we will check if any fresh apple left in the graph if fresh apple left then print -1 else print the ans;
    bool f=1;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(graph[i][j]==1){
                f=0;
                break;
            }
        }
    }
    if(f){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }


    return 0;
}


