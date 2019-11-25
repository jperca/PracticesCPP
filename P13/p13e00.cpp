#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Persona
{
    string cod;
    string nom;
public:
    void llenar_data();
    void imprimir_data();
    string getCode();
};
string Persona::getCode(){
        return cod;
    }
void Persona::llenar_data(){
    cout << "Code: " << endl; 
    cin >> cod;
    cout << "Name: " << endl;
    cin >> nom;
}
void Persona::imprimir_data(){
    cout << "Código: " << cod << endl;
    cout << "Nombre: " << nom << endl;
}

class Alumno:Persona
{
    int cred;
public:
    void llenar_data();
    void imprimir_data();
    
};
void Alumno::llenar_data(){
    Persona::llenar_data();
    cout << "Creditos: "; cin >> cred;
}
void Alumno::imprimir_data(){
    Persona::imprimir_data();
    cout << "El creditaje es: " << cred << endl;
}

class Profesor:Persona
{
    string course;
public:
    void llenar_data();
    void imprimir_data();
    
};
void Profesor::llenar_data(){
    Persona::llenar_data();
    cout << "course: "; cin >> course;
}
void Profesor::imprimir_data(){
    Persona::imprimir_data();
    cout << "El Curso es: " << course << endl;
}

class Sistema
{
    int actAlumno;
    int actProfesor;
    Alumno *listaalumno[100]; //arreglo de 100 punteros a alumnos
    Profesor *listaprofesor[100];
public:
    Sistema();
    void ingresar(int opcion);
    void listar();
    void buscar(int type, string key);

};

Sistema::Sistema(){ //MODIFICAR
    for(int i=0; i<100; i++)
        listaalumno[i] = 0;
    actAlumno = -1;
}
void Sistema::ingresar(int opcion){
    if (opcion == 1){
        actAlumno++;
        listaalumno[actAlumno] = new Alumno;
        listaalumno[actAlumno]->llenar_data();
    }
    else if (opcion == 2){
        actProfesor++;
        listaprofesor[actProfesor] = new Profesor;
        listaprofesor[actProfesor]->llenar_data();
    }
     
}
void Sistema::listar(){
    for (int i=0; i<=actAlumno; i++)
        listaalumno[i]->imprimir_data();
}

void Sistema::buscar(int type, string key){
    if (type == 1){
        for (int i=0; i<actAlumno; i++){
            bool isEqual = true;
            for (int k=0; k < key.length() ; k++){
                string code = listaalumno[i]->getCode();
                if (key[k] != code[k])
                    isEqual = false;
            }
            if (isEqual)
                listaalumno[i]->imprimir_data();
        }
    }
    else if (type == 2){
        for (int i=0; i<actProfesor; i++){
            bool isEqual = true;
            for (int k=0; k < key.length() ; k++){
                string code = listaprofesor[i]->getCode();
                if (key[k] != code[k])
                    isEqual = false;
            }
            if (isEqual)
                listaprofesor[i]->imprimir_data();
        }
    }
}

int main()
{
    int men;
    Sistema S;
    string key;
    
    for (;;)
    {
        cout << "(1) Ingresar datos " << endl;
        cout << "(2) Mostrar datos " << endl;
        cout << "(3) Buscar " << endl;
        cout << "(4) Salir" << endl;
        cin >> men;
        switch(men){
            case 1:
                int opc1;
                cout << "(1) Ingresar en alumnos" << endl;
                cout << "(2) Ingresar en profesores"  << endl;
                cin >> opc1;
                S.ingresar(opc1);
                break;
            case 2:
                S.listar();
                break;
            case 3:
                int opc3; 
                cout << "(1) Buscar en alumnos" << endl;
                cout << "(2) Buscar en profesores"  << endl;
                cin >> opc3;
                cout << "Ingresar código: "; cin >> key; 
                S.buscar(opc3, key);
                break;
            case 4:
                cout << "Gracias." << endl;
                return 0;
        }
    }
}
