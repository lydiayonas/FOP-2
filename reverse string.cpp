#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    string originalStr = "hello";
    cout << "Original string: " << originalStr << endl;
    string reversedStr = reverseString(originalStr);
    cout << "Reversed string: " << reversedStr << endl;

    int num = 12345;
    cout << "Number of digits in " << num << ": " << countDigits(num) << endl;

    return 0;
}
