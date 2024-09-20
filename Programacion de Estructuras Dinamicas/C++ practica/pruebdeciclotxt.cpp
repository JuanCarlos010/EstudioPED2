#include <iostream>
#include <fstream>
using namespace std;

void imprimir();
int  x;


int main(){
    do
    {
        imprimir();
        cout << "Desea terminar el ciclo?" << endl;
        cin >> x;
    } while (x != 2);
    
    
    return 0;
}

void imprimir(){
    static int i = 0;
    ofstream prueba;

    prueba.open("Prueba.txt", ios::out | ios::app);

    if (prueba.fail() == true)
    {
        cout << "prueba fallo";

    }else{
        prueba << "Esta cita llego en la posicion: " << i << endl;

    }
    i++;
}