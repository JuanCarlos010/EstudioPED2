/*Proyecto: Crear un sistema de gestión de citas médicas  a nivel consola
que permita a los usuarios agendar citas, ver historial médico, etc. */

#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "Supreme_Library.hpp"
#include "Libreria.cpp"

using namespace std;

int main()
{
    // Variables locales
    int opcionMenuPrincipal = 0;
    int opcionMenuAdmin = 0;
    int opcionHacerAdmin = 0;
    int opcionVerPacientes = 0;
    int opcionRegistrado = 0;
    bool validacion = false;
    bool validacionMenuAdmin = false;
    bool validacionMenuCliente = false;
    string Razon;
    string nombrePaciente;

    // Función para leer carácteres especiales, utilizando libreria <windows.h>
    SetConsoleOutputCP(CP_UTF8);

    // Agregamos los string para dejar ya declaradas las rutas
    string ruta = ".\\Historial_Medico";
    string rutaUsuarios = ".\\Historial_Medico\\Usuarios";
    string rutaPacientes = ".\\Historial_Medico\\Pacientes";
    string rutaPacientesAtendidos = ".\\Historial_Medico\\Pacientes_Atendidos";
    string rutaHistorial = ".\\Historial_Medico\\Lista_citas_ingresadas";

    // Dejamos los "CreateDirectory" para que puedan crear las carpetas donde se almacenaran la informacion
    CreateDirectory(ruta.c_str(), NULL);
    CreateDirectory(rutaUsuarios.c_str(), NULL);
    CreateDirectory(rutaPacientes.c_str(), NULL);
    CreateDirectory(rutaPacientesAtendidos.c_str(), NULL);
    CreateDirectory(rutaHistorial.c_str(), NULL);

    // Llamado de estructuras
    Cliente usuariosNuevos;
    Administrador admin;
    Nodo paciente;
    DatosPaciente datosP;

    // Declarar administradores
    DatosAdmin[0].nombre = "Oak";
    DatosAdmin[0].clave = 20;
    DatosAdmin[1].nombre = "Sycamore";
    DatosAdmin[1].clave = 30;
    DatosAdmin[2].nombre = "Yoceman";
    DatosAdmin[2].clave = 40;

    // Comienzo de la interfaz mostrada al usuario

    while (validacion != true)
    {

        // menu principal
        cout << "===========================================================" << endl;
        cout << "||            Bienvenido a clínica Teselia               ||" << endl;
        cout << "===========================================================" << endl;

        cout << endl;

        cout << "Seleccione una opción para continuar:" << endl;
        cout << "\n1- Acceder como doctor." << endl;
        cout << "2- Acceder como paciente." << endl;
        cout << "3- Revisar todos los usuarios" << endl;
        cout << "4- Salir del sistema." << endl;

        cin >> opcionMenuPrincipal;
        
        
            switch (opcionMenuPrincipal)
            {
            case 1:

                cout << "Ingrese su nombre de usuario: ";
                cin >> admin.nombre;
                cout << "Ingrese la clave de su usuario: ";
                cin >> admin.clave;
                cout << endl;

                if (ValidarDatosAdmin(admin) == true)
                {

                    cout << "Inicio de sesión correcto" << endl;

                    while (validacionMenuAdmin != true)
                    {
                        system("pause");
                        system("cls");
                        // Menu administrador
                        cout << "\nBienvenido Dr. " << admin.nombre << endl;
                        cout << "_________________________________" << endl;

                        cout << "\n¿Qué desea hacer?" << endl;
                        cout << "\n1) Agregar paciente" << endl
                             << "2) Eliminar paciente" << endl
                             << "3) Atender paciente" << endl
                             << "4) Ver citas atendidas" << endl
                             << "5) Ver citas pendientes" << endl
                             << "6) Cerrar sesión" << endl;
                        cin >> opcionMenuAdmin;

                        switch (opcionMenuAdmin)
                        {
                        case 1: // Ingresar un nuevo usuario

                            while (opcionHacerAdmin != 2)
                            {

                                cout << "Ingrese los datos del paciente: " << endl;
                                cout << "\nNombre: " << endl;
                                cin >> paciente.nombre;
                                cout << "Edad: " << endl;
                                cin >> paciente.datosP.edad;
                                Edad = paciente.datosP.edad;
                                auxEdad(Edad);
                                if (paciente.datosP.edad >= 18)
                                {
                                    cout << "DUI: " << endl;
                                    cin >> paciente.datosP.dui;
                                }
                                else
                                {
                                    paciente.datosP.dui = 0;
                                }
                                DUI = paciente.datosP.dui;
                                auxDUI(DUI);
                                cout << "Motivo de cita: " << endl;
                                cin.ignore(); // Para limpiar el buffer
                                getline(cin, paciente.datosP.motivoCita);

                                cout << "Nivel de urgencia:" << endl;
                                cout << "1- Estable." << endl;
                                cout << "2- Intermedio." << endl;
                                cout << "3- Grave." << endl;
                                cin >> paciente.datosP.nivelUrgencia;

                                while (paciente.datosP.nivelUrgencia != 1 && paciente.datosP.nivelUrgencia != 2 && paciente.datosP.nivelUrgencia != 3)
                                {
                                    cout << "Ingrese una opción válida: " << endl;
                                    cin >> paciente.datosP.nivelUrgencia;
                                }
                                insertarIncio(paciente);
                                CitaPaciente(paciente);

                                cout << "\n¿Desea agregar a otro paciente?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionHacerAdmin;
                                while (opcionHacerAdmin != 1 && opcionHacerAdmin != 2)
                                {
                                    cout << "Ingrese una opción válida" << endl;
                                    cin >> opcionHacerAdmin;
                                }
                            }

                            opcionHacerAdmin = 0;
                            break;

                        case 2: // Eliminar algun paciente
                            while (opcionHacerAdmin != 2)
                            {
                                cout << "\n¿Desea ver los pacientes en el sistema?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionVerPacientes;

                                while (opcionVerPacientes != 1 && opcionVerPacientes != 2)
                                {
                                    cout << "Ingrese una opción válida" << endl;
                                    cin >> opcionVerPacientes;
                                }

                                if (opcionVerPacientes == 1)
                                {
                                    mostrarPacientes();
                                }

                                cout << "\nIngrese el nombre del paciente que desea eliminar:" << endl;
                                cin >> paciente.nombre;
                                eliminarPaciente(paciente);

                                cout << "\n¿Desea eliminar otro paciente?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionHacerAdmin;
                                while (opcionHacerAdmin != 1 && opcionHacerAdmin != 2)
                                {
                                    cout << "\nIngrese una opción válida." << endl;
                                    cin >> opcionHacerAdmin;
                                }
                            }
                            opcionHacerAdmin = 0;

                            break;

                        case 3: // Atender paciente
                            while (opcionHacerAdmin != 2)
                            {
                                cout << "\n¿Desea ver las citas pendientes en el sistema?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionVerPacientes;

                                while (opcionVerPacientes != 1 && opcionVerPacientes != 2)
                                {
                                    cout << "Ingrese una opción válida" << endl;
                                    cin >> opcionVerPacientes;
                                }

                                if (opcionVerPacientes == 1)
                                {
                                    verCitasPendientes();
                                }

                                cout << "\n¿Desea actualizar el nivel de urgencia de algún paciente?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionVerPacientes;

                                while (opcionVerPacientes != 1 && opcionVerPacientes != 2)
                                {
                                    cout << "\nIngrese una opción válida" << endl;
                                    cin >> opcionVerPacientes;
                                }

                                if (opcionVerPacientes == 1)
                                {
                                    cout << "\nIngrese el nombre del paciente: " << endl;
                                    cin >> nombrePaciente;
                                    actualizarNivelUrgencia(lista, nombrePaciente);
                                }

                                cout << "\nIngrese el nombre del paciente que desea atender" << endl; // ultima modificación 24/11
                                cin >> paciente.nombre;

                                atenderPaciente(paciente, admin);

                                cout << "\n¿Desea atender otro paciente?" << endl;
                                cout << "1) Si || 2) No" << endl;
                                cin >> opcionHacerAdmin;

                                while (opcionHacerAdmin != 1 && opcionHacerAdmin != 2)
                                {
                                    cout << "Ingrese una opción válida" << endl;
                                    cin >> opcionHacerAdmin;
                                }
                            }
                            opcionHacerAdmin = 0;
                            break;

                        case 4: // Ver las citas atendidas

                            cout << "Desea ver las citas desde" << endl
                                 << " 1) terminal || 2) txt" << endl;
                            cin >> opcionHacerAdmin;
                            if (opcionHacerAdmin == 1)
                            {
                                cout << "Las citas atendidas son las siguientes:" << endl;
                                verCitasAtendidas();
                            }
                            else if (opcionHacerAdmin == 2)
                            {
                                system("start .\\Historial_Medico\\Pacientes_Atendidos");
                            }

                            break;

                        case 5: // Ver citas restantes
                            cout << "\n¿Desea ver las citas pendientes por filtro de búsqueda?" << endl;
                            cout << "1) Si || 2) No" << endl;
                            cin >> opcionVerPacientes;

                            while (opcionVerPacientes != 1 && opcionVerPacientes != 2)
                            {
                                cout << "Ingrese una opción válida" << endl;
                                cin >> opcionVerPacientes;
                            }

                            if (opcionVerPacientes == 1)
                            {
                                mostrarPacientesUrgencia();
                            }
                            cout << "\n¿Desea ver todas las citas pendientes?" << endl;
                            cout << "1) Si || 2) No" << endl;
                            cin >> opcionVerPacientes;

                            while (opcionVerPacientes != 1 && opcionVerPacientes != 2)
                            {
                                cout << "Ingrese una opción válida" << endl;
                                cin >> opcionVerPacientes;
                            }

                            if (opcionVerPacientes == 1)
                            {
                                verCitasPendientes();
                            }

                            break;

                        case 6:
                            cout << "Cerrando sesión..." << endl;
                            validacionMenuAdmin = true;
                            break;

                        default:
                            cout << "Ingrese una opción válida." << endl;
                            break;
                        }
                    }
                }

                else
                {
                    cout << "\nInicio de sesión incorrecto." << endl;
                }
                validacionMenuAdmin = false;

                break;

            case 2:
                cout << "¿Está registrado en el sistema?" << endl;
                cout << "1) Si || 2) No." << endl;
                cin >> opcionRegistrado;

                while (opcionRegistrado != 1 && opcionRegistrado != 2)
                {
                    cout << "Ingrese una opción válida" << endl;
                    cin >> opcionRegistrado;
                }

                if (opcionRegistrado == 1)
                {
                    cout << "Ingrese su nombre de usuario: ";
                    cin >> paciente.nombre;
                    cout << "Ingrese la clave de su usuario: ";
                    cin >> paciente.cliente.clave;

                    if (ValidarDatos(paciente) == true)
                    {
                        cout << "\nBienvenido " << paciente.nombre << endl;
                        cout << "_________________________________" << endl;

                        while (validacionMenuCliente != true)
                        {
                            // Menu usuario (paciente)
                            int opcion;
                            cout << "¿Que desea hacer?" << endl;
                            cout << "1) Citas" << endl
                                 << "2) Historial medico" << endl
                                 << "3) Cerrar sesion" << endl;
                            cin >> opcion;
                            switch (opcion)
                            {
                            case 1: // Opcion para agendar o cancelar la cita

                                int opcion2;
                                cout << "Desea:" << endl
                                     << "1) Reservar " << endl
                                     << "2) Cancelar una cita" << endl;
                                cin >> opcion2;
                                while (opcion2 != 1 && opcion2 != 2)
                                {
                                    cout << "\nIngrese una opción válida." << endl;
                                    cin >> opcion2;
                                }

                                if (opcion2 == 1)
                                {
                                    cout << "Ingrese el motivo de su cita" << endl;
                                    cin.ignore();
                                    getline(cin, paciente.datosP.motivoCita);
                                    cout << endl;
                                    insertarFinal(paciente); // guardar datos de cita
                                    CitaPorAtender(paciente);
                                }
                                else if (opcion2 == 2)
                                {
                                    int opcion3;
                                    cout << "Desea ver sus citas ingresadas?" << endl;
                                    cout << "1) Si || 2) No" << endl;
                                    cin >> opcion3;
                                    if (opcion3 == 1)
                                    {
                                        mostrarCitasIngresadas();
                                    }
                                    eliminarCita();
                                }
                                break;
                            case 2: // Opcion para abrir la carpeta del usuario para revisar su historial medico de las citas ingresadas
                                system("start .\\Historial_Medico\\Lista_citas_ingresadas");

                                break;
                            case 3: // cerrar sesion
                                cout << "Cerrando sesión ..." << endl;
                                validacionMenuCliente = true;
                                break;
                            default: // Opcion por si ingresa un dato no valido
                                cout << "Ingrese una opción válida" << endl;
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Inicio de sesión incorrecto" << endl;
                        validacion = false;
                    }
                }
                if (opcionRegistrado == 2)
                {
                    cout << "Ingrese el nuevo nombre de usuario" << endl;
                    cin >> usuariosNuevos.nombre;
                    cout << "Ingrese la nueva clave de usuario" << endl;
                    cin >> usuariosNuevos.clave;
                    cout << "Ingrese su edad" << endl;
                    cin >> usuariosNuevos.Edad;
                    Edad = usuariosNuevos.Edad;
                    auxEdad(Edad);
                    if (usuariosNuevos.Edad >= 18)
                    {
                        cout << "Ingrese su DUI" << endl;
                        cin >> usuariosNuevos.DUI;
                        DUI = usuariosNuevos.DUI;
                        auxDUI(DUI);
                    }
                    Datos.push_back(usuariosNuevos);
                    cout << "Usuario agregado exitosamente." << endl;
                    system("pause");
                    system("cls");
                }
                validacionMenuCliente = false;

                break;

            case 3: // se muestran los usuarios ingresados
                int eleccion;
                cout << "Desea ver los usuarios ingresados en: \n1) Terminal || 2) txt" << endl;
                cin >> eleccion;
                if (eleccion == 1)
                {
                    cout << mostrarUsuarios();
                }
                else if (eleccion == 2)
                {
                    imprimirUsuarios_txt();
                    system("start .\\Historial_Medico\\Usuarios");
                }
                validacion = false;
                system("pause");
                system("cls");
                break;

            case 4: // Cerrar sistema
                cout << "Saliendoo del sistema..." << endl;
                cout << "Tenga un lindo día." << endl;
                validacion = true;
                break;

            default:
                cout << "Por favor ingrese una opción válida." << endl;
                cout << endl;
                break;
            }
        }
    

    return 0;
}
