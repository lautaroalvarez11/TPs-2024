#include <iostream>
#include <string>
using namespace std;

/*
Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
Finalmente, imprimir la lista.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarAlInicio(Nodo* &cabeza, int valor)
{
    Nodo* nuevoNodo = new Nodo(); // Crear un nuevo nodo
    nuevoNodo -> dato = valor; // Asignar el valor al nodo
    nuevoNodo -> siguiente = cabeza; // El nuevo nodo apunta al antiguo inicio
    cabeza = nuevoNodo; // El nuevo nodo se convierte en el nuevo inicio
}

void mostrarLista(Nodo* cabeza)
{
    Nodo* actual = cabeza; // Puntero temporal para recorrer la lista
    while(actual != nullptr)
    {
        cout << actual -> dato << " -> ";
        actual = actual -> siguiente;
    }
    cout << "NULL" << endl;
}

int main()
{
    Nodo* lista = nullptr; // Puntero al inicio de la lista
    int valor;

    cout << "Ingrese un numero (0 para terminar): ";
    while (cin >> valor && valor != 0)
    {
        insertarAlInicio(lista, valor);
        cout << "Ingrese un numero (0 para terminar): ";
    }

    mostrarLista(lista); // Muestra la lista enlazada
    return 0;
}