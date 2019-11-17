#include <iostream>
#include <string>
using namespace std;
struct Tabla
{
    string *X;
    int *Y, i;

    Tabla(int t){
        X = new string [t];
        Y = new int [t];
        i = 0;
    }
    void agregar(string x, int y){
        *(X+i) = x;
        *(Y+i) = y;
        i++;
    }
    void listar(){
        cout << "num|cont\tX\t\tY" << endl;
        for(int f=0; f<i; f++)
        {
            cout << f << "\t\t" << *(X+f) << "\t\t" << *(Y+f) << endl;
        }
    }

    int contar(string key)
    {
        int cont = 0;
        for (int f=0; f<i; f++){
            bool isEqual = true;
            for(int j=0; j<key.length(); j++)
                if (key[j] != (*(X+f))[j])
                {
                    isEqual = false;
                    break;
                }
            if(isEqual)
                cont++;
        }

        return cont;
    }

    int sumar(string key)
    {
        int suma = 0;
        for (int f=0; f<i; f++){
            bool isEqual = true;
            for(int j=0; j<key.length(); j++)
                if (key[j] != (*(X+f))[j])
                {
                    isEqual = false;
                    break;
                }
            if(isEqual)
                suma = suma + *(Y+f);
        }
        return suma;
    }

};
int main()
{
    Tabla T(50);
    T.agregar("rosa", 11);
    T.agregar("maria", 12);
    T.agregar("rosangela", 30);
    T.listar();
    cout << endl;
    cout << T.contar("ros") << endl;
    cout << T.sumar("ros") << endl;

    return 0;
}