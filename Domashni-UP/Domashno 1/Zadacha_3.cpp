#include <iostream>
#include <cmath>

using namespace std;

const double precision = 1e-6;

int main()
{
	double golden_ratio = (1.0 + sqrt(5)) / 2.0;    //Poluchava se ot polojitelniq koren na uravnenieto x*x - x -1 = 0
	int divident, divisor;
	cout << "Enter a divident: ";
	cin >> divident;
	cout << "Enter a divisor: ";
	cin >> divisor;
	if (divisor == 0)
	{
		cout << "Wrong data!" << endl;
	}
	else
	{
		double quotient = ((double)divident) / ((double)divisor);      //Prevrushtame promenlivite ot tip int v tip double
		if (fabs(golden_ratio - quotient) < precision)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}
