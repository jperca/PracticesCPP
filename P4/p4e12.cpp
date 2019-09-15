#include <iostream>
using namespace std;

//EJERCICIO 12
int *deleteElementByPos(int A[], int n, int p)
{
	for (int i=p; i<=n-2; i++)
	{
		A[i] = A[i+1];
	}
	
	A[n-1] = 0;
	return A;
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
	int pos;

	int A[8] = {1,2,3,4,5,6,7,8};
	showArray(A,8);

	cout << "¿Que posicion desea eliminar?: "; cin >> pos;

	if (pos >= 1 && pos <= 8)
		showArray(deleteElementByPos(A,8,pos-1), 8);
	else
		cout << "Posicion incorrecta :( " << endl;

	return 0; 
}