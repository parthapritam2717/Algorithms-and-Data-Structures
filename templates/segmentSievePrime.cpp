#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include<math.h>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<stack>
using namespace std;
vector<int> prime;
void simpleSieve(int limit, vector<int> &prime){
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (int p=2; p*p<limit; p++){
        // If p is not changed, then it is a prime
        if (mark[p] == true){
            // Update all multiples of p
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++){
        if (mark[p] == true){
           // prime.push_back(p);
            cout << p << "  ";
        }
    }
}


/* to print all prime numbers less than n*/
void segmentedSieve(long long n){
        int limit = floor(sqrt(n))+1;

        simpleSieve(limit, prime);
        int low  = limit;
        int high = 2*limit;
            /*While all segments of range [0..n-1] are not processed process one segment at a time*/
         while (low < n){
            bool mark[limit+1];
            memset(mark, true, sizeof(mark));
            for (int i = 0; i < prime.size(); i++){
                    // Find the minimum number in [low..high] that is
                    // a multiple of prime[i] (divisible by prime[i])
                    // For example, if low is 31 and prime[i] is 3,
                        // we start with 33.
                int loLim = floor(low/prime[i]) * prime[i];
                if (loLim < low){
                    loLim += prime[i];
                }
                /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
                for (int j=loLim; j<high; j+=prime[i]){
                        mark[j-low] = false;
                }
            }
            // Numbers which are not marked as false are prime
            for (int i = low; i<high; i++){
            if (mark[i - low] == true)
                cout << i << "  ";
                //prime.push_back(i);
            }


          // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
    }
int main(){
    /*generate all primes between 2 and n*/
    long long n,m;
    scanf("%lld", &n);
    segmentedSieve(n);
    for(vector<int>::iterator i=prime.begin();i!=prime.end();++i){
        cout<<*i<<endl;
    }
    return 0;

}




