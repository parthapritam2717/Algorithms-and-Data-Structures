#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
#include<list>
#include<map>
#include<set>
#include<time.h>
#include<math.h>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define MOD 1000000007
#define pb push_back
#define mp make_pair
int countDecodingDP(string digits, int n)
{
    int count[n+1]; // A table to store results of subproblems
    count[0] = 1;
    count[1] =(digits[0]>'0')?1:0;

    for (int i = 2; i <= n; i++)
    {
        count[i] = 0;

        // If the last digit is not 0, then last digit must add to
        // the number of words
        if (digits[i-1] > '0')
            count[i] = count[i-1];

        // If second last digit is smaller than 2 and last digit is
        // smaller than 7, then last two digits form a valid character
        if ((digits[i-2] < '2' && digits[i-2]>'0')|| (digits[i-2] == '2' && digits[i-1] < '7') )
            count[i] += count[i-2];
    }
    return count[n];
}
int main()
 {
    int t;
    cin>>t;
    for(int j=0;j<t;++j){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<countDecodingDP(s,n)<<endl;
    }

    return 0;
}
