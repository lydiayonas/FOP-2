#include <iostream>
#include<cmath>

using namespace std;

int square(int &num1){

num1=pow(num1,2);

}
double square(double &num2){

num2=pow(num2,2);

}

int main()
{

int integer;
double rational;

 cout << "Enter an integer number: ";
    cin >> integer;


    cout << "Enter a rational number: ";
    cin >> rational;

    square(integer);
    cout << "Square of the integer number: " << integer<< endl;

    square(rational);
    cout << "Square of the rational number: " << rational << endl;




return 0;
}

