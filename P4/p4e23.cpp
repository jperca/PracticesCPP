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

void swapDiags(int A[10][10], int f, int c)
{
	for(int i=0; i<f; i++)
	{
		int temp = A[i][i];
		A[i][i] = A[i][c-i-1];
		A[i][c-i-1] = temp;
	}
}

int main()
{
	int f=3, c=3, X, Y;
	int M[10][10] = {{1,2,3},{4,5,6},{7,8,9}};
	showMatrix(M,f,c);

	swapDiags(M,f,c);
	cout << endl;
	showMatrix(M,f,c);

	return 0;
}