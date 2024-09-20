#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// estructura para guardar los datos del cliente
struct Cliente
{
    string nombre;
    int clave;
} Datos[2];

string Razon;
// Funcion para validar los datos del usuario
bool ValidarDatos(Cliente cliente);
// Funcion para el txt
void Cita();

int main()
{
    // Dejamos ya establecido el ciclo
    bool ciclo = false;
    int regreso;
    // Llamamos a la estructura
    Cliente cliente;
    // Dejamos ya declaradas el usuario principal
    Datos[0].nombre = "Brock";
    Datos[0].clave = 13;

    cout << "==================================================" << endl;
    cout << "||         Bienvenido a clinica Teselia         ||" << endl;
    cout << "==================================================" << endl;
    cout << "Ingrese su nombre de usuario: ";
    cin >> cliente.nombre;
    cout << "Ingrese la clave de su usuario: ";
    cin >> cliente.clave;

    // Llamamos a la funcion
    if (ValidarDatos(cliente) == true)
    {
        do
        {
            cout << "Inicio de sesion correcto";
            int opcion;
            cout << "¿Que desea hacer?" << endl;
            cout << "1) Citas" << endl
                 << "2) Historial medico" << endl
                 << "3) Crear nuevo usuario" << endl;
            cin >> opcion;
            switch (opcion)
            {
            case 1: // Opcion para agendar o cancelar la cita
                int opcion2;
                cout << "Desea" << endl
                     << " 1) reservar " << endl
                     << "2) cancelar una cita" << endl;
                cin >> opcion2;
                if (opcion2 == 1)
                {
                    cout << "Ingrese el motivo de su cita" << endl;
                    cin.ignore();
                    getline(cin, Razon);
                }
                else if (opcion2 == 2)
                {
                    cout << "Ingrese la cita que desea eliminar" << endl;
                }
                break;
            case 2: // Opcion para abrir la carpeta del usuario para revisar su historial medico
                system("Start C:\\Users\\lucky\\OneDrive\\Escritorio\\Pacientes");
                break;
            case 3: // Opcion para crear un nuevo usuario
                cout << "Ingrese el nuevo nombre de usuario" << endl;
                cin >> Datos[1].nombre;
                cout << "Ingrese la nueva clave de usuario" << endl;
                cin >> Datos[1].clave;
                break;
            default:
                cout << "Ingrese una opcion valida";
                break;
            }
            cout << "¿Desea salir del sistema?" << endl
                 << "1)Si 2)No" << endl;
            cin >> regreso;
            if (regreso == 1)
            {
                ciclo = true;
            }
            Cita(); // Llamamos a la funcion que hace los txt de citas medicas
        } while (!ciclo);
    }

    if (ValidarDatos(cliente) == false)
    {
        cout << "Inicio de sesion incorrecto";
    }

    return 0;
}

bool ValidarDatos(Cliente cliente)
{
    for (int i = 0; i < 2; i++)
    {
        if (cliente.nombre == Datos[i].nombre && cliente.clave == Datos[i].clave)
        {
            return true; // Retornara true si los datos ingresados coinciden
        }
    }
    return false; // Retornara falso si no encuentra ninguna coicidencia
}

void Cita()
{
    Cliente cliente;
    ofstream Cita;
    Cita.open("C:\\Users\\lucky\\OneDrive\\Escritorio\\Pacientes\\Cita.txt", ios::out | ios::app);
    if (Cita.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else
    { // imprimira estos datos en el archivo txt
        Cita << "====================================" << endl;
        Cita << "Nombre: " << Datos[0].nombre << endl;
        Cita << "Motivo: " << Razon << endl;
        Cita << "Receta: " << endl;
        Cita << "Doctor: Oak" << endl;
        Cita << "====================================" << endl;
    }
}