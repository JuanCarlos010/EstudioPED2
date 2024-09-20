#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct bolsaValores
{
    string empresa[3] = {Wendys, mcdonalds, kfc};
    float compra;
    float venta;
} valor;

void leerbolsa(float &actual);
void registrobolsa(struct bolsaValores &b);

int main()
{
    return 0;
}

void leerbolsa(float &actual)
{
}