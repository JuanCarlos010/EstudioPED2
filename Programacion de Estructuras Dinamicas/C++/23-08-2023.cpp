#include <iostream>
using namespace std;

int incrementoPorValor(int i);
int incrementoPuntero(int *i);
int incrementoReferencia(int &i);
void cambioVariable(int *n, int *m);
float calculadora (int x, int y, int &suma, int &resta, int&multiplicacion);

int main()
{
    int suma = 0;
    int resta = 0;
    int multiplicacion = 0;
    /*int i = 4;
    cout << i << endl;
    cout << incrementoPorValor(i) << endl;
    cout << i << endl;
    cout << incrementoPuntero(&i) << endl;
    cout << i << endl;
    cout << incrementoReferencia(i) << endl;
    cout << i << endl;*/
    /*int n = 3;
    int m = 5;
    cout << n << endl;
    cout << m << endl;
    cambioVariable(&n, &m);
    cout <<"Cambio: " << endl;
    cout << n << endl;
    cout << m << endl;*/

    float calculadora (3, 5, suma, resta, multiplicacion);
    cout << "suma" << suma << endl;
    cout << "resta" << resta << endl;
    cout << "Multiplicacion" << multiplicacion << endl;
    return 0;
}

int incrementoPorValor(int i)
{
    return i += 3;
}

int incrementoPuntero(int *i)
{
    return *i += 1;
}

int incrementoReferencia(int &i)
{
    return i += 1;
}

//(1) crear una funcion que cambie el valor de dos variables entre ellas
void cambioVariable(int *n, int *m)
{
    int cambio = *n;
    *n = *m;
    *m = cambio;
}

//(2) devolver varios valores usando referencia

float calculadora (int x, int y, int &suma, int &resta, int &multiplicacion)
{
    suma = x + y;
    resta = x - y;
    multiplicacion = x * y;
}