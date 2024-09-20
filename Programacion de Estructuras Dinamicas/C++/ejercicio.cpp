#include <iostream>
using namespace std;

int main(){
    int count;

    string *Lugar_Turistico;
    Lugar_Turistico = new string [count];

    string *pais, count2;
    pais = new string [count];

    cout << "Cuantos regsitros?" << endl;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Ingrese el lugar turistico: ";
        cin >> Lugar_Turistico[i]; 
        cout << "Ingrese el pais: ";
        cin >> pais[i];
    }
    delete [] Lugar_Turistico;
    delete [] pais;
    
    return 0;
}