/*
Ot: Nikolay Denev
nomer: 45231
Zadacha 1
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	
	int n;

	do
	{
		cout << "N= ";
		cin >> n;
	}
	while (n < 1);

	int n1 = n;
	int r = 0;             // r e broqt na cifrite v chisloto n
	while (n1)
	{
		n1 /=10;
		r += 1;
	}


	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (i == 1 || i == n || k==1 || k==n)         //Otpechatva stranite na kvadrata 
				cout <<setw(r)<< k <<setw(r)<< " ";
			else if (k == i || k == n - i+1)              //Otpechatva diagonalite
				cout <<setw(r) << k << setw(r) << " ";
			else                                          //Otpechatva prazni mesta
				cout <<setw(r)<< " "<<setw(r)<<" ";                             
		}
		cout << endl;
		if (r >= 2)
			for (int u = 1; u < r; u++)
				cout << endl;

	}
	
	return 0;
}