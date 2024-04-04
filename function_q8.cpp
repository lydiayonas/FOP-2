/*
#include <iostream>
using namespace std;
int main()
{
int num,second=1;
cout<<"enter an intger: "<<endl;
cin>>num;

for(int i=num;i>1;--i){

    second =num*(i-1);
    num=second;

}

cout<<"the factorial is: "<<second;

return 0;
}
*/
#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;  
    for (int i = 1; i <= n; ++i) {
        result *= i;  
    }
    return result;
}

int main() {
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    int fact = factorial(num);

    cout << "The factorial of " << num << " is: " << fact << endl;

    return 0;
}
