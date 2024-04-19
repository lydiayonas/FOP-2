#include <iostream>

using namespace std;

class Area {
private:
    double length;
    double breadth;

public:
    void setDim(double l, double b) {
        length = l;
        breadth = b;
    }

    double getArea() const {
        return length * breadth;
    }
};

int main() {
    double l, b;

    cout << "Enter length of rectangle: ";
    cin >> l;

    cout << "Enter breadth of rectangle: ";
    cin >> b;

    Area rectangle;
    rectangle.setDim(l, b);

    cout << "Area of the rectangle is: " << rectangle.getArea() << endl;

    return 0;
}
