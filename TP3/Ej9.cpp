#include <iostream>
#include <string>
using namespace std;

/*
Desarrollar un programa que realice las siguientes operaciones en listas enlazadas simples de números enteros:
A. Cargar una lista insertando los elementos ordenados en forma descendente. Finaliza luego de ingresar
el cero, que también se debe agregar a la lista.
B. Eliminar las ocurrencias de los números que son múltiplos de 3.
C. Imprimir la lista antes y después de la eliminación.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if (inicio == nullptr || nuevoNodo -> dato > inicio -> dato) // Si la lista está vacía o el valor del nuevo nodo es mayor que el valor del primer elemento, insertar al inicio
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && aux -> siguiente -> dato > nuevoNodo -> dato) // Si la lista no llegó al final y el siguiente elemento contiene un valor mayor que el dato del nuevo nodo, avanzar
        {
            aux = aux -> siguiente;
        }
        if(aux -> siguiente != nullptr) // Si la lista no llegó al final pero el siguiente elemento contiene un valor menor o igual que el dato del nuevo nodo, insertar después del valor apuntado por auxiliar
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
    
    do
    {
        cout << "Ingrese un numero (0 para finalizar): ";
        cin >> numeroIngresado;

        nuevoNodo = new Nodo;
        nuevoNodo -> dato = numeroIngresado;
        nuevoNodo -> siguiente = nullptr;

        insertarOrdenado(inicio, nuevoNodo);
    } while (numeroIngresado != 0);
}

void imprimirLista(Nodo* inicio)
{
    Nodo* aux = inicio;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        cout << aux -> dato << " -> ";
    }
    cout << "NULL" << endl;
}

void eliminarMultiplos(Nodo* &inicio, int multiplo)
{
    Nodo* aEliminar;
    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        if(inicio -> dato % multiplo == 0) // Si el primer elemento es múltiplo
        {
            aEliminar = inicio; // aEliminar apunta al elemento inicial de la lista
            aux = aux -> siguiente; // Auxiliar apunta al elemento que le sigue
            inicio = inicio -> siguiente; // El inicio de la lista se convierte en el siguiente elemento
            delete aEliminar; // Se elimina el elemento del inicio de la lista
        }
        else if(aux -> siguiente != nullptr && aux -> siguiente -> dato % multiplo == 0) // Si La lista no llegó al final y el siguiente dato apuntado por auxiliar es multiplo
        {
            aEliminar = aux -> siguiente; // aEliminar apunta al apuntado por auxiliar
            aux -> siguiente = aux -> siguiente -> siguiente; // Auxiliar apunta al siguiente de su siguiente
            delete aEliminar; // Se elimina el elemento apuntado por auxiliar en un principio
        }
        else
        {
            aux = aux -> siguiente;
        }
    }
}

int main()
{
    Nodo* inicio = nullptr; // Puntero al inicio de la lista

    int multiplo = 3;

    cargarNumeros(inicio);

    cout << "Lista completa: " << endl;
    imprimirLista(inicio);

    eliminarMultiplos(inicio, multiplo);

    cout << "Lista sin los multiplos de 3: " << endl;
    imprimirLista(inicio);

    return 0;
}