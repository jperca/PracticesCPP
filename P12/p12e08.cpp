#include <iostream>
#include <string> //manejo de cadenas. clase string
#include <cstdlib> //convertir cadena a numero
#include <fstream> //manejo de archivos txt
#include <ctype.h> //obtener assci de un char
using namespace std;

class Plantilla{
public:
    string **P;
    Plantilla(string namefile){
        P = new string *[100];
        for(int f=0; f<100; f++)
            *(P+f) = new string [26]; 
        /*MAS AQUI!*/
        namefile += ".txt";
        ifstream file(namefile);
        if(file.fail())
            cout << "Error al abrir " << namefile << endl;
        else
        {
            int filas = 0;
            char textline[545];

            while(!file.eof() and filas < 100)
            {
                file.getline(textline, sizeof(textline));
                //tratar las lineas de texto
                int columnas = 0, t = 0;
                string val_celda = "";
                while(textline[t] != '\0')
                {
                    val_celda += textline[t];
                    t++;
                    if (textline[t] == '\t')
                    {
                        *(*(P+filas)+columnas) = val_celda;
                        val_celda = "";
                        columnas++;
                        t++;
                    }
                    if (textline[t] == '\0')
                    {
                        *(*(P+filas)+columnas) = val_celda;
                        break;
                    }

                }
                filas++;
            }
        }
        file.close();

    }
    Plantilla(){
        P = new string *[100];
        for(int f=0; f<100; f++)
            *(P+f) = new string [26]; 
    }
    void asignar(string celda, string valor){
        int j = toascii(celda[0]) - 65;
        string str = "";
        for(int l=1; l<celda.length();l++)
            str += celda[l];
        int i = atoi(str.c_str()) - 1;

        *(*(P+i)+j) = valor;
    }
    void obtener(string celda){
        int j = toascii(celda[0]) - 65;
        string str = "";
        for(int l=1; l<celda.length();l++)
            str += celda[l];
        int i = atoi(str.c_str()) - 1;

        if (*(*(P+i)+j) != "")
            cout << *(*(P+i)+j) << endl;
        else
            cout << "NULL" << endl;
    }
    void grabar(string namefile){
        ofstream file(namefile);
        if (file.fail())
            cout << "Error al crear " << namefile << endl;
        else{
            for(int f = 0; f < 100; f++)
            {
                string textline = "";
                for (int c = 0; c < 26 ; c++)
                {
                    textline += *(*(P+f)+c);
                    textline += '\t';
                }
                file << textline << endl;
            }
        }
        
        file.close();
    }

};

int main(int argc, char const *argv[])
{
    Plantilla P("notas");
    P.asignar("A4", "alejo");
    P.obtener("B1");
    P.grabar("aux.txt");
    return 0;
}