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
    int up=0,down=A-1,s1=0,s2=A-1;
    int item=1;
    while(up<=down && s1<=s2){
        bool f=0;
        for(int i=0;i<A;++i){
            if(data[up][i]!=0 && f==0){
                continue;
            }
            else if(f==1 && data[up][i]!=0){
                break;
            }
            else{
                f=1;
                data[up][i]=item;++item;
            }
        }
        ++up;
        f=0;
        for(int i=0;i<A;++i){
            if(data[i][s2]!=0 && f==0){
                continue;
            }
            else if(f==1 && data[i][s2]!=0){
                break;
            }
            else{
                f=1;
                data[i][s2]=item;++item;
            }
        }
        --s2;
        f=0;
        for(int i=A-1;i>=0;--i){
            if(data[down][i]!=0 && f==0){
                continue;
            }
            else if(f==1 && data[down][i]!=0){
                break;
            }
            else{
                f=1;
                data[down][i]=item;++item;
            }
        }
        --down;
        f=0;
        for(int i=A-1;i>=0;--i){
                    if(data[i][s1]!=0 && f==0){
                        continue;
                    }
                    else if(f==1 && data[i][s1]!=0){
                        break;
                    }
                    else{
                        f=1;
                        data[i][s1]=item;++item;
                    }
                }
                ++s1;

    }
    for(int i=0;i<A;++i){
        for(int j=0;j<A;++j){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }



}



