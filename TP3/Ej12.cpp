#include <iostream>
#include <string>
using namespace std;

/*
Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1.
Se solicita:
A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.
B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.
C. Eliminar de la lista los artículos que no tienen stock.
*/

struct Articulos
{
    int codigo;
    string descripcion;
    float precio;
    int stock;
};

struct Nodo
{
    Articulos dato;
    Nodo* siguiente;
};

void insertarAlFinal(Nodo* &inicio, Nodo* nuevoNodo)
{
    if (inicio == nullptr)
    {
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr)
        {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }
}

Nodo* crearNodo(Articulos dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo -> dato = dato;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void cargarArticulos(Nodo* &inicio)
{
    Nodo* nuevoNodo;
    Articulos articulo;

    cout << "Ingrese el codigo del articulo (-1 para terminar): ";
    cin >> articulo.codigo;
    cin.ignore();

    while(articulo.codigo != -1)
    {
        cout << "Ingrese la descripcion del producto: ";
        getline(cin >> ws, articulo.descripcion);
        cout << "Ingrese el precio del producto: ";
        cin >> articulo.precio;
        cout << "Ingrese el stock del producto: ";
        cin >> articulo.stock;
        cin.ignore();

        Nodo* nuevoArticulo = crearNodo(articulo); // Se crea un nuevo nodo con el nuevo articulo
        insertarAlFinal(inicio, nuevoArticulo);

        cout << "Ingrese el codigo del articulo (-1 para terminar): ";
        cin >> articulo.codigo;
        cin.ignore();
    }
}

void incrementarPrecio(Nodo* inicio, Articulos articulo)
{
    int porcentaje;
    cout << "Ingrese el porcentaje de incremento: ";
    cin >> porcentaje;

    Nodo* aux = inicio;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        cout << "Precio actual del articulo con codigo " << aux -> dato.codigo << " : $" << aux -> dato.precio << endl;
        aux -> dato.precio += (aux -> dato.precio * porcentaje / 100);
        cout << "Precio actualizado del articulo con codigo " << aux -> dato.codigo << " : $" << aux -> dato.precio << endl;
        cout << "----------" << endl;
    }
}

void incrementarStock(Nodo* inicio, Articulos articulo)
{
    int codigoAux;
    cout << "Ingrese el codigo del articulo a incrementar stock: ";
    cin >> codigoAux;

    bool encontrado = false;

    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        if(aux -> dato.codigo == codigoAux)
        {
            encontrado = true;
            cout << "Stock actual: " << aux -> dato.stock << endl;
            int nuevoStock;
            cout << "Ingrese el stock a sumar en el articulo: ";
            cin >> nuevoStock;
            aux -> dato.stock += nuevoStock;
            cout << "Stock actualizado: " << aux -> dato.stock << endl;
            break;
        }
        else
        {
            aux = aux -> siguiente;
        }
    }

    if(!encontrado)
    {
        cout << "El codigo ingresado no corresponde a ningun articulo" << endl;
    }
}

void imprimirLista(Nodo* inicio, Articulos articulo)
{
    Nodo* aux = inicio;
    for(aux; aux != nullptr; aux = aux -> siguiente)
    {
        cout << "Codigo: " << aux -> dato.codigo << endl;
        cout << "Descripcion: " << aux -> dato.descripcion << endl;
        cout << "Precio: $" << aux -> dato.precio << endl;
        cout << "Stock: " << aux -> dato.stock << endl;
        cout << "----------" << endl;
    }
}

void eliminarArticulo(Nodo* &inicio)
{
    Nodo* aux = inicio;
    Nodo* aux2 = nullptr;

    while (aux != nullptr)
    {
        if (aux -> dato.stock == 0)
        {
            if (aux2 == nullptr)
            {
                inicio = aux -> siguiente;
            }
            else
            {
                aux2 -> siguiente = aux -> siguiente;
            }
            Nodo* aEliminar = aux;
            aux = aux -> siguiente;
            delete aEliminar;
            cout << "Articulo sin stock eliminado con exito." << endl;
        }
        else
        {
            aux2 = aux;
            aux = aux->siguiente;
        }
    }
}

int main()
{
    Nodo* inicio = nullptr;
    Articulos articulo;

    cargarArticulos(inicio);

    incrementarPrecio(inicio, articulo);

    incrementarStock(inicio, articulo);

    cout << "Listado de articulos completa:" << endl;
    imprimirLista(inicio, articulo);

    eliminarArticulo(inicio);

    cout << "Listado de articulos despues de eliminar los que no tienen stock:" << endl;
    imprimirLista(inicio, articulo);

    return 0;
}