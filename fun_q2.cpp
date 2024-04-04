#include <iostream>
using namespace std;


float average(float a, float b, float c){

int mean= (a+b+c)/3.0;

return mean;

}
int main()
{
    float x,y,z;

cout<<"enter three numbers: "<<endl;
cin>>x>>y>>z;

float mean= average(x,y,z);

cout<<"the result is: "<<mean;


return 0;
}