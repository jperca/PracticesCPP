#include <iostream>
using namespace std;
class Punto
{
public:
    float x; float y; float z;
    Punto(){
        x = 0; y = 0; z  = 0;
    }
    Punto(float x1, float y1, float z1){
        x = x1; y = y1; z = z1;
    }
    void setX(int x1){
        x = x1;
    }
    void setY(int y1){
        y = y1;
    }
    void setZ(int z1){
        z = z1;
    }
    void print(){
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
    
};
int main()
{
    Punto* Puntos;
    Puntos = new Punto[3];
    for (int i=0; i<3; i++)
    {
        float a,b,c;
        cout << "Ingrese cordenadas del P" << i + 1 << ": ";
        cin >> a >> b >> c;
        Puntos[i] = Punto(a,b,c);
    }

    for (int i=0; i<3; i++){
        cout << "Punto " << 
        Puntos[i].print();
    }
    return 0;
}