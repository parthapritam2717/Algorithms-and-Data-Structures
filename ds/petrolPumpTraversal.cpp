/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int remaining=0;
   int total=0;
   int sumremaining=0;
   int start=0;
   // sum remaining if at any point becomes
   //<0 then the new start will be current index
   for(int i=0;i<n;++i){
       remaining=p[i].petrol-p[i].distance;
       if(sumremaining>=0){
           // we can have further positive petrol pumps
           sumremaining+=remaining;
       }
       else{
           sumremaining=remaining;
           start=i;
       }
       total+=remaining;
   }
   if(total>=0){
       return start;
   }
   return -1;

}


