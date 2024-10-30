#include <iostream>
#include <string>
using namespace std;

/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
Finalmente, imprimir la lista.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarOrdenado(Nodo* &inicio, int valor)
{
    Nodo* nuevoNodo = new Nodo(); // Crear un nuevo nodo
    nuevoNodo -> dato = valor;
    nuevoNodo -> siguiente = nullptr;

    // Si la lista está vacía o el valor es menor que el primer elemento, insertar al inicio
    if (inicio == nullptr || valor < inicio -> dato)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        // Buscar la posición correcta
        Nodo* actual = inicio;
        while (actual -> siguiente != nullptr && actual -> siguiente -> dato <= valor)
        {
            actual = actual -> siguiente;
        }
        // Insertar el nuevo nodo antes de la primera ocurrencia mayor al valor
        nuevoNodo -> siguiente = actual -> siguiente;
        actual -> siguiente = nuevoNodo;
    }
}

void mostrarLista(Nodo* inicio)
{
    Nodo* actual = inicio; // Puntero temporal para recorrer la lista
    while(actual != nullptr)
    {
        cout << actual -> dato << " -> ";
        actual = actual -> siguiente;
    }
    cout << "NULL" << endl;
}

int main()
{
    Nodo* inicio = nullptr; // Puntero al inicio de la lista
    int valor;

    cout << "Ingrese un numero (0 para terminar): ";
    while (cin >> valor && valor != 0)
    {
        insertarOrdenado(inicio, valor); // Insertar en orden
        cout << "Ingrese un numero (0 para terminar): ";
    }

    mostrarLista(inicio); // Muestra la lista enlazada

    return 0;
}