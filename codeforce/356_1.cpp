#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    map<int,int> data;
    int temp_max=0;
    for(int i=0;i<5;++i){
        int t;
        cin>>t;
        temp_max+=t;
        map<int,int>::iterator ii=data.find(t);
        if(ii!=data.end()){
            ii->second+=1;
        }
        else{
            data.insert(pair<int,int> (t,1));
        }
    }
    // now the processing
    int maxi=temp_max;
    for(map<int,int>::reverse_iterator ii=data.rbegin();ii!=data.rend();++ii){
            //cout<<ii->second<<endl;
        if(ii->second>=3){
           int tem=temp_max-(ii->first)*3;
           if(tem<maxi){
            maxi=tem;
           }


        }
        else if(ii->second==2){
            int tem=temp_max-(ii->first)*2;
             if(tem<maxi){
                maxi=tem;
           }

        }
    }
    cout<<maxi<<endl;

}
