#include <iostream>
#include <string.h>
#include <math.h>

#include "clases2.cpp"

using namespace std;

int main()
{
    int option;
    string keySearch;
    Sistema AlqlerAutos;

    while (true){
        cout << "*****************************************" << endl
            <<  "*   SISTEMA DE ALQUILER DE AUTOS - XXX  *" << endl
            <<  "*****************************************" << endl
            <<  "*   (1) Ingreso de registros            *" << endl
            <<  "*   (2) Listado de registros            *" << endl
            <<  "*   (3) Busqueda                        *" << endl
            <<  "*   (4) Eiminacion de registros         *" << endl
            <<  "*   (5) Salir                           *" << endl
            <<  "*****************************************" << endl
            <<  "   Elija una opción: "; cin >> option;

            switch(option){
                case 1:
                    int option1;
                    cout << endl;
                    cout << "*****************************************" << endl
                        <<  "*         INGRESO DE REGISTROS          *" << endl
                        <<  "*****************************************" << endl
                        <<  "*    (1) Clientes                       *" << endl
                        <<  "*    (2) Empleados                      *" << endl
                        <<  "*    (3) Autos                          *" << endl
                        <<  "*    (4) Regresar                       *" << endl
                        <<  "*****************************************" << endl
                        <<  "    Elija una opción: "; cin >> option1;
                    AlqlerAutos.aniadir(option1);
                    break;
                case 2:
                    int option2;
                    cout << endl;
                    cout << "*****************************************" << endl
                        <<  "*         LISTADO DE REGISTROS          *" << endl
                        <<  "*****************************************" << endl
                        <<  "*    (1) Clientes                       *" << endl
                        <<  "*    (2) Empleados                      *" << endl
                        <<  "*    (3) Autos                          *" << endl
                        <<  "*    (4) Regresar                       *" << endl
                        <<  "*****************************************" << endl
                        <<  "    Elija una opción: "; cin >> option2;
                    AlqlerAutos.listar(option2);
                    break;
                case 3:
                    int option3;
                    cout << endl;
                    cout << "*****************************************" << endl
                        <<  "*        BUSQUEDA EN REGISTROS          *" << endl
                        <<  "*****************************************" << endl
                        <<  "*    (1) Clientes                       *" << endl
                        <<  "*    (2) Empleados                      *" << endl
                        <<  "*    (3) Autos                          *" << endl
                        <<  "*    (4) Regresar                       *" << endl
                        <<  "*****************************************" << endl
                        <<  "    Elija una opción: "; cin >> option3;
                    cout <<  "    Clave de busqueda: "; getline(cin,keySearch);
                    AlqlerAutos.buscar(option3, keySearch);
                    break;
                case 4:
                    int option4;
                    cout << endl;
                    cout << "*****************************************" << endl
                        <<  "*        ELIMINAR EN REGISTROS          *" << endl
                        <<  "*****************************************" << endl
                        <<  "*    (1) Clientes                       *" << endl
                        <<  "*    (2) Empleados                      *" << endl
                        <<  "*    (3) Autos                          *" << endl
                        <<  "*    (4) Regresar                       *" << endl
                        <<  "*****************************************" << endl
                        <<  "    Elija una opción: "; cin >> option4;
                    AlqlerAutos.eliminar(option4);
                    break;
                case 5:
                    cout << "Hasta luego." << endl;
                    return 0;
                    break;
                default:
                    cout << "Opción incorrecta. Intente de nuevo :)" << endl;
                    break;
            }
    }
}