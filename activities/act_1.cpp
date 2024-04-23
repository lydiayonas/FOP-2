#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];

    cout << "Enter the elements: ";

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    bool isPalindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (array[i] != array[n - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "The array is a palindrome." << endl;
    } else {
        cout << "The array is not a palindrome." << endl;
    }

    return 0;
}
