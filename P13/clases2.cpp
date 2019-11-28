#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

//Funciones
template <class T> 
int searchIn(T *lista[], string key, int actLista){
    int itrSearch = -1;
    for (int i=0; i<=actLista; i++){
        bool isEqual = true;
        for (int k = 0; key.length(); k++)
            if ((lista[i]->getCode())[k] != key[k]){
                isEqual = false;
                break;
            }
        if (isEqual){
            itrSearch = i;
        }
    }
    return itrSearch;

}

//Auto

class Auto
{
    string plac, modl, colr;
    int pr_alqulr, n_prts;
    bool isDisponible;
public:
    bool getEstatus(){return isDisponible;}
    void llenar_data(){
        cin.ignore();
        cout << "Ingrese los siguientes datos:\nPlaca: "; getline(cin, plac);
        cout << "Modelo: "; getline(cin, modl);
        cout << "Color: "; getline(cin, colr);
        cout << "Nro. de puertas: "; cin >> n_prts;
        cout << "Precio del alquiler S/.: "; cin >> pr_alqulr;
        isDisponible = true;
    }
    void imprimir_data(){
        cout << "Caracteristicas y estado del auto:\nPlaca: " << plac << endl
            << "Modelo: " << modl << endl
            << "Color: " << colr << endl
            << "Nro. de Puertas: " << n_prts << endl
            << "Precio de alquiler S/.: " << pr_alqulr << endl;
        if (isDisponible)
            cout << "Estado: Disponible" << endl;
        else
            cout << "Estado: No disponible" << endl; 
    }
    
};

//Persona
class Persona
{
    string name, DNI, dir;
public:
    string getDNI(){return DNI;}

    void llenar_data(){
        cin.ignore();
        cout << "Ingrese los siguientes datos:\nDNI: "; getline(cin, DNI);
        cout << "Nombre: "; getline(cin, name);
        cout << "Direccion: "; getline(cin, dir);
    }
    void imprimir_data(){
        cout << "Datos personales:\nDNI:" << DNI << endl;
        cout << "Nombre: " << name << endl;
        cout << "Direccion: " << dir << endl;
    }
    
};
class Cliente:Persona
{
    string code_cl;
    int saldo, i_vehp; 
    Auto *uvehprest;
public:
    string getDNI(){return Persona::getDNI();}
    string getCode(){return code_cl;}

    Cliente(){
        uvehprest = new Auto [10];
        i_vehp = 0;
    }
    ~Cliente(){
        delete [] uvehprest;
    }
    void llenar_data(){
        Persona::llenar_data();
        cout << "Cod. Cliente: "; getline(cin, code_cl);
        cout << "Saldo S/.: "; cin >> saldo;
        //LLENAR AUTOS?
    }
    void imprimir_data(){
        cout << "Cod. de Cliente: " << code_cl << endl;
        Persona::imprimir_data();
        cout << "Saldo: " << saldo << endl;
        //IMPRIMIR AUTOS?

    }
    
};

class Empleado:Persona
{
    string code_em, cargo;
    int sueldo;

public:
    string getDNI(){return Persona::getDNI();}
    string getCode(){return code_em;}

    void llenar_data(){
        Persona::llenar_data();
        cout << "Cod. Empleado: "; getline(cin, code_em);
        cout << "Cargo: "; getline(cin, cargo);
        cout << "Sueldo S/.: "; cin >> sueldo;
    }
    void imprimir_data(){
        cout << "Cod. de Empleado: " << code_em << endl;
        Persona::imprimir_data();
        cout << "Cargo: " << cargo << endl;
        cout << "Sueldo: " << sueldo << endl;
    }

};


class Sistema
{
    Cliente *listClientes[200];
    Empleado *listEmpleados[200];
    Auto *listAutos[200];

    int actCliente, actEmpleado, actAuto;
public:
    Sistema(){
        for (int i=0; i<200; i++)
        {
            listClientes[i] = 0;
            listEmpleados[i] = 0;
            listAutos[i] = 0;

            actCliente = actEmpleado = actAuto = -1;
        }
    }
    void aniadir(int typeItems){
        if (typeItems == 1){ //Cliente
            actCliente++;
            listClientes[actCliente] = new Cliente;
            listClientes[actCliente]->llenar_data();

        }else if (typeItems == 2){ //Empleado
            actEmpleado++;
            listEmpleados[actEmpleado] = new Empleado;
            listEmpleados[actEmpleado]->llenar_data();

        }else if (typeItems == 3){ //Auto
            actAuto++;
            listAutos[actAuto] = new Auto;
            listAutos[actAuto]->llenar_data();

        }else
            cout << "Regresar..." << endl;
    }

    void listar(int typeItems){
        switch(typeItems){
            case 1: //Cl
                cout << endl;
                for (int i=0; i<=actCliente; i++)
                    listClientes[i]->imprimir_data();
                cout << endl;
                break;
            case 2: //Em
                cout << endl;
                for (int i=0; i<=actEmpleado; i++)
                    listEmpleados[i]->imprimir_data();
                cout << endl;
                break;
            case 3: //Autos (Criterios a tener en cuenta)
                int opcAutos;
                cout << endl;
                cout << "¿Que desea listar?:\n(1)Disponible\n(2)No Disponible" << endl;
                cout << "Elija una opcion: "; cin >> opcAutos;
                cout << endl;
                if (opcAutos == 1)
                    for (int i=0; i<=actAuto; i++)
                        if (listAutos[i]->getEstatus())
                            listAutos[i]->imprimir_data();
                else if(opcAutos == 2)
                    for (int i=0; i<=actAuto; i++)
                        if (listAutos[i]->getEstatus() == false)
                            listAutos[i]->imprimir_data();
                break;
            default:
                cout << "Regresar..." << endl;
                break;
        }
    }
    void buscar(int typeItems, string key){
        switch(typeItems){
            case 1: //Cl
                int rsltSearch = searchIn <Cliente> (listClientes, key, actCliente);
                if (rsltSearch != -1)
                    listClientes[rsltSearch]->imprimir_data();
                else
                    cout << "No se encontró coincidencias! :(" << endl;
                break;
            /*case 2: //Em
                break;
            case 3: //Autos
                break;
            default:
                cout << "Regresar..." << endl;
                break;*/
        }

    }
    void eliminar(int typeItems){

    }
    
};

