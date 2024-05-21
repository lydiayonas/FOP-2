#include <iostream>
using namespace std;


template <typename T, typename U>
double floatingPointDivide(T a, U b) {
    return a/b;
}

int main() {
   
    int x = 7, y = 3;
    cout << "Division of integers: " << floatingPointDivide<double>(x, y) << endl;

    float f1 = 9.5, f2 = 1.2;
    cout << "Division of floats: " << floatingPointDivide<double>(f1, f2) << endl;

return 0;
}