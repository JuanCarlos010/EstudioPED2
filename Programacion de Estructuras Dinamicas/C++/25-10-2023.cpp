#include <iostream>

using namespace std;

#define dimension 7

int valorNumerico;
string caracter;

struct Registro
{
    string dato;
};

struct Nodo
{
    struct Registro registro;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};
// crear una funcion que convierta el char en entero
struct Nodo *lista = nullptr;
struct Nodo *tabla[dimension] = {nullptr};

void Agregar(string);
int F_Hash(int);
struct Nodo *Buscar(string, int);
void BuscarR(string);
void EliminarR(string);
void Imprimir();
int conversor(string);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese un caracter" << endl;
        cin >> caracter;
        cout << conversor(caracter) << endl;
    }

    Agregar(caracter);
    BuscarR(caracter);
    EliminarR(caracter);
}

int conversor(char caracter)
{
    valorNumerico = static_cast<int>(caracter);
    return valorNumerico;
}

void Agregar(string caracter)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = caracter;
    int clave = F_Hash(valorNumerico);
    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];
    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;
    tabla[clave] = nuevoNodo;

    cout << " Dir. nodo " << tabla[clave] << " Indice donde se almacena " << clave << " Dato almacenado " << r.dato << endl;
}

int F_Hash(int valorNumerico)
{
    return valorNumerico % dimension;
}

struct Nodo *Buscar(string caracter, int _clave)
{
    struct Nodo *nuevoNodo = tabla[_clave];
    while (nuevoNodo)
    {
        if (nuevoNodo->registro.dato == caracter)
        {
            return nuevoNodo;
        }
        nuevoNodo = nuevoNodo->siguiente;
    }
    return nullptr;
}

void BuscarR(string caracter)
{
    int clave = F_Hash(valorNumerico);
    struct Nodo *nuevoNodo = Buscar(caracter, clave);
    if (nuevoNodo)
    {
        cout << "Registro encontrado ... Posicion: " << clave << " Valor: " << nuevoNodo->registro.dato << endl;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void EliminarR(string caracter)
{
    int clave = F_Hash(valorNumerico);
    struct Nodo *nuevoNodo = Buscar(caracter, clave);
    if (nuevoNodo)
    {
        cout << "Registro eliminado " << nuevoNodo->registro.dato << endl;
        if (nuevoNodo->siguiente)
        {
            nuevoNodo->siguiente->anterior = nuevoNodo->anterior;
        }
        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }
        else
        {
            tabla[clave] = nuevoNodo->siguiente;
        }

        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }

        delete nuevoNodo;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void Imprimir()
{
    struct Nodo *temporal;
    for (int i = 0; i < dimension; i++)
    {
        temporal = tabla[i];

        while (temporal != nullptr)
        {
            cout << "Indice de almacenamiento " << i << " direccion del indice del arreglo " << tabla[i] << " dir. nodo " << temporal << " dir. nodo anterior" << temporal->anterior << " - " << temporal->registro.dato << endl;
            temporal = temporal->siguiente;
        }
    }
}
