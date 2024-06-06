#include <iostream>
using namespace std;

template <typename T, typename U>
double floatPointDivide(T a, U b){
    return a/b;
}
int main()
{
    int num1=4,num2=4;
  cout<<"the division of the numbers is: "<<  floatPointDivide <double>(num1,num2)<<endl;

return 0;
}