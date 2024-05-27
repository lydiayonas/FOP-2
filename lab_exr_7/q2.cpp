#include <iostream>
using namespace std;

template <typename T, typename U>

double floatingPointDivide( T num1, U num2){

    return num1/num2;
}
int main()
{

    int a=3,b=5;
  floatingPointDivide(a,b);

    cout<< "Division of integers: " <<floatingPointDivide<double>(a,b)<<endl;

    float c=5.88,d=5.4;

    floatingPointDivide(c,d);

    cout<<" Division of numbers: " <<floatingPointDivide<double>(c,d);
return 0;
}