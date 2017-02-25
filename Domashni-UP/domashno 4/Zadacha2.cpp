#include <iostream>
#include <cstring>

using namespace std;

char* stringReplace(const char * str, const char * what, const char * with);
int HowManyTimes(const char * str, const char * what);

int main()
{
    const char* str = "Ne moga da gi razbera tezi nizove!";
    const char* what = " ";
    const char* with = "          ";

    char* s = stringReplace(str, what, with);

    if (s)
        cout<<s<<endl;
    else
        cout<<"Not enough memory!"<<endl;

    delete[] s;

    return 0;
}

int HowManyTimes(const char * str, const char * what)
{
    int cnt = 0;
    int whatl = strlen(what);
    while (*str)
    {
        int i = 0;
        for (;i<whatl;i++)
        {
            if (what[i] != str[i])
                break;
        }
        if (i == whatl)
        {
            cnt++;
            str+= whatl;
        }
        else
            str++;
    }
    return cnt;
}

char* stringReplace(const char * str, const char * what, const char * with)
{
    int strl= strlen(str);
    int whatl= strlen(what);
    int withl= strlen(with);
    int difference = whatl - withl;

    int times =  HowManyTimes(str, what);

    char* s = new(nothrow) char[strl - difference*times + 1];
    if (!s)
        return NULL;

    char* p = s;

    while (*str)
    {
        int i = 0;
        for (;i<whatl;i++)
        {
            if (what[i] != str[i])
                break;
        }
        if (i==whatl)
        {
            str += whatl;
            for (int j = 0;j<withl;j++)
            {
                p[j] = with[j];
            }
            p+=withl;
        }
        else
        {
            *p = *str;
            str++;
            p++;
        }
    }
    *p = *str;

    return s;
}

