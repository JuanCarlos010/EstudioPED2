#include <iostream>
using namespace std;

int main()
{
    int count = 0;

    string *Lugar_Turistico;
    string *pais;

    cout << "Cuantos regsitros?" << endl;
    cin >> count;

    Lugar_Turistico = new string[count];
    pais = new string[count];
    
    for (int i = 0; i < count; i++)
    {
        cout << "Ingrese el lugar turistico: ";
        cin >> Lugar_Turistico[i];
        cout << "Ingrese el pais: ";
        cin >> pais[i];
    }
    delete[] Lugar_Turistico;
    delete[] pais;

    return 0;
}