#include <iostream>

using namespace std;

void SolutionsRec(double a, double b, double eps, double (*f)(double))
{
    if (b-a>eps)
    {
        SolutionsRec(a, (a+b)/2, eps, f);
        SolutionsRec((a+b)/2, b, eps, f);
    }
    if (b-a<eps&&f(a)*f(b)<0)
        cout<<"x= "<<(a+b)/2<<" is a root."<<endl;
}

double f(double x)
{
    return x*x*x*x -5*x*x +6;
}
/*
int main()
{
    SolutionsRec(-10.0, 10.0, 1e-6, f);
    return 0;
}
*/


