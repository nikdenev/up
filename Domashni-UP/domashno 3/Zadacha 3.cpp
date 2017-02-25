/*
Ot: Nikolay Denev
Nomer: 45231
Zadacha 3
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 500;
const double eps = 0.00001;


void FloatMultiplyRow(float Row[], int n, float p);
void FloatDivideRow(float Row[], int n, float p);
void FloatSumOfRows(float Row1[], float Row2[], int n);
void FloatSubtractionOfRows(float Row1[], float Row2[], int n);
void FloatSwapRows(float matrix[][MAX_SIZE], int Row1, int Row2, int n);
void FloatGaussMethod(float matrix[][MAX_SIZE], int n);
void FloatPrintResult(float matrix[][MAX_SIZE], int n);
void FloatPrintSolutions(float Solutions[], int n);
void FloatPrintMatrix(float matrix[][MAX_SIZE], int n);
void FloatReadMatrix(float matrix[][MAX_SIZE], int n);


void IntMultiplyRow(int Row[], int n, int p);
void IntDivideRow(int Row[], int n, int p);
void IntSumOfRows(int Row1[], int Row2[], int n);
void IntSubtractionOfRows(int Row1[], int Row2[], int n);
void IntSwapRows(int matrix[][MAX_SIZE], int Row1, int Row2, int n);
void IntGaussMethod(int matrix[][MAX_SIZE], int n);
void IntPrintResult(int matrix[][MAX_SIZE], int n);
void IntPrintMatrix(int matrix[][MAX_SIZE], int n);
void IntReadMatrix(int matrix[][MAX_SIZE], int n);


int main()
{
	cout<<"If the values are represented by integers only press 1!"<<endl
	<<"If the values are represented by decimals (and/or integers) press 0!"<<endl
	<<"Your choice is: ";

    short choice;
    cin>>choice;
	while(choice!=0&&choice!=1)
    {
        cout<<"Error! Try again! Your choice is: ";
        cin>>choice;
    }


    int n;
	cout << "The Matrix is n x n+1 (n in [1 ; 499])."<<endl<<"n = ";
	cin >> n;
	while (n < 1 || n >= 500)
	{
		cout << "Error! Try again! n = ";
		cin >> n;
	}


	switch (choice)
	{
        case 0:
            {
                float matrix[MAX_SIZE-1][MAX_SIZE];

	            FloatReadMatrix(matrix, n);

                cout << endl;

	            FloatGaussMethod(matrix, n);

	            FloatPrintResult(matrix, n);

                cout << endl;

                break;
            }
        case 1:
            {
                int matrix[MAX_SIZE-1][MAX_SIZE];

                IntReadMatrix(matrix, n);

                cout << endl;

                IntGaussMethod(matrix, n);

                IntPrintResult(matrix, n);

                cout << endl;
            }
	}

	return 0;
}


void FloatReadMatrix(float matrix[][MAX_SIZE], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}


void FloatMultiplyRow(float Row[], int n, float p)
{
	if (abs(p) > eps)
	{
		for (int i = 0;i <= n;i++)
		{
			Row[i] *= p;
		}
	}
}


void FloatDivideRow(float Row[], int n, float p)
{
	if (abs(p) > eps)
	{
		for (int i = 0;i <= n;i++)
		{
			Row[i] /= p;
		}
	}
}


void FloatSumRows(float Row1[],float Row2[], int n)
{
	for (int i = 0;i <= n;i++)
	{
		Row1[i] += Row2[i];
	}
}


void FloatSubtractionRows(float Row1[],float Row2[], int n)
{
	for (int i = 0;i <= n;i++)
	{
		Row1[i] -= Row2[i];
	}
}


void FloatSwapRows(float matrix[][MAX_SIZE], int Row1, int Row2, int n)
{
	float Row3[MAX_SIZE] = { 0, };
	for (int i = 0;i <= n;i++)
	{
		Row3[i] = matrix[Row1][i];
		matrix[Row1][i] = matrix[Row2][i];
		matrix[Row2][i] = Row3[i];
	}
}


void FloatGaussMethod(float matrix[][MAX_SIZE], int n)
{
	for (int i = 0;i < n-1;i++)              // Proverka
	{
		if (abs(matrix[i][i]) < eps)
		{
			for (int p = i + 1;p < n;p++)
			{
				if (abs(matrix[p][i]) > eps)
				{
					FloatSwapRows(matrix, p, i, n);
					break;
				}
			}

			if (abs(matrix[i][i]) < eps)
			{
				continue;
			}
		}

		for (int k = i+1;k < n;k++)
		{
			if (abs(matrix[k][i]) > eps)
			{
				float x = matrix[k][i] / matrix[i][i];

				FloatMultiplyRow(matrix[i], n, x);

				FloatSubtractionRows(matrix[k], matrix[i], n);

				FloatDivideRow(matrix[i], n, x);
			}
		}
	}
}


void FloatPrintResult(float matrix[][MAX_SIZE], int n)
{
	float Solutions[MAX_SIZE-1] = { 0, };                      //Masiv ot korenite na matiricata

	for (int i = n-1;i >= 0;i--)
	{
		for (int k = n-1;k > i;k--)
		{
			Solutions[i] -= (Solutions[k]) * (matrix[i][k]);
		}

		Solutions[i] += (matrix[i][n]);

		if (abs(Solutions[i]) > eps)
		{
			if (abs(matrix[i][i]) > eps)
				Solutions[i] /= (matrix[i][i]);
			else
			{
				cout << "The matrix is inconsistent!" << endl;
				return;
			}
		}
		else
		{
			if (abs(matrix[i][i]) < eps)
			{
				cout << "The Matrix is consistent! There are infinitely many sets of solution!" << endl;
				return;
			}
			else
			{
				Solutions[i] = 0;
			}
		}
	}

	FloatPrintSolutions(Solutions, n);
}


void FloatPrintSolutions(float Solutions[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << "x" << i + 1 << " = " << Solutions[i] << endl;
	}
}


//*********************************************************************************


void IntMultiplyRow(int Row[], int n, int p)
{
	if (p != 0)
	{
		for (int i = 0;i <= n;i++)
		{
			Row[i] *= p;
		}
	}
}


void IntDivideRow(int Row[], int n, int p)
{
	if (p != 0)
	{
		for (int i = 0;i <= n;i++)
		{
			Row[i] /= p;
		}
	}
}


void IntSumRows(int Row1[],int Row2[], int n)
{
	for (int i = 0;i <= n;i++)
	{
		Row1[i] += Row2[i];
	}
}


void IntSubtractionRows(int Row1[],int Row2[], int n)
{
	for (int i = 0;i <= n;i++)
	{
		Row1[i] -= Row2[i];
	}
}


void IntSwapRows(int matrix[][MAX_SIZE], int Row1, int Row2, int n)
{
	int Row3[MAX_SIZE] = { 0, };
	for (int i = 0;i < n+1;i++)
	{
		Row3[i] = matrix[Row1][i];
		matrix[Row1][i] = matrix[Row2][i];
		matrix[Row2][i] = Row3[i];
	}
}



void IntGaussMethod(int matrix[][MAX_SIZE], int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int z=i+1;(z < n)&&(matrix[i][i] == 0);z++)
        {
            if (matrix[z][i] != 0)
                IntSwapRows(matrix, z, i, n);
        }

        if (matrix[i][i]==0)
            continue;

        int x;
        int y;
        for (int k=i+1;k<n;k++)
        {
            x=matrix[k][i];
            y=matrix[i][i];
            if (x)
            {
            IntMultiplyRow(matrix[i], n, x);
            IntMultiplyRow(matrix[k], n, y);
            IntSubtractionRows(matrix[k], matrix[i], n);
            IntDivideRow(matrix[i], n, x);
            }
        }
    }
}

void IntPrintResult(int matrix[][MAX_SIZE], int n)
{
    float Solutions[MAX_SIZE - 1];

    for (int i=n-1;i >= 0;i--)
    {
        for (int k = n - 1;k > i;k--)
        {
            Solutions[i] -= matrix[i][k] * Solutions[k];
        }

        Solutions[i] += matrix[i][n];

        if (abs(Solutions[i]) > 0)
        {
            if (matrix[i][i])
                Solutions[i] /= matrix[i][i];
            else
            {
                cout<<"The Matrix is inconsistent! "<<endl;
                return;
            }
        }
        else
        {
            if (matrix[i][i])
                Solutions[i]=0;
            else
            {
                cout<<"The Matrix is consistent! There are infinitely many sets of solution!"<<endl;
                return;
            }
        }
    }

    FloatPrintSolutions(Solutions, n);
}


void IntReadMatrix(int matrix[][MAX_SIZE], int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
		}
	}
}

