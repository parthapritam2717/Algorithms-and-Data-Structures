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

            int n;
            si(n);
            vi list1;
            ll total=0,countt=0;
            map<int,int> m1;
            fori(j,0,n){
                    int tem;
                    si(tem);
                    map<int,int>::iterator it=m1.find(tem);
                    if(it!=m1.end()){
                        it->second+=1;
                    }
                    else{
                        pii t(tem,1);
                        m1.insert(t);
                    }
            }



            int counti=0;
            int a,b,c;
            for(map<int,int>::iterator it=m1.end();it!=m1.begin();--it){
                --it;
                    //cout<<it->second<<endl;
                if(it->second>=3){
                    cout<<it->first<<" "<<it->first<<" "<<it->first;

                }


                else if(it->second==2){
                    c=it->first;
                    b=it->first;
                    a=(--it)->first;
                    if((a+b)>c){
                        cout<<a<<" "<<b<<" "<<c;
                    }
                    else{
                        cout<<-1;
                    }
                }
                 else if(it->second==1){
                      c=it->first;
                        b=(--it)->first;
                        if(it->second>=2){
                            a=it->first;
                        }
                        else{
                            a=(--it)->first;
                        }
                         if((a+b)>c){
                       cout<<a<<" "<<b<<" "<<c;
                         }
                         else{
                            cout<<-1;
                         }
                 }


            break;
            }



    return 0;

}



