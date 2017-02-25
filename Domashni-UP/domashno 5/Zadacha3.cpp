#include <iostream>

using namespace std;

void EveryZero(bool** table, int n)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            table[i][j] = false;
}

bool HasPathRec(bool** table, int move_x[], int move_y[], int n, int x, int y, int k) // k=1
{
    if (x>=n||x<0||y>=n||y<0)
        return false;

    if (table[x][y])
        return false;

    if (k == n*n)
        return true;

    table[x][y] = true;

    bool haspath = false;

    for (int i=0;!haspath&&i<8;i++)
    {
        haspath = HasPathRec(table, move_x, move_y, n, x + move_x[i], y + move_y[i], k+1);
    }

    if (!haspath)
        table[x][y] = false;

    return haspath;
}

bool HasPath(int n, int x, int y)
{
    bool** table = new(nothrow) bool*[n];
    if (!table)
        return false;

    for (int i=0;i<n;i++)
    {
        table[i] = new(nothrow) bool[n];
        if (!table[i])
            return false;
    }

    EveryZero(table, n);

    int move_x[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int move_y[] = {2, 1, -1, -2, -2, -1, 1, 2};

    bool temp = HasPathRec(table, move_x, move_y, n, x, y, 1);

    for (int i=0;i<n;i++)
        delete[] table[i];
    delete[] table;

    return temp;
}

int main()
{
    int x, y;
    int n;
    while(true)
    {
        cout<<"N= ";
        cin>>n;
        cout<<"(x,y): ";
        cin>>x>>y;
        if (HasPath(n, x, y))
            cout<<"It has path!"<<endl;
        else
            cout<<"It doesn't have path!"<<endl;
    }
    return 0;
}


