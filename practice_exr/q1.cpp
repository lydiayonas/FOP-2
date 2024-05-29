#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
template <typename T>

bool containsDuplicates(const vector<T>& vec){
    unordered_set<T> seen;
   
     for(const T& element : vec){
      if(seen.count(element)){
        return true;
        }
        seen.insert(element);
     }
     return false;
}
int main()
{

   vector< int> vec1={1,1,2,3};
   if(containsDuplicates(vec1)) {
    cout<<"the vector contains duplicates";

   }else{

    cout<<"the vector doesn't contain duplicate";
   }
return 0;
}