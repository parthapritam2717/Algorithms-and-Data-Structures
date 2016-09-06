#include<iostream>
#include<string>
using namespace std;
int  isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.length();
    int j=n-1;
    int mid=(n%2==0)?n/2:n/2-1;
    bool f=1;
    //cout<<A<<endl;
    for(int i=0;i<=mid;++i){
        if((A[i]>=65 && A[i]<=90 || A[i]>=97 && A[i]<=122 )){

        if((A[j]>=65 && A[j]<=90 || A[j]>=97 && A[j]<=122 )){
            // now check for ineuality
            //cout<<A[i]<<" "<<A[j];
            if(A[i]!=A[j]){
                return 0;
            }
            else{
                --j;
                continue;
            }

        }
        else{
            --j;
            --i;
            continue;
        }
    }
    else{
        ++i;
    }
}
if(f){
    return 1;
}
}

int main(){
    string A;
    cin>>A;
     string ans="0";
    string num;
    int l=A.length();
    int c=0;
    while(c<10){
    int i=0;
    if(ans!="0"){
        A=ans;
        ans="";
        //cout<<A<<endl;
        if(A.length()==1 && A[0]=='1' || A[0]=='0'){
                break;
        }
        l=A.length();
    }
    cout<<"A="<<A<<endl;
    while(i<l){
        num+=A[i];
        int n=stoi(num);
        if(n<2){
            ans+='0';
            ++i;
            continue;
        }
        else{
            ++i;
             int x=n/2;
            if(n%2==0){
                string temp=to_string(x);
                ans+=temp;
                num="";
            }
            else{string temp=to_string(x);
                ans+=temp;
                num="1";

            }
        }
    }
    //cout<<ans<<endl;
    // remove previous 0 starting
    int k=0;
    int tt=ans.length();
    for(int j=0;j<tt;++j){
        if(ans[j]=='0'){
            ++k;
        }
        else{
            break;
        }
    }
    string ss=ans.substr(k,tt);
   // cout<<"ans="<<ss<<endl;
    ans=ss;
    if(num=="1"){
            cout<<0<<endl;
            exit(0);

    }
    num="";++c;
    }
    cout<<A[0]<<endl;
    return 0;
}


