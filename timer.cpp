#include<iostream>
#include<cmath>
#include<ctime>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

int countdown(int);
int main()
{
    int i, min, sec, start;
    char choice;
    
    cout<<"Timer.\n";
    do
    {
    cout<<"Enter the countdown time, in minutes.\n";
    cin>>min;
    cout<<"Enter the countdown time, in sec.\n";
    cin>>sec;
    start= (min*60)+sec;
    i=start;
    
    for(i=start; i>0; i--)
    {
    double intpart;
    double fraction=modf(i/60., &intpart);
    system("cls");
    cout<<"Time Remaining:\n";
    cout<<"Minutes: "<<intpart<<endl;
    cout<<"Seconds: "<<fraction*60<<endl;
    //cout<<1*CLOCKS_PER_SEC<<endl;
    countdown(1);
    }
    cout<<"Time's up!\n";
    PlaySound("alarm.wav", NULL, SND_ASYNC);
    cout<<"Another countdown? (y/n)\n";
    cin>>choice;
    if ( !cin.good() )
         {
         cout<<"Data input error!\n"; 
         }
    }
    while (choice=='y');
    
    system("pause");
    return 0;
}

int countdown(int sec)
{
     clock_t count;
     count=clock()+ sec*CLOCKS_PER_SEC;
     while (clock() < count){}
     return count;
}
     
