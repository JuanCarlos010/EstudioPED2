#include <iostream>
using namespace std;

struct Gasolinera
{

    float Cantidad;
} gasolina, diesel;

void Aumentar_Cantidad(struct Gasolinera &g);
void leergas(float &actual)

int main()
{

    return 0;
}

void Aumentar_Cantidad(struct Gasolinera &g)
{
float actual = 0;
    leergas(actual);
    cout << "Gasolina depositada: " << actual << "\n";
    g.Cantidad = g.Cantidad + actual;
}
void leergas(float &actual)
{
    int t = time(NULL);
    srand(t);
    actual = rand() % (48 + 1);
}