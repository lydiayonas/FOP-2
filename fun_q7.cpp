/*Write a C++ function called isPrime that takes an
integer parameter and returns true if the number is prime,
otherwise returns false.*/

#include <iostream>
using namespace std;
bool isprime(int n){

    if(n<=1){
        return false;

    }else{
 for(int i=2;i<n;i++){
if(n%i==0){

    return false;
}
 }
return true;
    }
}
int main()
{
int num;

cout<<"enter an integer: "<<endl;
cin>>num;

bool prime= isprime(num);

if (prime) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

return 0;
}