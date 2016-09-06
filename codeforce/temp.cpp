#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
int main(){
    int A;
    cin>>A;
    vector<vector<int> > data(A,vector<int>(A,0));
    vector<vector<int> > list1;
    for(int i=0;i<A;++i){
        for(int j=0;j<A;++j){
            int t;
            cin>>t;
            data[i][j]=t;
        }
    }
    for(int i=0;i<A;++i){
        for(int j=0;j<A;++j){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int j=0;j<=A-1;++j){
        int k=0;int t=j;
        while(k<=j && t>=0){
            cout<<data[k][t]<<" ";
            ++k;
            --t;
        }
    }
    // now the lower part
     for(int j=1;j<=A-1;++j){
          int k=A-1;int t=j;
        while(t<=A-1){
                cout<<data[t][k]<<" ";
                ++t;
                --k;
        }
     }






}



