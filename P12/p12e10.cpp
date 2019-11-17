#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Text
{
public:
    string str;
    Text(){
        str = "";
    }
    Text(string namefile)
    {
        str = "";
        ifstream txtfile(namefile);
        if (txtfile.fail())
            cout << "Error al abrir " << namefile << endl;
        else
        {
            while(!txtfile.eof())
            {
                char paragraph[1000]; //parrafo de 1000 caracteres a lo mucho
                txtfile.getline(paragraph, sizeof(paragraph));
                str += paragraph;
                str += '\n';
            }
        }
        txtfile.close();
    }
    string contents(){
        return str;
    }
    
};

int main(int argc, char const *argv[])
{
    Text txt("texto.txt");
    cout << txt.contents() << endl;    
    return 0;
}