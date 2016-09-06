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
    int t;
    si(t);
    fori(i,0,t){
            string s;
            cin>>s;
            long long count=0;
            bool flag1=0;
            bool flag2=0;
            // process the string
            int len=s.length();
            int s1,s2;
            if(len%2==0){
                s1=len/2-1;
                s2=(len+1)/2;

            }
            else{
                s1=len/2-1;
                s2=len/2+1;
            }
            int j=len-1;
           // cout<<s<<" "<<endl;
            for(int i=0;i<=s1;++i){
                if(s[i]!=s[j]){
                    // ignore once j and once i
                    int ii=i+1;
                    int jj=j;
                    for(ii=i+1;ii<=s1;++ii){
                        if(s[ii]!=s[jj]){
                            flag2=1;
                            break;
                        }
                        else{
                            jj--;
                            continue;
                        }
                    }
                    if(flag2==0){
                        cout<<i<<endl;
                        flag1=1;
                        break;
                    }
                    ii=i;
                    jj=j-1;
                    flag2=0;
                    for(jj=j-1;jj>=s2;--jj){
                           // cout<<ii<<s[ii]<<" "<<jj<<s[jj]<<endl;
                        if(s[ii]!=s[jj]){
                            flag2=1;
                            break;
                        }
                        else{
                            ii++;
                            continue;
                        }
                    }
                    if(flag2==0){
                             flag1=1;
                        cout<<j<<endl;
                    }

                }
                if(flag1==1){
                    break;
                }
                else{
                    continue;
                }

            }
            if(flag1==0){
                cout<<-1<<endl;
            }


    }
    return 0;

}


