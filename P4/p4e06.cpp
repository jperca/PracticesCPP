#include <iostream>
using namespace std;

//EJERCICIO 6
bool isPrimo(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

int howPrimos(int A[], int n)
{
	int cont = 0;

	for (int i=0; i<n; i++)
	{
		if (isPrimo(A[i]))
			cont += 1;
	}
	return cont;
}

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

int main()
{
	int n;
	cout << "Ingrese numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);

	cout << "El arreglo contiene: " << howPrimos(A,n) << " primos." << endl;

	return 0;
}