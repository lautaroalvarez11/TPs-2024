#include <iostream>
#include <string>
using namespace std;

/*
Implementar una función que reciba dos listas enlazadas simples con datos de tipo string ordenadas según el
alfabeto y retorne una tercera lista ordenada por el mismo criterio, conformada por todos los elementos de las listas originales (merge).
Una función merge se encarga de recibir dos listas enlazadas ordenadas y devolver una nueva lista enlazada que contenga todos los elementos de ambas listas en orden alfabético.
Agregar las funciones auxiliares que sean necesarias para cumplir con este propósito.
*/

// Estructura de Nodo
struct Nodo
{
    string dato;
    Nodo* siguiente;
};

void insertarOrdenado(Nodo* &inicio, string palabra)
{
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo -> dato = palabra;
    nuevoNodo -> siguiente = nullptr;

    if (inicio == nullptr || inicio -> dato > palabra)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && aux -> siguiente -> dato <= palabra)
        {
            aux = aux -> siguiente;
        }
        nuevoNodo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevoNodo;
    }
}

void imprimirLista(Nodo* inicio)
{
    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        cout << aux -> dato << " -> ";
        aux = aux -> siguiente;
    }
    cout << "NULL" << endl;
}

// Función para fusionar dos listas enlazadas en una tercera lista ordenada
Nodo* mergeListas(Nodo* lista1, Nodo* lista2)
{
    Nodo* listaFusionada = nullptr;
    Nodo* aux1 = lista1;
    Nodo* aux2 = lista2;

    while (aux1 != nullptr && aux2 != nullptr)
    {
        if (aux1 -> dato < aux2 -> dato)
        {
            insertarOrdenado(listaFusionada, aux1 -> dato);
            aux1 = aux1 -> siguiente;
        }
        else{
            insertarOrdenado(listaFusionada, aux2 -> dato);
            aux2 = aux2 -> siguiente;
        }
    }

    // Insertar los elementos restantes de lista1
    while (aux1 != nullptr)
    {
        insertarOrdenado(listaFusionada, aux1 -> dato);
        aux1 = aux1 -> siguiente;
    }

    // Insertar los elementos restantes de lista2
    while (aux2 != nullptr)
    {
        insertarOrdenado(listaFusionada, aux2 -> dato);
        aux2 = aux2 -> siguiente;
    }

    return listaFusionada;
}

void ingresarPalabras(Nodo* &inicio)
{
    string palabra;
    cout << "Ingrese palabras (escriba 'x' para terminar): ";
    getline(cin >> ws, palabra);

    while (palabra != "x")
    {
        insertarOrdenado(inicio, palabra);
        cout << "Ingrese palabras (escriba 'x' para terminar): ";
        getline(cin >> ws, palabra);
    }
}

int main()
{
    Nodo* lista1 = nullptr;
    Nodo* lista2 = nullptr;

    cout << "Ingresar palabras para la Lista 1:" << endl;
    ingresarPalabras(lista1);

    cout << "Ingresar palabras para la Lista 2:" << endl;
    ingresarPalabras(lista2);

    cout << "Lista 1:" << endl;
    imprimirLista(lista1);

    cout << "Lista 2:" << endl;
    imprimirLista(lista2);

    // Fusionar las dos listas
    Nodo* listaFusionada = mergeListas(lista1, lista2);

    cout << "Lista fusionada:" << endl;
    imprimirLista(listaFusionada);

    return 0;
}