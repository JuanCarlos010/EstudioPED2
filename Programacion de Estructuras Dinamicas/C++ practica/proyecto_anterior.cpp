#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include "MasterLibrary.hpp"
#include <cstdlib>
#include <unordered_map>
using namespace std;

// Estructuras:

struct Credenciales // Estructura para almacenar las credenciales de los empleados
{
    string username;
    int password;
} credenciales[2]; // arreglo de structura

struct Selector1 // Estructura para guardar los datos de la comida
{
    int cantidad;
    float precio;
    string comida;
} selector;

struct Selector2 // Estructura para guardar los datos de las bebidas
{
    float precio2;
    int cantidad2;
    string bebida;
} selector2;

// Apartado de la declaración de funciones:

// Función de inicio de sesión
bool inicioSesion(string infouser, int infopass, struct Credenciales credenciales[]);

// Función para mostrar el menú
void escribir();

// Función para registrar una venta
void registrarVenta();

// Función para generar recibo del usuario
void recibo();

// Función para calcular total
float Total();

// Función para limpiar la terminal en sistemas Windows
void limpiarTerminal();

// Función para mostrar el contenido de un archivo en la terminal
void mostrarContenidoArchivo(const string &nombreArchivo);

// Función para obtener la comida más vendida
string obtenerComidaMasVendida(const unordered_map<string, int> &ventas);

// Función para obtener las ventas diarias
unordered_map<string, int> obtenerVentasDiarias();

// Función para guardar la comida más vendida en un archivo
void guardarComidaMasVendida(const string &nombreArchivo, const string &comidaMasVendida);

// Función para generar el registro de comidas más vendidas
void generarRegistroComidasMasVendidas(const string &nombreArchivo);

// Variables globales:

string slogan = "El sabor que conquista corazones, Sabor Casero: donde cada bocado es un hogar en tu paladar.";
int seleccion;
int alimento;
int seleccion2;
bool respuestaSalirSistema = true;
bool validacion = false; // la expresion booleana permitirá saber si estan correctas las credenciales

