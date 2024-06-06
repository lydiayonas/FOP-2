#include <iostream>
using namespace std;

class Sample {
public:
    long int n;
};

int main() {
    Sample x;

    
   

    while (x.n != 0) {
        cout << "Enter the number: ";
        cin >> x.n;
            cout << "WAW = " << x.n << endl;
        }
    

    cout << "Stop" << endl;

    return 0;
}
