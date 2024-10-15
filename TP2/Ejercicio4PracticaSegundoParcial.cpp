#include <iostream>
#include <string>
using namespace std;

/*
En un hospital, se necesita un sistema para gestionar la información de los pacientes hospitalizados, con un máximo de 1000 pacientes. Cada paciente tiene los siguientes datos:
    Nombre completo (string).
    Número de historia clínica (int).
    Edad (int).
    Diagnóstico (string).
    Datos de contacto de emergencia (struct) que contiene:
        Nombre (string).
        Teléfono (int).
El programa debe realizar las siguientes acciones:
- Admisión de pacientes: Permitir la carga de los datos de los pacientes hospitalizados (el proceso finaliza cuando el número de historia clínica sea 0).
- Búsqueda de paciente: Buscar a un paciente por su número de historia clínica. Si se encuentra, mostrar todos sus datos. Si no, mostrar el mensaje "Paciente no encontrado".
- Reporte de pacientes por diagnóstico: Solicitar un diagnóstico y listar todos los pacientes que tienen dicho diagnóstico, mostrando su nombre y edad.
*/

const int MAX_PACIENTES = 1000;

struct ContactoEmergencia
{
    string nombre;
    int telefono;
};

struct Paciente
{
    string nombreApellido;
    int numeroHistoriaClinica;
    int edad;
    string diagnóstico;
    ContactoEmergencia contactoDeEmergencia;
};

void altaPaciente(Paciente pacientes[], int &dl)
{
    if (dl >= MAX_PACIENTES)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; i < MAX_PACIENTES; i++)
    {
        cout << "Paciente " << i+1 << ":" << endl;
        cout << "Ingrese el nombre y apellido: ";
        getline(cin >> ws, pacientes[i].nombreApellido);

        cout << "Ingrese el número de historia clínica (0 para finalizar la carga de datos): ";
        cin >> pacientes[i].numeroHistoriaClinica;
        cin.ignore();

        if(pacientes[i].numeroHistoriaClinica == 0)
        {
            cout << "Finalizando carga..." << endl;
            break;
        }

        cout << "Ingrese la edad: ";
        cin >> pacientes[i].edad;
        cin.ignore();

        cout << "Ingrese el diagnóstico: ";
        getline(cin >> ws, pacientes[i].diagnóstico);

        cout << "Datos de contacto en caso de emergencia:" << endl;
        cout << "Ingrese el nombre del contacto: ";
        getline(cin >> ws, pacientes[i].contactoDeEmergencia.nombre);

        cout << "Ingrese el telefono del contacto: ";
        cin >> pacientes[i].contactoDeEmergencia.telefono;
        cin.ignore();

        dl++;
    }
}

void buscarPaciente(Paciente pacientes[], int dl)
{
    int historiaClinicaTemporal;
    cout << "Ingrese el numero de historia clinica del paciente a buscar: ";
    cin >> historiaClinicaTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(pacientes[i].numeroHistoriaClinica == historiaClinicaTemporal)
        {
            encontrado = true;
            cout << "Datos del paciente:" << endl;
            cout << "Nombre y apellido: " << pacientes[i].nombreApellido << endl;
            cout << "Numero de historia clinica: " << historiaClinicaTemporal << endl;
            cout << "Edad: " << pacientes[i].edad << endl;
            cout << "Diagnostico: " << pacientes[i].diagnóstico << endl;
            cout << "Nombre de contacto de emergencia: " << pacientes[i].contactoDeEmergencia.nombre << endl;
            cout << "Telefono de contacto de emergencia: " << pacientes[i].contactoDeEmergencia.telefono << endl;
            break;
        }
    }

    if(!encontrado)
    {
        cout << "El numero de historia clinica ingresado no corresponde a ningun paciente registrado." << endl;
    }
}

void buscarDiagnosticos(Paciente pacientes[], int dl)
{
    string diagnosticoTemporal;
    cout << "Ingrese el diagnostico a buscar: ";
    cin >> diagnosticoTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(pacientes[i].diagnóstico == diagnosticoTemporal)
        {
            encontrado = true;
            cout << "Listado de pacientes con el diagnostico: " << diagnosticoTemporal << endl;
            cout << "Nombre y apellido: " << pacientes[i].nombreApellido << endl;
            cout << "Edad: " << pacientes[i].edad << endl;
            cout << "----------" << endl;
        }
    }

    if(!encontrado)
    {
        cout << "No hay pacientes con dicho diagnostico." << endl;
    }
}

int main()
{
    Paciente pacientes[MAX_PACIENTES];
    int dl = 0;

    altaPaciente(pacientes, dl);
    buscarPaciente(pacientes, dl);
    buscarDiagnosticos(pacientes, dl);

    return 0;
}