int main()
{
    cout << "===============================================SABOR CASERO===============================================" << endl;
    cout << slogan << endl;

    Credenciales credenciales[2]; // definir variable

    // inicializar los valores de los miembros
    credenciales[0].username = "denisemgiron";
    credenciales[0].password = 1234;
    credenciales[1].username = "juancarlos";
    credenciales[1].password = 12345;

    // con estas variables se van a guardar el usuario y contrasenia
    string infouser;
    int infopass;

    cout << "*************************Bienvenidos al sistema de Sabor Casero*************************" << endl;

    cout << "*************************Inicio de sesion del Administrador*************************" << endl;
    cout << "Ingrese su usuario" << endl;
    cin >> infouser;
    cout << "Ingrese su clave" << endl;
    cin >> infopass;

    // llamar a la funcion
    if ((inicioSesion(infouser, infopass, credenciales)) == true)
    {
        cout << "Inicio de sesion correcto" << endl;
        system("pause"); // Esperara que el usuario accione en la terminal

        do
        {

            escribir(); // LLama a la funcion para el menú

            int vuelta;
            cout << "----------------------Nueva venta----------------------" << endl;
            cout << "¿Cuantas personas van a ordenar?" << endl;

            cin >> vuelta;
            for (int i = 0; i < vuelta; i++) // este ciclo sera para que el usuario ingrese la cantidad de comida que desea
            {
                cout << "Ingrese el tipo de comida que desee" << endl;
                cout << "1)Desayuno 2) Hamburguesas 3) Comida mexicana" << endl;
                cin >> seleccion;
                switch (seleccion) // Hacemos este switch para que el usuario decida que sección desea
                {
                case 1:
                    cout << "Usted ha seleccionado Desayuno, ingrese su comida" << endl;
                    cout << "1) pupusas 2) Tipicos" << endl;
                    cin >> alimento;
                    switch (alimento) // menu para que pueda seleccionar su comida de la seccion del desayuno
                    {
                    case 1:
                        selector.precio = 0.60;
                        selector.comida = "Pupusas";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 2:
                        selector.precio = 1.60;
                        selector.comida = "Tipicos";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        ;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    default:
                        cout << "Opcion no valida";
                        break;
                    }
                    break;
                case 2:
                    cout << "Usted ha seleccionado hamburguesas, ingrese su comida" << endl;
                    cout << "1) Clasicas 2)Cheese Burguer 3) BBQ Burguer" << endl;
                    cin >> alimento;
                    switch (alimento) // menu para que pueda seleccionar su comida de la seccion de hamburguesas
                    {
                    case 1:
                        selector.precio = 3.00;
                        selector.comida = "Clasicas";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 2:
                        selector.precio = 4.00;
                        selector.comida = "Cheese Burguer";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 3:
                        selector.precio = 4.00;
                        selector.comida = "BBQ Burguer";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    default:
                        cout << "opcion no valida";
                        break;
                    }
                    break;
                case 3:
                    cout << "Usted ha seleccionado comida mexicana, ingrese su comida" << endl;
                    cout << "1) Tortas de pastor 2) Tortas de res 3) Tacos de pollo 4) Big burrito res" << endl;
                    cin >> alimento;
                    switch (alimento) // menu para que pueda seleccionar su comida de la seccion de comida mexicana
                    {
                    case 1:
                        selector.precio = 3.00;
                        selector.comida = "Tortas de pastor";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 2:
                        selector.precio = 3.25;
                        selector.comida = "Tortas de res ";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 3:
                        selector.precio = 3.00;
                        selector.comida = "Tacos de pollo ";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    case 4:
                        selector.precio = 4.00;
                        selector.comida = "Big burrito res ";
                        cout << "Usted ha seleccionado " << selector.comida << ", ingrese la cantidad" << endl;
                        cin >> selector.cantidad;
                        total = selector.precio * selector.cantidad;
                        break;
                    default:
                        cout << "opcion no valida";
                        break;
                    }
                    break;
                default:
                    cout << "opcion no valida";
                    break;
                }
                cout << "Ingrese la bebida que desee" << endl;
                cout << "1)Soda 2) Cafe" << endl;
                cin >> seleccion2;
                switch (seleccion2) // menu para que el usuario pueda decidir la bebida que quiera consumir
                {
                case 1:
                    selector2.precio2 = 0.75;
                    selector2.bebida = "Soda";
                    cout << "Usted ha seleccionado " << selector2.bebida << ", ingrese la cantidad" << endl;
                    cin >> selector2.cantidad2;
                    total2 = selector2.precio2 * selector2.cantidad2;
                    break;
                case 2:
                    selector2.precio2 = 0.60;
                    selector2.bebida = "Cafe";
                    cout << "Usted ha seleccionado " << selector2.bebida << ", ingrese la cantidad" << endl;
                    cin >> selector2.cantidad2;
                    total2 = selector2.precio2 * selector2.cantidad2;
                    break;
                default:
                    cout << "opcion no valida";
                    break;
                }
                limpiarTerminal();
                recibo();         // Llamar a la funcion del recibo
                registrarVenta(); // Llamar función para registrar venta

                string nombreArchivo2 = "registro_comidas.txt";
                generarRegistroComidasMasVendidas(nombreArchivo2);

                // Apartado para mostrar algun archivo en la terminal
                string nombreArchivo;
                int respuestaUsuario;

                cout << "Desea ver algun archivo en concreto en la terminal" << endl;
                cout << "1-Si, 2-No" << endl;
                cin >> respuestaUsuario;

                if (respuestaUsuario == 1)
                {
                    cout << "Ingrese el nombre del archivo que desea ver (recuerde utilizar .txt al final)" << endl;
                    cin >> nombreArchivo;
                    mostrarContenidoArchivo(nombreArchivo);
                }

                int respuestaUsuario2;

                cout << "¿Desea salir del sistema?" << endl;
                cout << "1-Si, 2-No" << endl;
                cin >> respuestaUsuario2;

                if (respuestaUsuario2 == 1)
                {
                    respuestaSalirSistema = false;
                }
            }
        } while (respuestaSalirSistema != false);
    }
    else
    {
        cout << "Inicio de sesion incorrecto" << endl;
    }

    return 0;
}

// Apartado de la definición de las funciones

// Definir función para el inicio de sesión
bool inicioSesion(string infouser, int infopass, struct Credenciales credenciales[])

{
    /*cout << infouser;
    cout << infopass << "\n";*/

    for (int i = 0; i < 2; i++)
    {
        /*cout<<credenciales[i].username<<endl;
        cout<<credenciales[i].password<<endl;*/

        if (infouser == credenciales[i].username && infopass == credenciales[i].password)
        {
            validacion = true;
        }
    }
    return validacion;
}

// Definir funcion para generar el archivo txt
void escribir()
{
    ofstream archivo;

    archivo.open("menu.txt", ios::out | ios::app); // Abrir archivo

    if (archivo.fail() == true)
    {
        cout << "No se puede abrir el archivo"; // si falla se mostrará este mensaje
        exit(1);                                // Si el programa falla esto hara que se detenga
    }
    archivo << "=========================================================Menu========================================================= " << endl; // Imprimira el mensaje en le archivo txt
    archivo << "****************************************************Desayunos****************************************************" << endl;
    archivo << "Pupusas $0.60" << endl;
    archivo << "Tipicos $1.60" << endl;
    archivo << "***************************************************Hamburguesas***************************************************" << endl;
    archivo << "Clásica $3.00" << endl;
    archivo << "Cheese burger $4.00" << endl;
    archivo << "BBQ burger $4.00" << endl;
    archivo << "***************************************************Comida mexicana***************************************************" << endl;
    archivo << "Tortas pastor $3.00" << endl;
    archivo << "Tortas de res $3.25" << endl;
    archivo << "Tacos de pollo  $3.00" << endl;
    archivo << "Big burrito res $4.00" << endl;
    archivo << "Soda en lata $0.75" << endl;
    archivo << "Café $0.60" << endl;

    archivo.close(); // cierra el archivo
}

