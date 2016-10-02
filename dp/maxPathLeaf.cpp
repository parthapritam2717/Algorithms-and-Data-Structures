/*http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/*/
/*Find the max distance beetween any leaft node in a tree which is represented as array*/\

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
int getSum(vi &arr,int root,int &res,int n){
    if(arr[root]==-1){
        return 0;
    }
    // now we will deal with the case when both left and right subtree are null for this node
    if(2*root+1>=n || (arr[2*root+1]==-1 && arr[2*root+2]==-1 )){
        return arr[root];
    }
    int ls=getSum(arr,2*root+1,res,n);
    int rs=getSum(arr,2*root+2,res,n);
    // now if both are present
    if(arr[2*root+1]!=-1 && arr[2*root+2]!=-1){
        // now we will have to change res
        // res contains the max if the
        res=max(res,ls+rs+arr[root]);
        return max(ls,rs)+arr[root];
    }
    if(arr[2*root+1]==-1){
        return rs+arr[root];
    }
     return ls+arr[root];

}
int main()
{
    int res=INT_MIN;
    int n;
    cin>>n;
    vi arr(n,0);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    getSum(arr,0,res,n);
    cout<<res<<endl;
    return 0;
}


