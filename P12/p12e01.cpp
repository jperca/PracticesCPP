#include <iostream>
using namespace std;

class Rectangulo
{
public:
    float largo; float ancho;

    void setLargo(float x){
        largo = x;
    }
    void setAncho(float y){
        ancho = y;
    }
    float getLargo(){
        return largo;
    }
    float getAncho(){
        return ancho;
    }
    float Area(){
        return largo*ancho;
    }
    float Perimetro(){
        return 2*(largo + ancho);
    }
    
};
int main()
{
    Rectangulo R1, R2;
    R1.setLargo(7); R1.setAncho(9);
    R2.setLargo(5.7); R2.setAncho(10.6);
    cout << "Area de R1: " << R1.Area() << endl;
    cout << "Perimetro de R1: " << R1.Perimetro() << endl;
    cout << "Area de R2: " << R2.Area() << endl;
    cout << "Perimetro de R2: " << R2.Perimetro() << endl;
    
    return 0;
}