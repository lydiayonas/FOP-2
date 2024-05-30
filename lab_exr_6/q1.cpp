#include <iostream>
#include <fstream>
using namespace std;
ofstream studentInfo("test.txt");

void getRecord(){
    string name;
    double rate;
    int hrs;
    cout<<"enter the name the student: ";
    cin.ignore();
    getline(cin,name);
    cout<<"enter the test rate ";
    cin>>rate;
     cout<<"enter the test hours ";
     cin>>hrs;

    studentInfo<<' '<<name<<' '<<rate<<' '<<hrs<<endl;
    
}
int main(){
int n;
    cout<<"enter the number of students to store their information ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
       getRecord();
    }
    studentInfo.close();
    return 0;

}
