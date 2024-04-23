#include <iostream>
using namespace std;

int tempFinder(){
    int temp1, temp2;

    cout<<"enter daily average temperatures: "<<endl;
    cin >> temp1 >> temp2;

   int daily_av = (temp1+temp2)/2;

   return daily_av;

}
int tempFinder(int length){
int sum=0;
    cout<<"Enter  average temperatures: "<<endl;
    for(int i=0;i<length;i++){
        int temp;
        cin>>temp;
        sum+=temp;
    }
int weekly_av=sum/length;
return weekly_av;

}
int main()
{

int htemp,ltemp,week,month;

cout<<"enter the low & high temperature ";
cin>>htemp>>ltemp;

 int daily_avg = tempFinder();
    cout << "Daily average temperature: " << daily_avg << endl;

cout<<"enter number of days in a week";
cin>>week;
int weekly_avg = tempFinder(week);
    cout << "Weekly average temperature: " << weekly_avg << endl;

cout<<"enter number of days in a month";
cin>>month;
int monthly_avg = tempFinder(month);
    cout << "monthly average temperature: " << monthly_avg << endl;
return 0;
}