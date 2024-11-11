#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Registro de Productos de un Supermercado
Descripción: Crea una lista para registrar productos, cada uno con los campos: código de producto, nombre, precio y cantidad en stock.
- Insertar productos en la lista en orden alfabético por nombre.
- Eliminar productos agotados (cuando la cantidad en stock es 0).
- Informar la cantidad de productos con precio superior a un valor ingresado por el usuario.
- Recorrer la lista y mostrar todos los productos disponibles.
*/

struct Producto
{
    int codigo;
    string nombre;
    int precio;
    int cantidad;
};

struct Nodo
{
    Producto dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Producto datosProducto)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = datosProducto;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr || nuevoNodo -> dato.nombre < inicio -> dato.nombre)
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr && aux -> siguiente -> dato.nombre < nuevoNodo -> dato.nombre)
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

void cargarProducto(Nodo* &inicio)
{
    Producto datosProducto;

    cout << "Ingrese el codigo del producto (-1 para finalizar): ";
    cin >> datosProducto.codigo;
    cin.ignore();

    while(datosProducto.codigo > -1)
    {
        cout << "Ingrese el nombre del producto: ";
        getline(cin >> ws, datosProducto.nombre);

        cout << "Ingrese el precio del producto: $";
        cin >> datosProducto.precio;
        cin.ignore();

        cout << "Ingrese la cantidad en stock del producto: ";
        cin >> datosProducto.cantidad;
        cin.ignore();

        Nodo* nuevoProducto = crearNodo(datosProducto);
        insertarOrdenado(inicio, nuevoProducto);

        cout << "Ingrese el codigo del producto (-1 para finalizar): ";
        cin >> datosProducto.codigo;
        cin.ignore();
    }
}

void eliminarProductos(Nodo* &inicio)
{
    Nodo* aEliminar;
    Nodo* aux = inicio;

    while(inicio != nullptr && inicio -> dato.cantidad < 0)
    {
        aEliminar = inicio;
        inicio = inicio -> siguiente;
        delete aEliminar;
    }

    while(aux != nullptr && aux -> siguiente != nullptr)
    {
        if(aux -> siguiente -> dato.cantidad < 0)
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

void informarProductosPrecioSuperior(Nodo* inicio)
{
    int precioConsultado;
    cout << "Ingrese un precio para filtrar los productos que superen dicho monto: $";
    cin >> precioConsultado;
    cin.ignore();

    Nodo* aux = inicio;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        if(aux -> dato.precio > precioConsultado)
        {
            cout << "Codigo del producto: " << aux -> dato.codigo << endl;
            cout << "Nombre del producto: " << aux -> dato.nombre << endl;
            cout << "Precio del producto: $" << aux -> dato.precio << endl;
            cout << "Cantidad en stock del producto: " << aux -> dato.cantidad << endl;
            cout << "----------" << endl;
        }
    }
}

void imprimirListadoCompleto(Nodo* inicio)
{
    Nodo* aux = inicio;
    int iterador = 0;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        cout << "Producto " << iterador + 1 << ":" << endl;
        cout << "Codigo del producto: " << aux -> dato.codigo << endl;
        cout << "Nombre del producto: " << aux -> dato.nombre << endl;
        cout << "Precio del producto: $" << aux -> dato.precio << endl;
        cout << "Cantidad en stock del producto: " << aux -> dato.cantidad << endl;
        iterador++;
        cout << "----------" << endl;
    }
}

int main()
{
    Nodo* inicio = nullptr;
    Producto datosProducto;

    cargarProducto(inicio);

    eliminarProductos(inicio);

    informarProductosPrecioSuperior(inicio);

    imprimirListadoCompleto(inicio);

    return 0;
}