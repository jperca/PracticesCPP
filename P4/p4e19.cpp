#include <iostream>
#include <string>
using namespace std;

void inputMatrix(int M[10][10], int f, int c )
{
	string Categoria[4] = {"Peleas", "Kata", "R. Madera", "Total"};

	for(int i=0; i<f; i++)
	{
		M[i][0] = i;
		int pTotal = 0;

		for(int j=1; j<c-1; j++)
		{
			cout << "Ingrese Puntaje " << Categoria[j-1] << " del Participante " << i << ": ";
			cin >> M[i][j];
			pTotal += M[i][j]; 
		}
		M[i][c-1] = pTotal;
	}
		
}
void showMatrix(int M[10][10], int f, int c)
{
	cout << "\nParticipante\tP.Peleas\tP. Kata\t\tP. R. Maderas\tP. Total" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for(int i=0; i<f; i++)
	{
		for(int j=0; j<c; j++)
			cout << M[i][j] << "\t\t";
		cout << endl;
	}
	cout << endl;		
}

int main()
{
	int nParticipantes;
	string Categoria[4] = {"Peleas", "Kata", "R. Madera", "General del Torneo"};
	cout << "Ingrese numero de participantes: "; cin >> nParticipantes;

	int f = nParticipantes, c=5;
	int M[10][10];

	inputMatrix(M,f,c);
	showMatrix(M,f,c);

	for (int j=1; j<c; j++)
	{
		int posWinner = 0;
		int pMayor = M[0][j];

		for(int i=1; i<f; i++)
			if(M[i][j] > pMayor)
			{
				pMayor = M[i][j];
				posWinner = i;
			}	
		cout << "El ganador en " << Categoria[j-1] << " es el PARTICIPANTE: " << posWinner <<endl;
	}

	return 0;
}
