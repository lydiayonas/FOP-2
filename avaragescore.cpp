#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Date {
    int day;
    int month;
    int year;
};


struct Student {
    int rollno;
    string name;
    int marks[5];
    Date birthDate;
};


void inputStudentDetails(Student& student) {
    cout << "Enter Roll Number: ";
    cin >> student.rollno;
    cout << "Enter Name: ";
    cin.ignore(); 
    getline(cin, student.name);
    cout << "Enter Birth Date (DD MM YYYY): ";
    cin >> student.birthDate.day >> student.birthDate.month >> student.birthDate.year;
    cout << "Enter Marks in 5 subjects: ";
    for (int i = 0; i < 5; ++i) {
        cin >> student.marks[i];
    }
}


double calculateAverage(const Student& student) {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += student.marks[i];
    }
    return sum / 5;
}


void printStudentDetails(const Student& student) {

    cout << setw(20) << student.rollno;
    cout << setw(20) << student.name;
    cout << setw(15) << student.birthDate.day << "/" << student.birthDate.month << "/" << student.birthDate.year;

    for (int i = 0; i < 5; ++i) {
        cout << setw(8) << student.marks[i];
    }
    cout << endl;
}


int main() {
    const int numStudents = 2;
    Student students[numStudents];

    
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter details of Student " << i + 1 << endl;
        inputStudentDetails(students[i]);
    }

    
    cout << "\nStudents Details and Marks:" << endl;
    cout <<setw(3)<< "Roll No  \tName  \tBirth Date  \tMark 1  \tMark 2  \tMark 3  \tMark 4  \tMark 5" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\t";
        printStudentDetails(students[i]);
    }

    
   cout << "\nStudents who scored an average mark below 50:" << endl;
   
cout << setw(10) << "Roll No" << setw(20) << "Name" << setw(15) << "Birth Date" << setw(10) << "Avg Mark" << endl;
cout << "_____________________________________________________" << endl; 

for (int i = 0; i < numStudents; ++i) {
    double avg = calculateAverage(students[i]);
    if (avg < 50) {
        cout << setw(10) << students[i].rollno 
             << setw(20) << students[i].name 
             << setw(15) << students[i].birthDate.day << "/" << students[i].birthDate.month << "/" << students[i].birthDate.year
             << setw(10) << avg << endl;
    }
}

    return 0;
}

