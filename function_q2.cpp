#include <iostream>
#include <cmath>
using namespace std;

double sum(double num1, double num2);

int main()
{
double x,y;
cout<<"enter the two numbers"<<endl;
cin>>x>>y;

 x= pow(x,3);
 y= sqrt(y);
double result;

result= sum(x,y);

cout<<"The sum is: "<<result;

return 0;
}


double sum(double num1, double num2){


return num1 + num2;

}




