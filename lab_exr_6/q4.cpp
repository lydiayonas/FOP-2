#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Employee {
    int id;
    char sex;
    float hourlyWage;
    int yearsWithCompany;
};

bool compareById(const Employee& emp1, const Employee& emp2) {
    return emp1.id < emp2.id;
}

void EmployeesData(Employee emp[]) {
    for (int i = 0; i < 2; ++i) {
        cout << "Enter ID number for employee " << i+1 << ": ";
        cin >> emp[i].id;
        cout << "Enter sex (M/F) for employee " << i+1 << ": ";
        cin >> emp[i].sex;
        cout << "Enter hourly wage for employee " << i+1 << ": ";
        cin >> emp[i].hourlyWage;
        cout << "Enter years with the company for employee " << i+1 << ": ";
        cin >> emp[i].yearsWithCompany;
    }
}

void writeToFile(Employee emp[]) {
    ofstream outFile("employee_records.txt");
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    for (int i = 0; i < 2; ++i) {
        outFile << emp[i].id << " " << emp[i].sex << " " << emp[i].hourlyWage << " " << emp[i].yearsWithCompany << endl;
    }

    outFile.close();
}

void readAndCalculatePay(Employee emp[]) {
    ifstream inFile("employee_records.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int hoursWorked;
    for (int i = 0; i < 2; ++i) {
        inFile >> emp[i].id >> emp[i].sex >> emp[i].hourlyWage >> emp[i].yearsWithCompany;
        cout << "Enter hours worked for employee with ID " << emp[i].id << ": ";
        cin >> hoursWorked;
        float totalPay = hoursWorked * emp[i].hourlyWage;
        cout << "Total pay for employee with ID " << emp[i].id << " for the month: $" << totalPay << endl;
    }

    inFile.close();
}

void updateEmployeeData() {
    ifstream inFile("employee_records.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Employee emp[10];
    for (int i = 0; i < 2; ++i) {
        inFile >> emp[i].id >> emp[i].sex >> emp[i].hourlyWage >> emp[i].yearsWithCompany;
    }

    inFile.close();

    int idToUpdate;
    cout << "Enter the ID of the employee whose data you want to update: ";
    cin >> idToUpdate;

    for (int i = 0; i < 2; ++i) {
        if (emp[i].id == idToUpdate) {
            cout << "Enter new hourly wage: ";
            cin >> emp[i].hourlyWage;
            cout << "Enter new years with the company: ";
            cin >> emp[i].yearsWithCompany;
        }
    }

    writeToFile(emp);
}

int main() {
    Employee employees[10];

    cout << "Enter information for 10 employees:" << endl;
    EmployeesData(employees);

    sort(employees, employees + 2, compareById);
    writeToFile(employees);

    readAndCalculatePay(employees);

    updateEmployeeData();

    return 0;
}
