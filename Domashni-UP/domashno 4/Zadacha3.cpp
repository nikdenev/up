#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 200;

void ReverseWords(char* str);
bool IsWordLetter(char a);
void Revers(char* s, int k);

int main()
{
    char* str = new(nothrow) char[MAX_SIZE];

    cin.sync();
    cin.getline(str, MAX_SIZE);

    ReverseWords(str);
    cout<<str<<endl;

    delete[] str;

    return 0;
}

bool IsWordLetter(char a)
{
    return (a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a=='-');
}

void ReverseWords(char* str)
{
    while (*str)
    {
        while (*str&&!IsWordLetter(*str))
            str++;

        if (*str)
        {
            int cnt=0;
            char* s = str;

            while (IsWordLetter(*str))
            {
                str++;
                cnt++;
            }

            Revers(s, cnt);
        }
    }
}

void Revers(char* s, int k)
{
    if (k==1)
        return;

    for (int i=0;i<k/2;i++)
    {
        int t = s[i];
        s[i] = s[k-1-i];
        s[k-1-i] = t;
    }
}

