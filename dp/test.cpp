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

#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,n,s) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,n,s) for(ll i=(n)-1;i>=(s);--i)
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
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
		int n,m;
		cin>>n>>m;
		vvi G(n,vi(m,0));
		vvi K(n,vi(m,0));
		int total=0;
		fori(i,0,n){
			fori(j,0,m){
				cin>>G[i][j];
				if(G[i][j]==1){
                    total++;
				}
            }
		}
		fori(i,0,n){
			fori(j,0,m){
				cin>>K[i][j];
			}
		}
		//map<pair<int,int>,vector<pair<int,int> > > point_bomb;// store point to bomb mapping of the terrorist
		//map<pair<int,int>,map<int,set<pair<int,int> >,less<int> >cmp> bomb_kill_points;// contains bombs to kill number and the terrorist this bomb will kill
        vvi preprocess(n,vi (m,0));
        int maxi=0;
        int x,y;
        map<pii,set<pii> > bomb_points;// bomb contains which all points terrorists
        map<pii,set<pii> > point_bomb;// this point is in whic which bomb
        fori(i,0,n){
			fori(j,0,m){
				// now for each point check what is the kill value
                int k=K[i][j];
                int c=0;
                // check in the row and column how many terrorist we can kill
                set<pii> temp;
                bomb_points.insert(mp(mp(i,j),temp));
                point_bomb.insert(mp(mp(i,j),temp));
                for(int ii=i-1;ii>=i-k && ii>=0;--ii){
                    if(G[ii][j]==1){
                        (bomb_points.find(mp(i,j))->second).insert(mp(ii,j));
                        point_bomb.insert(mp(mp(i,j),temp));
                        (point_bomb.find(mp(ii,j))->second).insert(mp(i,j));
                        c++;
                    }
                }
                for(int ii=i+1;ii<=i+k && ii<n;++ii){
                    if(G[ii][j]==1){
                        (bomb_points.find(mp(i,j))->second).insert(mp(ii,j));
                        point_bomb.insert(mp(mp(i,j),temp));
                        (point_bomb.find(mp(ii,j))->second).insert(mp(i,j));
                        c++;
                    }
                }
                // now the row
                for(int jj=j-1;jj>=j-k && jj>=0;--jj){
                    if(G[i][jj]==1){
                        (bomb_points.find(mp(i,j))->second).insert(mp(i,jj));
                                                point_bomb.insert(mp(mp(i,j),temp));
                        (point_bomb.find(mp(i,jj))->second).insert(mp(i,j));
                        c++;
                    }
                }
                for(int jj=j+1;jj<=j+k && jj<m;++jj){
                    if(G[i][jj]==1){
                        (bomb_points.find(mp(i,j))->second).insert(mp(i,jj));
                        point_bomb.insert(mp(mp(i,j),temp));
                        (point_bomb.find(mp(i,jj))->second).insert(mp(i,j));
                        c++;
                    }
                }
                if(G[i][j]==1){
                    (bomb_points.find(mp(i,j))->second).insert(mp(i,j));
                        point_bomb.insert(mp(mp(i,j),temp));
                        (point_bomb.find(mp(i,j))->second).insert(mp(i,j));
                    c++;
                }
                preprocess[i][j]=c;
                if(c>maxi){
                    maxi=c;
                    x=i;y=j;
                }
			}
		}
        // now i will start from the maximum ans will
        map<pair<int,int>,int> bomb_kill;// this map will store the bomb to kill
        fori(i,0,n){
            fori(j,0,m){
                bomb_kill.insert(mp(i,j),preprocess[i][j]);
            }
        }
        int ans=0;
        vector<pair<int,int> > ans_pair;
        while(total>0){
                ans++;
                ans_pair.pb(mp(x,y));
                // now i need to remove all the bombs count of bombs
                map<pii,set<pii> >::iterator j=bomb_points.find(x,y);
                set<pii>::iterator jj=j->S.begin();
                for(jj;jj!=j->S.end();++jj){
                    // now we got all the points which this bomb will blow
                    // now for each these points we will check will all bombs they belong to and for each bomb we will decrese the kill
                    map<pii,set<pii> >::iterator kk=point_bomb.find(*j);
                    set<pii>::iterator kkk=kk->S.begin();
                    for(kkk;kkk!=kk->S.end();++kkk){
                        // now we will decrease the value of that bomb by one
                        bomb_kill.find(kkk)->second-=1;
                        if(bomb_kill.find(kkk)->second==0){
                            bomb_kill.erase(kkk);
                        }
                    }  }
        }
    }
    return 0;
}
