#include <iostream>
#include <string>
using namespace std;

/*
Dos sucursales de Fiestísima disponen cada una de una lista enlazada simple con el detalle de las ventas
realizadas. De cada venta se conoce: código de producto y cantidad vendida (un producto pudo haber sido
vendido 0, 1 o más veces en la misma sucursal). Las listas de ventas están ordenadas de menor a mayor por
código de producto. Realizar una función que reciba las dos listas y retorne una nueva lista unificando todas las
ventas, ordenada por el mismo criterio. Utilizar un algoritmo destructivo (que reutilice los nodos de las listas
originales). Agregar las funciones auxiliares que sean necesarias.
*/

struct Ventas
{
    int codigo;
    int cantidadVendidas;
};

struct Nodo
{
    Ventas dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Ventas infoVenta)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = infoVenta;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if (inicio == nullptr || inicio -> dato.codigo < nuevoNodo -> dato.codigo)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && aux -> siguiente -> dato.codigo < nuevoNodo -> dato.codigo)
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

void cargarInformacionSucursal(Nodo*& inicio, int numeroSucursal)
{
    Ventas infoVenta;

    cout << "Ingrese el codigo del producto para la sucursal " << numeroSucursal << " (-1 para finalizar): ";
    cin >> infoVenta.codigo;

    while (infoVenta.codigo != -1)
    {
        do
        {
            cout << "Ingrese la cantidad de unidades vendidas para la sucursal " << numeroSucursal << ": ";
            cin >> infoVenta.cantidadVendidas;
            if (infoVenta.cantidadVendidas < 0)
            {
                cout << "Por favor ingrese una cantidad válida (0 o más)" << endl;
            }
        } while (infoVenta.cantidadVendidas < 0);

        Nodo* nuevoNodo = crearNodo(infoVenta);
        insertarOrdenado(inicio, nuevoNodo);

        cout << "Ingrese el codigo del producto para la sucursal " << numeroSucursal << " (-1 para finalizar): ";
        cin >> infoVenta.codigo;
    }
}

Nodo* unirListas(Nodo* lista1, Nodo* lista2)
{
    Nodo* listaFusionada = nullptr;

    while (lista1 != nullptr && lista2 != nullptr)
    {
        if (lista1 -> dato.codigo < lista2 -> dato.codigo)
        {
            Nodo* nuevoNodo = crearNodo(lista1 -> dato);
            insertarOrdenado(listaFusionada, nuevoNodo);
            lista1 = lista1 -> siguiente;
        }
        else if (lista2 -> dato.codigo < lista1 -> dato.codigo)
        {
            Nodo* nuevoNodo = crearNodo(lista2 -> dato);
            insertarOrdenado(listaFusionada, nuevoNodo);
            lista2 = lista2 -> siguiente;
        }
        else // Si los códigos son iguales, sumar las cantidades
        {
            Ventas infoFusionada;
            infoFusionada.codigo = lista1 -> dato.codigo;
            infoFusionada.cantidadVendidas = lista1 -> dato.cantidadVendidas + lista2 -> dato.cantidadVendidas;
            Nodo* nuevoNodo = crearNodo(infoFusionada);
            insertarOrdenado(listaFusionada, nuevoNodo);
            lista1 = lista1 -> siguiente;
            lista2 = lista2 -> siguiente;
        }
    }

    // Si quedan nodos en lista1, se agregan a listaFusionada
    while (lista1 != nullptr)
    {
        Nodo* nuevoNodo = crearNodo(lista1 -> dato);
        insertarOrdenado(listaFusionada, nuevoNodo);
        lista1 = lista1 -> siguiente;
    }

    // Si quedan nodos en lista2, se agregan a listaFusionada
    while (lista2 != nullptr)
    {
        Nodo* nuevoNodo = crearNodo(lista2 -> dato);
        insertarOrdenado(listaFusionada, nuevoNodo);
        lista2 = lista2 -> siguiente;
    }

    return listaFusionada;
}

void imprimirLista(Nodo* lista)
{
    while (lista != nullptr)
    {
        cout << "Listado de ventas de ambas sucursales:" << endl;
        cout << "Con el codigo: " << lista -> dato.codigo << "- La cantidad vendida en total es: " << lista -> dato.cantidadVendidas << endl;
        lista = lista -> siguiente;
    }
}

int main()
{
    Nodo* lista1 = nullptr;
    Nodo* lista2 = nullptr;

    cargarInformacionSucursal(lista1, 1);
    cargarInformacionSucursal(lista2, 2);

    Nodo* listaFusionada = unirListas(lista1, lista2);
    imprimirLista(listaFusionada);

    return 0;
}