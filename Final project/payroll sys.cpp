#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <limits> // for numeric_limits
#include <vector>

using namespace std;

const string PASSWORD = "123"; // Set your password here

// Define a structure to represent an Employeea
struct Employee {
    int payCode;      // Pay code for the type of employee (1 for manager, 2 for hourly, 3 for commission, 4 for pieceworker)
    string name;      // Employee name
    double salary;    // Weekly salary of the employee
};

// Function prototypes
void addEmployee(vector<Employee>& employees, double& managerTotal, double& hourlyTotal, double& commissionTotal, double& pieceworkerTotal);
void findEmployee(const vector<Employee>& employees);
void summaryReport(const vector<Employee>& employees, double managerTotal, double hourlyTotal, double commissionTotal, double pieceworkerTotal);
void displayEmployees(const vector<Employee>& employees);
void readDataFromFile(vector<Employee>& employees, double& managerTotal, double& hourlyTotal, double& commissionTotal, double& pieceworkerTotal);
void addEmployeeToFile(const Employee& employee);
void updateEmployee(vector<Employee>& employees);
void deleteEmployee(vector<Employee>& employees);
bool authenticate();

int main() {
    vector<Employee> employees;  // Vector to store employees
    double managerTotal = 0, hourlyTotal = 0, commissionTotal = 0, pieceworkerTotal = 0;

    readDataFromFile(employees, managerTotal, hourlyTotal, commissionTotal, pieceworkerTotal);

    char choice; // User's menu choice
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Find Specific Record\n";
        cout << "3. Summary Report\n";
        cout << "4. Update Employee Record\n";
        cout << "5. Delete Employee Record\n";
        cout << "6. Show Weekly Salary and Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addEmployee(employees, managerTotal, hourlyTotal, commissionTotal, pieceworkerTotal);
                break;
            case '2':
                findEmployee(employees);
                break;
            case '3':
                if (authenticate()) {
                    summaryReport(employees, managerTotal, hourlyTotal, commissionTotal, pieceworkerTotal);
                } else {
                    cout << "Invalid password. Access denied.\n";
                }
                break;
            case '4':
                if (authenticate()) {
                    updateEmployee(employees);
                } else {
                    cout << "Invalid password. Access denied.\n";
                }
                break;
            case '5':
                if (authenticate()) {
                    deleteEmployee(employees);
                } else {
                    cout << "Invalid password. Access denied.\n";
                }
                break;
            case '6':
                displayEmployees(employees);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != '6');

    return 0;
}

bool authenticate() {
    string password;
    cout << "Enter password: ";
    cin >> password;
    return password == PASSWORD;
}

void readDataFromFile(vector<Employee>& employees, double& managerTotal, double& hourlyTotal, double& commissionTotal, double& pieceworkerTotal) {
    ifstream inputFile("update.txt"); // Open file for reading
    if (inputFile.is_open()) {
        // Read employee data from file
        Employee newEmployee;
        while (inputFile >> newEmployee.payCode) {
            inputFile.ignore();
            getline(inputFile, newEmployee.name, ',');
            inputFile >> newEmployee.salary;

            // Add employee to vector
            employees.push_back(newEmployee);

            // Update totals based on pay code
            switch (newEmployee.payCode) {
                case 1:
                    managerTotal += newEmployee.salary;
                    break;
                case 2:
                    hourlyTotal += newEmployee.salary;
                    break;
                case 3:
                    commissionTotal += newEmployee.salary;
                    break;
                case 4:
                    pieceworkerTotal += newEmployee.salary;
                    break;
                default:
                    break;
            }
        }
        inputFile.close(); // Close the file
    } else {
        cout << "Error: Unable to open file for reading.\n";
    }
}

