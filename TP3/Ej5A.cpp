#include <iostream>
#include <string>
using namespace std;

/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
Finalmente, imprimir la lista.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarAlInicio(Nodo* &inicio, int valor)
{
    Nodo* nuevoNodo = new Nodo(); // Crear un nuevo nodo
    nuevoNodo -> dato = valor; // Asignar el valor al nodo
    nuevoNodo -> siguiente = inicio; // El nuevo nodo apunta al antiguo inicio
    inicio = nuevoNodo; // El nuevo nodo se convierte en el nuevo inicio
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
        insertarAlInicio(inicio, valor);
        cout << "Ingrese un numero (0 para terminar): ";
    }

    mostrarLista(inicio); // Muestra la lista enlazada
    return 0;
}