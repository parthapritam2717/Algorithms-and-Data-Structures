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

vector<string> ff(20,"-1");
string multiplication(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
    int ss=max(len1,len2);
    int *s1=new (nothrow) int[ss];
    int *s2=new (nothrow) int [ss];
    int *s3=new (nothrow) int [ss];
    string result;
    int index=ss-1;
    int c1=0,c2=0;
    for(int tt=len1-1;tt>=0;--tt){
            s1[index]=s11[tt]-48;
            if(s1[index]==0){
                c1++;
            }
            --index;
    }
    if(c1==len1){
        return "0";
    }
    index=ss-1;
    for(int tt=len2-1;tt>=0;--tt){
            s2[index]=s22[tt]-48;
            if(s2[index]==0){
                c2++;
            }
            --index;
    }

     if(c2==len2){
        return "0";
    }
    // now multiply a,b
        int loop=0;
        int temp=ss;
      for(int i=temp-1;i>=0;--i){
       int carry=0;index=ss-1-loop;int sum=0;
        for(int j=temp-1;j>=0;--j){
            sum=s2[i]*s1[j]+carry;
            if (index<0){
                        size_t sz=ss+1;
                        int *newarr=new int [sz];
                        memcpy(newarr+1,s3,ss*sizeof(int));
                        ss=sz;
                        delete[] s3;
                        s3=newarr;
                        index=0;

                }
            if(sum>9){
                while(sum!=0){
                    int temp=sum%10;
                    sum=sum/10;
                    s3[index]+=temp;
                    carry=sum;
                    --index;


                    break;
                }

            }
            else{
                s3[index]+=sum;
                --index;
                carry=0;
            }

        }
        if(carry!=0){
                // reallocate the array by extending the array by one element and then add the carry to the left most element
                 size_t sz=ss+1;
                int *newarr=new int [sz];
                memcpy(newarr+1,s3,ss*sizeof(int));
                ss=sz;
                delete[] s3;
                newarr[0]=carry;
                s3=newarr;
                }
        ++loop;
    }
    bool flag=0;
     fori(i,0,ss){
            // delete any pre zeros

            if(flag==0 && s3[i]==0){
                continue;
            }
            else{

                result=result+(char)(s3[i]+48);
                flag=1;
            }

     }
    // nl();
    return result;
}
string addition(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
    int ss=max(len1,len2);
    int *s1=new (nothrow) int[ss];
    int *s2=new (nothrow) int [ss];
    int *s3=new (nothrow) int [ss];
    string result;
    int index=ss-1;
    for(int tt=len1-1;tt>=0;--tt){
            s1[index]=s11[tt]-48;
            --index;
    }
    index=ss-1;
    for(int tt=len2-1;tt>=0;--tt){
            s2[index]=s22[tt]-48;
            --index;
    }
     // now the logic for adition of the two numbers
     int carry=0;
     for(int index=ss-1;index>=0;--index){
        int sum=s1[index]+s2[index]+carry;
        if(sum>9){
            // split the digits and add the left most digit for carry
            while(sum!=0){
                int temp=sum%10;
                sum=sum/10;
                s3[index]=temp;
                carry=sum;
                break;
            }
        }
        else{
            s3[index]=sum;
            carry=0;
        }
     }
     // now the boundary condition if the carry is produces at the last element
     if(carry!=0){

        size_t sz=ss+1;
        int *newarr=new int [sz];
        memcpy(newarr+1,s3,ss*sizeof(int));
        ss=sz;
        delete[] s3;
        newarr[0]=carry;
        s3=newarr;

    }
    // now copy back the array into a string
     bool flag=0;
     fori(i,0,ss){
            if(flag==0 && s3[i]==0){
                continue;
            }
            else{

                result=result+(char)(s3[i]+48);
                flag=1;
            }
     }
    return result;
}

string fibo(int n){
    if(ff[n]!="-1"){
            return ff[n];
        }
    else{

        for(int i=2;i<=n;++i){
            if(ff[i]=="-1"){
                ff[i]=addition(multiplication(fibo(i-1),fibo(i-1)),fibo(i-2));
               // cout<<i<<" "<<ff[i]<<endl;

            }
        }
        return ff[n];
    }
}




int main(){
            int n,a,b;
            si(a);
            si(b);
            si(n);
            ff[0]=to_string(a);
            ff[1]=to_string(b);
           // cout<<ff[0]<<" "<<ff[1]<<endl;
            if(n==1){
                cout<<ff[0]<<endl;
            }
            else if(n==2){
                cout<<ff[1]<<endl;
            }
            else{
                cout<<fibo(n-1);
            }

    return 0;

}



