#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void ReadMatrix(char** table, int N, int M);
bool HorizontalSearch(char** table, const char* str, int i, int j);
bool VerticallySearch(char** table, const char* str, int i, int j);
bool SearchOnDiagonal(char** table, int N, int M, const char* str);
bool UnderDiagonalSearch(char** table, int N, int M, const char* str);
bool AboveDiagonalSearch(char** table, int N, int M, const char* str);
void PrintResult(char** table, int N, int M, const char* str, const int ALLOWABLE_SIZE);

int main()
{
    const int MAX_SIZE_WORD = 100;

    int N, M;
    cin>>N>>M;
    while (N<=3||N>=100||M<=3||M>=100)
    {
        cout<<"Wrong data!"<<endl;
        cout<<"Try again!"<<endl;
        cin>>N>>M;
    }

    const int ALLOWABLE_SIZE = max(N, M);

    int K;
    cin>>K;

    char ** table;

    table = new(nothrow) char*[N];
    if (!table)
    {
        cout<<"Error!"<<endl;
        return 1;
    }

    for (int i = 0;i<N;i++)
    {
        table[i] = new(nothrow) char[M];
        if (!table[i])
        {
            cout<<"Error!"<<endl;
            return 1;
        }
    }
    ReadMatrix(table, N, M);

    char ** words;

    words = new(nothrow) char*[K];
    if (!words)
    {
        cout<<"Error!"<<endl;
        return 1;
    }

    for (int i = 0;i<K;i++)
    {
        words[i] = new(nothrow) char[MAX_SIZE_WORD];
        if (!words[i])
        {
            cout<<"Error!"<<endl;
            return 1;
        }
    }

    for (int i=0;i<K;i++)
    {
        cin.sync();
        cin>>words[i];

        PrintResult(table, N, M, words[i], ALLOWABLE_SIZE);
    }


    for (int r = 0;r<K;r++)
    {
        delete[] words[r];
    }
    delete[] words;

    for (int r = 0;r<N;r++)
    {
        delete[] table[r];
    }
    delete[] table;

    return 0;
}

void ReadMatrix(char** table, int N, int M)
{
    for (int i = 0;i<N;i++)
    {
        for (int j=0;j<M;j++)
            cin>>table[i][j];
    }
}

bool HorizontalSearch(char** table, const char* str, int i, int j)
{
    bool flag1=true, flag2=true;

    int strl = strlen(str);

    for (int k=0;str[k];k++)
    {
        if (str[k] != table[i][j+k])
            flag1=false;
    }

    for (int k=0;k<strl;k++)
    {
        if (str[strl-1-k] != table[i][j+k])
            flag2=false;
    }

    return flag1||flag2;
}

bool VerticallySearch(char** table,const char* str, int i, int j)
{
    bool flag1=true, flag2=true;

    int strl = strlen(str);

    for (int k=0;str[k];k++)
    {
        if (str[k] != table[i+k][j])
            flag1=false;
    }

    for (int k=0;k<strl;k++)
    {
        if (str[strl-1-k] != table[i+k][j])
            flag2=false;
    }

    return flag1||flag2;
}

bool SearchOnDiagonal(char** table, int N, int M,const char* str)
{
    int strl = strlen(str);

    for (int i=0;i<N;i++)
    {
        for (int j=0;j+strl<=M;j++)
        {
            if (i-j>=0&&i-j-strl+1<=0&&HorizontalSearch(table, str, i, j))
                return true;
        }
    }

    for (int j=0;j<M;j++)
    {
        for (int i=0;i+strl<=N;i++)
        {
            if (i-j<=0&&i+strl-1-j>=0&&VerticallySearch(table, str, i, j))
                return true;
        }
    }

    return false;
}

bool UnderDiagonalSearch(char** table, int N, int M, const char* str)
{
    int strl = strlen(str);

    for (int i=strl;i<N;i++)
    {
        for (int j=0;i-j-strl>=0&&j<=M-strl;j++)
        {
            if (HorizontalSearch(table, str, i, j))
                return true;
        }
    }

    for (int j=0;j<M;j++)
    {
        for (int i=j+1;i+strl<=N;i++)
        {
            if (VerticallySearch(table, str, i, j))
                return true;
        }
    }

    return false;
}

bool AboveDiagonalSearch(char** table, int N, int M, const char* str)
{
    int strl = strlen(str);

    for (int i=0;i<N;i++)
    {
        for (int j=i+1;j+strl<=M;j++)
        {
            if (HorizontalSearch(table, str, i, j))
                return true;
        }
    }

    for (int j=strl;j<M;j++)
    {
        for (int i=0;i+strl<=j&&strl+i<=N;i++)
        {
            if (VerticallySearch(table, str, i, j))
                return true;
        }
    }

    return false;
}

void PrintResult(char** table, int N, int M, const char* str, const int ALLOWABLE_SIZE)
{
    if (strlen(str) > ALLOWABLE_SIZE)
        cout<<"NO"<<endl;
    else if (SearchOnDiagonal(table, N, M, str)&&!(UnderDiagonalSearch(table, N, M, str)||AboveDiagonalSearch(table, N, M, str)))
        cout<<"YES"<<endl;
    else if(!SearchOnDiagonal(table, N, M, str)&&UnderDiagonalSearch(table, N, M, str)&&AboveDiagonalSearch(table, N, M, str))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

