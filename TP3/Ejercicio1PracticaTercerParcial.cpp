#include <iostream>
#include <string>
using namespace std;

/*
1) Dados los siguientes punteros:
char* a = new char;
char* b = a;
Escribir las instrucciones para:
a) Almacenar el caracter 'H' en el espacio de memoria apuntado por a.
b) Imprimir el caracter apuntado por a.
c) Almacenar el caracter 'P' en el espacio de memoria apuntado por b.
d) Imprimir el caracter apuntado por b y luego el apuntado por a.

2) Dada una lista enlazada simple de números enteros, hacer una función que informe la longitud de la misma,
o sea la cantidad de números almacenados en la lista. Implementar la función con los parámetros que considere necesarios.

3) Analizar el siguiente programa e indicar que salida produce su ejecución si se ingresan los números 5,9,6,4,3,7,8,0:
struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertar(Nodo* fin, Nodo* nuevo)
{
    if(fin == nullptr)
    {
        nuevo -> siguiente = nuevo;
        return nuevo;
    }
    else
    {
        nuevo -> siguiente = fin -> siguiente;
        fin -> siguiente = nuevo;
        return fin;
    }
}

Nodo* cargaDeDatos(Nodo* fin)
{
    int numero;
    Nodo* nuevo;
    cout << "Ingrese un numero (0 para cortar): ";
    cin >> numero;
    while(numero != 0)
    {
        nuevo = new Nodo;
        nuevo -> dato = numero;
        fin = insertar(fin, nuevo);
        cout << "Ingrese un numero (0 para cortar): ";
        cin >> numero;
    }
    return fin;
}

void imprimir(Nodo* fin)
{
    if(fin != nullptr)
    {
        Nodo* aux = fin -> siguiente;
        do
        {
            cout << aux -> dato << endl;
            aux = aux -> siguiente;
        } while(aux != fin -> siguiente);
    }
}

int main()
{
    Nodo* fin = nullptr;
    fin = cargaDeDatos(fin);
    imprimir(fin);

    return 0;
}

4) El colegio San Francisco requiere implementar un sistema de registro de los datos personales de sus alumnos.
De cada alumno se necesita la siguiente información: legajo, apellido, nombre, DNI y las notas de tres materias (matemática, literatura y geografia).
La ProTIC de la UNNOBA desarrolló gran parte de los módulos para este sistema. Solo faltarían implementar dos funcionalidades, las cuales,
te han sido asignadas y tendrás que desarrollarlas según los requerimientos que se describen a continuación:
a) Carga de datos: Realizar la carga de datos en base a las estructuras que se describen más abajo.
Almacenar los datos en una lista enlazada simple insertando al principio.
struct Alumno
{
    int legajo; 
    string nombre;
    long dni;
    float notas[3]; // 0: Matemática; 1: Literatura; 2: Geografía
};

struct Nodo
{
    Alumno alumno;
    Nodo* siguiente;
};
b) Reporte personalizado: Informar la cantidad de alumnos que aprobaron las tres materias (se aprueba con 7).
*/

int main()
{


    return 0;
}