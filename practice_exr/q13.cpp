#include <iostream>
#include <fstream>
using namespace std;

struct student{
    string name;
    int ID;
    double GPA;
    int rank;

};

void studentInfo(student stud){
    ofstream infile("student.dat",ios::binary | ios::app);

    if(!outfile.is_open){
        cerr<<"unable to open file!";
        return 1;
    }
    
    cout<<"enter name";
    cin.ignore();
    getline(cin,stud.name);
    cout<<"enter ID and GPA";
    cin>>stud.ID>>stud.GPA;
    cout<<"enter rank";
    cin>>stud.rank;

    infile.write(reinterpret_cast<char*>(&stud.ID),sizeof(stud.ID));
    infile.write(reinterpret_cast<char*>(&stud.rank),sizeof(stud.rank));
    infile.write(reinterpret_cast<char*>(&stud.GPA),sizeof(stud.GPA));
    size_t length = stud.name.size();
    infile.write(reinterpret_cast<char*>(&length),sizeof(length));
    infile.write(stud.name.c_str(),length);

    infile.close();

}

void readdata(){

    student stud;
    ifstream outfile("student.dat",ios::binary );
    while(!outfile.eof()){
        

        size_t length;
        outfile.read(reinterpret_cast<char*>(&stud.ID),sizeof(stud.ID));
        outfile.read(reinterpret_cast<char*>(&stud.rank),sizeof(stud.rank));
        outfile.read(reinterpret_cast<char*>(&stud.GPA),sizeof(stud.GPA));
        outfile.read(reinterpret_cast<char*>(&length),sizeof(length));
      

    char*buffer = new char[length+1];
    outfile.read(buffer,length);
    buffer[length]='\0';
    stud.name=string(buffer);
    delete[]buffer;

    cout<<stud.name<<" "<<stud.GPA<<" "<<stud.ID<<" "<<stud.rank<<" "<<endl;

    }

}

int main()
{

    int n;
    cout<<"enter the number of students";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        student stud;
        studentInfo(stud);
    }
     readdata();

return 0;
}