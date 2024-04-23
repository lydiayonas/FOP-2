#include <iostream>
using namespace std;
double my_max(double a, double b){

    if(a>b){
        return a;
    }else {
        return b;
    }
}
double my_max( double a, double b, double c){

    if(a>b && a>c){

        return a;
    }else if(b>a && b>c){
        return b;
    }else{
        return c;
    }
}
int main()
{
      int a,b,c;

   cout<<"enter 2 numbers";
   cin>>a>>b;
   double largest1= my_max(a,b);

   cout<<"the largest is: "<<largest1<<endl;
  
    cout<<"enter the numbers";
    cin>>a>>b>>c;

     double largest2= my_max(a,b,c);
     cout<<"the largest is: "<<largest2<<endl;

return 0;
}