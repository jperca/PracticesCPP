#include <iostream>
#include <iomanip>
using namespace std;

void showArray(int A[], int n)
{
	cout << "[";
	for (int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << "]" << endl;
}

void showMatrix(int M[10][10], int f, int c)
{
	for (int i=0; i<f; i++)
	{
		cout << "[";
		for (int j=0; j<c; j++)
		{
			cout <<  setw(2) << M[i][j];
		}
		cout << "]" << endl;
	}
}

int mayorDiagPrinc(int M[10][10], int f, int c)
{
	int mayor = M[0][0];
	for (int i=1; i<f; i++)
	{
		for (int j=1; j<c; j++)
			if (i==j && M[i][j]>mayor)
				mayor = M[i][j];
	}
	return mayor;
}

int menorDiagSec(int M[10][10], int f, int c)
{
	int menor = M[0][c-1];
	for (int i=1; i<f; i++)
	{
		for (int j=1; j<c; j++)
			if (i+j==f-1 && M[i][j] < menor)
				menor = M[i][j];
	}
	return menor;
}

int main()
{
	int f=3, c=3;
	int M[10][10] = {{1,2,3},{4,5,6},{7,8,9}};
	showMatrix(M,f,c);

	cout <<"Mayor de la diagonal principal: " << mayorDiagPrinc(M,f,c) << endl;
	cout <<"Menor de la diagonal secundaria: " << menorDiagSec(M,f,c) << endl;

	return 0;
}