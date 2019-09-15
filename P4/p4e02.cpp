#include <iostream>
using namespace std;

//EJERCICIO 2
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

float media(int A[], int n)
{
	float s;

	for (int i=0; i < n; i++)
	{
		s += A[i];
	}
	return s/n;
}

int main()
{
	int n;
	cout << "Ingrese numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);
	cout << "La media es " << media(A,n) << endl;

	return 0;
}