// Reserva de memoria
#include <iostream>
using namespace std;

int main()
{
    /*int *ptr;
    ptr = (int*)malloc(100*sizeof(int));
    free(ptr);*/

    int *edad, numEdad;
    //(arreglo estatico)edad[numEdad];
    edad = new int[numEdad];

    cout << "Cuantas edades se registraran?" << endl;
    cin >> numEdad;

    for (int i = 0; i < numEdad; i++)
    {
        cout << "Ingrese la edad: ";
        cin >> edad[i];
    }

    delete [] edad;
    return 0;
}

// anotaciones
// int *ptr = new int
/*if (ptr == NULL)
{
    cout << "Error de asignacion de memoria";
}else{
    cout << "Direccion de memoria " << ptr;
}*/