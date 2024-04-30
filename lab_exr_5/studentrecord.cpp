#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ofstream studentRecord("test.txt");

void getRecord(){
    int test_mark;
    string name;
    cout<<"enter the name of the student: ";
    cin>>name;
    studentRecord<<name;

    cout<<"enter the test result of the student: ";
    cin>>test_mark;
    studentRecord<<' '<<test_mark<<endl;
    
}


int main(){
    int n;
    cout<<"enter the number of students";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
       getRecord();
    }
    

}