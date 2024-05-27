#include <vector>
#include <iostream>
using namespace std;
template <typename T>

bool ispalindrome(vector<T> vec){

size_t left =0;
size_t right =vec.size()-1;

while(left<right){

    if(vec[left]!=vec[right]){
        return false;
    }
    left++;
    right--;
}

        return true;
  
}

  int main(){
  
  vector<int> vec1={1,2,3,4};

  if(ispalindrome(vec1)){

    cout<<"the numbers are palindrome"<<endl;
  }else{

  cout<<"the numbers are not palindrome"<<endl;
  }
return 0;
}

