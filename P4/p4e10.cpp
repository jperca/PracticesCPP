#include <iostream>
using namespace std;

int *copyArrayNoRepeat(int [], int [], int, int);

bool isThere(int [], int, int);
void showArray(int [], int);
int howRepeatsAB(int [], int [], int, int);

int main()
{
	int A[5] = {1,2,3,4,5};
	int B[5] = {3,4,5,6,7};

	showArray(A,5);
	showArray(B,5);

	showArray(copyArrayNoRepeat(A,B,5,5), 5+5 - howRepeatsAB(A, B, 5, 5));

	return 0;
}

bool isThere(int A[], int n, int X)
{
	for (int i=0; i<n; i++)
		if (X==A[i])
			return true;
	return false;
}

int howRepeatsAB(int A[], int B[], int n, int m)
{
	int cont = 0;
	for (int i=0; i<n; i++)
		if (isThere(B, m, A[i]))
			cont++;

	return cont;
}

int *copyArrayNoRepeat(int A[], int B[], int n, int m)
{
	int *C = new int [n+m - howRepeatsAB(A,B,n,m)];
	int k = 0;

	for (int i=0; i<n; i++)
		if (not(isThere(B,m,A[i])))
		{
			C[k] = A[i];
			k++;
		}

	for (int j=0; j<m; j++)
		C[k+j] = B[j];
	return C;
}

void showArray(int A[], int n)
{
	cout << "[";
	for (int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << "]" << endl;
}
