#include <iostream>
using namespace std;

//EJERCICIO 5
void showArray(int A[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int sumEven(int A[], int n)
{
	int sumEven = 0;
	for (int i=0; i<n; i++)
	{
		if (i%2==1)
			sumEven += A[i];
	}
	return sumEven;
}

int main()
{
	int A[5] = {1,2,3,4,5};

	showArray(A,5);
	cout << "La suma de los A[<Pares>] es: " << sumEven(A,5) << endl;

	return 0;
}