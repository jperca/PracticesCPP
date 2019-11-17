#include <iostream>
using namespace std;

class Entero
{
public:
    int valor;
    void setValue(int a)
    {
        valor = a;
    }
    void print(){
        cout << valor << endl;
    }
    int getValue(){
        return valor;
    }
    Entero sumar(Entero b){
        Entero suma;
        suma.setValue(valor + b.valor);
        return suma;

    }
    Entero inverso(){
        Entero inver;
        inver.setValue(0 - valor);
        return inver;
    }
    Entero restar(Entero b){
        Entero resta;
        resta = b.sumar((b.inverso()));
        return resta;
    }

};

int main()
{
    Entero e1, e2, suma, inver;
    e1.setValue(7);
    e2.setValue(9);
    suma = e1.sumar(e2);
    inver = e1.inverso();
    cout << "e1 = ";e1.print(); 
    cout << "e2 = ";e2.print();
    cout << "e1 + e2 = ";suma.print();
    cout << "e1 inverso = ";inver.print();
    
    return 0;
}