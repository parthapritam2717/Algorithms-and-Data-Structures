#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<long long> primeData;
void sieve(long long n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++){
        // if prime p is not changed then its a prime
        if (prime[p] == true){
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p){
                prime[i] = false;
            }
        }
    }
    // now create a vector and put all the primes into it and return

    for(long long i=2;i<=n;++i){
        if(prime[i]){
            primeData.push_back(i);
        }
    }

}
int main(){
    /*generate all primes between 2 and n*/
    long long n,m;
    scanf("%lld", &n);
    sieve(n);
    for(vector<long long>::iterator i=primeData.begin();i!=primeData.end();++i){
        printf("%lld\n",*i);
    }
    cout<<"Num="<<primeData.size();
    //cout<<primeData[0];
    //cout<<primeData[2];


    return 0;

}



