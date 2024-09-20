// Listas doblemente enlazadas
/*Ejercicio: Debes implementar una lista doblemente enlazada que permita agregar, eliminar y buscar elementos en la lista.
Además, debes implementar una función para imprimir los elementos de la lista en orden ascendente y en orden descendente.*/

#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};
struct Nodo *lista = nullptr;

void Insertar_Inicio(int);
void Insertar_Final(int);
void Buscar(int);
void Eliminar(int);
void Ordenar_Creciente();
void Ordenar_Decreciente();

int main()
{
    int dato, vuelta, vuelta2;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese un numero: ";
        cin >> dato;
        Insertar_Inicio(dato);
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Ingrese un numero que ira al final de la lista: ";
        cin >> dato;
        Insertar_Final(dato);
    }
    cout << "Desea buscar algun numero?(1. Si 2. No)" << endl;
    cin >> vuelta;
    if (vuelta == 1)
    {
        cout << "Que numero desea buscar?" << endl;
        cin >> dato;
        Buscar(dato);
    }
    cout << "Desea eliminar algun numero(1.Si 2.No)" << endl;
    cin >> vuelta2;
    if (vuelta2 == 1)
    {
        cout << "Que numero desea eliminar?" << endl;
        cin >> dato;
        Eliminar(dato);
    }
    Ordenar_Creciente();
    Ordenar_Decreciente();


    return 0;
}

void Insertar_Inicio(int n)
{
    struct Nodo *Nuevo_Nodo = new Nodo();
    struct Nodo *aux = lista;
    Nuevo_Nodo->dato = n;
    Nuevo_Nodo->siguiente = nullptr;
    Nuevo_Nodo->anterior = nullptr;

    if (lista == nullptr)
    {
        lista = Nuevo_Nodo;
    }
    else
    {
        Nuevo_Nodo->siguiente = lista;
        lista->anterior = Nuevo_Nodo;

        lista = Nuevo_Nodo;
    }
}

void Insertar_Final(int n)
{
    struct Nodo *Nuevo_Nodo = new Nodo();
    struct Nodo *aux = lista;
    Nuevo_Nodo->dato = n;
    Nuevo_Nodo->anterior = nullptr;
    Nuevo_Nodo->siguiente = nullptr;
    if (lista == nullptr)
    {
        lista = Nuevo_Nodo;
    }
    else
    {
        while (aux->siguiente != nullptr)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = Nuevo_Nodo;
        Nuevo_Nodo->anterior = aux;
    }
}

void Eliminar(int n)
{
    Nodo *aux = lista;
    while (aux != nullptr && aux->dato != n) {
        aux = aux->siguiente;
    }
    if (aux == nullptr) {
        return;
    }
    if (aux->anterior != nullptr) {
        aux->anterior->siguiente = aux->siguiente;
    } else {
        lista = aux->siguiente;
    }
    if (aux->siguiente != nullptr) {
        aux->siguiente->anterior = aux->anterior;
    }
    delete aux;
}

void Buscar(int n)
{
    struct Nodo *aux = lista;
    bool encontrado = false;

    while (aux != nullptr)
    {
        if (n == aux->dato)
        {
            cout << "Dato Encontrado: " << aux->dato << endl;
            encontrado = true;
        }
        aux = aux->siguiente;
    }

    if (!encontrado)
    {
        cout << "El dato " << n << " no fue encontrado en la lista." << endl;
    }
}

void Ordenar_Creciente()
{
    struct Nodo *aux = lista;
    if (aux == nullptr)
    {
        cout << "Lista vacia" << endl;
        return;
    }
    cout << "Orden ascendente: ";
    while (aux != nullptr)
    {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

void Ordenar_Decreciente(){
    struct Nodo *aux = lista;
    if (aux == nullptr) {
        cout << "Lista vacía" << endl;
        return;
    }
    cout << "Orden descendente: ";
    while (aux->siguiente != nullptr) {
        aux = aux->siguiente;
    }
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->anterior;
    }
    cout << endl;
}