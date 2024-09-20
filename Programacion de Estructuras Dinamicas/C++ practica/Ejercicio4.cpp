/*COLAS*/
/*Ejercicio: Hacer un prgrama que contenga el siguiente menu
1: Insertar caracter a la cola
2: mostrar los elementos de la cola
3: salir*/

#include <iostream>
using namespace std;

struct Nodo
{
    char dato;
    struct Nodo *siguiente;
};
struct Nodo *frente_cola = nullptr;
struct Nodo *final_cola = nullptr;

void Insertar_Dato(char);
void Imprimir();
bool Vacia();
int main()
{
    return 0;
}

bool Vacia(){
    if (frente_cola == nullptr)
    {
        return true;
    }else{
        return false;
    }
}

void Insertar_Dato(char n)
{
    struct Nodo *Nuevo_Nodo = new Nodo();
    Nuevo_Nodo->dato = n;
    Nuevo_Nodo->siguiente = nullptr;
    if (Vacia())
    {
        frente_cola = Nuevo_Nodo;
    }else{
        final_cola->siguiente = Nuevo_Nodo;
    }
    final_cola = Nuevo_Nodo;
}
