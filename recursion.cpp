#include <iostream>
using namespace std;

int calculateFactorial(int n){

if (n == 0 || n == 1) {
        return 1;

}else{

return n * calculateFactorial(n - 1);

}

}
int main()
{

 int num;
    cout << "Enter a non-negative integer to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Invalid input! Factorial is not defined for negative numbers." << endl;
    } else {
        int factorial = calculateFactorial(num);
        cout << "Factorial of " << num << " is: " << factorial << endl;
    }



return 0;
}

