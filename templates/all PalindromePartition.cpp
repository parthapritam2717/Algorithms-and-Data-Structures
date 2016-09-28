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
bool is_palin(string s,int low,int high){
    while(low<high){
        if(s[low]==s[high]){
            ++low;
            --high;
        }
        else{
            return 0;
        }
    }
    return 1;
}
void util(vector<vector<string> > &allPal,vector<string> &ans,string &s,int start,int n){
    if(start>=n){
        allPal.pb(ans);
        return;
    }
    // pick all possible ending points for substrings check if they are palindrome
    for(int i=start;i<n;++i){
        if(is_palin(s,start,i)){
            // ok we have the palindrome lets add this to the answer vector and recur further
            ans.pb(s.substr(start,i-start+1));
            util(allPal,ans,s,i+1,n);
            ans.pop_back();
        }
    }
}
void printAllPalin(string &s){
    vector<vector<string> > allPal;
    vector<string> ans;
    util(allPal,ans,s,0,s.size());
    for(int i=0;i<allPal.size();++i){
        for(int j=0;j<allPal[i].size();++j){
            cout<<allPal[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string s;
    cin>>s;
    printAllPalin(s);
    return 0;
}


