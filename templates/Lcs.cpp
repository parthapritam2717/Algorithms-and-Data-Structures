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



int L[1024][1024];
// program will work for string of length max 1023
int LCS(string X,int m,string Y,int n){
    // base case when starting of one string is equal to m ;
    for(int i=0;i<m;++i){
        L[i][n]=0;
    }
    for(int i=0;i<n;++i){
        L[m][i]=0;
    }
    // now the recursion part
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            if(X[i+1]==Y[j+1]){
                L[i][j]=1+L[i+1][j+1];
            }
            else if(X[i+1]!=Y[j+1]){
                L[i][j]=max(L[i+1][j],L[i][j+1]);
            }
        }
    }
    return L[0][0];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(L,0,sizeof(L[0][0]*1024*1024));
    int l1=s1.length();
    int l2=s2.length();
    cout<<LCS(s1,l1,s2,l2);
    return 0;

}


