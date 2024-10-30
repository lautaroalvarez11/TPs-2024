#include <iostream>
#include <string>
using namespace std;

/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
b) Al final de la lista.
Finalmente, imprimir la lista.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarAlFinal(Nodo* &inicio, int valor)
{
    Nodo* nuevoNodo = new Nodo(); // Crear un nuevo nodo
    nuevoNodo -> dato = valor; // Asignar el valor al nodo
    nuevoNodo -> siguiente = nullptr; // Al ser el último, su siguiente es nullptr

    if (inicio == nullptr) // Si la lista está vacía, el nuevo nodo es la cabeza
    {
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* actual = inicio; // Puntero para recorrer la lista
        while (actual -> siguiente != nullptr) // Ir hasta el último nodo
        {
            actual = actual -> siguiente;
        }
        actual -> siguiente = nuevoNodo; // El último nodo apunta al nuevo nodo
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
        insertarAlFinal(inicio, valor);
        cout << "Ingrese un numero (0 para terminar): ";
    }

    mostrarLista(inicio); // Muestra la lista enlazada

    return 0;
}