void limpiarTerminal()
{
    system("cls");
}

// Definir función que genera el recibo
void recibo()
{
    ofstream tiquete;

    tiquete.open("tiquete.txt", ios::out | ios::app);
    if (tiquete.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else // imprimira estos datos en el archivo txt
    {
        tiquete << "============================"
                << "\n";
        tiquete << endl;
        tiquete << "* Comida        " << selector.comida << "(" << selector.cantidad << ")"
                << "\n"; // El parentesis demuestra la cantidad de producto que se ha seleccionado
        tiquete << endl;
        tiquete << "* Precio unidad $" << selector.precio << "\n";
        tiquete << endl;
        tiquete << "* Bebida        " << selector2.bebida << "(" << selector2.cantidad2 << ")"
                << "\n";
        tiquete << endl;
        tiquete << "* Precio unidad $" << selector2.precio2 << "\n";
        tiquete << endl;
        tiquete << "* Total         $" << Total() << "\n";
        tiquete << endl;
        tiquete << "============================"
                << "\n";
    }
}

// Definir función para registrar una venta
void registrarVenta()
{

    // Obtener fecha actual
    time_t tiempoActual = time(nullptr);
    tm *fechaActual = localtime(&tiempoActual);

    // Generar el nombre del archivo con el formato "día, mes, año.txt"
    string nombreArchivo = "Registro_venta-" +
                           to_string(fechaActual->tm_mday) + "-" +
                           to_string(fechaActual->tm_mon + 1) + "-" +
                           to_string(fechaActual->tm_year + 1900) + ".txt";
    // tm_mday hace que demuestre el dato del dia en numero
    // como el contador de mes es de rango 0 - 11 se agrega un +1 para que sea mas exacta el numero del mes
    // como el contador del año es de 1900 en adelante, se agrega el +1900 para que pueda ser mas exacto en el numero del año

    // Abrir archivo en modo escritura
    ofstream archivo(nombreArchivo, ios::out | ios::app);

    // Verificar que el archivo abre correctamente
    if (archivo.is_open())
    {

        // Escribir datos de la venta
        archivo << "---------------------------" << endl;
        archivo << "Producto: " << selector.comida << endl;
        archivo << "Precio: " << selector.precio << endl;
        archivo << "Cantidad: " << selector.cantidad << endl;
        archivo << "Bebida: " << selector2.bebida << endl;
        archivo << "Precio: " << selector2.precio2 << endl;
        archivo << "Cantidad: " << selector2.cantidad2 << endl;
        archivo << "Total: $" << Total() << endl;
        archivo << "---------------------------" << endl;

        // Cerrar archivo
        archivo.close();

        cout << "La venta ha sido registrada correctamente en el archivo " << nombreArchivo << endl;
    }
    else
    {

        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
    }
}

// Definir función para mostrar el contenido de un archivo en la terminal
void mostrarContenidoArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);

    if (archivo.is_open())
    {
        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
    else
    {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
}

// Definir función para obtener la comida más vendida
string obtenerComidaMasVendida(const unordered_map<string, int> &ventas)
{
    string comidaMasVendida;
    int maxVentas = 0;

    for (const auto &par : ventas)
    {
        if (par.second > maxVentas)
        {
            maxVentas = par.second;
            comidaMasVendida = par.first;
        }
    }

    return comidaMasVendida;
}

// Definir función para obtener las ventas diarias
unordered_map<string, int> obtenerVentasDiarias()
{
    unordered_map<string, int> ventasDiarias;

    string producto = selector.comida;
    int cantidad = selector.cantidad;

    // Verificar si el producto ya existe en el mapa
    if (ventasDiarias.count(producto) == 0)
    {
        // Si no existe, agregarlo al mapa con la cantidad actual
        ventasDiarias[producto] = cantidad;
    }
    else
    {
        // Si existe, sumar la cantidad actual a la cantidad existente
        ventasDiarias[producto] += cantidad;
    }

    return ventasDiarias;
}

// Definir función para guardar la comida más vendida en un archivo
void guardarComidaMasVendida(const string &nombreArchivo, const string &comidaMasVendida)
{
    ofstream archivo(nombreArchivo, ios::out | ios::app);

    if (archivo.is_open())
    {
        archivo << "Comida más vendida: " << comidaMasVendida << endl;
        archivo.close();

        cout << "La informacion de la comida mas vendida se ha guardado en el archivo " << nombreArchivo << endl;
    }
    else
    {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
    }
}

// Definir función para generar el registro de comidas más vendidas
void generarRegistroComidasMasVendidas(const string &nombreArchivo)
{
    unordered_map<string, int> ventasDiarias = obtenerVentasDiarias();

    string comidaMasVendida = obtenerComidaMasVendida(ventasDiarias);

    guardarComidaMasVendida(nombreArchivo, comidaMasVendida);
}