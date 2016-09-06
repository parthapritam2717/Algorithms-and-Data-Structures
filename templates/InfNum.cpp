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

bool compare(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
      int ss=max(len1,len2);
    int *s1=new (nothrow) int[ss]();
    int *s2=new (nothrow) int [ss]();
    int *s3=new (nothrow) int [ss]();
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
    index=ss-1;
    for(int tt=len2-1;tt>=0;--tt){
            s2[index]=s22[tt]-48;
            if(s2[index]==0){
                c2++;
            }
            --index;
    }
    fori(i,0,ss){
        if(s1[i]>s2[i]){
            return true;
        }
        else if(s1[i]==s2[i]){
            continue;
        }
        else{
            return false;
        }
    }
}


string divide(string s11,string s22){
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
    // this case is when we are having the divisor to be equal to zero
     if(c2==len2){
        return "-1";
    }
    // delete the trailing zeros from both the divident and divisors
    int counti=0;
    for(int i=ss-1;i>=0;--i){
        if(s1[i]==0){
            counti++;
            continue;
        }
        else{
            break;
        }
    }
    // reallocate the input to different array excluding the number of counti
    int countii=0;
    for(int i=ss-1;i>=0;--i){
        if(s2[i]==0){
            countii++;
            continue;
        }
        else{
            break;
        }
    }

    int minzero=min(counti,countii);
    size_t sz=ss-minzero;
    int *newarr=new int [sz];
    memcpy(newarr,s1,sz*sizeof(int));
    ss=sz;
    delete[] s1;
    s1=newarr;

    newarr=new int [sz];
    memcpy(newarr,s2,sz*sizeof(int));
    s2=newarr;
   // now the actual divide part

    return result;
}



string multiplication(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
    int ss=max(len1,len2);
   // ss=250;
    int *s1=new (nothrow) int[ss]();
    int *s2=new (nothrow) int [ss]();
    int *s3=new (nothrow) int [ss*2]();
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
    int loop=1;

    for(int i=ss-1;i>=0;--i){
        int start=2*ss-loop;int carry=0;int ll=0;
        for(int j=ss-1;j>=0;--j){


        }
    }
    bool flag=0;
     fori(i,0,2*ss){
            result=result+(char)(s3[i]+48);

     }
    // nl();
    return result;
}



string substract(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
    int ss=max(len1,len2);
    int *s1=new (nothrow) int[ss]();
    int *s2=new (nothrow) int [ss]();
    int *s3=new (nothrow) int [ss]();
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
    // now the processing part
     for(int index=ss-1;index>=0;--index){
            if(s1[index]-s2[index]>=0){
                // no carry case
                s3[index]+=(s1[index]-s2[index]);
            }
            else if(s1[index]-s2[index]<0){
                // now need to borrow from the adjoining left hand side
                int temp=index-1;
                while(true){
                        if(s1[temp]-1>=0){
                            s1[temp]-=1;
                            for(int i=temp+1;i<index;i++){
                                s1[i]-=1;
                            }
                            s3[index]=(s1[index]+10)-s2[index];
                            break;
                        }
                        else{
                            s1[temp]=10;
                            --temp;
                            continue;
                        }
                }


            }

     }
      bool flag=0;
     fori(i,0,ss){

            result=result+(char)(s3[i]+48);

     }
    return result;
}


string addition(string s11,string s22){
    int len1=s11.length();
    int len2=s22.length();
    int ss=max(len1,len2);
    int *s1=new (nothrow) int[ss]();
    int *s2=new (nothrow) int [ss]();
    int *s3=new (nothrow) int [ss]();
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
        int *newarr=new int [sz]();
        memcpy(newarr+1,s3,ss*sizeof(int));
        ss=sz;
        delete[] s3;
        newarr[0]=carry;
        s3=newarr;

    }
    // now copy back the array into a string
     bool flag=0;
     fori(i,0,ss){

            result=result+(char)(s3[i]+48);

     }
    return result;
}

int main(){
    /*This program reads a given arbitarily large number which cant be hold in unsigned long long  and performes basic operations*/
    string input1,input2;
    cin>>input1>>input2;
   // cout<<addition(input1,input2)<<endl;
    /*Now the substraction part assuming that the first input is bigger than the second input*/
   // cout<<substract(input1,input2)<<endl;
    /*Multiplication of two numbers assuming both are positive numbers*/
    cout<<multiplication(input1,input2)<<endl;
    /*Divide the given numbers two numbers and return the quotiesnt*/
    //cout<<divide(input1,input2);



    return 0;

}



