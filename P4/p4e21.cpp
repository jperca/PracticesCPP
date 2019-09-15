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

void swapRows(int M[10][10], int f, int c, int X, int Y)
{
	for(int j=0; j<c; j++)
	{
		int temp = M[X][j];
		M[X][j] = M[Y][j];
		M[Y][j] = temp;
	}
}

int main()
{
	int f=3, c=3, X, Y;
	int M[10][10] = {{1,2,3},{4,5,6},{7,8,9}};
	showMatrix(M,f,c);

	cout << "Ingrese X: "; cin >> X;
	cout << "Ingrese Y: "; cin >> Y;

	swapRows(M,f,c,X-1,Y-1);

	showMatrix(M,f,c);

	return 0;
}