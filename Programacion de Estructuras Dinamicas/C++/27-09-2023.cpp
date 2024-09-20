#include <iostream>
using namespace std;
// Tema: listas (creo)

void eliminarmedio(int);
// Declaración de funciones
void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void Imprimir();
void EliminarInicio();
void EliminarFinal();

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

int main()
{
    InsertarInicio(45);
    InsertarInicio(5);
    InsertarInicio(4);
    InsertarFinal(48);
    InsertarFinal(79);
    InsertarIntermedio(400, 2);
    Imprimir();
    cout << "------------------------------------------------" << endl;
    eliminarmedio(3);

    return 0;
}

void eliminarmedio(int)
{
    int posicion;
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        // posicion--;
    }
    temporal2->siguiente = temporal->siguiente;
    temporal->siguiente = temporal2;
    delete temporal;
    temporal = nullptr;
}

void InsertarInicio(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al inicio
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
}

// Insertar nodo al final de la lista
void InsertarFinal(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    // Si la lista esta vacia se agrega el primer nodo
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // Agregar un nodo al final
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
    }
}

void InsertarIntermedio(int n, int posicion)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;

    posicion--;

    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        cout << "Lista vacia";
    }
}