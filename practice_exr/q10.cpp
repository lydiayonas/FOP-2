#include <iostream>
using namespace std;
template <typename T>

void printarry(T arry[],int n){

    for (int i = 0; i <n; i++)

    {
        cout<<" "<<arry[i]<<" ";

    }
    
}

int main(){
    int intarr[]={2,3,4};
    int intsize=sizeof(intarr)/sizeof(intarr[0]);
    printarry(intarr,intsize);
    cout<<endl;

    float floatarr[]={2.3,4.5,6.3};
    float floatsize=sizeof(floatarr)/sizeof(floatarr[0]);
    printarry(floatarr,floatsize);



   
    return 0;
}
