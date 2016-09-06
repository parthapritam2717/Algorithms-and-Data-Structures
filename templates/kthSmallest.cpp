#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int ksmallest(int k,const vector<int> &A){
    // create a max heap and then
    vector<int> temp;
    for(int i=0;i<k;++i){
        temp.push_back(A[i]);

    }
    int l=A.size();
    make_heap(temp.begin(),temp.end());
   // cout<<"Initially heap top="<<temp.front()<<endl;
    for(int i=k;i<l;++i){
        if(temp.front()>A[i]){
           // temp.pop();
            //  temp.push(A[i];)
             //make_heap(temp.begin(),temp.end());
             pop_heap(temp.begin(),temp.end());
             temp.pop_back();
                temp.push_back(A[i]);
            push_heap (temp.begin(),temp.end());
        }
    }
     //cout<<"Initially heap top="<<temp.front()<<endl;
    return temp.front();
}



int main(){
    int n;
    cin>>n;
    vector<int> data;
    for(int i=0;i<n;++i){
            int tt;
            cin>>tt;
            data.push_back(tt);
    }

    int key;
    cin>>key;
    cout<<ksmallest(key,data)<<endl;
}
