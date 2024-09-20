#include <iostream>
using namespace std;
int i;
int j;
struct Producto
{
    string nombre;
    float precio;
} producto;
void Informacion();
// void ShowInformacion();
struct Informacion
{
    string name;
    float price;
    string categoria[j];
} informacion[3];

int main()
{
    /*struct Producto *ptr;
    ptr = &producto;
    // acceder a los miembros de la estructura
    ptr->nombre = "Cuaderno";
    ptr->precio = 1.25;

    cout << ptr->nombre << "-" << ptr->precio;*/
    void Informacion();
    struct Informacion *ptr;
    ptr = Informacion;
    ptr->name;
    ptr->price;
    ptr->categoria[j];
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el nombre del producto";
        cin >> ptr->name;
        cout << "ingrese el precio del producto";
        cin >> ptr->price;
        for (int j = 0; i < 2; j++)
        {
            cout << "Ingrese el nombre de la categoria";
            cin >> ptr.categoria[j];
        }
        
    }

    return 0;
}

// una funcion que me permita almacenar la informacion de 3 productos y a su vez imprima la informacion

/*void Informacion()
{
    struct Informacion *ptr;
    ptr = *Informacion;
    ptr->name;
    ptr->price;
    ptr->categoria;
}*/