#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    int *ar=new int [5]();
    for(int i=0;i<t;++i){
            int a;
            cin>>a;
            ar[a]++;
    }
    int c=0;
    c+=ar[4];
    ar[4]=0;
    if(ar[3]>=ar[1]){
        c+=ar[1];
        c+=(ar[3]-ar[1]);
         ar[1]=0;
        ar[3]=0;
        //cout<<"Am here";
       // cout<<c<<endl;
    }
    else if(ar[3]<ar[1]){
        c+=ar[3];
        ar[1]=ar[1]-ar[3];
        ar[3]=0;
    }
    int tt=ar[2]*2+ar[1];
    //cout<<ar[1]<<endl;
    //cout<<ar[1]<<endl;
    //cout<<tt<<endl;
    if(tt%4==0){
        c+=tt/4;
    }
    else{
        c+=tt/4;
        c++;
    }
    cout<<c;
    return 0;
}
