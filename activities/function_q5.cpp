
#include <iostream>
using namespace std;


void deftriangle() {
    const int n = 5;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

void Custtriangle(char s, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << s;
        }
        cout << endl;
    }
}

int main() {
    int choice;
    char s;
    int n;

    cout << "What would you like? " << endl;
    cout << "1. Print the default right-angle triangle" << endl;
    cout << "2. Create your own triangle" << endl;
    cin >> choice;

    switch (choice) {

    case 1:

       deftriangle();

        break;

    case 2:

        cout << "Enter the size of the triangle: ";
        cin >> n;
        cout << "Enter the symbol to use: ";
        cin >> s;
       Custtriangle(s,n);
        break;

    default:

        cout << "Invalid input" << endl;
        break;
    }

    return 0;
}







