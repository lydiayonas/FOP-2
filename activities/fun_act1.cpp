#include <iostream>
using namespace std;


int sum(int a,int b){

    int sum= a+ b;
    return sum;
}
int main()
{
int num1,num2;
cout<<"enter two numbers: ";
cin>>num1>>num2;

int result= sum( num1,num2);

cout<<"the result is: "<<result;







return 0;
}