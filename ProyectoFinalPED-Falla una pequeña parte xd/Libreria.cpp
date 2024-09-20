#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;

// definición de las funciones

Nodo *crearNodo(Nodo paciente)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->nombre = paciente.nombre;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    return nuevoNodo;
}

string Fecha()
{
    time_t t = time(0); // obtenemos la hora actual del sistema y guardamos en variable "t"
    struct tm *f;
    f = localtime(&t); // convertimos el valor entero a una estructura que contiene los componentes de la fecha y h
    fecha aux;
    aux.anio = f->tm_year + 1900;
    aux.mes = f->tm_mon + 1;
    aux.dia = f->tm_mday;
    string fechaActual = "Fecha: " + to_string(aux.dia) + "/" + to_string(aux.mes) + "/" + to_string(aux.anio);
    return fechaActual;
}

string hora()
{
    time_t t = time(0);
    struct tm *now = localtime(&t);

    // Convertir las partes de la hora a cadenas
    string horaStr = to_string(now->tm_hour);
    string minutoStr = to_string(now->tm_min);
    string segundoStr = to_string(now->tm_sec);

    string horaActual = "Hora: " + horaStr + ":" + minutoStr;

    // Ajustar el formato de la hora
    size_t pos = horaActual.find(':');
    if (horaActual[0] == '0')
    {
        horaActual = horaActual.substr(1);
    }
    else if (pos != string::npos && horaActual[pos + 1] == '0')
    {
        horaActual = horaActual.substr(0, pos + 1) + horaActual.substr(pos + 2);
    }

    return horaActual;
}

string auxReceta(string receta)
{
    return receta;
}

int auxEdad(int Edad)
{
    return Edad;
}

int auxDUI(int DUI)
{
    return DUI;
}

bool ValidarDatos(Nodo paciente)
{
    for (int i = 0; i < 2; i++)
    {
        if (paciente.nombre == Datos[i].nombre && paciente.cliente.clave == Datos[i].clave)
        {
            paciente.cliente.Edad = Datos[i].Edad;
            paciente.cliente.DUI = Datos[i].DUI;
            return true; // Si los datos ingresados coinciden
        }
    }
    return false; // Si no encuentra ninguna coicidencia
}

bool ValidarDatosAdmin(Administrador admin)
{
    for (int i = 0; i < 3; i++)
    {
        if (admin.nombre == DatosAdmin[i].nombre && admin.clave == DatosAdmin[i].clave)
        {
            return true; // Si los datos ingresados coinciden
        }
    }
    return false; // Si no encuentra ninguna coicidencia
}

void guardarNivelUrgencia(Nodo paciente)
{

    Nodo *temporal = lista;
    bool found = false;
    // guardar nivel de urgencia en variable string

    while (temporal != nullptr)
    {
        if (temporal->nombre == paciente.nombre)
        {
            found = true;
            if (temporal->datosP.nivelUrgencia == 1)
            {
                temporal->datosP.urgencia = "Estable";
            }
            else if (temporal->datosP.nivelUrgencia == 2)
            {
                temporal->datosP.urgencia = "Precaución";
            }
            else if (temporal->datosP.nivelUrgencia == 3)
            {
                temporal->datosP.urgencia = "Grave";
            }
            temporal->datosP.urgencia = paciente.datosP.urgencia;
            break;
        }
        temporal = temporal->siguiente;
    }
    if (!found)
    {
        cout << "\nNo se encontró el paciente buscado" << endl;
    }
}

void insertarIncio(Nodo paciente)
{
    Nodo *nuevoNodo = crearNodo(paciente);
    struct Nodo *temporal = lista;
    nuevoNodo->nombre = paciente.nombre;
    nuevoNodo->datosP.edad = paciente.datosP.edad;
    nuevoNodo->datosP.dui = paciente.datosP.dui;
    nuevoNodo->datosP.motivoCita = paciente.datosP.motivoCita;
    nuevoNodo->datosP.atendido = false;

    if (paciente.datosP.nivelUrgencia == 1)
    {
        urgencia = "Estable";
    }
    else if (paciente.datosP.nivelUrgencia == 2)
    {
        urgencia = "Precaución";
    }
    else if (paciente.datosP.nivelUrgencia == 3)
    {
        urgencia = "Grave";
    }

    if (lista == nullptr)
    {
        lista = nuevoNodo; // Si la lista está vacía, el nuevo nodo será el frente de la lista
    }
    else
    {
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente; // Avanza al siguiente nodo
        }
        temporal->siguiente = nuevoNodo; // Agrega el nuevo nodo al final de la lista
        nuevoNodo->anterior = temporal;
    }
    cout << "\nPaciente agregado exitosamente" << endl;
}

