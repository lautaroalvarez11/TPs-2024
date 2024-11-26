#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que, dadas dos listas enlazadas simples, retorne true si ambas listas tienen la misma longitud (cantidad de nodos), false en caso contrario.
Optimizar la función para que, en caso de que una lista sea más corta que la otra (por ejemplo, la lista A tiene 10000 nodos y la lista B tiene 5 nodos), no se continúe contabilizando la cantidad de nodos de la lista más larga.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlInicio(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero; // Agregar numero al nodo
    nuevoNodo -> siguiente = inicio; // Que el nuevo nodo apunte al puntero inicio
    inicio = nuevoNodo; // Que el nuevo nodo sea el inicio, osea el primer elemento
    return inicio;
}

bool mismasLongitudes(Nodo* lista1, Nodo* lista2)
{
    if (lista1 == nullptr && lista2 == nullptr) // Caso base: Si ambas listas son nulas al mismo tiempo
    {
        return true;
    }
    
    if (lista1 == nullptr || lista2 == nullptr) // Caso base: Si una lista es nula pero la otra no
    {
        return false;
    }

    return mismasLongitudes(lista1 -> siguiente, lista2 -> siguiente); // Caso recursivo: Continuar comparando los siguientes nodos de ambas listas
}

int main()
{
    Nodo* lista1 = nullptr;
    Nodo* lista2 = nullptr;

    int numero;

    cout << "Ingrese numeros para la primera lista (-1 para finalizar): ";
    cin >> numero;
    while (numero != -1)
    {
        lista1 = insertarAlInicio(lista1, numero);
        cout << "Ingrese otro numero para la primera lista (-1 para finalizar): ";
        cin >> numero;
    }

    cout << "Ingrese numeros para la segunda lista (-1 para finalizar): ";
    cin >> numero;
    while (numero != -1)
    {
        lista2 = insertarAlInicio(lista2, numero);
        cout << "Ingrese otro numero para la segunda lista (-1 para finalizar): ";
        cin >> numero;
    }

    if (!mismasLongitudes(lista1, lista2))
    {
        
        cout << "Las listas no tienen la misma longitud." << endl;
    }
    else
    {
        cout << "Las listas tienen la misma longitud." << endl;
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo (listas iguales en longitud):
    Lista1 = 1 -> 2 -> nullptr
    Lista2 = 3 -> 4 -> nullptr
1. El usuario ingresa los números para la primera lista, que se van añadiendo al inicio:
    - Primer número: 2 -> Lista1 = 2 -> nullptr
    - Segundo número: 1 -> Lista1 = 1 -> 2 -> nullptr
2. Luego, el usuario ingresa los números para la segunda lista:
    - Primer número: 4 -> Lista2 = 4 -> nullptr
    - Segundo número: 3 -> Lista2 = 3 -> 4 -> nullptr
3. Se llama a la función `mismasLongitudes` con las dos listas.
4. La función compara los nodos uno a uno:
    - Nodo1 (Lista1: 1, Lista2: 3): Ambos existen, pasa al siguiente nodo.
    - Nodo2 (Lista1: 2, Lista2: 4): Ambos existen, pasa al siguiente nodo.
    - Nodo3 (Lista1: nullptr, Lista2: nullptr): Ambas listas son nulas, retorna true.
5. Se muestra el mensaje "Las listas tienen la misma longitud."

Ejemplo (listas desiguales en longitud):
    Lista1 = 1 -> nullptr
    Lista2 = 3 -> 4 -> nullptr
1. Al llegar al segundo nodo, Lista1 es nula y Lista2 no lo es.
2. La función retorna false, indicando que las listas no tienen la misma longitud.
*/