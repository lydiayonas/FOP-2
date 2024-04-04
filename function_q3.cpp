#include <iostream>
using namespace std;

// Function prototype (declaration)
void calculateProduct(int num1, double num2, double& result);

int main() {
    int firstnum;
    double secondnum;
    double product;

    cout << "Enter the two numbers: ";
    cin >> firstnum >> secondnum;

    // Calling the function
    calculateProduct(firstnum, secondnum, product);

    cout << "The product is: " << product << endl;

    return 0;
}

// Function definition
void calculateProduct(int num1, double num2, double& result) {
    result = num1 * num2; // Calculate the product and store it in the third parameter
}


