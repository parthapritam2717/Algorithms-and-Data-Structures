/*Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.*/

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
bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return (a.S.S>b.S.S);
}
void getSchedule(vector<pair<int,pair<int,int> > > &jobs,vector<int> &sol){
    // here first we will have to sort the list by decreasing order of profit
    sort(jobs.begin(),jobs.end(),cmp);
    // now we will do the processing
    int current=2;
    int total_prof=jobs[0].S.S;
    sol.pb(jobs[0].F);
    for(int j=1;j<jobs.size();++j){
        if(current<=jobs[j].S.F){
            current++;
            total_prof+=jobs[j].S.S;
            sol.pb(jobs[j].F);
        }
    }
    cout<<total_prof<<endl;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;// n jobs
        vector<pair<int,pair<int,int> > > jobs(n);// job id,deadline,profit
        fori(i,0,n){
            int deadline;
            int profit;
            cin>>deadline>>profit;
            jobs[i]=mp(i,mp(deadline,profit));
        }
        vector<int> sol;
        getSchedule(jobs,sol);
        fori(i,0,sol.size()){
            cout<<sol[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


