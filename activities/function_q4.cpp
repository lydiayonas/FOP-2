#include <iostream>
using namespace std;
void Fibonacci (int n){

int first=0,second=1;

cout<<"The Fibonacci Series up to "<<n<<"terms: "<<endl;
cout<<first<<" "<<second<<" ";

for(int i=0; i<n; ++i){

    int next=first + second;
    cout<<next<<" ";
    first=second;
    second=next;

}
}





void deffibonacci (int n=5){

int first=0,second=1;

cout<<"The Fibonacci Series up to "<<n<<"terms: "<<endl;
cout<<first<<" "<<second<<" ";

for(int i=0; i<3; ++i){

    int next=first + second;
    cout<<next<<" ";
    first=second;
    second=next;

}
}
int main()
{
    int choice;
    char s;
    int n;

    cout << "What would you like? " << endl;
    cout << "1. Print the default Fibonacci series" << endl;
    cout << "2. Create your own " << endl;
    cin >> choice;

    switch (choice) {
    case 1:
       deffibonacci();
        break;
    case 2:

int terms;

cout<<"enter the number of terms: ";
cin>>terms;

Fibonacci(terms-2);
break;

    default:
        cout << "Invalid input" << endl;
        break;
    }


    return 0;
}



