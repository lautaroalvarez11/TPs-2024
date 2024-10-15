#include <iostream>
#include <string>
using namespace std;

/*
Se solicita un programa que permita registrar y administrar la información de estudiantes en una escuela con un máximo de 1000 estudiantes. Cada estudiante tiene los siguientes datos:
    Nombre (string).
    Edad (int).
    Promedio general (float).
    Fecha de ingreso (struct) que contiene:
        Día (int).
        Mes (int).
        Año (int).
El programa debe ser capaz de realizar las siguientes operaciones:
- Alta de estudiantes: Permitir la carga de datos de los estudiantes (la carga finaliza cuando el nombre ingresado sea "FIN").
- Actualizar promedio: Solicitar el nombre de un estudiante, buscarlo y actualizar su promedio general si es encontrado. Si no existe, mostrar "Estudiante no encontrado".
- Listado de estudiantes: Mostrar todos los estudiantes que hayan ingresado en un año específico (ingresado por teclado) con sus respectivos nombres y fechas de ingreso.
*/

const int MAX_ESTUDIANTES  = 1000;

struct FechaIngreso
{
    int dia;
    int mes;
    int anio;
};

struct Estudiante
{
    string nombre;
    int edad;
    float promedioGeneral;
    FechaIngreso fechaIngreso;
};

void altaEstudiante(Estudiante estudiantes[], int &dl)
{
    if(dl >= MAX_ESTUDIANTES)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; i < MAX_ESTUDIANTES; i++)
    {
        cout << "Estudiante " << i+1 << ":" << endl;

        cout << "Nombre ('FIN' para finalizar): ";
        getline(cin >> ws, estudiantes[i].nombre);

        if(estudiantes[i].nombre == "FIN")
        {
            cout << "Finalizando carga..." << endl;
            break;
        }

        cout << "Edad: ";
        cin >> estudiantes[i].edad;
        cin.ignore();

        cout << "Promedio general: ";
        cin >> estudiantes[i].promedioGeneral;
        cin.ignore();

        cout << "Dia de ingreso: ";
        cin >> estudiantes[i].fechaIngreso.dia;
        cin.ignore();

        cout << "Mes de ingreso: ";
        cin >> estudiantes[i].fechaIngreso.mes;
        cin.ignore();

        cout << "Año de ingreso: ";
        cin >> estudiantes[i].fechaIngreso.anio;
        cin.ignore();

        dl++;
    }
}

void actualizarPromedio(Estudiante estudiantes[], int dl)
{
    string nombreTemporal;
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombreTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(estudiantes[i].nombre == nombreTemporal)
        {
            encontrado = true;
            cout << "Ingrese el nuevo promedio del estudiante: ";
            cin >> estudiantes[i].promedioGeneral;
        }
    }

    if(!encontrado)
    {
        cout << "No hay un alumno registrado con ese nombre en el sistema.";
    }
}

void reporteAnual(Estudiante estudiantes[], int dl)
{
    int anioTemporal;
    cout << "Ingrese el anio para buscar estudiantes ingresados en dicho anio: ";
    cin >> anioTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(estudiantes[i].fechaIngreso.anio == anioTemporal)
        {
            encontrado = true;
            cout << "Estudiantes ingresados en el anio " << anioTemporal << ": " << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Fecha de ingreso: " << estudiantes[i].fechaIngreso.dia << "/" << estudiantes[i].fechaIngreso.mes << "/" << estudiantes[i].fechaIngreso.anio << endl;
        }
    }

    if(!encontrado)
    {
        cout << "No hay estudiantes ingresados en ese anio." << endl;
    }
}

int main()
{
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int dl = 0;

    altaEstudiante(estudiantes, dl);
    actualizarPromedio(estudiantes, dl);
    reporteAnual(estudiantes, dl);

    return 0;
}