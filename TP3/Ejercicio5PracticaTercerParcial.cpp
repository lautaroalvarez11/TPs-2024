#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Lista de Proyectos en una Empresa
Descripción: Llevar una lista de proyectos con los campos: número de proyecto, nombre del proyecto, presupuesto y duración (en meses).
- Insertar proyectos en orden de mayor a menor presupuesto.
- Eliminar proyectos con duración inferior a un valor dado.
- Mostrar todos los proyectos junto con el presupuesto total.
- Calcular y mostrar el proyecto con mayor duración y su presupuesto.
*/

struct Proyecto
{
    int numero;
    string nombre;
    int presupuesto;
    int duracion; // Meses
};

struct Nodo
{
    Proyecto dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Proyecto datoProyecto)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = datoProyecto;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr || nuevoNodo -> dato.presupuesto > inicio -> dato.presupuesto)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr && aux -> siguiente -> dato.presupuesto > nuevoNodo -> dato.presupuesto)
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

void insertarProyecto(Nodo* &inicio)
{
    Proyecto datoProyecto;

    cout << "Ingrese el numero de proyecto (0 para finalizar): ";
    cin >> datoProyecto.numero;
    cin.ignore();

    while(datoProyecto.numero > 0)
    {
        cout << "Ingrese el nombre del proyecto: ";
        getline(cin >> ws, datoProyecto.nombre);

        cout << "Ingrese el presupuesto del proyecto: $";
        cin >> datoProyecto.presupuesto;
        cin.ignore();

        cout << "Ingrese la duracion del proyecto en cantidad de meses: ";
        cin >> datoProyecto.duracion;
        cin.ignore();

        Nodo* nuevoProyecto = crearNodo(datoProyecto);
        insertarOrdenado(inicio, nuevoProyecto);

        cout << "Ingrese el numero de proyecto (0 para finalizar): ";
        cin >> datoProyecto.numero;
        cin.ignore();
    }
}

void eliminarProyecto(Nodo* &inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay proyectos en el listado" << endl;
        return;
    }

    int duracionAux;
    cout << "Ingrese una duracion en meses para eliminar proyectos con duraciones inferiores: ";
    cin >> duracionAux;

    Nodo* aux = inicio;
    Nodo* aEliminar;

    while(inicio != nullptr && inicio -> dato.duracion < duracionAux)
    {
        aEliminar = inicio;
        inicio = inicio -> siguiente;
        delete aEliminar;
    }

    while(aux != nullptr && aux -> siguiente != nullptr)
    {
        if(aux -> siguiente -> dato.duracion < duracionAux)
        {
            aEliminar = aux -> siguiente;
            aux -> siguiente = aux -> siguiente -> siguiente;
            delete aEliminar;
        }
        else
        {
            aux = aux -> siguiente;
        }
    }
}

void mostrarProyecto(Nodo* inicio)
{
    Nodo* aux = inicio;
    int presupuestoTotal = 0;

    cout << "Proyectos: " << endl;

    while(aux != nullptr)
    {
        presupuestoTotal += aux -> dato.presupuesto;
        
        cout << "- " << aux -> dato.nombre << endl;

        aux = aux -> siguiente;
    }

    cout << "----------" << endl;

    cout << "Presupuesto total de todos los proyectos: $" << presupuestoTotal << endl;
    cout << "----------" << endl;
}

void filtrarProyecto(Nodo* inicio)
{
    if (inicio == nullptr)
    {
        cout << "No hay proyectos en la lista." << endl;
        return;
    }

    Nodo* aux = inicio;
    Nodo* proyectoMayorDuracion = inicio;

    while (aux != nullptr)
    {
        if (aux -> dato.duracion > proyectoMayorDuracion -> dato.duracion)
        {
            proyectoMayorDuracion = aux;
        }
        aux = aux -> siguiente;
    }

    cout << "El proyecto con mayor duracion es: " << proyectoMayorDuracion -> dato.nombre << endl;
    cout << "Duracion: " << proyectoMayorDuracion->dato.duracion << " meses" << endl;
    cout << "Presupuesto: $" << proyectoMayorDuracion->dato.presupuesto << endl;
    cout << "----------" << endl;
}

int main()
{
    Nodo* inicio = nullptr;

    insertarProyecto(inicio);

    eliminarProyecto(inicio);

    mostrarProyecto(inicio);

    filtrarProyecto(inicio);

    return 0;
}