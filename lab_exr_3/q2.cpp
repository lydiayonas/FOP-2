#include <iostream>
using namespace std;

class area {
private:
    double length;
    double width;

public:
    void setdim(double l, double w) {
        length = l;
        width = w;
    }

    double getarea() const {
        return length * width;
    }
};

int main() {
    double l, w;

    cout << "Enter length of rectangle: ";
    cin >> l;

    cout << "Enter width of rectangle: ";
    cin >> w;

    area rectangle; // Creating an object of the area class
    rectangle.setdim(l, w); // Setting dimensions using the setdim function

    cout << "Area of the rectangle is: " << rectangle.getarea() << endl; // Getting area using the getarea function

    return 0;
}