void addEmployeeToFile(const Employee& employee) {
    ofstream outputFile("update.txt", ios::app); // Open file in append mode
    if (outputFile.is_open()) {
        outputFile << employee.payCode << "," << employee.name << "," << fixed << setprecision(2) << employee.salary << endl;
        outputFile.close();
        cout << "Employee added successfully.\n";
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}

void addEmployee(vector<Employee>& employees, double& managerTotal, double& hourlyTotal, double& commissionTotal, double& pieceworkerTotal) {
    char ch;
    do {
        Employee newEmployee;
        cout << "\nEnter employee data (enter '0' for pay code to quit):\n";
        cout << "Enter pay code (1 for manager, 2 for hourly, 3 for commission, 4 for pieceworker): ";
        cin >> newEmployee.payCode;

        if (newEmployee.payCode == 0) {
            break;
        }

        // Consume newline
        cin.ignore();

        cout << "Enter employee name: ";
        getline(cin, newEmployee.name);

        // Update salary based on pay code
        switch (newEmployee.payCode) {
            case 1: // Manager
                cout << "Enter weekly salary: ";
                cin >> newEmployee.salary;
                managerTotal += newEmployee.salary;
                break;
            case 2: // Hourly worker
                double hourlyRate, hoursWorked;
                cout << "Enter hourly rate: ";
                cin >> hourlyRate;
                cout << "Enter hours worked: ";
                cin >> hoursWorked;
                newEmployee.salary = hoursWorked <= 40 ? hourlyRate * hoursWorked : 40 * hourlyRate + (hoursWorked - 40) * hourlyRate * 1.5;
                hourlyTotal += newEmployee.salary;
                break;
            case 3: // Commission worker
                double grossSales;
                cout << "Enter gross weekly sales: ";
                cin >> grossSales;
                newEmployee.salary = 250 + grossSales * 0.057;
                commissionTotal += newEmployee.salary;
                break;
            case 4: // Pieceworker
                double wagePerItem, itemsProduced;
                cout << "Enter wage per item: ";
                cin >> wagePerItem;
                cout << "Enter number of items produced: ";
                cin >> itemsProduced;
                newEmployee.salary = wagePerItem * itemsProduced;
                pieceworkerTotal += newEmployee.salary;
                break;
            default:
                cout << "Invalid pay code.\n";
                break; // Skip to the next employee
        }

        // Add employee to vector
        employees.push_back(newEmployee);
        addEmployeeToFile(newEmployee);

        cout << "Do you want to add another employee? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void findEmployee(const vector<Employee>& employees) {
    string searchName;
    cout << "Enter the name to search for: ";
    // Consume newline
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (const auto& employee : employees) {
        if (employee.name == searchName) {
            cout << "Employee found:\n";
            cout << "Name: " << employee.name << ", Pay Code: " << employee.payCode << ", Salary: " << fixed << setprecision(2) << employee.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found.\n";
    }
}

void summaryReport(const vector<Employee>& employees, double managerTotal, double hourlyTotal, double commissionTotal, double pieceworkerTotal) {
    cout << "\nSummary Report:\n";
    cout << setw(25) << left << "Pay Code" << setw(15) << "Count" << setw(15) << "Total" << setw(15) << "Max" << setw(15) << "Min" << endl;

    double managerMax = numeric_limits<double>::min(), hourlyMax = numeric_limits<double>::min(), commissionMax = numeric_limits<double>::min(), pieceworkerMax = numeric_limits<double>::min();
    double managerMin = numeric_limits<double>::max(), hourlyMin = numeric_limits<double>::max(), commissionMin = numeric_limits<double>::max(), pieceworkerMin = numeric_limits<double>::max();
    int managerCount = 0, hourlyCount = 0, commissionCount = 0, pieceworkerCount = 0;

    for (const auto& employee : employees) {
        switch (employee.payCode) {
            case 1:
                managerCount++;
                managerMax = max(managerMax, employee.salary);
                managerMin = min(managerMin, employee.salary);
                break;
            case 2:
                hourlyCount++;
                hourlyMax = max(hourlyMax, employee.salary);
                hourlyMin = min(hourlyMin, employee.salary);
                break;
            case 3:
                commissionCount++;
                commissionMax = max(commissionMax, employee.salary);
                commissionMin = min(commissionMin, employee.salary);
                break;
            case 4:
                pieceworkerCount++;
                pieceworkerMax = max(pieceworkerMax, employee.salary);
                pieceworkerMin = min(pieceworkerMin, employee.salary);
                break;
            default:
                break;
        }
    }

    cout << setw(25) << left << "Managers" << setw(15) << managerCount << setw(15) << fixed << setprecision(2) << managerTotal << setw(15);
    if (managerCount > 0) {
        cout << fixed << setprecision(2) << managerMax;
    } else {
        cout << "No data";
    }
    cout << setw(15);
    if (managerCount > 0) {
        cout << fixed << setprecision(2) << managerMin;
    } else {
        cout << "No data";
    }
    cout << endl;

    cout << setw(25) << left << "Hourly Workers" << setw(15) << hourlyCount << setw(15) << fixed << setprecision(2) << hourlyTotal << setw(15);
    if (hourlyCount > 0) {
        cout << fixed << setprecision(2) << hourlyMax;
    } else {
        cout << "No data";
    }
    cout << setw(15);
    if (hourlyCount > 0) {
        cout << fixed << setprecision(2) << hourlyMin;
    } else {
        cout << "No data";
    }
    cout << endl;

    cout << setw(25) << left << "Commission Workers" << setw(15) << commissionCount << setw(15) << fixed << setprecision(2) << commissionTotal << setw(15);
    if (commissionCount > 0) {
        cout << fixed << setprecision(2) << commissionMax;
    } else {
        cout << "No data";
    }
    cout << setw(15);
    if (commissionCount > 0) {
        cout << fixed << setprecision(2) << commissionMin;
    } else {
        cout << "No data";
    }
    cout << endl;

    cout << setw(25) << left << "Pieceworkers" << setw(15) << pieceworkerCount << setw(15) << fixed << setprecision(2) << pieceworkerTotal << setw(15);
    if (pieceworkerCount > 0) {
        cout << fixed << setprecision(2) << pieceworkerMax;
    } else {
        cout << "No data";
    }
    cout << setw(15);
    if (pieceworkerCount > 0) {
        cout << fixed << setprecision(2) << pieceworkerMin;
    } else {
        cout << "No data";
    }
    cout << endl;
}

void displayEmployees(const vector<Employee>& employees) {
    cout << setw(15) << "Name" << setw(15) << "Pay Code" << setw(15) << "Weekly Salary" << endl;
    cout << setw(15) << "_________" << setw(15) << "___________" << setw(15) << "____________" << endl;
    for (const auto& employee : employees) {
        cout << setw(15) << employee.name << setw(15) << employee.payCode << setw(15) << fixed << setprecision(2) << employee.salary << endl;
    }
}

void updateEmployee(vector<Employee>& employees) {
    string searchName;
    cout << "Enter the name of the employee to update: ";
    cin.ignore();
    getline(cin, searchName);
    bool found = false;
    for (auto& employee : employees) {
        if (employee.name == searchName) {
            cout << "Enter new details for the employee:\n";
            cout << "Enter pay code (1 for manager, 2 for hourly, 3 for commission, 4 for pieceworker): ";
            cin >> employee.payCode;
            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, employee.name);
            switch (employee.payCode) {
                case 1: // Manager
                    cout << "Enter weekly salary: ";
                    cin >> employee.salary;
                    break;
                case 2: // Hourly worker
                    double hourlyRate, hoursWorked;
                    cout << "Enter hourly rate: ";
                    cin >> hourlyRate;
                    cout << "Enter hours worked: ";
                    cin >> hoursWorked;
                    employee.salary = hoursWorked <= 40 ? hourlyRate * hoursWorked : 40 * hourlyRate + (hoursWorked - 40) * hourlyRate * 1.5;
                    break;
                case 3: // Commission worker
                    double grossSales;
                    cout << "Enter gross weekly sales: ";
                    cin >> grossSales;
                    employee.salary = 250 + grossSales * 0.057;
                    break;
                case 4: // Pieceworker
                    double wagePerItem, itemsProduced;
                    cout << "Enter wage per item: ";
                    cin >> wagePerItem;
                    cout << "Enter number of items produced: ";
                    cin >> itemsProduced;
                    employee.salary = wagePerItem * itemsProduced;
                    break;
                default:
                    cout << "Invalid pay code.\n";
                    break;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee not found.\n";
    } else {
        // Update file
        ofstream outputFile("update.txt");
        if (outputFile.is_open()) {
            for (const auto& emp : employees) {
                outputFile << emp.payCode << "," << emp.name << "," << fixed << setprecision(2) << emp.salary << endl;
            }
            outputFile.close();
        } else {
            cout << "Error: Unable to open file for writing.\n";
        }
    }
}

void deleteEmployee(vector<Employee>& employees) {
    string searchName;
    cout << "Enter the name of the employee to delete: ";
    cin.ignore();
    getline(cin, searchName);
    auto it = remove_if(employees.begin(), employees.end(), [&](const Employee& employee) { return employee.name == searchName; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Employee deleted successfully.\n";
    } else {
        cout << "Employee not found.\n";
    }

    // Update file
    ofstream outputFile("update.txt");
    if (outputFile.is_open()) {
        for (const auto& emp : employees) {
            outputFile << emp.payCode << "," << emp.name << "," << fixed << setprecision(2) << emp.salary << endl;
        }
        outputFile.close();
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}
