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
//ifstream fin("input.txt"); fin>>n;
//ofstream fout("output.txt"); fout<<n;

/*You are required to complete this method*/
int calcArea(vector<int> &arr,int m){
    int mx=0;
    int area,tp,i=0;
    stack<int> s;
    while(i<m){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }
        else{
            tp=s.top();
            s.pop();
            if(s.empty()){
                area=arr[tp]*i;
            }
            else{
                area=arr[tp]*(i-s.top()-1);
            }
            if(area>mx){
                mx=area;
            }
        }

    }
    while(!s.empty()){
        tp=s.top();
            s.pop();
            if(s.empty()){
                area=arr[tp]*i;
            }
            else{
                area=arr[tp]*(i-s.top()-1);
            }
            if(area>mx){
                mx=area;
            }

    }
    return mx;

}
int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here
    // the matrix is of size n and m
    vector<int> arr(m,0);
    int maxi=0;
    int area,tp;
    for(int j=0;j<m;++j){
        arr[j]=M[0][j];
    }
    area=calcArea(arr,m);
    if(area>maxi){
        maxi=area;
    }
    for(int j=1;j<n;++j){
        for(int k=0;k<m;++k){
            if(M[j][k]==0){
                arr[k]=0;
            }
            else{
                arr[k]+=1;
            }
        }
        area=calcArea(arr,m);
        if(area>maxi){
            maxi=area;
        }
    }
    return maxi;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){





    }
    return 0;
}


