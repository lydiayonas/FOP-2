#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct employee{
 string name;
 int ID;
 string sex;
 double salary;
};

void getInfo(employee &emp){
    ofstream infile("employee.txt", ios::app);

    cout<<"enter the name: ";
    cin.ignore();
    getline(cin,emp.name);
    cout<<"enter ID.NO: ";
    cin>>emp.ID;
    cout<<"enter sex: ";
    cin>>emp.sex;
    cout<<"enter salary: ";
    cin>>emp.salary;

    infile<<emp.name<<" "<<emp.ID<<" "<<emp.sex<<" "<<emp.salary<<endl;
    infile.close();
}
void readfile(){
    ifstream outfile("employee.txt");

    employee emp;
    while(outfile>>emp.name>>emp.ID>>emp.sex>>emp.salary){
       cout << "Name: " << emp.name << ", ID: " << emp.ID << ", Sex: " << emp.sex << ", Salary: " << emp.salary << endl;
    }
   outfile.close();
};
int main(){
    int n;
    cout<<"enter the number of employee: ";
    cin>>n;

    vector<employee> employees(n);

    for(int i=0;i<n;i++){
        getInfo(employees[i]);

    }
    readfile();

    return 0;
}