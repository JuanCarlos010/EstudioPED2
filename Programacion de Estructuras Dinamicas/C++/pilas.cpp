// Lunes 9 de septiembre de 2023
#include <iostream>
using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};
struct Nodo *pila = nullptr;

void insertar(int);
void EliminarUltimo(int &);
void imprimir();
void vacia();
void UltimoElemento();

int main()
{
    int valor;

    for (int i = 0; i < 4; i++)
    {
        cout << "Ingrese un valor :";
        cin >> valor;
        insertar(valor);
    }
    //vacia();
    /*imprimir();
    EliminarUltimo(valor);
    cout << "--------------------" << endl;
    imprimir();
    cout << "--------------------" << endl;
    UltimoElemento();*/
    cout << "----" << endl;
    cout << pila->siguiente->siguiente->elemento << "-" << pila->siguiente->siguiente;
    return 0;
}

void insertar(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    // asignar valor
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

void imprimir()
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        cout << "Elementos de la pila :" << temporal->elemento << endl;
        temporal = temporal->siguiente;
    }
}

void EliminarUltimo(int &n)
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        n = temporal->elemento;
        pila = temporal->siguiente;
        delete temporal;
    }
}

void vacia(){
    if (pila == nullptr)
    {
        cout << "La pila esta vacia";
    }   
}

void UltimoElemento(){
    cout << pila->elemento << " - " << pila;
}