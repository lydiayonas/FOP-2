#include <iostream>
using namespace std;

int fibonacci (int n){

    int a=0 , b=1,c;

    if(n==0){
        cout<<"fibonacci upto 0"<<a<<endl;
        return a;
    }else if(n==1 ){
        cout<<"fibonacci upto 1"<<a<<" "<<b<<" "<<endl;
        return b;
    }else{
        cout<<"fibonacci upto "<<n<<":";
        cout<<a<<" "<<b;
        for(int i=2;i<=n;i++){
           c=a+b;
            cout<<" "<<c<<" ";
            a=b;
            b=c;
            
        }
        cout<<endl;

         return b;
    }
}
int main()
{

    int n;

cout<<"enter the fibonacci series upto"<<endl;
cin>>n;

fibonacci(n);

return 0;
}