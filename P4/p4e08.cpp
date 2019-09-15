#include <iostream>
using namespace std;

//PROTOTIPO
void howRepeat(int [], int);
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

	howRepeat(A,n);

	return 0;
}

//Ejercicio 8
int repetidosA(int A[], int n)
{
	int cont = 0;
	
	return cont; 
}

void howRepeat(int B[], int n)
{
	int *A = new int[n - repetidosA(B,n)];
	for (int i=0; i<n; i++)
	{
		int cont = 0;
		for (int j=0; j<n; j++){
			if (A[i]==A[j])
				cont += 1;
		}
		cout << A[i] << " se repite " << cont << " veces" << endl;
	}
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