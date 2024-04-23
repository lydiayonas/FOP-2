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

cout<<"enter an integer and a rational number: ";
cin>>num1>>num2;

  int result_int = square(num1);
    double result_double = square(num2);

    cout << "The square of the integer number is: " << result_int << endl;
    cout << "The square of the rational number is: " << result_double << endl;



return 0;
}