#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct date{
    int day,month, year;
};

struct studentInfo
{
    string name;
    double GPA;
    int ID;
   date DOB;
};

void getInfo(studentInfo& stud){
    ofstream file("student.txt",ios::app);
    cout<<"enter name of the student: ";
    cin.ignore();
    getline(cin,stud.name);
    cout<<"enter GPA: ";
    cin>>stud.GPA;
    cout<<"enter ID: ";
    cin>>stud.ID;
    cout<<"enter date of birth in DD/MM/YYYY format: ";
    cin>>stud.DOB.day>>stud.DOB.month>>stud.DOB.year;
    
    file<<stud.name<<" "<<stud.GPA<<" "<<stud.ID<<" " <<stud.DOB.day<<" "<<stud.DOB.month<<" "<<stud.DOB.year<<endl;

file.close();

}

void searchstudent(int searchID){

ifstream file("student.txt");

studentInfo stud;
    bool isFound=false;

     while (file >> stud.name >> stud.GPA >> stud.ID >> stud.DOB.day >> stud.DOB.month >> stud.DOB.year) { 

    if(searchID == stud.ID){
       isFound = true;
        cout<<"student found!"<<endl;
        cout<<stud.name<<" "<<stud.GPA<<" "<<stud.ID<<" " <<stud.DOB.day<<" "<<stud.DOB.month<<" "<<stud.DOB.year<<endl;
        
        break;

    }
     }
    if(!isFound){
cout<<"student not found!"<<endl;

    }
file.close();
}

void deleteInfo(){
    studentInfo stud;

}

/* 
to delete a file 
1. create new file
2. copy each old file to new file
3. if you got the data that you want to delete it, skip and not write in a new file
4. delete the entire old file
5. rename the old file to the old file name

*/

int main(){
    
    int n,choice,x;
    do{
    cout << "Menu: \n"<< "1. add student: \n" <<"2. search by ID: \n"<<"3. delete student INFO: \n"<<"Enter your choice(enter 4 to exit): \n";
    cin>>choice;

    switch(choice){

    case 1: 
    cout<<"enter the number of students";
    cin>>n;

    for(int i=0;i<n;i++){
        studentInfo stud;
            getInfo(stud);
        }
        break;

    case 2: 
        int searchID;
        cout<<"enter the ID of the student to search: ";
        cin>>searchID;

        searchstudent(searchID);
        break;

    case 3:
    studentInfo stud;
        cout<<"enter ID of the student you want to delete: ";
        cin>>stud.ID;
        cout<<"student deleted!\n";
        deleteInfo(stud);
        break;
    case 4:
    cout<<"exiting the program,Thank you!";
        break;

        default :
        cout<<"invalid input";
        }
    }while(choice !=4);
        
     return 0;
    }