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
#include <iomanip>

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
int main(){
    int t;
    si(t);
    fori(i,0,t){
            int m;
            si(m);
            set<string> g1,g2;
            fori(j,0,m){
                    string s1,s2;
                    cin>>s1>>s2;
                    bool flag=true;
                    // now do the processing
                    // check for bot person if they are currently in any of the group
               set<string>::iterator f=g1.find(s1);
                    if(f!=g1.end()){
                        // check if in the same group or not
                     set<string>::iterator ff=g1.find(s2);
                        if(ff==g1.end()){
                            // ok then we can add s2 to g2
                            // before adding s2 in g2 check if s1 already present in g2
                         set<string>::iterator gf=g2.find(s1);
                            if(gf!=g2.end()){
                                flag=false;
                            }
                            else{
                                g2.insert(s2);
                            }

                        }
                        else{
                            flag=false;

                        }

                    }
                    else if(f==g1.end()){
                            // check if its in g2
                            set<string>::iterator g=g2.find(s1);
                            if(g!=g2.end()){
                                // then insert s2 in g1 but before that do the checking
                                g1.insert(s2);

                            }
                            else{
                                // check if s21 also in none of the group
                                 set<string>::iterator gg=g1.find(s2);
                                  set<string>::iterator g1=g2.find(s2);
                                  if(gg==g1.end() && g1==g2.end()){
                                    g1.insert(s1);
                                    g2.insert(s2);
                                  }
                                  else if(gg!=g1.end()){
                                        g2.insert(s1);

                                  }
                                  else{
                                    g1.insert(s1);
                                  }
                            }
                    }
                    if(flag){
                        cout<<"case #"<<i+1<<": "<<"Yes"<<"\n";
                    }
                    else{
                        cout<<"case #"<<i+1<<": "<<"No"<<"\n";
                    }
            }
		//cout<<"case #"<<i+1<<": "<<out<<"\n";
    }
    return 0;

}



