#include <iostream>
#include <string>
using namespace std;

/*
Generar una lista con los datos personales de los alumnos de un colegio (legajo, apellido y nombre, DNI) y las
notas de tres materias: matemática, literatura y geografía (para cada alumno se cargarán las tres materias). Las
notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas, volviendo a pedir una
nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor en el rango indicado. Se pide
informar la cantidad de alumnos que aprobaron las tres materias (se aprueba con 7) y el porcentaje que
representan los aprobados sobre el total de alumnos.
*/

struct Alumno
{
    int legajo, dni, notas[3]; // 0: Matemática; 1: Literatura; 2: Geografía
    string apellido, nombre;
};

struct Nodo
{
    Alumno dato;
    Nodo* siguiente;
};

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

Nodo* crearNodo(Alumno info)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = info;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void cargarAlumno(Nodo* &inicio)
{
    Nodo* nuevoNodo;
    Alumno info;

    cout << "Ingrese el legajo del alumno (-1 para finalizar): ";
    cin >> info.legajo;
    cin.ignore();

    while(info.legajo != -1)
    {
        cout << "Ingrese el apellido del alumno: ";
        getline(cin >> ws, info.apellido);

        cout << "Ingrese el nombre del alumno: ";
        getline(cin >> ws, info.nombre);

        cout << "Ingrese el DNI del alumno: ";
        cin >> info.dni;
        cin.ignore();

        do
        {
            cout << "Ingrese la nota obtenida en Matematica: ";
            cin >> info.notas[0];
            cin.ignore();
            if(info.notas[0] < 1 || info.notas[0] > 10)
            {
                cout << "Por favor ingrese una nota valida (1-10)." << endl;
            }
        } while(info.notas[0] < 1 || info.notas[0] > 10);

        do
        {
            cout << "Ingrese la nota obtenida en Literatura: ";
            cin >> info.notas[1];
            cin.ignore();
            if(info.notas[1] < 1 || info.notas[1] > 10)
            {
                cout << "Por favor ingrese una nota valida (1-10)." << endl;
            }
        } while(info.notas[1] < 1 || info.notas[1] > 10);

        do
        {
            cout << "Ingrese la nota obtenida en Geografia: ";
            cin >> info.notas[2];
            cin.ignore();
            if(info.notas[2] < 1 || info.notas[2] > 10)
            {
                cout << "Por favor ingrese una nota valida (1-10)." << endl;
            }
        } while(info.notas[2] < 1 || info.notas[2] > 10);

        Nodo* nuevoAlumno = crearNodo(info);
        insertarAlFinal(inicio, nuevoAlumno);

        cout << "Ingrese el legajo del alumno (-1 para finalizar): ";
        cin >> info.legajo;
        cin.ignore();
    }
}

void informarAprobados(Nodo* inicio)
{
    int cantidadAprobados = 0;

    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        if(aux -> dato.notas[0] < 7 || aux -> dato.notas[1] < 7 || aux -> dato.notas[2] < 7)
        {
            cout << "El alumno/a con legajo " << aux -> dato.legajo << " no fue aprobado/a ya que se necesita obtener 7 o mas en las tres materias." << endl;
            cout << "Sus notas son:" << endl;
            cout << "Matematica: " << aux -> dato.notas[0] << endl;
            cout << "Literatura: " << aux -> dato.notas[1] << endl;
            cout << "Geografia: " << aux -> dato.notas[2] << endl;
            cout << "----------" << endl;
        }
        else
        {
            cantidadAprobados++;
            cout << "El alumno/a con legajo " << aux -> dato.legajo << " esta aprobado ya que tiene aprobada las tres materias." << endl;
            cout << "Sus notas son:" << endl;
            cout << "Matematica: " << aux -> dato.notas[0] << endl;
            cout << "Literatura: " << aux -> dato.notas[1] << endl;
            cout << "Geografia: " << aux -> dato.notas[2] << endl;
            cout << "----------" << endl;
        }
        aux = aux -> siguiente;
    }

    cout << "Cantidad de alumnos aprobados: " << cantidadAprobados << endl;
}

void informarPorcentajeAprobados(Nodo* inicio)
{
    int totalAlumnos = 0;
    int cantidadAprobados = 0;

    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        totalAlumnos++;

        if(aux -> dato.notas[0] >= 7 && aux -> dato.notas[1] >= 7 && aux -> dato.notas[2] >= 7)
        {
            cantidadAprobados++;
        }
        
        aux = aux->siguiente;
    }

    if (totalAlumnos == 0)
    {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    // Con 'static_cast<float>' se asegura de que la división sea con `float` para un resultado correcto
    float porcentajeAprobados = (static_cast<float>(cantidadAprobados) / totalAlumnos) * 100;

    cout << "Cantidad total de alumnos: " << totalAlumnos << endl;
    cout << "Cantidad de alumnos aprobados en las tres materias: " << cantidadAprobados << endl;
    cout << "Porcentaje de aprobados: " << porcentajeAprobados << "%" << endl;
}

int main()
{
    Nodo* inicio = nullptr;
    Alumno dato;

    cargarAlumno(inicio);

    informarAprobados(inicio);

    informarPorcentajeAprobados(inicio);

    return 0;
}