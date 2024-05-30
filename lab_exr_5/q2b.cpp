#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void displayRecord() {
    ifstream studentRecord("TestBinary.dat", ios::binary);
    if (!studentRecord.is_open()) {
        cout << "Unable to open the file." << endl;
        return;
    }
    
    cout << "Student records:" << endl;
    int test_mark;
    string name;
    int name_length;
    
    while (studentRecord.read(reinterpret_cast<char*>(&name_length), sizeof(name_length))) {
        name.resize(name_length);
        studentRecord.read(&name[0], name_length);
        studentRecord.read(reinterpret_cast<char*>(&test_mark), sizeof(test_mark));
        
        cout << "Name: " << name << ", Test Mark: " << test_mark << endl;
    }
    
    studentRecord.close();
}

int main() {
    displayRecord();
    return 0;
}
