#include <iostream>
#include <vector>
using namespace std;

template<typename T>

T  findLargestElement (vector<T>& vec){

 if(vec.empty()){

     cerr<<"error: empty vector\n";
    return T();
 }

 T largest = vec[0];

 for(const T& element: vec){

    if (element>largest){
        largest=element;
    }

 }
 return largest;
    
}
int main()
{
 vector<int> vec1={1,2,3,6,7};
 cout<<"The largest element is: "<<findLargestElement(vec1)<<endl;

vector<double> doubleVec = {3.5, 2.8, 9.1, 1.2, 7.6};
cout << "Largest element in doubleVector is: " << findLargestElement(doubleVec) <<endl;

return 0;
}