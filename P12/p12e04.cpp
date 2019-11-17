#include <iostream>
using namespace std;

class Cuenta
{
public:
    int id;
    float saldo;
    Cuenta(){
        id = 0; saldo = 0;
    }
    Cuenta(int x, float y){
        id = x; saldo = y;
    }
    void depositar(float x){
        saldo += x;
    }
    bool girar(float x){
        if (saldo-x >= 0){
            saldo -= x;
            return true;
        }
        else
            return false;
    }
    float consultar(){
        return saldo;
    }
    
};

int main()
{
    Cuenta* c;
    c = new Cuenta(1,100);
    c->depositar(20);
    c->girar(80);
    cout << "S/." << c->consultar() << endl;
    return 0;
}