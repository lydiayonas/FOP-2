#include <iostream>
using namespace std;
int square(int &a){

return a*a;
    
}
double square(double &b){

return b*b;

}

int main()
{
int num1;
double num2;

cout<<"enter an integer"<<endl;
cin>>num1;

int int_squ=square(num1);

cout<<"the square of the integer is: "<<int_squ<<endl;

cout<<"enter an integer"<<endl;
cin>>num2;

double dub_squ=square(num2);

cout<<"the square of the rational number is: "<<dub_squ;

return 0;
}