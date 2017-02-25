/*
Ot: Nikolay Denev
Nomer: 45231
Zadacha 2
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 500;

void ReadArray(int arr[], int n);
void MostCommon(int arr[],int arrCheck[], int n);
void PrintArray(int arr[], int n);
int MaxIndex(int arrCheck[], int n);


int main()
{
	int n;
	cout << "n= ";
	cin >> n;

	while (n < 1 || n > MAX_SIZE)
	{
		cout << "Try again! n= ";
		cin >> n;
	}

	int arr[MAX_SIZE];
	ReadArray(arr, n);


	// Masiv v koito zapisvam broq na povtarqniqta na daden element na negovata poziciqta
	int arrCheck[MAX_SIZE] = { 0, };

	MostCommon(arr, arrCheck, n);

	cout << "The Most common number is: " << arr[MaxIndex(arrCheck, n)] << endl;

	return 0;
}


void ReadArray(int arr[], int n)
{
	cout << "Enter numbers in [-5000;5000]" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
		while (abs(arr[i]) > 5000)
		{
			cout << "Try again! arr[" << i << "]= ";
			cin >> arr[i];
		}
	}
}


void MostCommon(int arr[], int arrCheck[], int n)
{
	for (int i = 0;i < n;i++)
	{
		if (arrCheck[i] != -1)
		{
			for (int k = 1;k < n;k++)
			{
				if ((arr[i] == arr[k])&&(i != k))
				{
					arrCheck[i]++;
					arrCheck[k] = -1;
				}
			}
		}
	}
}


int MaxIndex(int arrCheck[], int n)
{
	int Maxindex = 0;

	for (int i = 1;i < n;i++)
	{
		if (arrCheck[i] > arrCheck[Maxindex])
		{
			Maxindex = i;
		}
	}

	return Maxindex;
}
