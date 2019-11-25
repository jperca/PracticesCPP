#include <string>
#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>
using namespace std;

int toInteger(string num){
    int n = 0, p = 0;
    for(int i = num.length()-1; i >= 0; i--){
        n += (toascii(num[i])-48)*(pow(10,p));
        p++;
    }
    return n;
}

class CDate
{
public:
    int *D; // [DD,MM,AAAA]
    CDate(){
        D = new int[3];
    }
    ~CDate(){
        delete [] D;
    }

    void SetDate(string date){
        string str = "";
        int pos = 0;
        for (int i = 0; i < date.length(); i++)
        {
            str += date[i];
            if (date[i+1] == '/' or i+1 == date.length()){
                D[pos] = toInteger(str);
                str = "";
                pos++;
                i++;
            }
        }
    }
    void IncrementarFecha(int numdias){
        *(D+0) += numdias;
    }

    int GetDia(){return *(D+0);}
    int GetMes(){return *(D+1);}
    int GetAnhio(){return *(D+2);}
    
};

class Prestamo
{
	int cod_prest;
	int DNI_prest;
	int ID_docprest;
	CDate fec_prest;
	CDate fec_entr;
	
public:
	void llenar_data(){
		string FPrestamo, FDevoluc;
		cout << "Cod. Prestamo: "; cin >> cod_prest;
		cout << "DNI del usuario: "; cin >> DNI_prest;
		cout << "ID del documento: "; cin >> ID_docprest;
		cout << "Fecha de prestamo: "; cin >> FPrestamo;
	}
	
};

//PERSONA --?
class Persona
{
	int DNI;
	string n_apellidos;
public:
	void llenar_data(){
		cout << "DNI: "; cin >> DNI;
		cout << "Nombre: "; cin >> n_apellidos;
	}
	void imprimir_data(){
		cout << "El DNI es: " << DNI << endl;
		cout << "El Nombre y apellido es: " << n_apellidos << endl;
	}	
};

//ALUMNO --?
class Alumno:Persona
{
	int CUI;
public:
	void llenar_data(){
		Persona::llenar_data();
		cout << "CUI: "; cin >> CUI;
	}
	void imprimir_data(){
		Persona::imprimir_data();
		cout << "El CUI es: " << CUI << endl;
	}
};

//PROFESOR --?
class Profesor:Persona
{
	int CDD;
public:
	void llenar_data(){
		Persona::llenar_data();
		cout << "CDD: "; cin >> CDD;
	}
	void imprimir_data(){
		Persona::imprimir_data();
		cout << "El CDD es: " << CDD << endl;
	}
	
};

//DOCUMENTO
class Documento
{
	int ID_Document;
	string Title;
	int numAut;
	string *Autors;
	int stock = 0;
public:
	void llenar_data(){
		cout << "ID del documento: "; cin >> ID_Document;
		cout << "Titulo: "; cin >> Title;
		cout << "Numero de autores: "; cin >> numAut;
		Autors = new string [numAut];
		for(int i=0; i<numAut;i++)
		{
			cout << "Autor Nro." << i+1 << ": ";
			cin >> *(Autors+i);
		}
		stock++;
	}
	void imprimir_data(){
		cout << "ID es: " << ID_Document << endl;
		cout << "Titulo es: " << Title << endl;
		for(int i=0; i<numAut;i++)
			cout << "Autor Nro.: " << *(Autors+i) << endl;
	}	 	
};

class Tesis:Documento
{
	string nom_uni;
	string type_tesis;
public:
	void llenar_data(){
		Documento::llenar_data();
		cout << "Universidad: "; cin >> nom_uni;
		cout << "Tesis para: "; cin >> type_tesis;
	}
	void imprimir_data(){
		Documento::imprimir_data();
		cout << "Universidad es: " << nom_uni << endl;
		cout << "Tesis para: " << type_tesis << endl;
	}
};
class Revista
{
	string editrev;
	string type_rev;
public:
	void llenar_data(){
		Documento::llenar_data();
		cout << "Editorial: "; cin >> editrev;
		cout << "Tipo de Revista: "; cin >> type_rev;
	}
	void imprimir_data(){
		Documento::imprimir_data();
		cout << "Editorial: " << editrev << endl;
		cout << "Tipo: " << type_rev << endl;
	}
	
};

class Libro:Documento
{
	string editlib;
	string type_lib;
public:
	void llenar_data(){
		Documento::llenar_data();
		cout << "Editorial: "; cin >> editlib;
		cout << "Tipo de Libro: "; cin >> type_lib;
	}
	void imprimir_data(){
		Documento::imprimir_data();
		cout << "Editorial: " << editlib << endl;
		cout << "Tipo: " << type_lib << endl;
	}
	
};

class Sistema
{
	Alumno *listalumno[100];
	Profesor *listaprofesor[100];
	Tesis *listatesis[100];
	Revista *listarevista[100];
	Libro *listalibro[100];
	Prestamo *listaprestamo[100];
public:
	Sistema();
	~Sistema();
	
};