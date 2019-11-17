#include <iostream>
using namespace std;

class Pila
{
public:
    //Atributos
    char *vpila;
    int size, top;

    //Metodos
    Pila(int n){
        top = 0;
        size = n;
        vpila = new char [size];
    }
    ~Pila(){
        delete [] vpila;
    }
    void push (char c)
    {
        if (top < size){
            *(vpila + top) = c;
            top++;
        }
        else
            cout << "Pila llena" << endl;
        
    }
    char pop(){
        if (top > 0)
        {
            top--;
            return *(vpila+top);
        }
        return '$';        
    }
    
};

class Cola
{
    int size, top;
    char *vcola;
public:
    Cola(int n){
        size = n;
        vcola = new char [size];
        top = 0;
    }
    ~Cola(){
        delete [] vcola;
    }
    void push (char key){
        if (top < size)
        {
            *(vcola + top) = key;
            top++;
        } 
    }
    void pop(){
        if (top > 0)
        {
            for (int i=1; i<size; i++)
            {
                *(vcola + i -1) = *(vcola +i);
            }
            top--;
        }            
    }
    char front()
    {
        if (top > 0)
            return *(vpila + top - 1);
        else
            return '$'; 
    }
    
};

int main()
{
    /*
    Pila P(5);
    int opcion;

    do
    {
        cout << "(1) Insertar\n(2) Sacar ultimo\n(3) Salir" << endl;
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                char val;
                cout << "Caracter: "; cin >> val; 
                P.push(val);
                break;
            case 2:
                if (P.pop() != '$')
                    cout << "La pila esta vacia." << endl;
                else
                    cout << P.pop() << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        };

    }while(opcion != 3);
    */

    Cola C(6);

    return 0;
}