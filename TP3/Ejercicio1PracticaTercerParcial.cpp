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

/* 1)
A. a = 'H';
B. cout << *a << endl;
C. b = 'P';
D. cout << *b << *a << endl;
*/

/* 2)
void informarLongitudLista(Nodo* inicio)
{
    Nodo* aux = inicio;
    int contador = 0;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        contador++;
        if(aux == nullptr)
        {
            break;
        }
    }
    cout << "La longitud de la lista es: " << contador;
}
*/

/* 3)
- Análisis del Código:
Estructura Nodo:
    Cada Nodo tiene un valor entero dato y un puntero siguiente, que apunta al próximo nodo en la lista.

Función insertar:
    Esta función inserta un nuevo nodo en una lista circular.
    Si fin es nullptr (la lista está vacía), establece el nuevo nodo como el único nodo en la lista y apunta nuevo -> siguiente a sí mismo para crear la circularidad.
    Si la lista ya tiene elementos, inserta nuevo entre fin y el primer nodo de la lista (esto hace que nuevo se vuelva el primer nodo lógicamente). La función devuelve siempre el nodo fin, que es el último nodo agregado antes de nuevo.

Función cargaDeDatos:
    Lee números y los añade a la lista circular usando insertar. Detiene la lectura al ingresar 0.
    Actualiza el puntero fin en cada inserción.

Función imprimir:
    Imprime todos los elementos de la lista comenzando por el nodo siguiente a fin (es decir, el primer nodo lógico) y continúa hasta volver al inicio de la lista.

Función main:
    Inicializa la lista como vacía (fin = nullptr).
    Llama a cargaDeDatos para crear la lista y luego imprime los elementos en el orden en que fueron ingresados.

- Ejecución con los Datos Ingresados:
Insertar 5:
    La lista está vacía (fin == nullptr).
    5 se convierte en el único nodo, apuntándose a sí mismo (5 -> 5).
    fin apunta a 5.

Insertar 9:
    Se inserta 9 entre fin (5) y el primer nodo lógico (5).
    La lista ahora es 5 -> 9 -> 5.
    fin permanece apuntando a 5.

Insertar 6:
    Se inserta 6 entre fin (5) y el primer nodo (9).
    La lista ahora es 5 -> 6 -> 9 -> 5.
    fin sigue siendo 5.

Insertar 4:
    Se inserta 4 entre fin (5) y el primer nodo (6).
    La lista es 5 -> 4 -> 6 -> 9 -> 5.

Insertar 3:
    Se inserta 3 entre fin (5) y el primer nodo (4).
    La lista es 5 -> 3 -> 4 -> 6 -> 9 -> 5.

Insertar 7:
    Se inserta 7 entre fin (5) y el primer nodo (3).
    La lista es 5 -> 7 -> 3 -> 4 -> 6 -> 9 -> 5.

Insertar 8:
    Se inserta 8 entre fin (5) y el primer nodo (7).
    La lista es 5 -> 8 -> 7 -> 3 -> 4 -> 6 -> 9 -> 5.

Ingresar 0:
    Termina la carga de datos.

- Salida:
8
7
3
4
6
9
5
*/

/* 4)
A.
Nodo* insertarAlPrincipio(Nodo* &inicio, Alumno infoAlumnos)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> alumno = infoAlumnos;
    nuevoNodo -> siguiente = inicio;
    inicio = nuevoNodo;
    return inicio;
}

void cargarAlumno(Nodo* &inicio)
{
    Alumno alumnos;

    cout << "Ingrese el legajo del alumno/a ('0' para finalizar): ";
    cin >> alumnos.legajo;

    while(alumnos.legajo != 0)
    {
        cout << "Ingrese el nombre del alumno/a: ";
        cin.ignore(); // Ignoramos el salto de línea pendiente de `cin`
        getline(cin, alumnos.nombre);

        cout << "Ingrese el DNI del alumno/a: ";
        cin >> alumnos.dni;

        do
        {
            cout << "Ingrese la nota obtenida en Matematica (1-10): ";
            cin >> alumnos.notas[0];
            if(alumnos.notas[0] < 1 || alumnos.notas[0] > 10)
            {
                cout << "Por favor vuelva a ingresar una nota valida (1-10)." << endl;
            }
        } while (alumnos.notas[0] < 1 || alumnos.notas[0] > 10);

        do
        {
            cout << "Ingrese la nota obtenida en Literatura: ";
            cin >> alumnos.notas[1];
            if(alumnos.notas[1] < 1 || alumnos.notas[1] > 10)
            {
                cout << "Por favor ingrese una nota valida (1-10)." << endl;
            }
        } while(alumnos.notas[1] < 1 || alumnos.notas[1] > 10);

        do
        {
            cout << "Ingrese la nota obtenida en Geografia: ";
            cin >> alumnos.notas[2];
            if(alumnos.notas[2] < 1 || alumnos.notas[2] > 10)
            {
                cout << "Por favor ingrese una nota valida (1-10)." << endl;
            }
        } while(alumnos.notas[2] < 1 || alumnos.notas[2] > 10);

        insertarAlPrincipio(inicio, alumnos);

        cout << "Ingrese el legajo del alumno/a ('0' para finalizar): ";
        cin >> alumnos.legajo;
    }
}

B.
void informarAprobados(Nodo* inicio)
{
    int cantidadAprobados = 0;
    Nodo* aux = inicio;

    while(aux != nullptr)
    {
        if(aux -> alumno.notas[0] >= 7 && aux -> alumno.notas[1] >= 7 && aux -> alumno.notas[2] >= 7)
        {
            cantidadAprobados++;
        }
        aux = aux -> siguiente; // Avanzamos al siguiente nodo
    }

    cout << "La cantidad de aprobados es: " << cantidadAprobados << endl;
}
*/

int main()
{

    return 0;
}