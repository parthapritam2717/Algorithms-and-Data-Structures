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
int main(){
    string s;
    cin>>s;
    int len=s.length();
    int *data=new int[123]();
    for(int i=0;i<len;++i){
        data[s[i]]+=1;
    }
    int c=0;int maxi=0;int cc=0;vi dd;
    set<int> dat;
    for(int i=97;i<=122;i++){
            if(data[i]!=0){
                dat.insert(data[i]);
            }
    }

    if(dat.size()==1){
        cout<<"YES";
    }
    else if(dat.size()==2){
        // check what is the distance of the values
        set<int>::iterator i=dat.begin();
        int x=*i;
        ++i;
        int y=*i;
                // find how many times y appeared
                int cx=0;int cy=0;
                for(int i=97;i<=122;++i){
                        if(data[i]==x){
                               // cout<<char(i)<<data[i]<<endl;
                            cx++;
                        }
                        else if(data[i]==y){
                             //cout<<char(i)<<data[i]<<endl;
                            cy++;
                        }

                }
                if(cx==1 || cy==1 ){
                    cout<<"YES";
                }
                else{
                    cout<<"NO";
                }


        }
        else{
            cout<<"NO";
        }


    return 0;

}


