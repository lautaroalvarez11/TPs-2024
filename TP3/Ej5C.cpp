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
    Nodo* nuevoNodo = new Nodo();
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
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && aux -> siguiente -> dato <= valor)
        {
            aux = aux -> siguiente;
        }
        // Insertar el nuevo nodo antes de la primera ocurrencia mayor al valor
        nuevoNodo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevoNodo;
    }
}

void mostrarLista(Nodo* inicio)
{
    Nodo* aux = inicio; // Puntero auxiliar para recorrer la lista
    while(aux != nullptr)
    {
        cout << aux -> dato << " -> ";
        aux = aux -> siguiente;
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