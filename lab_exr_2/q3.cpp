#include <iostream>
#include <cmath>
using namespace std;

double triangle(double s1, double s2, double &s3){

s3=sqrt((s1*s1)+(s2*s2));

return s3;

}
int main()
{

  double side1,side2,side3;

cout<<"enter the length is side one"<<endl;
cin>>side1;

cout<<"enter the length of side two"<<endl;
cin>>side2;

triangle(side1,side2,side3);

cout<<"the length of the thrid side is: "<<side3;
return 0;
}