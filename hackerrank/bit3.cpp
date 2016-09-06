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


int bitCount(unsigned long long item){
int c=0;
while(item>0){
    item=item>>1;
    c++;
}
return c;
}



int checkBit(int n,int i){
    int t=(n&(1<<i));
    if(t!=0){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){
    int t;
    si(t);
    vector<ll> result;
    fori(i,0,t){
           ll n,m;
            cin>>n>>m;
            int b1=bitCount(n);
            int b2=bitCount(m);
           // cout<<"b1="<<b1<<endl;
            // cout<<"b2="<<b2<<endl;
            //cout<<"n="<<n<<" "<<"m="<<m<<endl;
            if(b1<b2){
                   // cout<<"0"<<endl;
                    result.pb(0);
                    continue;
            }
            else if(n==m){
               // cout<<n<<endl;
                result.pb(n);
                continue;
            }
            else{
                // find the first unmatched index  from LHS in input 1 and input 2
                int index=32-1;
                // index found now need to reset all bits from that point onwards
                for(int i=b1-1;i>=0;--i){
                    if(checkBit(n,i)!=checkBit(m,i)){
                        index=i;
                        break;
                    }
                }
               // cout<<"Mis="<<index<<endl;
                // now reset all the elemnets fro index to 0
                for(int k=index;k>=0;--k){
                    n=n&(~(1<<k));
                }
                //cout<<"value="<<n<<endl;
                result.pb(n);
            }
    }

    for(vector<long long>::iterator i=result.begin();i!=result.end();++i){
       cout<<*i<<endl;
   }
    return 0;

}



