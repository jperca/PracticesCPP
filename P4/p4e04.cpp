#include <iostream>
using namespace std;

//EJERCICIO 4
bool isThere(int A[], int n, int X)
{
	for (int i=0; i<n; i++)
	{
		if (X==A[i])
			return true;
	}
	return false;
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

	cout << "Ingrese X: ";
	cin >> X;

	if (isThere(A,n,X))
		cout << X << " SI está en el arreglo" << endl;
	else
		cout << X << " NO está en el arreglo" << endl;

	return 0;
}