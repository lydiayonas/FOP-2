#include <iostream>
#include <fstream>
using namespace std;
struct employee{
    int number;
    string name;
    int rate;
    int hrs;
    double grossPay;
    double netPay;
};

template <typename T>

void getData(T emp,int n ){

    for (int i = 0; i < n; i++)
    {
     
    cout<<"enter name: ";
    cin.ignore();
     getline(cin, emp[i].name);
    cout<<"enter the number: ";
    cin>>emp[i].number;
    cout<<"enter the rate and worked hours: ";
    cin>>emp[i].rate>>emp[i].hrs;
   

    emp[i].grosspay = emp[i].rate*emp[i].hours*80;
    double tax=emp[i].grosspay*0.15;
    double pension =emp[i].grosspay*0.07;
    emp[i].netpay = emp[i].grosspay*emp[i]-tax-pension;
     }

}

template <typename T>

void payrollreport(T  emp,int n){
    ofstream report("payroll_report.txt");

    report<<"payroll report"<<endl;
    report<<"___________________"<<endl;
    report<<"number\tname\t\tGross\tnet pay"<<endl;

    for (int i = 0; i < n; i++)
    {
      report << employees[i].number << "\t" << employees[i].name << "\t\t"
               << employees[i].grossPay << "\t" << employees[i].netPay << endl;
    }

    report.close();
}
   
    
int main()
{

const int n=6;
employee emp[n];
getData(emp,n);
payrollreport(emp,n);



return 0;
}