#include <iostream>
using namespace std;

//EJERCICIO 13 
int *insertInPos(int A[], int n, int P, int X)
{
	int *B = new int[n+1];
	int k=0;
	for (int j=0; j<P; j++)
	{
		B[k] = A[j];
		k++;
	}
	
	//k++;
	for (int i=P+1; i < n + 1; i++)
		B[i] = A[i-1];
	B[P] = X;
	
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
	int pos, X;

	int A[8] = {1,2,3,4,5,6,7,8};
	showArray(A,8);

	cout << "¿En que posicion desea insertar?: "; cin >> pos;
	cout << "Ingrese X: "; cin >> X;

	if (pos >= 1 && pos <= 8)
		showArray(insertInPos(A,8,pos-1,X), 8+1);
	else
		cout << "Posicion incorrecta :( " << endl;

	return 0;
}