#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    cin>>n;
    long long sq=pow(n,2);
    long long limit=sqrt(n);
    long long c=0;
    for(int i=2;i<=limit;++i){
        if(n%i!=0 && sq%i==0){
        // we have hit a jackpot lets add all the multiples of i into the number
        int temp=i;
        int k=1;
        while(temp<n){
            temp=temp*k;++k;
            if(sq%temp==0){
                c++;
            }
        }

        }
    }
    cout<<c<<endl;
    return 0;
}
