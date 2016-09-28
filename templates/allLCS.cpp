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


void createTable(vvi &LCS,string &s1,string &s2){
    for(int i=1;i<=s1.size();++i){
        for(int j=1;j<=s2.size();++j){
            if(s1[i-1]==s2[j-1]){
                LCS[i][j]=LCS[i-1][j-1]+1;
            }
            else{
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }

        }
    }
}
void printLCS(vvi &LCS,string &s1,string &s2,int ss1,int ss2,string ans){
    if(ss1==0 || ss2==0){
        string temp=ans;
        reverse(temp.begin(),temp.end());
        cout<<temp<<endl;
        return;
    }
    else if(s1[ss1-1]==s2[ss2-1]){
        ans.pb(s1[ss1-1]);
        printLCS(LCS,s1,s2,ss1-1,ss2-1,ans);
    }
    else if(LCS[ss1-1][ss2]==LCS[ss1][ss2-1]){
        //ans.pb(s1[ss1-1]);
        printLCS(LCS,s1,s2,ss1-1,ss2,ans);
        //ans.pop_back();
        //ans.push_back(s2[ss2-1]);
        printLCS(LCS,s1,s2,ss1,ss2-1,ans);
    }
    else if(LCS[ss1-1][ss2]>LCS[ss1][ss2-1]){
         printLCS(LCS,s1,s2,ss1-1,ss2,ans);
    }
    else{
         printLCS(LCS,s1,s2,ss1,ss2-1,ans);
    }

}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    // create the LCS table
    vvi LCS(s1.size()+1,vi(s2.size()+1,0));
    createTable(LCS,s1,s2);
    cout<<LCS[s1.size()][s2.size()]<<endl;
    // now we will try to print all the LCs for the given two strings
    string ans;
    printLCS(LCS,s1,s2,s1.size(),s2.size(),ans);
    return 0;
}


