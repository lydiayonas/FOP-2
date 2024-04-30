#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream inputFile("Sheet5Ex5.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open the file." << endl;
        return 1;
    }
    
    char ch;
    int count[26] = {0};
    
    while (inputFile.get(ch)) {
        if (islower(ch)) {
            count[ch - 'a']++;
        }
    }
    
    inputFile.close();
    
    cout << setw(20) << left << "CHARACTER" << setw(15) << "OCCURRENCES" << endl;
    
    for (int i = 0; i < 26; i++) {
        char lowercase='a'+i;
           cout<<setw(20)<<lowercase<<" "<<setw(15)<<count[i]<<endl;
        }
    return 0;
}
