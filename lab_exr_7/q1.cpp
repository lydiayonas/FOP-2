#include <iostream>
using namespace std;


template <typename T>

void printArray(T arr[], int size){

for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
}

int main()
{

int intArray[]={1,2,3,4,5,6};
 int intSize = sizeof(intArray) / sizeof(intArray[0]);
    cout << "Integer array: ";
    printArray(intArray, intSize);

float floatarray[]={1.1,1.2,1.3,1.4};
float floatsize = sizeof(floatarray )/ sizeof(floatarray[0]);;

cout<<"Float array: ";
printArray(floatarray, floatsize);

char charArray[]={'a','b','c','d'};
 int charSize = sizeof(charArray) / sizeof(charArray[0]);
    cout << "character array: ";
    printArray(charArray, charSize);

return 0;
}