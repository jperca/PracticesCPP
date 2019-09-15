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
		for (int j=0; j<c; j++)
		{
			cout <<  setw(2) << M[i][j];
		}
		cout << endl;
	}
}

int sumDiagSec (int M[10][10], int f, int c )
{
	int sum = 0;
	int n = f;
	for (int i = 0; i<n ; i++){
		for(int j = 0; j<n; j++)
			if(i+j==n-1)
				sum += M[i][j];
	}
		
	return sum;
}

int main()
{
	int f=3, c=3;
	int M[10][10] = {{1,2,3},{4,5,6},{7,8,9}};
	showMatrix(M,f,c);

	cout << sumDiagSec(M,f,c) << endl;
	return 0;
}