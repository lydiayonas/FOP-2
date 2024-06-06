#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct date {
    int day, month, year;
};

struct studentInfo {
    string name;
    double GPA;
    int ID;
    date DOB;
};

void getInfo(studentInfo& stud) {
    ofstream file("student.dat", ios::binary | ios::app); 
    if (!file) {
        cerr << "Unable to open file for writing" << endl;
        return;
    }

    cout << "Enter name of the student: ";
    cin.ignore();
    getline(cin, stud.name);
    cout << "Enter GPA: ";
    cin >> stud.GPA;
    cout << "Enter ID: ";
    cin >> stud.ID;
    cout << "Enter date of birth in DD/MM/YYYY format: ";
    cin >> stud.DOB.day >> stud.DOB.month >> stud.DOB.year;

    size_t length = stud.name.size();
    file.write(reinterpret_cast<char*>(&stud.ID), sizeof(stud.ID));
    file.write(reinterpret_cast<char*>(&stud.GPA), sizeof(stud.GPA));
    file.write(reinterpret_cast<char*>(&stud.DOB), sizeof(stud.DOB));
    file.write(reinterpret_cast<char*>(&length), sizeof(length));
    file.write(stud.name.c_str(), length);
    file.close();
}

void searchStudent(int searchID) {
    bool isFound = false;

    ifstream file("student.dat", ios::binary);
    if (!file) {
        cerr << "Unable to open file for reading" << endl;
        return;
    }

    while (file) {
        studentInfo stud;
        size_t length;
        file.read(reinterpret_cast<char*>(&stud.ID), sizeof(stud.ID));
        file.read(reinterpret_cast<char*>(&stud.GPA), sizeof(stud.GPA));
        file.read(reinterpret_cast<char*>(&stud.DOB), sizeof(stud.DOB));
        file.read(reinterpret_cast<char*>(&length), sizeof(length));

        if (!file) break;  // Exit if reading fails

        char* buffer = new char[length + 1];
        file.read(buffer, length);
        buffer[length] = '\0';
        stud.name = string(buffer);
        delete[] buffer;

        if (stud.ID == searchID) {
            isFound = true;
            cout << "Student found: " << stud.name << " " << stud.ID << " "
                 << stud.DOB.day << "/" << stud.DOB.month << "/" << stud.DOB.year << " " << stud.GPA << endl;
            break;
        }
    }

    if (!isFound) {
        cout << "Student not found!" << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "Menu: \n"
             << "1. Add student \n"
             << "2. Search by ID \n"
             << "3. Exit \n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of students: ";
                cin >> n;

                for (int i = 0; i < n; ++i) {
                    studentInfo stud;
                    getInfo(stud);
                }
                break;
            }
            case 2: {
                int searchID;
                cout << "Enter the ID of the student to search: ";
                cin >> searchID;

                searchStudent(searchID);
                break;
            }
            case 3:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
