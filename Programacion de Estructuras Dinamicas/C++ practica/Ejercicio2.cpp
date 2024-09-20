/*Listas enlazadas*/
/*Debes implementar una lista enlazada simple que permita agregar elementos al final de la lista. 
luego imprimir los elementos en el orden en que se agregaron.*/
#include <iostream>
using namespace std;
struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void Insertar_Inicio(int);
void Insertar_Final(int);
void Imprimir_Lista();


int main(){
    int dato;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese un numero: ";
        cin >> dato;
        Insertar_Inicio(dato);
    }
    cout << "Ingrese un numero que ira al final de la linea" << endl;
    cin >> dato;
    Insertar_Final(dato);
    Imprimir_Lista();
    
    return 0;
}

void Insertar_Inicio(int n){
    struct Nodo *Nuevo_Nodo = new Nodo();
    Nuevo_Nodo->dato = n;
    Nuevo_Nodo->siguiente = lista;
    lista = Nuevo_Nodo;

    if (lista == nullptr)
    {
        lista = Nuevo_Nodo;
    }else
    {
        Nuevo_Nodo->siguiente = lista;
        lista = Nuevo_Nodo;
    }
}

void Insertar_Final(int n){
    struct Nodo *Nuevo_Nodo = new Nodo();
    struct Nodo *aux = lista;
    Nuevo_Nodo->dato = n;
    Nuevo_Nodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        lista = Nuevo_Nodo;
    }else{
        while (aux->siguiente != nullptr)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = Nuevo_Nodo;
    }
    
}

void Imprimir_Lista(){
    struct Nodo *aux = lista;
    if (lista != nullptr)
    {
        while (lista != nullptr)
        {
            cout << "Dato: " << aux->dato << endl;
            aux = aux->siguiente;
        }
    }
    else{
        cout << "Lista vacia" << endl;
    }

}