#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;


int main()
{
 
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {3, 4, 5, 6, 7};

   
    set<int> set1(vec1.begin(), vec1.end());
    set<int> set2(vec2.begin(), vec2.end());

    
    vector<int> commonElements;

    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(commonElements));


    
    cout << "Common elements: ";
    for (int element : commonElements) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}


    