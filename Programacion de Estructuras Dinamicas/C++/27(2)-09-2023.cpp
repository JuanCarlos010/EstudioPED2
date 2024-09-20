#include <iostream>
using namespace std;

void insertarinicio(int n);
void insertarfinal(int n);
void InsertarIntermedio(int n, int posicion)
void eliminarmedio(int n);
void eliminar(int);
struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

// Variable global,, donde se establece que la lista esta vacia
struct Nodo *lista = nullptr;

int main(){
    
    
    return 0;
}
void insertarinicio(int n){

    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }else{
        //conexion del neuvo nodo con la lista
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        //asignar nuevo nodo a la cabeza de la lista
        lista = nuevoNodo;
    }
}

void insertarfinal(int n){
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }else{
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevoNodo;
        neuvoNodo->anterior = temporal;
    }
}

void insertarmedio(int n, int posicion){
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
}

void eliminarmedio(int n){
    int posicion;
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    struct Nodo *temporal3;

    posicion--;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        temporal3 = temporal->siguiente;
        posicion--;
    }
    //Conexiones del nuevoNodo con la lista 
    temporal2->siguiente = temporal3;
    temporal3->anterior = temporal2;
    delete temporal;
    temporal = nullptr;
}

void InsertarIntermedio(int n, int posicion)
{

    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    //Conexiones del nuevoNodo con la lista 
    temporal2 = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
    temporal2->anterior = nuevoNodo;
    nuevoNodo->siguiente = temporal2;
    nuevoNodo->anterior = temporal;
}

void eliminar(int pos){
    struct Nodo *aux = lista;
    int i = 1;
    while (aux != nullptr && i < pos)
    {
        aux = aux->siguiente;
        i++;
    }
    
    if (aux != nullptr)
    {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;
    }else{
        cout << "No se encontro";
    }
}    