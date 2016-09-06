// map::lower_bound/upper_bound
#include <iostream>
#include <map>
using namespace std;




int counti(int n){
    int c=0;

    while(n>0){
        n=n>>1;
        c++;
    }
    return c;


}
int main ()
{
  for(int i=0;i<33;i++){
    cout<<i<<"->"<<counti(i)<<endl;
  }
  return 0;
}
