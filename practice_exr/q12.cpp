#include <iostream>
using namespace std;

template <class T, class U >
class check{
    T x;
    U y;
    pubic:
    check(){
        cout<<"A constructor has been called" <<endl;
    }
    void swapp(T x, T y){
        T v= x;
        x=y;
        y=v;
    }
};
int main()
{
    check<char,char>a;
    check<int,double>b;

return 0;
}