/*

Ot: Nikolay Denev
Nomer: 45231
Zadacha 1

*/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 128;

void PrintMatrix(int Matrix[][MAX_SIZE], int n, int w);

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	while (n < 1 || n > MAX_SIZE)
	{
		cout << "Error! Try again! n = ";
		cin >> n;
	}

	int Matrix[MAX_SIZE][MAX_SIZE];

	int p = 0;       // p raste po diagonalite i se prisvoqva ot elementite na matricata

	for (int i = 0;i <= 2 * n - 2;i++)
	{
		if (i < n)
		{
			for (int k = 0;k <= i;k++)
			{
				Matrix[n - k - 1][i - k] = p++;
			}
		}
		else
		{
			for (int r = 0;r <= 2 * n - 2 - i ;r++)
			{
				Matrix[2 * n - 2 - i - r][n - 1 - r] = p++;
			}
		}
	}

	int n1 = n*n-1;
	int w = 0;           // w e broqt na cifrite na chisloto n
	while (n1)
	{
		n1 /= 10;
		w++;
	}

	PrintMatrix(Matrix, n, w);

}


void PrintMatrix(int Matrix[][MAX_SIZE], int n, int w)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout <<setw(w)<< Matrix[i][j] << " ";

		cout << endl;
	}
}
