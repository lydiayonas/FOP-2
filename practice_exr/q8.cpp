#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int number=234;
    string name="Hello";

    ofstream outfile("data.dat",ios::binary);
    if(!outfile){
        cerr<<"unable to open file"<<endl;
        return 1;
    }

    outfile.write(reinterpret_cast<char*>(&number), sizeof(number));

    size_t length=name.size();
    outfile.write(reinterpret_cast<char*>(&length), sizeof(length));
    outfile.write(name.c_str(), length);
    outfile.close();

    int readnumber;
    string readname;

    ifstream infile("data.dat",ios::binary);
     if(!infile){
        cerr<<"unable to open file"<<endl;
        return 1;
    }
    infile.read(reinterpret_cast<char*>(&readnumber), sizeof(readnumber));
    infile.read(reinterpret_cast<char*>(&length), sizeof(length));
    infile.close();

    cout<<readnumber<<readstring;

return 0;
}