#include <iostream>
using namespace std;

//EJERCICIO 9
int *copyArray(int A[], int B[], int n, int m)
{
	int *C = new int[n+m];

	for (int i=0; i<n; i++)
		C[i] = A[i];

	for (int j=0; j<m; j++)
		C[n+j] = B[j];

	return C;
}

void showArray(int A[], int n)
{
	cout << "[";
	for (int i=0; i<n-1; i++)
	{
		cout << A[i] << ",";
	}

	cout << A[n-1] << "]" << endl;
}


int main()
{
	int A[8] = {1,2,3,4,5,6,7,8};
	int B[6] = {9,10,11,12,13,14};

	showArray(A,8);
	showArray(B,6);

	showArray(copyArray(A,B,8,6), 8+6);

	return 0;
}