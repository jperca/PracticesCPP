#include <iostream>
using namespace std;

bool isThere(int A[], int n, int X)
{
	for (int i=0; i<n; i++)
		if (X==A[i])
			return true;
	return false;
}

int *pasarNoRepeat(int A[], int n)
{
	int *B = new int[n];
	int k = 0;

	for (int i=0; i<n; i++)
		if(not(isThere(B,n,A[i])))
		{
			B[k] = A[i];
			k++;
		}

	return B;
}
void showArray(int A[], int n)
{
	cout << "[";
	for (int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << "]" << endl;
}

int main()
{
	int A[6] = {2,2,3,6,5,6};
	showArray(A,6);
	showArray(pasarNoRepeat(A,6),6);
}