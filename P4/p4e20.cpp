#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void inputMatrix(float M[10][5], int f, int c )
{
	string Categoria[5] = {"Codigo", "Cantidad", "P. Unitario", "Descuento", "Total"};
	for(int i=0; i<f; i++)
	{
		float pTotal = 0;
		for(int j=0; j<c-1; j++)
		{
			cout << "Ingrese " << Categoria[j] << " del producto: ";
			cin >> M[i][j]; 
		}
		pTotal = M[i][c-3]*M[i][c-4] - M[i][c-2];
		M[i][c-1] = pTotal;
	}
		
}
void showMatrix(float M[10][5], int f, int c)
{
	cout << "\nCodigo\t\tCantidad\tP. Unitario\tDescuento\tTotal" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	for(int i=0; i<f; i++)
	{
		for(int j=0; j<c; j++)
			cout << M[i][j] << "\t\t";
		cout << endl;
	}	
}

int main()
{
	int nProductos;
	float tPagar=0, igv = 0.18;

	string Categoria[5] = {"Codigo", "Cantidad", "P. Unitario", "Descuento", "Total"};
	cout << "Ingrese numero de Productos: "; cin >> nProductos;

	int f = nProductos, c=5;
	float M[10][5];

	inputMatrix(M,f,c);
	showMatrix(M,f,c);

	cout << "---------------------------------------------------------------------" << endl;
	for (int k=0; k<f; k++)
		tPagar += M[k][c-1];
	cout << setw(60) << "Total (S/)\t" << tPagar << endl;
	cout << setw(60) << "igv\t" << igv*100 << "%" << endl;

	tPagar *= igv;
	cout << setw(60) << "Total a pagar (S/)\t" << tPagar << endl;

	return 0;
}
