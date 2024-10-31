#include <iostream>
#include <string>
using namespace std;

/*
Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
cual no debe insertarse en la lista).
A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres repetidos).
*/

struct Nodo
{
    string dato;
    Nodo* siguiente;
};

void cargarNombres(Nodo* &cabeza)
{
    string nombre;
    cout << "Ingrese el nombre de un alumno ('x' para terminar): ";
    while (getline(cin >> ws, nombre) && nombre != "x" && nombre != "X")
    {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo -> dato = nombre;
        nuevoNodo -> siguiente = nullptr;

        if (cabeza == nullptr)
        {
            cabeza = nuevoNodo;
        }
        else
        {
            Nodo* actual = cabeza;
            while (actual -> siguiente != nullptr)
            {
                actual = actual -> siguiente;
            }
            actual -> siguiente = nuevoNodo;
        }
        
        cout << "Ingrese el nombre de un alumno ('x' para terminar): ";
    }
}

void mostrarLista(Nodo* cabeza)
{
    Nodo* actual = cabeza;
    while (actual != nullptr)
    {
        cout << actual -> dato << " -> ";
        actual = actual -> siguiente;
    }
    cout << "NULL" << endl;
}

void buscarNombre(Nodo* cabeza)
{
    string nombreBuscado;
    cout << "Ingrese el nombre de un alumno a buscar: ";
    getline(cin >> ws, nombreBuscado);

    Nodo* actual = cabeza;
    bool encontrado = false;
    while (actual != nullptr)
    {
        if (actual -> dato == nombreBuscado)
        {
            encontrado = true;
            break;
        }
        actual = actual -> siguiente;
    }

    if (encontrado)
    {
        cout << nombreBuscado << " se encuentra en la lista." << endl;
    }
    else
    {
        cout << nombreBuscado << " no se encuentra en la lista." << endl;
    }
}

void eliminarNombre(Nodo* &cabeza)
{
    string nombreEliminar;
    cout << "\nIngrese el nombre de la alumna a eliminar: ";
    getline(cin, nombreEliminar);

    if (cabeza == nullptr) return;

    if (cabeza->dato == nombreEliminar)
    {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << nombreEliminar << " ha sido eliminado de la lista." << endl;
    }
    else
    {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != nombreEliminar)
        {
            actual = actual->siguiente;
        }
        if (actual->siguiente != nullptr)
        {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            cout << nombreEliminar << " ha sido eliminado de la lista." << endl;
        }
        else
        {
            cout << nombreEliminar << " no se encuentra en la lista." << endl;
        }
    }
}

int main()
{
    Nodo* lista = nullptr;

    cargarNombres(lista);

    cout << "Lista de alumnos:" << endl;
    mostrarLista(lista);

    buscarNombre(lista);

    // Eliminar "Josefina Ortega" de la lista
    eliminarNombre(lista);

    // Mostrar lista después de la eliminación
    cout << "\nLista de alumnos después de eliminar 'Josefina Ortega':\n";
    mostrarLista(lista);

    return 0;
}