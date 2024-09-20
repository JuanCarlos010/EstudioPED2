#include <iostream>
using namespace std;
float calculadora (int x, int y, int &suma, int &resta, int&multiplicacion);
int main()
{  
    int suma = 0;
    int resta = 0;
    int multiplicacion = 0;
    float calculadora (3, 5, suma, resta, multiplicacion);
    cout << "suma" << suma << endl;
    cout << "resta" << resta << endl;
    cout << "Multiplicacion" << multiplicacion << endl;
    return 0;
}

float calculadora (int x, int y, int &suma, int &resta, int&multiplicacion)
{
    suma = x + y;
    resta = x - y;
    multiplicacion = x * y;
}