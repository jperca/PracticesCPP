#include <iostream>
using namespace std;

int mcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return mcd(b, a%b);
}

class Fraccion
{
public:
    int num, den;
    Fraccion(){
        num = 1; den = 1;
    }
    Fraccion(int a, int b){
        num = a; den = b;
    }

    int getN(){
        return num; 
    }
    int getD(){
        return den;
    }

    void setN(int a){
        num = a;
    }

    void setD(int b){
        den = b;
    }

    Fraccion Sumar(Fraccion f1){
        Fraccion suma;
        suma.setN(num*(f1.getD()) + (f1.getN())*den);
        suma.setD(den*(f1.getD()));
        return suma;
    }
    void mostrar(){
        if (den == 1)
            cout << num << endl;
        else
            cout << num << "/" << den << endl;
    }
    void simplificar(){
        int a = num, b = den;
        int k = mcd(a,b);
        num = num/k;
        den = den/k;        
    }
};

int main()
{
    Fraccion a(8,4);
    Fraccion b(8,4);
    Fraccion suma;
    suma = a.Sumar(b);
    suma.simplificar();
    suma.mostrar();

    return 0;
}