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
	for (int i=0; i<f; i++){
		cout << "[";
		for (int j=0; j<c; j++)
			cout << setw(2) << M[i][j];
		cout << "]" << endl;
	}
}

int *mayorByRows(int M[10][10], int f, int c)
{
	int *V = new int[f];
	for (int i=0; i<f; i++)
	{
		int May = M[i][0];
		for (int j=1; j<c; j++)
			if(M[i][j] > May)
				May = M[i][j];
		V[i] = May;
	}
	return V;
}

int main()
{
	const int f = 4;
	const int c = 3;
	int M[10][10] = {{1,2,3},{3,4,5},{5,6,7},{7,8,9}};
	showMatrix(M,f,c);
	showArray(mayorByRows(M,4,3),4);

	return 0; 
}