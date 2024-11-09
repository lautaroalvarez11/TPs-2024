#include <iostream>
#include <string>
using namespace std;

/*
1)
Dado el siguiente código:
int* p = new int;
int* q = p;
Escribir las instrucciones para:
a) Almacenar el número 10 en el espacio de memoria apuntado por p.
b) Imprimir el valor apuntado por p.
c) Almacenar el número 20 en el espacio de memoria apuntado por q.
d) Imprimir el valor apuntado por q y luego el apuntado por p.

2)
Dada una lista enlazada simple de números enteros, hacer una función que:
Informe la cantidad de números pares en la lista.
Informe la cantidad de números impares en la lista. Implementar la función con los parámetros que considere necesarios.

3)
Analizar el siguiente programa e indicar qué salida produce si se ingresan los números 10, 15, 12, 8, 6, 11, 9, 0:
struct Nodo
{
    int valor;
    Nodo* siguiente;
};

Nodo* insertarCircular(Nodo* fin, Nodo* nuevo)
{
    if(fin == nullptr)
    {
        nuevo->siguiente = nuevo;
        return nuevo;
    }
    else
    {
        nuevo->siguiente = fin->siguiente;
        fin->siguiente = nuevo;
        return fin;
    }
}

Nodo* cargarNumeros(Nodo* fin)
{
    int numero;
    Nodo* nuevo;
    cout << "Ingrese un numero (0 para terminar): ";
    cin >> numero;
    while(numero != 0)
    {
        nuevo = new Nodo;
        nuevo->valor = numero;
        fin = insertarCircular(fin, nuevo);
        cout << "Ingrese un numero (0 para terminar): ";
        cin >> numero;
    }
    return fin;
}

void imprimirCircular(Nodo* fin)
{
    if(fin != nullptr)
    {
        Nodo* aux = fin->siguiente;
        do
        {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        } while(aux != fin->siguiente);
    }
}

int main()
{
    Nodo* fin = nullptr;
    fin = cargarNumeros(fin);
    imprimirCircular(fin);

    return 0;
}

4)
Una universidad quiere implementar un sistema de registro de estudiantes. Los datos de cada estudiante incluyen:
- Número de matrícula, apellido, nombre, DNI.
- Notas de tres asignaturas: Programación, Matemática y Física.
El sistema requiere dos funcionalidades:
A. Carga de datos: Realizar la carga de estudiantes en una lista enlazada simple, insertando al final.
B. Reporte de aprobados: Contar e informar cuántos estudiantes aprobaron las tres materias (se aprueba con 7) y mostrar el porcentaje de aprobados.

Estructuras sugeridas:
struct Estudiante
{
    int matricula;
    string nombre;
    long dni;
    float notas[3]; // 0: Programación; 1: Matemática; 2: Física
};

struct Nodo
{
    Estudiante estudiante;
    Nodo* siguiente;
};

5)
Se desea implementar un sistema para registrar productos en una tienda. Los datos de cada producto son:
- Código, nombre, precio unitario, cantidad en stock.
El sistema requiere las siguientes funcionalidades:
A. Carga de productos: Insertar productos en una lista enlazada simple de forma ordenada, de mayor a menor precio.
B. Inventario bajo: Informar cuántos productos tienen un stock inferior a 5 unidades.

Estructuras sugeridas:
struct Producto
{
    int codigo;
    string nombre;
    float precio;
    int cantidadStock;
};

struct Nodo
{
    Producto producto;
    Nodo* siguiente;
};
*/