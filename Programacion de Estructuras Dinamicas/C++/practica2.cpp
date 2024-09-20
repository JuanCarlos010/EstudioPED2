#include <iostream>
using namespace std;

void calculartiquet(float cant, float precio, float &desc, float &tf);
int main()
{
    float cant;
    float precio = 35.25;
    float desc = 0.20;
    float tf;
    float descuento = precio * desc;
    cout << "Ingrese cantidad del producto: ";
    cin >> cant;
    cout << endl;
    cout << "El descuento es de :";
    cout << descuento << endl;
    cout << "El total final es de :";
    calculartiquet(cant, precio, desc, tf);
    cout << tf;
    return 0;
}

void calculartiquet(float cant, float precio, float &desc, float &tf)
{
    tf = (precio - (desc * precio)) * cant;
}