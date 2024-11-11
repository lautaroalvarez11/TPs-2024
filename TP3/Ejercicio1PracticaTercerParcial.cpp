#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Gestión de Empleados
Descripción: Genera una lista que contenga los datos de los empleados de una empresa, con los campos: ID, nombre, sueldo.
Se debe permitir insertar empleados en orden de menor a mayor sueldo.
- Insertar un nuevo empleado en orden de sueldo (de menor a mayor).
- Eliminar empleados cuyo sueldo sea inferior a un valor ingresado por el usuario.
- Contar y mostrar el sueldo promedio de los empleados, además de aquellos con sueldo superior al promedio.
*/

struct Empleado
{
    int ID;
    string nombre;
    int sueldo;
};

struct Nodo
{
    Empleado dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Empleado infoEmpleado)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = infoEmpleado;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr || nuevoNodo -> dato.sueldo < inicio -> dato.sueldo)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr && aux -> siguiente -> dato.sueldo < nuevoNodo -> dato.sueldo)
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

void cargarEmpleado(Nodo* &inicio)
{
    Empleado infoEmpleado;

    cout << "Ingrese el ID del empleado (0 para finalizar): ";
    cin >> infoEmpleado.ID;
    cin.ignore();

    while(infoEmpleado.ID != 0)
    {
        cout << "Ingrese el nombre: ";
        getline(cin >> ws, infoEmpleado.nombre);

        cout << "Ingrese el sueldo: $";
        cin >> infoEmpleado.sueldo;
        cin.ignore();

        Nodo* nuevoEmpleado = crearNodo(infoEmpleado);
        insertarOrdenado(inicio, nuevoEmpleado);

        cout << "Ingrese el ID del empleado (0 para finalizar): ";
        cin >> infoEmpleado.ID;
        cin.ignore();
    }
}

void eliminarEmpleado(Nodo* &inicio)
{
    int sueldoEliminar;
    cout << "Ingrese un monto salarial para eliminar todos los empleados que tengan un sueldo menor: $";
    cin >> sueldoEliminar;

    Nodo* aEliminar;
    Nodo* aux = inicio;

    while (inicio != nullptr && inicio->dato.sueldo < sueldoEliminar) // Si el nodo inicial es el que se va a eliminar
    {
        aEliminar = inicio; // El nodo a eliminar es el inicial
        inicio = inicio->siguiente; // El nodo inicial apunta al siguiente para modificar el inicio y no perderlo
        delete aEliminar; // Se elimina el nodo
    }

    while(aux != nullptr && aux -> siguiente != nullptr)
    {
        if(aux -> siguiente -> dato.sueldo < sueldoEliminar)
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

int contarEmpleados(Nodo* inicio)
{
    int contador = 0;

    Nodo* aux = inicio;

    while(aux != nullptr)
    {
        contador++;
        aux = aux -> siguiente;
    }

    return contador;
}

void imprimirSueldo(Nodo* inicio)
{
    if (inicio == nullptr)
    {
        cout << "No hay empleados en la lista." << endl;
        return;
    }

    int sumaSueldos = 0;
    int cantidadEmpleados = contarEmpleados(inicio);

    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        sumaSueldos += aux -> dato.sueldo;
        aux = aux -> siguiente;
    }

    int sueldoPromedio = sumaSueldos / cantidadEmpleados;
    cout << "El sueldo promedio de los empleados es: $" << sueldoPromedio << endl;
    
    cout << "Empleados con sueldo superior al promedio:" << endl;
    aux = inicio;
    while (aux != nullptr)
    {
        if (aux -> dato.sueldo > sueldoPromedio)
        {
            cout << "Nombre: " << aux -> dato.nombre << endl;
            cout << "Sueldo: $" << aux -> dato.sueldo << endl;
        }
        else
        {
            cout << "No hay empleados con sueldo superior al promedio." << endl;
        }
        aux = aux -> siguiente;
    }
}

int main()
{
    Nodo* inicio = nullptr;
    Empleado infoEmpleado;

    cargarEmpleado(inicio);

    eliminarEmpleado(inicio);

    imprimirSueldo(inicio);

    return 0;
}