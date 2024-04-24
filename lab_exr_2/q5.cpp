#include <iostream>
using namespace std;
void  calcQuotient(double n1, double n2, double &answer);
void  calcQuotient(double n1, double n2, double &answer){

    answer= n1/n2;

}
int main()
{
double num1, num2, quotient =0 ;
cout<<"enter the two numbers"<<endl;
cin>>num1>>num2;

calcQuotient(num1, num2, quotient );

cout<<"the result is: "<<quotient;

return 0;
}