#include <iostream>
using namespace std;

int calculatearea(int num1,int num2){
int area = num1*num2;

return area;
}
int calculatearea(int radius){

    int area=radius*radius;
    return area;
}
int main()
{

int a,b;

cout<<"enter length and width of the rectangle: ";
cin>>a>>b;

int area= calculatearea(a,b);

cout<<"the area is: "<<area<<endl;

int r;
cout<<"enter radious: ";
cin>>r;

 area=calculatearea(r);

cout<<"the area of the circle is: "<<area;



return 0;
}