void insertarFinal(Nodo paciente)
{
    Nodo *nuevoNodo = crearNodo(paciente);
    struct Nodo *temporal = lista;
    nuevoNodo->cliente.Edad = paciente.cliente.Edad;
    nuevoNodo->datosP.dui = paciente.cliente.DUI;
    nuevoNodo->datosP.motivoCita = paciente.datosP.motivoCita;
    nuevoNodo->datosP.atendido = false;

    
    if (lista == nullptr)
    {
        lista = nuevoNodo; // Si la lista está vacía, el nuevo nodo será el frente de la lista
    }
    else
    {

        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente; // Avanza al siguiente nodo
        }
        temporal->siguiente = nuevoNodo; // Agrega el nuevo nodo al final de la lista
        nuevoNodo->anterior = temporal;
    }
    cout << "\nCita agregada exitosamente" << endl;
}

void mostrarPacientes()
{
    Nodo *temporal = lista;

    cout << "\n Pacientes registrados en el sistema:" << endl;

    if (temporal != nullptr)
    {
        // buscar elementos existentes
        while (temporal != nullptr)
        {
            cout << "\n___________________________________________________" << endl;
            cout << "Nombre: " << temporal->nombre << endl;
            cout << "Edad: " << temporal->datosP.edad << endl;
            cout << "Dui: " << temporal->datosP.dui << endl;
            cout << "Motivo de la cita: " << temporal->datosP.motivoCita << endl;
            cout << "Urgencia: " << temporal->datosP.urgencia << endl;
            temporal = temporal->siguiente; // avanzar al siguiente nodo
        }
    }
    else
    {
        cout << "\no hay pacientes registrados" << endl;
    }
}

bool buscarPaciente(Nodo paciente)
{
    Nodo *temporal = lista;
    bool found = false;
    while (temporal != nullptr)
    {
        if (temporal->nombre == paciente.nombre)
        {
            found = true;
            break;
        }
        temporal = temporal->siguiente;
    }
    if (!found)
    {
        cout << "\nNo se encontró el paciente buscado" << endl;
        found = false;
    }
    return found;
}

