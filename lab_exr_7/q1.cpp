#include <iostream>
using namespace std;

template <typename T>

void printArray(T arr[],int n){

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

int intarr[]={2,3,4};
int intsize= sizeof(intarr)/sizeof(intarr[0]);
cout<<"integer array"<<endl;
printArray(intarr,intsize);


float floatarr[]={2.1,3.4,4.4};
float floatsize=sizeof(floatarr)/sizeof(floatarr[0]);
cout<<"the float array"<<endl;
printArray(floatarr, floatsize);

return 0;
}