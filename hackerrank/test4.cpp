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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
   // set<vector<int>> result;
   unordered_map<ll,vi> result;
    ll counti=0;
    //cout<<"a="<<a<<"b="<<b<<"c="<<c<<"d="<<d<<endl;
      for(int i=1;i<=a;++i){

        for(int j=1;j<=b;++j){

            for(int k=1;k<=c;++k){

                for(int l=1;l<=d;++l){
                        vi temp;
                        temp.pb(i);
                        temp.pb(j);
                        temp.pb(k);
                        temp.pb(l);
                        sort(temp.begin(),temp.end());
                        ll xr=i^j^k^l;
                        unordered_map<ll,vi> ::iterator ii=result.find(xr);
                        if(ii==result.end()){
                            result.insert(pair<ll,vi> (xr,temp));
                            counti++;
                        }
                        else{
                                bool flag=false;
                            vi t=ii->second;
                            for(int z=0;z<4;++z){
                                if(t[z]==temp[z]){
                                    flag=false;
                                }
                                else{
                                    flag=true;
                                    break;
                                }
                            }
                            if(flag!=false){
                                // insert into the ,ap
                                 result.insert(pair<ll,vi> (xr,temp));counti++;
                            }

                        }

                }

            }

        }


      }
      /*for(set<vi>::iterator i=result.begin();i!=result.end();i++){
        vi  ii=(*i);
        for(vi::iterator j=ii.begin();j!=ii.end();++j){
            cout<<*j<<" ";
        }
        nl();
      }*/




    cout<<counti<<endl;
    return 0;

}



