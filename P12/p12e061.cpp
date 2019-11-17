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
    int getNum(){return num;}
    int getDen(){return den;}

    void setNum(int a){num = a;}
    void setDen(int b){den = b;}
    
};

Fraccion sumar(Fraccion a, Fraccion b)
{
    Fraccion suma;
    suma.setNum((a.getNum())*(b.getDen()) + (b.getNum())*(a.getDen()));
    suma.setDen((a.getDen())*(b.getDen()));
    return suma;
}

void simplificar(Fraccion a)
{
    int n = a.getNum(), d = a.getDen();
    int k = mcd(n,d);
    a.setNum(n/k);
    a.setDen(d/k);
}

void mostrar(Fraccion a)
{
    if (a.getDen() == 1)
        cout << a.getNum() << endl;
    else
        cout << a.getNum() << "/" << a.getDen() << endl;
}

int main()
{
    Fraccion a(1,3), b(4,5), suma;
    suma = sumar(a,b);
    simplificar(suma);
    mostrar(suma);
    return 0;
}