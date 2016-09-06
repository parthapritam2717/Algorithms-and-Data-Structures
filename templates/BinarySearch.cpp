#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int upperBound(vector<int> &A,int k){
    // always check for a 2 element test case in which firsts gives no and second gives yes
    int low=0;
    int high=A.size()-1;
    while(low<high){
        int mid=low+(high-low+1)/2;
        if(A[mid]>=k){
            high=mid-1;
        }
        else{
            low=mid;
        }

    }
    if(A[low]>=k){
        return -1;
    }
    return low;


}
int lowerBound(vector<int> &A,int k){
    int low=0;
    int high=A.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(A[mid]>=k){
            high=mid;
        }
        else{
            low=mid+1;
        }

    }
    if(A[low]<k){
        return -1;
    }
    return low;




}
int binarySearch(vector<int> &A,int k){
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(A[mid]==k){
            return mid;
        }
        else if(A[mid]>k){
            low=mid+1;


        }
        else{
            high=mid-1;
        }
    }
    return -1;

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
    sort(data.begin(),data.end());
    int key;
    cin>>key;
    cout<<binarySearch(data,key)<<endl;
    cout<<upperBound(data,key)<<endl;
    cout<<lowerBound(data,key)<<endl;

}
