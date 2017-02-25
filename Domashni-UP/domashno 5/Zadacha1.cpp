#include <iostream>
#include <iomanip>

using namespace std;

void PrintLastRow(int n)
{
    if (n==1)
        cout<<" 1";
    else
    {
        cout<<setw(2)<<n<<" ";
        PrintLastRow(n-1);
        cout<<" "<<setw(2)<<n;
    }
}

void PrintRow(int n, int row)
{
    if (n==1)
    {
        cout<<"  ";
        return;
    }

    if (row)
    {
        cout<<setw(2)<<n<<" ";
        PrintRow(n-1,row-1);
        cout<<" "<<setw(2)<<n;
    }
    else
    {
        cout<<"   ";
        PrintRow(n-1, row);
        cout<<"   ";
    }
}

void Print(int n, int row=1)
{
    if (n==row)
    {
        PrintLastRow(n);
        cout<<endl;
    }

    else
    {
        PrintRow(n, row);
        cout<<endl;
        Print(n, row+1);
    }
}

int main()
{
    int n;
    do
    {
        cout<<"N= ";
        cin>>n;
    }while(n<=0||n>40);

    Print(n);
    return 0;
}

