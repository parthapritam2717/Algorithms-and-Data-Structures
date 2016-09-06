#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
   int n,a;
   cin>>n>>a;
   bool *arr=new bool[n]();
   for(int i=0;i<n;++i){
    int t;
    cin>>t;
    arr[i]=t;
   }
   // now the processing
        int c=0;
        if(arr[a-1]==1){
            c=1;
        }
   int maxi=0;int endi=max(abs(n-a),abs(0-a));
   for(int i=0;i<=endi;++i){
        if((((a-1)+i)<n && arr[(a-1)+i]==1) && (((a-1)-i)>=0 && arr[(a-1)-i]==1) && (((a-1)+i)!=(a-1)-i)){
                    c+=2;
            }
        else if((((a-1)+i)<n && arr[(a-1)+i]==1) && (((a-1)-i)<0)){
                    c++;
        }
        else if((((a-1)-i)>=0 && arr[(a-1)-i]==1) &&  (((a-1)+i)>=n)){
            c++;
        }

        }

   cout<<c<<endl;
}
