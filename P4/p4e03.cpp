#include <iostream>
using namespace std;

//Ejercicio 3
void inputArray(int A[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "Ingrese valor al arreglo: "; cin >> A[i];
	}
}
void showArray(int A[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int mayor(int A[], int n)
{
	int m = A[0];

	for (int i=1; i < n; i++)
	{
		if (A[i] > m)
			m = A[i];
	}
	return m;
}

int main()
{
	int n;
	cout << "Ingrese numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);
	cout << "El mayor es " << mayor (A, n) << endl;

	return 0;
}