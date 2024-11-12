#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Registro de Pacientes en una Clínica
Descripción: Crear una lista enlazada para almacenar los datos de los pacientes: ID, nombre, edad, diagnóstico.
- Insertar pacientes al final de la lista.
- Eliminar pacientes mayores de 65 años (simulando que fueron dados de alta).
- Mostrar los nombres y diagnósticos de todos los pacientes.
- Contar la cantidad de pacientes menores de edad y calcular el porcentaje que representan sobre el total.
*/

struct Paciente
{
    int id;
    string nombre;
    int edad;
    string diagnostico;
};

struct Nodo
{
    Paciente dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Paciente datoPaciente)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = datoPaciente;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarAlFinal(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr)
    {
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr)
        {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }
}

void cargarPaciente(Nodo* &inicio)
{
    Paciente datoPaciente;

    cout << "Ingrese el ID del paciente (-1 para finalizar): ";
    cin >> datoPaciente.id;
    cin.ignore();

    while(datoPaciente.id >= 0)
    {
        cout << "Ingrese el nombre del paciente: ";
        getline(cin, datoPaciente.nombre);

        cout << "Ingrese la edad del paciente: ";
        cin >> datoPaciente.edad;
        cin.ignore();

        cout << "Ingrese el diagnostico del paciente: ";
        getline(cin, datoPaciente.diagnostico);

        Nodo* nuevoPaciente = crearNodo(datoPaciente);
        insertarAlFinal(inicio, nuevoPaciente);

        cout << "Ingrese el ID del paciente (-1 para finalizar): ";
        cin >> datoPaciente.id;
        cin.ignore();
    }
}

void eliminarPaciente(Nodo* &inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay pacientes registrados.";
        return;
    }

    Nodo* aux = inicio;
    Nodo* aEliminar;

    while(inicio != nullptr && inicio -> dato.edad > 65)
    {
        aEliminar = inicio;
        inicio = inicio -> siguiente;
        delete aEliminar;
    }

    while(aux != nullptr && aux -> siguiente != nullptr)
    {
        if(aux -> siguiente -> dato.edad > 65)
        {
            aEliminar = aux -> siguiente;
            aux -> siguiente = aux -> siguiente -> siguiente;
            delete aEliminar;
        }
        else
        {
            aux = aux -> siguiente;
        }
    }
}

void imprimirPaciente(Nodo* inicio)
{
    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        cout << "Nombre del paciente: " << aux -> dato.nombre << endl;
        cout << "Diagnostico del paciente: " << aux -> dato.diagnostico << endl;
        cout << "----------" << endl;
        aux = aux -> siguiente;
    }
}

void contarPacientes(Nodo* inicio)
{
    int contadorMenores = 0;
    int contadorTotal = 0;

    Nodo* aux = inicio;

    while(aux != nullptr)
    {
        if(aux -> dato.edad < 18)
        {
            contadorMenores++;
        }
        contadorTotal++;
        aux = aux -> siguiente;
    }

    if(contadorTotal > 0)
    {
        double porcentajeMenores = (static_cast<double>(contadorMenores) / contadorTotal) * 100;
        cout << "Cantidad de pacientes menores de edad: " << contadorMenores << endl;
        cout << "Porcentaje de pacientes menores de edad: " << porcentajeMenores << "%" << endl;
    }
    else
    {
        cout << "No hay pacientes en la lista." << endl;
    }
}

int main()
{
    Nodo* inicio = nullptr;

    cargarPaciente(inicio);

    eliminarPaciente(inicio);

    imprimirPaciente(inicio);

    contarPacientes(inicio);

    return 0;
}