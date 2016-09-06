#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *ans=new int[n]();
    for(int i=0;i<n;++i){
        for(int k=0;k<=2;++k){
            int tt;
            cin>>tt;
            ans[i]+=tt;
        }
    }
    int c=0;
    for(int i=0;i<n;++i){
        if(ans[i]>=2){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}



