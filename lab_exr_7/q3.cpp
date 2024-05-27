#include <iostream>
#include <cmath>
using namespace std;

template< typename T,typename U>

T euclidean(T arr1[], U arr2[] ){

  return sqrt(pow(arr1[1]-arr1[0],2) + pow(arr2[1]-arr2[0],2));
}

int main()
{
    double ponit1[]={2,3};
     int ponit2[]={9,5};

      cout<<"the distance is: "<<euclidean(ponit1,ponit2);
return 0;
}