
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// structs

struct DatosPaciente
{
    int edad;
    int nivelUrgencia;
    int dui;
    int clave;
    bool atendido;
    string motivoCita;
    string urgencia;
    string receta;
};

struct fecha{
    int dia, mes, anio;
};

struct Cliente // estructura para guardar los datos del cliente
{
    string nombre, razon;
    int clave, DUI, Edad;
};
vector<Cliente> Datos; // Vector para almacenar usuarios

struct Nodo
{
    string nombre;
    struct Nodo *siguiente;
    struct Nodo *anterior;
    struct DatosPaciente datosP;
    struct Cliente cliente;
};

struct Administrador // estructura para guardar los datos del administrador
{
    string nombre;
    int clave;
};

Administrador DatosAdmin[3]; // alias para un arreglo de estructuras Administrador

// variables globales

struct Nodo *lista = nullptr; // para verificar si está vacía la lista

int regreso, DUI, Edad;
string fechaActual, receta, urgencia;
bool ciclo = false; // Dejamos ya establecido el ciclo

// prototipo de funciones

int auxEdad(int);
int auxDUI(int);
string Fecha();
string hora();
string mostrarUsuarios();
string auxReceta(string);
string auxUrgencia(string);
bool ValidarDatos(Nodo Paciente);          // Funcion para validar los datos del usuario
bool ValidarDatosAdmin(struct Administrador admin); // Funcion para validar los datos del doctor
bool buscarPaciente(Nodo paciente); 
void CitaPaciente(Nodo paciente);                   // Funcion para el txt
void CitaPacienteAtendida(Nodo paciente, struct Administrador admin);
void insertarFinal(Nodo paciente);
void insertarIncio(Nodo paciente);
void eliminarCita();
void mostrarCitasIngresadas();
void mostrarPacientes();
void eliminarPaciente(Nodo paciente);
void atenderPaciente(Nodo paciente, Administrador admin);
void verCitasAtendidas();
void verCitasPendientes();
void imprimirUsuarios_txt();
void mostrarPacientesUrgencia();
void actualizarNivelUrgencia(Nodo *lista, string nombre);