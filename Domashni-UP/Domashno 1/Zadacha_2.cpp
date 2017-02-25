/*
Zadacha 2
Ot:Nikolay Denev
Programa, koqto chete ot konzolata karta i boq i izvejda na ekrana predhodnata i sledvashtata karta

*/

#include <iostream>

using namespace std;

int main()
{
    char type, slash, color;
    cout<<"Enter the card:";
    cin>>type>>slash>>color;
    int x=type;                                   //promenlivata x prisvoqva ASCII kodut na promenlivata type
    switch (color)
    {
        case 'D':
            cout<<"Previous "<<type<<"/C. Next "<<type<<"/H."<<endl;
        break;
        case 'H':
            cout<<"Previous "<<type<<"/D. Next "<<type<<"/S."<<endl;
        break;
        case 'S':
            if((x>=50)&&(x<=56))                  //Tozi operator proverqva dali vida na kartata e ot 2 do 8
            {                                     //50 e ASCII kodut na '2', a 56 na '8'
                cout<<"Previous "<<type<<"/H. Next "<<(char)(x+1)<<"/C."<<endl;
            }
            else                                  //Tozi operator if moje da se zameni s podoben na sledvashtiqt switch
            {
             switch (type)
               {
                case '9':
                    cout<<"Previous "<<type<<"/H. Next "<<"X/C."<<endl;
                    break;
                case 'X':
                    cout<<"Previous "<<type<<"/H. Next "<<"J/C."<<endl;
                    break;
                case 'J':
                    cout<<"Previous "<<type<<"/H. Next "<<"Q/C."<<endl;
                    break;
                case 'Q':
                    cout<<"Previous "<<type<<"/H. Next "<<"K/C."<<endl;
                    break;
                case 'K':
                    cout<<"Previous "<<type<<"/H. Next "<<"A/C."<<endl;
                    break;
                case 'A':
                    cout<<"Previous "<<type<<"/H. Next "<<"2/C."<<endl;
                    break;
                }
            }
            break;

        case 'C':
            if((x>=51)&&(x<=57))                      //51 e ASCII kodut na '3', a 57 na '9'
            {
                cout<<"Previous "<<(char)(x-1)<<"/S. Next "<<type<<"/D."<<endl;
            }
            else
            {
                switch (type)
                {
                case 'X':
                    cout<<"Previous 9/S. Next "<<type<<"/D."<<endl;
                    break;
                case 'J':
                    cout<<"Previous X/S. Next "<<type<<"/D."<<endl;
                    break;
                case 'Q':
                    cout<<"Previous J/S. Next "<<type<<"/D."<<endl;
                    break;
                case 'K':
                    cout<<"Previous Q/S. Next "<<type<<"/D."<<endl;
                    break;
                case 'A':
                    cout<<"Previous K/S. Next "<<type<<"/D."<<endl;
                    break;
                case '2':
                    cout<<"Previous A/S. Next "<<type<<"/D."<<endl;
                    break;
                }
            }
            break;
          default:
            cout<<"Wrong data!"<<endl;

    }
    return 0;
}
