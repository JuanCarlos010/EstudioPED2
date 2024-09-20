#include <iostream>
using namespace std;
#define tam 7

struct Registro{
    int dato;
};
struct Nodo{
    struct Registro registro;
    struct Nodo *anterior, *siguiente;
}

struct Nodo *tabla[tam] = {nullptr}
struct Nodo *lista = nullptr;
void EliminarR(int);
void agregar(int);
int F_Hash(int);
struct Nodo *Busca;
void Imprimir();
int main(){
    return 0;
}

void agregar(int _dato){
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = _dato;
    int clave = F_Hash(_dato);
    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];
    if (tabla[clave])
    {
        tabla[clave]->anterior = nuevoNodo;
        tabla[clave] = nuevoNodo;

        cout << "Direccion " << tabla[clave] << " Indice donde se almacena " << 
    }
    
    
}

int F_Hash(int _dato){

}

void Imprimir(){
    struct Nodo *temporal;
    for (int i = 0; i < tam; i++)
    {
        temporal = tabla[i];
        if (temporal != nullptr)
        {
            while (temporal != nullptr)
            {
                cout << "Indice de almacenamiento " << i << " direccion";
                temporal = temporal->siguiente
            }
            
        }
        
    }
    
}
struct Nodo *buscar(int _dato, int _clave){
    struct Nodo *nuevoNodo = tabla[_clave];
    while (nuevoNodo)
    {
        if (nuevoNodo->registro.dato == _dato)
        {
            return nuevoNodo;
        }
        
    }
    
}
void EliminarR(int _dato){
    int clave = F_Hash(_dato);
    struct Nodo *nuevoNodo = Buscar()
}