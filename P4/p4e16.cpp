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
			cout << M[i][j] << setw(2);
		}
		cout << endl;
	}
}

int *menorByCol(int M[10][10], int f, int c)
{
	int *V = new int[c];
	
	for(int j=0; j<c; j++)
	{
		int menor = M[0][j];
		for(int i=1; i<f; i++)
			if (M[i][j] < menor)
				menor = M[i][j];
			
		V[j] = menor;
	}
	return V;
}

int main()
{
	int f=3, c=3;
	int M[10][10] = {{1,2,3},{4,5,6},{7,8,9}};
	showMatrix(M,f,c);
	showArray(menorByCol(M,f,c),c);
	return 0;
}