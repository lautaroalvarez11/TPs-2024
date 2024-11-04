#include <iostream>
#include <string>
using namespace std;

/*
Implementar una función que reciba dos parámetros: una lista enlazada simple de números enteros y un
número entero. La función debe eliminar todas las ocurrencias del número indicado en el segundo parámetro.
Retornar la cantidad de ocurrencias eliminadas.
Nota: Se debe pasar una sola vez por cada uno de los elementos de la lista.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void cargarNumeros(Nodo* &inicio)
{
    int numeroIngresado;
    cout << "Ingrese un numero en la lista (0 para finalizar): ";
    cin >> numeroIngresado;

    while(numeroIngresado != 0)
    {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo -> dato = numeroIngresado;
        nuevoNodo -> siguiente = nullptr;

        if(inicio == nullptr)
        {
            nuevoNodo -> siguiente = inicio;
            inicio = nuevoNodo;
        }
        else
        {
            Nodo* aux = inicio;
            while(aux -> siguiente != nullptr)
            {
                aux = aux -> siguiente;
            }
            aux -> siguiente = nuevoNodo;
        }

        cout << "Ingrese un numero en la lista (0 para finalizar): ";
        cin >> numeroIngresado;
    }
}

void eliminarOcurrencias(Nodo* &inicio, int numero)
{
    cout << "Ingrese el numero a eliminar en la lista: ";
    cin >> numero;

    int contador = 0;

    Nodo* aux = inicio;
    Nodo* aEliminar;
    while(aux != nullptr)
    {
        if(inicio -> dato == numero)
        {
            aEliminar = inicio;
            aux = aux -> siguiente;
            inicio = inicio -> siguiente;
            contador++;
            delete aEliminar;
        }
        else if(aux -> siguiente != nullptr && aux -> siguiente -> dato == numero)
        {
            aEliminar = aux -> siguiente;
            aux -> siguiente = aux -> siguiente -> siguiente;
            delete aEliminar;
            contador++;
        }
        else
        {
            aux = aux -> siguiente;
        }
    }

    if(contador == 0)
    {
        cout << "El numero ingresado no se encuentra en la lista" << endl;
    }
    else
    {
        cout << "Cantidad de ocurrencias que se eliminaron del numero " << numero << ": " << contador << endl;
    }
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

int main()
{
    Nodo* inicio = nullptr;
    int numero;

    cargarNumeros(inicio);

    cout << "Lista original:" << endl;
    imprimirLista(inicio);

    eliminarOcurrencias(inicio, numero);

    cout << "Lista con ocurrencias eliminadas:" << endl;
    imprimirLista(inicio);
    
    return 0;
}