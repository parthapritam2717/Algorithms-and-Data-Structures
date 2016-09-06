#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int> data(n),data1(n);
    for(int i=0;i<n;++i){
        cin>>data[i];
        data1[i]=data[i];

    }
    map<int,int> m;
    sort(data1.begin(),data1.end());
    for(int i=0;i<n;++i){
        m[data1[i]]=i;
    }
    int f=0;
    int l1=0,r1=0;
    for(int i=0;i<n;++i){
        int t=data[i];
         //cout<<"hello";
        if(m.find(t)->second==i){continue;  // already in the correct position

        }
        else{
            // find the actual index from which i need to do the reverse
            int indexactual=m.find(t)->second;// this is the actual place in which the number should be
            int data_temp=data[indexactual];
            // now check if it is possible to do a swapping and correct the order
             //cout<<data[i]<<" "<<data[indexactual]<<endl;
            if(m.find(data_temp)->second==i && f==0){
                // yes we can do a swap
                int a=data[i];
                data[i]=data[indexactual];
                data[indexactual]=a;
                f=1;
                l1=i+1;
                r1=indexactual+1;
            }
            else if(m.find(data_temp)->second==i && f>=1){
                    if(indexactual>=r1+1){
                        cout<<"no"<<endl;
                        f=0;
                        break;
                    }
                     int a=data[i];
                    data[i]=data[indexactual];
                    data[indexactual]=a;
                     f=2;
            }
            else if(m.find(data_temp)->second!=i && (f>=1 || f==0)){
                cout<<"no"<<endl;
                break;
            }

        }
    }
    if(f==1){
        cout<<"yes"<<endl;
        cout<<"swap "<<l1<<" "<<r1<<endl;
    }
    else if(f==2){
            cout<<"yes"<<endl;
            cout<<"reverse "<<l1<<" "<<r1<<endl;

    }



    return 0;
}


