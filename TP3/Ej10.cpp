#include <iostream>
#include <string>
#include <cctype> // Para tolower
using namespace std;

/*
Cargar una lista enlazada simple con palabras ingresadas por el usuario, las cuales deben almacenarse en
minúsculas independientemente de cómo las ingrese. Luego, a partir de esa lista, generar una nueva lista con
las palabras que se encuentran repetidas. Finalmente, imprimir ambas listas.
*/

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

string convertirMinusculas(string palabra)
{
    for (int i = 0; i < palabra.length(); i++)
    {
        palabra[i] = tolower(palabra[i]);
    }
    return palabra;
}

void insertarPalabra(Nodo* &inicio, string palabra)
{
    cout << "Ingrese palabras (escriba 'fin' para terminar): ";
    getline(cin >> ws, palabra);

    while (palabra != "fin")
    {
        palabra = convertirMinusculas(palabra);
        
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->dato = palabra;
        nuevoNodo->siguiente = nullptr;

        if (inicio == nullptr)
        {
            inicio = nuevoNodo;
        }
        else
        {
            Nodo* aux = inicio;
            while (aux->siguiente != nullptr)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevoNodo;
        }

        cout << "Ingrese palabras (escriba 'fin' para terminar): ";
        getline(cin >> ws, palabra);
    }
}

void generarListaRepetidas(Nodo* inicio, Nodo* &listaRepetidas)
{
    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        string palabraActual = aux -> dato;
        Nodo* aux2 = aux -> siguiente;
        bool repetida = false;

        while (aux2 != nullptr)
        {
            if (aux2 -> dato == palabraActual)
            {
                repetida = true;
                break;
            }
            aux2 = aux2 -> siguiente;
        }

        if (repetida)
        {
            Nodo* auxRepetidas = listaRepetidas;
            bool yaEnListaRepetidas = false;

            while (auxRepetidas != nullptr)
            {
                if (auxRepetidas -> dato == palabraActual)
                {
                    yaEnListaRepetidas = true;
                    break;
                }
                auxRepetidas = auxRepetidas->siguiente;
            }

            if (!yaEnListaRepetidas)
            {
                insertarPalabra(listaRepetidas, palabraActual);
            }
        }
        aux = aux->siguiente;
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
    Nodo* listaOriginal = nullptr;
    Nodo* listaRepetidas = nullptr;
    string palabra;

    insertarPalabra(listaOriginal, palabra);

    generarListaRepetidas(listaOriginal, listaRepetidas);

    cout << "Lista de palabras originales:" << endl;
    imprimirLista(listaOriginal);

    cout << "Lista de palabras repetidas:" << endl;
    imprimirLista(listaRepetidas);

    return 0;
}