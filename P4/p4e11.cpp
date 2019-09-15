#include <iostream>
using namespace std;

//EJERCICIO 11
bool isThere(int A[], int n, int X)
{
	for (int i=0; i<n; i++)
		if (X==A[i])
			return true;
	return false;
}

void showRepeats(int A[], int n, int X)
{
	for (int i=0; i<n; i++)
	{
		if (A[i] == X)
			cout << i+1 << endl;
	}
	if (not(isThere(A,n,X)))
		cout << "-1" << endl;
}
void showArray(int A[], int n)
{
	cout << "[";
	for (int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << "]" << endl;
}
void inputArray(int A[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "Ingrese valor al arreglo: "; cin >> A[i];
	}
}

int main()
{
	int n, X;
	cout << "Ingrese numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);

	cout << "Ingrese X: ";
	cin >> X;

	showRepeats(A,n,X);

	return 0;
}