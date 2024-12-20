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

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if (inicio == nullptr || nuevoNodo -> dato < inicio -> dato) // Si la lista está vacía o el valor del nuevo nodo es menor que el valor del primer elemento, insertar al inicio
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && aux -> siguiente -> dato < nuevoNodo -> dato) // Si la lista no llegó al final y el siguiente elemento contiene un valor menor que el dato del nuevo nodo, avanzar
        {
            aux = aux -> siguiente;
        }
        if(aux -> siguiente != nullptr) // Si la lista no llegó al final pero el siguiente elemento contiene un valor mayor o igual que el dato del nuevo nodo, insertar después del valor apuntado por auxiliar
        {
            nuevoNodo -> siguiente = aux -> siguiente; // El nuevo nodo apunta a lo que apuntaba auxiliar para colocarse adelante de auxiliar
        }
        aux -> siguiente = nuevoNodo;
        /*
        - El elemento apuntado por auxiliar apunta al nuevo nodo entonces queda detrás del nuevo nodo (Caso que el siguiente elemento contiene un valor mayor o igual que el dato del nuevo nodo si entró en el if)
        - Si no entró al if, entonces este nuevo nodo es el mayor valor de la lista y se coloca al final
        */
    }
}

void cargarNumeros(Nodo* &inicio)
{
    Nodo* nuevoNodo;
    int numeroIngresado;
    cout << "Ingrese un numero (0 para finalizar): ";
    cin >> numeroIngresado;

    while(numeroIngresado != 0)
    {
        nuevoNodo = new Nodo;
        nuevoNodo -> dato = numeroIngresado;
        nuevoNodo -> siguiente = nullptr;

        insertarOrdenado(inicio, nuevoNodo);

        cout << "Ingrese un numero (0 para finalizar): ";
        cin >> numeroIngresado;
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

    cargarNumeros(inicio);

    mostrarLista(inicio);

    return 0;
}