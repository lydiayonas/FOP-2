#include <iostream>
using namespace std;

int factorial(int n){

    int temp=1;

      if (n < 0) {
        cout << "Invalid input! Factorial is not defined for negative numbers." << endl;
        return -1; 
    } else {

     for(int i=n;i>=1;i--){

         temp*=i;
     
     }
    }
     return temp;
}

int fibonacci(int n){
     if (n == 0 || n == 1) {
        return n;
        }
    
    return fibonacci(n-1) + fibonacci(n-2);
        
}
int main()
{

int num1;

cout<<"enter an integer: ";
cin>>num1;

int result = factorial(num1);

cout<<"the factorial of the number is: "<<result<<endl;


 cout << "Fibonacci series up to " << num1 << ": ";

  for (int i = 0; i < num1; i++) {
    cout << fibonacci(i) << " ";
  }


return 0;
}