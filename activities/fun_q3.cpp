#include <iostream>
using namespace std;
bool iseven(int n){
    if(n%2==0){
        return true;
    }else{
        return false;
    }
}
int main()
{

int a;
cout<<"enter the number: "<<endl;
cin>>a;

int result =iseven(a);

if(true){
    cout<<"the number is even"<<endl;
}else{

    cout<<"the numer is odd"<<endl;
}




return 0;
}