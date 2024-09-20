#include <iostream>
#include <string>

using namespace std;

int main() {
    string miCadena;  // Declaración de una variable de tipo string

    cout << "Ingresa una cadena con espacios: ";
    getline(cin, miCadena);  // Permite al usuario ingresar una cadena con espacios

    cout << "La cadena ingresada es: " << miCadena << endl;

    return 0;
}