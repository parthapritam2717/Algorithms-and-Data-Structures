#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Box{
int width, height;
 public:
    Box(int a=1,int b=10){
        cout<<"Constructer called"<<endl;
        width=a;
        height=b;
    }



    void set_values (int,int);
    int area() {return width*height;}
};

void Box::set_values (int x, int y) {
  width = x;
  height = y;
}

int main(){
    Box b1;
    b1.set_values(1,2);
    cout<<b1.area()<<endl;
    Box b2;
    cout<<b2.area();
    Box *p;
    p=&b1;
    p->set_values(10,10);
    cout<<p->area();
return 0;}
