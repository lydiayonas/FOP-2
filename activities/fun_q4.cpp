#include <iostream>
using namespace std;
void printRectangle( int width , int height ) {
               
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
cout<<"*";
    }
    cout<<"\n";
}

}
int main()
{

int w,h;
 cout<<"enter width and height: "<<endl;
 cin>>w>>h;

 printRectangle(w,h);




return 0;
}
