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



int main()
{

    return 0;
}