#include<iostream>
#include<fstream>
using namespace std;
ifstream studentRecord("test.txt");
void displayRecord(){
    char s;
    while (studentRecord.get(s))
    {
       cout<<s;
    }
}
int main(){
   cout<<"the data is "<<endl;
   displayRecord();
    
}
