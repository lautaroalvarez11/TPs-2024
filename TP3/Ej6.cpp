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
    string nombre;
    Nodo* siguiente;
};

void cargarNombre(Nodo* &inicio)
{
    string nombreAlumno;
    cout << "Ingrese el nombre del alumno ('x' para finalizar): ";
    getline(cin >> ws, nombreAlumno);

    while(nombreAlumno != "x" && nombreAlumno != "X")
    {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo -> nombre = nombreAlumno;
        nuevoNodo -> siguiente = nullptr;

        if(inicio == nullptr)
        {
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
        cout << "Ingrese el nombre del alumno ('x' para finalizar): ";
        getline(cin >> ws, nombreAlumno);
    }
}

void imprimirLista(Nodo* inicio)
{
	Nodo* aux = inicio;
	for(aux; aux != nullptr; aux = aux -> siguiente)
	{
		cout << aux -> nombre << endl;
	}
}

void buscarAlumno(Nodo* inicio)
{
    string nombreBuscado;
    cout << "Ingrese el nombre a buscar: ";
    getline(cin >> ws, nombreBuscado);

    bool encontrado = false;

	Nodo* aux = inicio;
	for(aux; aux != nullptr; aux = aux -> siguiente)
	{
		if(aux -> nombre == nombreBuscado)
		{
            encontrado = true;
            cout << "Alumno encontrado." << endl;
            break;
		}
	}
	if(!encontrado)
    {
        cout << "Alumno no encontrado." << endl;
    }
}

void eliminarAlumnos(Nodo* &inicio, string alumnoEliminar)
{
    Nodo* aEliminar;
    Nodo* aux = inicio;

    while(aux != nullptr)
    {
        if(inicio -> nombre == alumnoEliminar) // Si el primer elemento es el alumno a eliminar
        {
            aEliminar = inicio; // Guardar en aEliminar el primer elemento
            aux = aux -> siguiente; // Auxiliar cambia de posición porque arrancó desde el inicio
            inicio = inicio -> siguiente; // El inicio se modifica y pasa a ser el siguiente elemento
            delete aEliminar; // Se elimina el primer elemento
        }
        else if(aux -> siguiente != nullptr && aux -> siguiente -> nombre == alumnoEliminar) // Si auxiliar no llegó al final de la lista y el siguiente elemento que le sigue al apuntado por auxiliar es el alumno a eliminar
        {
            aEliminar = aux -> siguiente; // aEliminar apunta al siguiente del apuntado por auxiliar
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
    Nodo* inicio = nullptr;

    string alumnoEliminar = "Josefina Ortega";

    cargarNombre(inicio);

    buscarAlumno(inicio);

    cout << "Lista completa de alumnos:" << endl;
    imprimirLista(inicio);

    eliminarAlumnos(inicio, alumnoEliminar);

    cout << "Lista de alumnos despues de eliminar a " << alumnoEliminar << ":" << endl;
    imprimirLista(inicio);

    return 0;
}