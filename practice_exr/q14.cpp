#include <iostream>
#include <fstream>
using namespace std;
struct student{
    string name;
    int ID;
    double GPA;
    int rank;

};

int main()
{
    ofstream infile("student.dat", ios::binary | ios::app);
    student stud;

    stud.name = "alemu";
    stud.ID = 258;
    stud.GPA = 3.88;
    stud.rank = 3;

    infile.write(reinterpret_cast<char*>(&stud),size_of(student));


    infile.close();


    ifstream outfile("student.dat", ios::binary );

    outfile.seekg(-8,ios::end);

     char ch;
    infile.get(ch);
    cout << "Character at the middle of the last line: " << ch << endl;

     Student stud;
    while (infile.read(reinterpret_cast<char*>(&stud), sizeof(Student))) {
        cout << "ID: " << stud.ID << ", Name: " << stud.name << ", CGPA: " << stud.GPA << ", Rank: " << stud.rank << endl;
    }

   
    infile.close();
return 0;
}