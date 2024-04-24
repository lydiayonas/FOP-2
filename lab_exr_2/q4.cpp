#include <iostream>
#include <cmath>
using namespace std;
double num(double a){
    if(a<0){
        return a*a;
    }else{

        double result=sqrt(a);

        return result;

    }
}
int main()
{

    double num1;

cout<<"enter an integer\n";
cin>>num1;

double final= num(num1);
if(num1<0){
    cout<<"the number is negative so the square is: "<<final<<endl;
}else{
    cout<<"the number is positive so the square-root is: "<<final<<endl;
}

return 0;
}