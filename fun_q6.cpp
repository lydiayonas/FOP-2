#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int exp){

int result= pow(base,exp);

return result;

}
int main()
{

int x, y;
cout<<"enter the base and the exponent: ";
cin>>x>>y;

int result=power(x, y);

cout<<"the result is: "<<result<<endl;

return 0;
}