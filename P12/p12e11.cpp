#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;

int toInteger(string num){
    int n = 0, p = 0;
    for(int i = num.length()-1; i >= 0; i--){
        n += (toascii(num[i])-48)*(pow(10,p));
        p++;
    }
    return n;
}

class CTime
{
public:
    int *T; //[hh:mm:ss]
    CTime(){
        T = new int [3];
    }
    ~CTime(){
        delete [] T;
    }
    void SetTime(string time){
        string str = "";
        int pos = 0;
        for (int i = 0; i < time.length(); i++)
        {
            str += time[i];
            if (time[i+1] == ':' or i+1 == time.length()){
                T[pos] = toInteger(str);
                str = "";
                pos++;
                i++;
            }
        }
    }
    int GetHoras(){return T[0];}
    int GetMinutos(){return T[1];}
    int GetSegundos(){return T[2];}

    void printFE(){
        if (T[0] <= 12)
            cout << T[0] << ":" << T[1] << ":" << T[2] << " A.M." << endl;
        else
            cout << T[0] - 12 << ":" << T[1] << ":" << T[2] << " P.M." << endl;
    }
    
};
int main(int argc, char const *argv[])
{
    CTime A,B,C;
    A.SetTime("08:16:20");
    B.SetTime("23:46:50");
    cout << A.GetHoras() << endl;
    cout << A.GetMinutos() << endl;
    cout << A.GetSegundos() << endl;
    A.printFE();
    return 0;
}