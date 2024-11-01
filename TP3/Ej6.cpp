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
    while(getline(cin >> ws, nombreAlumno) && nombreAlumno != "x" && nombreAlumno != "X")
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
            cout << "Alumno encontrado.";
            break;
		}
	}
	if(!encontrado)
    {
        cout << "Alumno no encontrado.";
    }
}

int main()
{
    Nodo* inicio = nullptr;

    cargarNombre(inicio);

    buscarAlumno(inicio);

    imprimirLista(inicio);

    return 0;
}