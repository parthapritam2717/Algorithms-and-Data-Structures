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
#include <queue>
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
void fill_buttom(vector<vector<int> > &but,vector<vector<int> > &arr,int r,int c){
    // to preprocess and find for each node how much we can go without getting a 1
    for(int i=0;i<c;++i){
        if(arr[r-1][i]==0){
            but[r-1][i]=1;
        }
    }
    for(int i=0;i<c;++i){
        for(int j=r-2;j>=0;--j){
            if(arr[j][i]==1){
                but[j][i]=0;
            }
            else{
                but[j][i]=but[j+1][i]+1;
            }
        }
    }
}



int main(){
    int t;
    si(t);
    fori(ii,0,t){
        int r,c,k;
        fastRead_int(r);
        fastRead_int(c);
        fastRead_int(k);
        vector<vector<int> > arr(r,vector<int> (c,1));
        ll ans=0;
        for(int i=0;i<k;++i){
            int ri,ci;
            fastRead_int(ri);
            fastRead_int(ci);
            arr[ri][ci]=0;
        }
        // now the processing
        vector<vector<int> >sum(r,vector<int> (c,0));
        for(int i=0;i<c;++i){
            sum[0][i]=arr[0][i];

        }
        for(int j=0;j<r;++j){
            sum[j][0]=arr[j][0];

        }
        for(int i=1;i<r;++i){
            for(int j=1;j<c;++j){
                if(arr[i][j]==1){
                    sum[i][j]=min(sum[i-1][j],min(sum[i-1][j-1],sum[i][j-1]))+1;
                     //ans+=sum[i][j];

                }
                else{
                    sum[i][j]=0;

                }

            }
        }
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                //cout<<sum[i][j]<<" ";
                ans+=sum[i][j];
            }
            //cout<<endl;
        }
        //cout<<endl;
		 cout<<"Case #"<<ii+1<<": "<<ans<<endl;
    }
    return 0;

}


