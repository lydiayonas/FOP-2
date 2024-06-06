/*find factors*/
#include <iostream>
using namespace std;
class integer{
    public: 
    int factors ;

    int findFactor(int num){
        cout<<"the factors of "<<num<< " are: ";

        for(int i=1;i<=num;i++){
           if(num%i==0){
          cout<<i<<" ";
           }
        }
        cout<<endl;

    }
};
int main()
{
    integer n;

    int number;
    cout<<"enter the number: ";
    cin>>number;

   n.findFactor(number);

return 0;
}