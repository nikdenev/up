/*
Zadacha 1
Ot: Nikolay Denev
Programa, koqto proverqva dali tochka e vav figura
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cout<<"Enter the coordinates of point P(x,y):";
    cin>>x>>y;
    if((x>=0)&&(y>=0)&&(x<=3)&&(y<=3))                    //Proverqva dali tochka e v parvi kvadrant
    {
        cout<<"Inside"<<endl;
    }
    else if ((x<=0)&&(y<=0)&&(x>=-3)&&(y>=-3))
    {
        cout<<"Inside"<<endl;
    }
    else if ((x<0)&&(y>0)&&(sqrt(x*x+y*y)<=3))             //x*x+y*y tazi suma e vinagi polojitelna
    {
        cout<<"Inside"<<endl;
    }
    else if ((x>0)&&(y<0)&&(sqrt(x*x+y*y)<=3))
    {
        cout<<"Inside"<<endl;
    }
    else
    {
        cout<<"Outside"<<endl;
    }
    return 0;
}
