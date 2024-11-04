#include <iostream>
#include <string>
using namespace std;

/*
Se lee de teclado una secuencia de números que finaliza con la primera ocurrencia de un número negativo, el
cual no debe ser procesado. Los números deben ser almacenados en una lista enlazada simple. Se solicita:
A. Leer de teclado un número e informar si existe en la lista.
B. Leer de teclado un número e informar la cantidad de ocurrencias del número en la lista.
C. Implementar una función que reciba la lista de números y genere dos nuevas listas, una con los
números pares y otra con los impares. Las nuevas listas deberán estar formadas con los nodos de la lista
original, la que quedará vacía después de invocar a la función.
Imprimir las listas resultantes.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr || nuevoNodo -> dato < inicio -> dato)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr && aux -> siguiente -> dato < inicio -> dato)
        {
            aux = aux -> siguiente;
        }
        if(aux -> siguiente != nullptr)
        {
            nuevoNodo -> siguiente = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }
}

void cargarNumeros(Nodo* &inicio)
{
    Nodo* nuevoNodo;
    int numeroIngresado;
    cout << "Ingrese un numero (negativo para finalizar): ";
    cin >> numeroIngresado;

    while(numeroIngresado >= 0)
    {
        nuevoNodo = new Nodo;
        nuevoNodo -> dato = numeroIngresado;
        nuevoNodo -> siguiente = nullptr;

        insertarOrdenado(inicio, nuevoNodo);

        cout << "Ingrese un numero (negativo para finalizar): ";
        cin >> numeroIngresado;
    }
}

void buscarNumero(Nodo* inicio)
{
    int numeroBuscar;
    cout << "Ingrese el numero a buscar en la lista: ";
    cin >> numeroBuscar;

    bool encontrado = false;

    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        if(aux -> dato == numeroBuscar)
        {
            encontrado = true;
            cout << "El numero " << numeroBuscar << " se encuentra en la lista." << endl;
            break;
        }
        aux = aux -> siguiente;
    }
    if(!encontrado)
    {
        cout << "El numero ingresado no pertenece a la lista." << endl;
    }
}

void contarOcurrencias(Nodo* inicio)
{
    int numeroBuscar;
    cout << "Ingrese el numero a buscar ocurrencias: ";
    cin >> numeroBuscar;

    bool encontrado = false;

    Nodo* aux = inicio;
    int contador = 0;

    while(aux != nullptr)
    {
        if(aux -> dato == numeroBuscar)
        {
            encontrado = true;
            contador++;
        }
        aux = aux -> siguiente;
    }

    if(contador == 0)
    {
        cout << "El numero ingresado no tiene ocurrencias en la lista." << endl;
    }
    else
    {
        cout << "El numero de ocurrencias que tiene el numero " << numeroBuscar << " es: " << contador << endl;
    }
}

void separarLista(Nodo* &inicio, Nodo* &listaPares, Nodo* &listaImpares)
{
    while(inicio != nullptr)
    {
        Nodo* aux = inicio;
        inicio = inicio -> siguiente;

        if(aux -> dato % 2 == 0)
        {
            aux -> siguiente = listaPares;
            listaPares = aux;
        }
        else
        {
            aux -> siguiente = listaImpares;
            listaImpares = aux;
        }
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
    Nodo* listaPares = nullptr;
    Nodo* listaImpares = nullptr;

    cargarNumeros(inicio);

    buscarNumero(inicio);

    contarOcurrencias(inicio);

    separarLista(inicio, listaPares, listaImpares);

    cout << "Lista original:" << endl;
    imprimirLista(inicio);

    cout << "Listas de Pares:" << endl;
    imprimirLista(listaPares);

    cout << "Listas de Impares:" << endl;
    imprimirLista(listaImpares);
    
    return 0;
}