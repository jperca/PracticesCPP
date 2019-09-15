#include <iostream>
using namespace std;

//EJERCICIOS 1
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

	cout << "Ingrese el numero de elementos: ";
	cin >> n;

	int *A = new int[n];

	inputArray(A,n);
	showArray(A,n);
	media(A,n);

	return 0;
}