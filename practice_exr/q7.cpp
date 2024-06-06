#include <iostream>
using namespace std;
int fibonacci(int n){
    int a=0, b=1;

    cout<<"fibonacci serious upto "<<n<<": "<<a<<" "<<b<<" ";
    for (int i = 2; i < n; i++)
    {
        int c;
        c=a+b;
        cout<<" "<<c<<" "; 
        a=b;
        b=c;
       
    }
    return b;
    
}
int main()
{
    int num;
    cout<<"enter the integer: ";
    cin>>num;

    fibonacci(num);
return 0;
}