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

/*
Otra variante:
Nodo* crearNodo(int dato)
{
	Nodo* nuevoNodo = new Nodo; // Crear nodo
	nuevoNodo -> dato = dato; // Asignar dato
	nuevoNodo -> siguiente = nullptr; // Asignar siguiente
	return nuevoNodo;
}

Nodo* insertarAlInicio(Nodo* &inicio, int dato)
{
	Nodo* nuevo = crearNodo(dato);
	nuevo -> siguiente = inicio;
	inicio = nuevo;
	return inicio;
}
*/

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
        insertarAlInicio(inicio, valor);
        cout << "Ingrese un numero (0 para terminar): ";
    }

    mostrarLista(inicio);
    return 0;
}