#include <iostream>
using namespace std;

 
int factorial(int n) {
    if (n < 0) {
        cout << "Invalid input! Factorial is not defined for negative numbers." << endl;
        return -1; 
    } else {
        int result = 1;
        for (int i = n; i > 1; i--) {
            result *= i;
        }
        return result;
    }
}

int main() {
    int num;

    cout << "Enter a positive integer: ";
    cin >> num;

    int result = factorial(num);
    if (result != -1) {
        cout << "Factorial of " << num << " is: " << result << endl;
    }

    return 0;
}
