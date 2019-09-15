#include <iostream>
using namespace std;

//PROTOTIPOS
int howRepeatX (int [], int, int);
void inputArray(int [], int);
void showArray(int [], int);

int main()
{
	int n, X;

	cout << "Ingrese el numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);

	cout << "Ingrese X: "; cin >> X;

	cout << X << " se repite " << howRepeatX(A,n,X) << " veces" << endl;

	return 0;
}

//EJERCICIO 7
int howRepeatX (int A[], int n, int X)
{
	int cont;
	for(int i=0; i<n; i++)
	{
		if(A[i]==X)
			cont++;
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
