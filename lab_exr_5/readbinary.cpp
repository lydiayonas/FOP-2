#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void getRecord() {
    ofstream studentRecord("TestBinary.dat", ios::binary | ios::app);

    if (!studentRecord.is_open()) {
        cout << "Unable to open the file." << endl;
        return;
    }
    
    int test_mark;
    string name;
    cout << "Enter the name of the student: ";
    cin >> name;
    
    cout << "Enter the test result of the student: ";
    cin >> test_mark;
    
    // Write the name length followed by the name itself
    int name_length = name.size();
    studentRecord.write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
    studentRecord.write(name.c_str(), name_length);
    
    // Write the test result
    studentRecord.write(reinterpret_cast<const char*>(&test_mark), sizeof(test_mark));
    
    studentRecord.close();
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
       getRecord();
    }
    
    return 0;
}
