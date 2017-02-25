/*
Ot: Nikolay Denev
nomer: 45231
Zadacha 2
*/


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;

	do
	{
		cout << "N= ";
		cin >> n;
	} while (n < 1);
	
	/*
	Razglejdame stoinosta na kvadratchetata kato 2 na nqkakva stepen.
	Kato sbora ot stoinostite na kvadtatchetata predi i-toto e 2^(i-1) - 1.
	*/
	for (int i = 0; i <= n*n; i++)
		cout << pow(2, i) - 1 << "; ";

	cout << endl;

	return 0;
}