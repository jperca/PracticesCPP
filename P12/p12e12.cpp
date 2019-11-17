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

int CompararFechas(CDate F1, CDate F2)
{
    if (F1.GetAnhio() > F2.GetAnhio())
        return 1;
    else if (F1.GetAnhio() < F2.GetAnhio())
        return -1;
    else
    {
        if (F1.GetMes() > F2.GetMes())
            return 1;
        else if (F1.GetMes() < F2.GetMes())
            return -1;
        else
        {
            if (F1.GetDia() > F2.GetDia())
                return 1;
            else if (F1.GetDia() < F2.GetDia())
                return -1;
            else
                return 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    CDate D1, D2;
    D1.SetDate("01/11/80");
    D2.SetDate("01/11/80");
    D1.IncrementarFecha(10);
    cout << D1.GetDia() << endl;
    cout << D1.GetMes() << endl;
    cout << D1.GetAnhio() << endl;
    cout << CompararFechas(D1,D2) << endl;
    return 0;
}