void CitaPaciente(Nodo paciente)
{
    string urgencia = "";
    if (paciente.datosP.nivelUrgencia == 1)
    {
        urgencia = "Estable";
    }
    else if (paciente.datosP.nivelUrgencia == 2)
    {
        urgencia = "Precaución";
    }
    else if (paciente.datosP.nivelUrgencia == 3)
    {
        urgencia = "Grave";
    }
    ofstream Cita;
    string ruta = "C:.\\Historial_Medico\\Pacientes\\Cita_" + paciente.nombre + ".txt";
    Cita.open(ruta, ios::out | ios::app);
    if (Cita.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else
    { // imprimira estos datos en el archivo txt
        Cita << "====================================" << endl;
        Cita << Fecha();
        Cita << endl;
        Cita << hora();
        Cita << endl;
        Cita << "Edad: " << paciente.datosP.edad << endl;
        Cita << "DUI: " << paciente.datosP.dui << endl;
        Cita << "Motivo: " << paciente.datosP.motivoCita << endl;
        Cita << "Urgencia: " << urgencia << endl;
        Cita << "====================================" << endl;
        Cita.close();
        cout << "Paciente agregado al historial exitosamente" << endl;
    }
}

void eliminarPaciente(Nodo paciente)
{
    Nodo *aux = lista;
    while (aux != nullptr && aux->nombre != paciente.nombre)
    {
        aux = aux->siguiente;
    }
    if (aux != nullptr)
    {
        if (aux->anterior != nullptr)
        {
            aux->anterior->siguiente = aux->siguiente;
        }
        else
        {
            lista = aux->siguiente;
        }

        if (aux->siguiente != nullptr)
        {
            aux->siguiente->anterior = aux->anterior;
        }

        delete aux;
        cout << "Paciente: " << paciente.nombre << " eliminado del sistema." << endl;
    }
    else
    {
        cout << "\nNo se encontró el paciente buscado." << endl;
    }
}

void atenderPaciente(Nodo paciente, Administrador admin)
{
    Nodo *temporal = lista;
    bool found = false;
    while (temporal != nullptr)
    {
        if (temporal->nombre == paciente.nombre)
        {
            temporal->datosP.atendido = true;
            found = true;
            cout << "Ingrese la receta: ";
            cin.ignore(); // limpiar buffer
            getline(cin, paciente.datosP.receta);
            CitaPacienteAtendida(paciente, admin);
            receta = paciente.datosP.receta;
            auxReceta(receta);
            break;
        }
        temporal = temporal->siguiente;
    }
    if (!found)
    {
        cout << "\nNo se encontró el paciente buscado" << endl;
    }
}

void actualizarNivelUrgencia(Nodo *lista, string nombre)
{
    Nodo *temporal = lista;
    bool found = false;
    urgencia = "";

    while (temporal != nullptr)
    {
        if (temporal->nombre == nombre)
        {
            found = true;
            cout << "Ingrese el nuevo nivel de urgencia: ";
            cin >> temporal->datosP.nivelUrgencia;

            if (temporal->datosP.nivelUrgencia == 1)
            {
                urgencia = "Estable";
            }
            else if (temporal->datosP.nivelUrgencia == 2)
            {
                urgencia = "Precaución";
            }
            else if (temporal->datosP.nivelUrgencia == 3)
            {
                urgencia = "Grave";
            }
            auxUrgencia(urgencia);
            break;
        }
        temporal = temporal->siguiente;
    }

    if (!found)
    {
        cout << "\nNo se encontró el paciente buscado" << endl;
    }
}

void mostrarPacientesUrgencia()
{
    Nodo *temporal = lista;
    Nodo paciente;
    bool found = false;
    int filtro;

    cout << "\nIngrese el nivel de urgencia para filtrar: " << endl;
    cout << "1- Estable" << endl;
    cout << "2- Precaución" << endl;
    cout << "3- Grave" << endl;
    cin >> filtro;

    cout << "\nPacientes con nivel de urgencia " << filtro << ":" << endl;

    if (temporal == nullptr)
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    while (temporal != nullptr)
    {

        if (temporal->datosP.nivelUrgencia == filtro)
        {
            found = true;
            cout << "\n___________________________________________________" << endl;
            cout << "Nombre: " << temporal->nombre << endl;
            cout << "Edad: " << temporal->datosP.edad << endl;
            cout << "Dui: " << temporal->datosP.dui << endl;
            cout << "Motivo de la cita: " << temporal->datosP.motivoCita << endl;
        }
        temporal = temporal->siguiente;
    }

    if (!found)
    {
        cout << "\nNo se encontraron pacientes con nivel de urgencia " << filtro << endl;
    }
}

string auxUrgencia(string urgencia)
{
    return urgencia;
}
void verCitasAtendidas()
{
    Nodo *temporal = lista;
    Nodo paciente;
    bool found = false;
    temporal->datosP.receta = auxReceta(receta);
    temporal->datosP.dui = auxDUI(DUI);
    temporal->datosP.edad = auxEdad(Edad);
    temporal->datosP.urgencia = auxUrgencia(urgencia);

    while (temporal != nullptr)
    {
        if (temporal->datosP.atendido == true)
        {

            auxUrgencia(urgencia);
            found = true;
            cout << "\n ___________________________________________________" << endl;
            cout << "Nombre: " << temporal->nombre << endl;
            cout << "Edad: " << temporal->datosP.edad << endl;
            cout << "Dui: " << temporal->datosP.dui << endl;
            cout << "Motivo de la cita: " << temporal->datosP.motivoCita << endl;
            cout << "Urgencia: " << temporal->datosP.urgencia << endl;
            cout << "Receta: " << temporal->datosP.receta << endl;
            break;
        }
        temporal = temporal->siguiente;
    }

    if (!found)
    {
        cout << "\nNo se encontraron citas atendidas" << endl;
    }
}

void CitaPacienteAtendida(Nodo paciente, Administrador admin)
{
    // insertarFinal(paciente);

    paciente.datosP.dui = auxDUI(DUI);
    paciente.datosP.edad = auxEdad(Edad);
    paciente.datosP.urgencia = auxUrgencia(urgencia);

    ofstream CitaPaciente_Atendida;

    string ruta = "C:.\\Historial_Medico\\Pacientes_Atendidos\\CitaAtendida_" + admin.nombre + ".txt";

    CitaPaciente_Atendida.open(ruta, ios::out | ios::app);
    if (CitaPaciente_Atendida.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else
    { // imprimira estos datos en el archivo txt
        CitaPaciente_Atendida << "====================================" << endl;
        CitaPaciente_Atendida << Fecha();
        CitaPaciente_Atendida << endl;
        CitaPaciente_Atendida << hora();
        CitaPaciente_Atendida << endl;
        CitaPaciente_Atendida << "Nombre: " << paciente.nombre << endl;
        CitaPaciente_Atendida << "Edad: " << paciente.datosP.edad << endl;
        CitaPaciente_Atendida << "DUI: " << paciente.datosP.dui << endl;
        CitaPaciente_Atendida << "Motivo: " << paciente.datosP.motivoCita << endl;
        CitaPaciente_Atendida << "Urgencia: " << paciente.datosP.urgencia << endl;
        CitaPaciente_Atendida << "Receta: " << paciente.datosP.receta << endl;
        CitaPaciente_Atendida << "====================================" << endl;
        CitaPaciente_Atendida.close();
        cout << "Cita atendida guardada exitosamente" << endl;
    }
}

void verCitasPendientes()
{
    Nodo *temporal = lista;
    Nodo paciente;
    CitaPaciente(paciente);
    bool found = false;
    cout << "\n Citas pendientes en el sistema:" << endl;

    while (temporal != nullptr)
    {
        if (temporal->datosP.atendido == false)
        {
            temporal->cliente.Edad = auxEdad(Edad);
            temporal->cliente.DUI = auxDUI(DUI);
            found = true;
            cout << "\n___________________________________________________" << endl;
            cout << "Nombre: " << temporal->nombre << endl;
            cout << "Edad: " << temporal->cliente.Edad << endl;
            cout << "Dui: " << temporal->cliente.DUI << endl;
            cout << "Motivo de la cita: " << temporal->datosP.motivoCita << endl;
            break;
        }
        temporal = temporal->siguiente;
    }
    if (!found)
    {
        cout << "\nNo se encontraron citas pendientes" << endl;
    }
}

string mostrarUsuarios()
{
    string usuarios = "";

    usuarios += "Nombres de Clientes:\n";
    for (const auto &cliente : Datos)
    {
        usuarios += cliente.nombre + "\n";
    }

    usuarios += "------------------------------------\n";
    usuarios += "Nombres de Administradores:\n";
    for (int i = 0; i < 3; i++)
    {
        usuarios += DatosAdmin[i].nombre + "\n";
    }

    return usuarios;
}

void imprimirUsuarios_txt()
{
    ofstream imprimirUsuarios;
    string ruta = "C:.\\Historial_Medico\\Usuarios\\Usuarios.txt";
    imprimirUsuarios.open(ruta, ios::out | ios::app);
    if (imprimirUsuarios.fail() == true)
    {
        cout << "No se pudo crear el archivo";
    }
    else
    { // imprimira los datos de los nombres ingresados en el archivo txt
        imprimirUsuarios << "====================================" << endl;
        imprimirUsuarios << mostrarUsuarios();
        imprimirUsuarios << "====================================" << endl;
        imprimirUsuarios.close();
    }
}

void mostrarCitasIngresadas()
{
    struct Nodo *aux = lista;
    struct Nodo paciente;
    paciente.cliente.razon = aux->datosP.motivoCita;
    if (aux != nullptr)
    {
        cout << "Citas ingresadas:" << endl;
        while (aux != nullptr)
        {
            cout << "Nombre: " << aux->nombre << endl;
            cout << "Motivo: " << aux->datosP.motivoCita << endl;
            cout << "-------------------------" << endl;

            aux = aux->siguiente;
        }
    }
    else
    {
        cout << "No hay citas ingresadas" << endl;
    }
}

void CitaPorAtender(Nodo paciente)
{
    ofstream CitaAtender;
    string ruta = "C:.\\Historial_Medico\\Lista_citas_ingresadas\\Listado.txt";
    paciente.cliente.DUI = auxDUI(DUI);
    paciente.cliente.Edad = auxEdad(Edad);
    CitaAtender.open(ruta, ios::out | ios::app);

    if (CitaAtender.fail())
    {
        cout << "No se pudo crear el archivo" << endl;
    }
    else
    {
        // Imprimimos datos en el archivo txt
        CitaAtender << "====================================" << endl;
        CitaAtender << Fecha() << endl;
        CitaAtender << hora() << endl;
        CitaAtender << "Nombre: " << paciente.nombre << endl;
        CitaAtender << "Edad: " << paciente.cliente.Edad << endl;
        CitaAtender << "DUI: " << paciente.cliente.DUI << endl;
        CitaAtender << "Motivo: " << paciente.datosP.motivoCita << endl;
        CitaAtender << "====================================" << endl;

        CitaAtender.close();
        cout << "Cita agregada al historial medico" << endl;
    }
}

void eliminarCita()
{
    Cliente cliente1;
    if (lista != nullptr)
    {
        string motivoEliminar;
        cout << "Ingrese el motivo de la cita que desea eliminar: ";
        cin.ignore();
        getline(cin, motivoEliminar);

        struct Nodo *temporal = lista;

        while (temporal != nullptr)
        {
            if (temporal->datosP.motivoCita == motivoEliminar)
            {
                if (temporal->anterior != nullptr)
                {
                    temporal->anterior->siguiente = temporal->siguiente;
                }
                else
                {
                    lista = temporal->siguiente;
                }

                if (temporal->siguiente != nullptr)
                {
                    temporal->siguiente->anterior = temporal->anterior;
                }

                delete temporal;
                cout << "Cita eliminada exitosamente" << endl;
                return;
            }

            temporal = temporal->siguiente;
        }

        cout << "No se encontró la cita" << endl;
    }
    else
    {
        cout << "No hay citas para eliminar" << endl;
    }
}