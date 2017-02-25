/*
Ot: Nikolay Denev
nomer: 45231
Zadacha 3
*/

#include <iostream>
#include <cmath>

using namespace std;

void PrintOctets(unsigned x);                 
void PrintPrefix(unsigned x, unsigned y);

int main()
{
	/*
	x i y sa celite chisla, koito trqbva da se vuvedat
	*/
	unsigned x;
	cout << "x= ";
	cin >> x;

	unsigned y;
	cout << "y= ";
	cin >> y;

	cout << "Octets: ";
	PrintOctets(x);
	PrintOctets(y);
	cout << endl;

	PrintPrefix(x, y);

	return 0;
}

void PrintOctets(unsigned x)
{
	int octet_1 = 0, octet_2 = 0, octet_3 = 0, octet_4 = 0;

	for (int i = 31; i >= 0; i--)
	{
		if (x&(1 << i))
		{
			if (i <= 31 && i >= 24)
				octet_1 += 1 << (i - 24);
			else if (i <= 23 && i >= 16)
				octet_2 += 1 << (i - 16);
			else if (i <= 15 && i >= 8)
				octet_3 += 1 << (i - 8);
			else
				octet_4 += 1 << i;
		}
	}

	cout << octet_1 << "." << octet_2 << "." << octet_3 << "." << octet_4 << "; ";
	return;
}

void PrintPrefix(unsigned x, unsigned y)
{
	//Izvejda Prefix length.
	int length = 0;
	for (int i = 31; i >= 0; i--)
	{
		if ((x & 1 << i) == (y & 1 << i))
		{
			length += 1;
		}
		else
		{
			break;
		}
	}
	cout << "Prefix length: " << length << ";"<< endl;



	unsigned prefix = 0;
	for (int k = 31; k > 31 - length; k--)
	{
		prefix += (int)pow(2, k);
	}



	//Izvejda Prefix binary.
	cout << "Prefix binary: ";
	for (int m = 31; m >= 0; m--)
	{
		cout << ((prefix & 1 << m) ? 1 : 0);
	}
	cout << endl;



	//Izvejda Prefix octets.
	cout << "Prefix octets: ";
	PrintOctets(prefix);
	cout << endl;
	return;
}