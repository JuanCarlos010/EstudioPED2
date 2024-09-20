//Pilas
/*Ejercicio 1: hacer una pila que pueda agregar tantos numeros hasta que el usuario diga que no, luego
mostrar al usuario los datos que el mismo agrego*/
#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};
struct Nodo *pila = nullptr;

void agregar_dato(Nodo *&, int);
void mostrar_dato(Nodo *&, int &);

int main(){
    int dato, rpt;
    do
    {
        cout << "Ingrese un numero a la pila" << endl;
        cin >> dato;
        agregar_dato(pila, dato);

        cout << "Desea agregar otro dato a la pila" << endl << "1: Si, 2: No" << endl;
        cin >> rpt;
    } while (rpt == 1);
    
    cout << "Sacando los valores de la pila ..." << endl;

    while (pila != nullptr)
    {
        mostrar_dato(pila, dato);
        if (pila != nullptr)
        {
            cout << dato << " , ";
        }else{
            cout << dato <<".";
        }
        
    }
    return 0;
}

void agregar_dato(Nodo *&pila, int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;

    cout << endl << "Elemento " << n << " agregado exitosamente";
}

void mostrar_dato(Nodo *&pila, int &n){
    Nodo *temporal = pila;
    n = temporal->dato;
    pila = temporal->siguiente;
    delete temporal;
}