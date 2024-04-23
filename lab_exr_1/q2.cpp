#include <iostream>
using namespace std;

void triangle (int n){

 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

}

int main()
{

int choice,n;
char choose;
cout<<"what would you like?\n";
cout<<"1.the default triangle\n";
cout<<"2.make your own\n";
cin>>choice;

switch (choice)
{

case 1: cout<<" The default triangle"<<endl;

triangle(5);

    break;

case 2: 

cout<<"enter the size: "<<endl;
cin>>n;
cout<<"choose symbol"<<endl;
cout<<"a. * \n";
cout<<"b. # \n";
cin>>choose;

switch (choose)
{
case 'a': 

    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    break;

case 'b':

 for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<"#";
        }
        cout<<"\n";
    }
      break;

default:

cout<<"invalid input"<<endl;
    break;

}

  break;

default:

cout<<"invalid input"<<endl;

    break;

}

return 0;
}