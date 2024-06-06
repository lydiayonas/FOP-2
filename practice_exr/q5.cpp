#include <iostream>
#include<string>
using namespace std;

void count_char(const string& word, char b){
    int count=0;
 
    for(int i=0;i<word.length();i++){
       if(word[i]==b){
        count++;
       }
    }
if(count>0){
    cout<<"the character appears "<<count<<" times!"<<endl;
}else{
    cout<<"this character no found!"<<endl;
}
  

}
 
int main()
{
     string line;
     char a;
    cout<<"enter a word or sentence: ";
    cin.ignore();
    getline(cin,line);
    cout<<"enter the character you want to count: ";
    cin>>a;

    count_char(line,a);

return 0;
}