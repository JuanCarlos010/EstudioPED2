#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};
int Razon;
void InsertarInicio();
void InsertarFinal();
void InsertarIntermedio();
void Imprimir();
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio();
void EliminarNodo();
void Eliminar();

int main()
{
    int opcion2;
    cout << "Desea 1) reservar" << endl << "2) cancelar una cita" << endl;
    cin >> opcion2;
    if (opcion2 == 1)
    {
        cout << "Ingrese el motivo de su cita" << endl;
        getline(cin, Razon);
    }
    else if (opcion2 == 2)
    {
        cout << "Ingrese la cita que desea " << endl;
    }
    return 0;
}

void InsertarInicio()
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal = lista;

    nuevoNodo->elemento = ;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    // Si la lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
    }
    else
    {
        // conexion del nuevo nodo con la lista
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        // asignar el nuevonodo a la cabeza de la lista
        lista = nuevoNodo;
    }
}
