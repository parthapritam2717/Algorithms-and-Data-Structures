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
int _merge(vi &arr,int left,int mid,int right){
    int i=left;
    int j=mid+1;
    vi temp(right-left+1);
    int k=0;
    int inv=0;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            // here we will get the inversion
            inv+=(mid-i+1);
        }

    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    // now copy the temp array back to arr
    i=left;j=0;
    while(i<=right){
        arr[i++]=temp[j++];
    }
    return inv;

}
int mergeSort(vi &arr,int left,int right){
    int inv=0;
    if(left<right){
        int mid=(left+right)/2;
        inv=mergeSort(arr,left,mid);
        inv+=mergeSort(arr,mid+1,right);
        inv+=_merge(arr,left,mid,right);
    }
    return inv;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    vi arr(t,0);
    fori(i,0,t){
        cin>>arr[i];
    }
    //now we will perform merge sort in this vector and count inversion in the array
    cout<<mergeSort(arr,0,t-1)<<endl;
    return 0;
}



