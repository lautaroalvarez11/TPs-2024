#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Control de Inventario en una Librería
Descripción: En una librería, cada producto tiene los campos: código de producto, descripción, cantidad en stock y precio por unidad.
- Permitir agregar productos al principio de la lista.
- Eliminar un producto específico según el código ingresado por el usuario.
- Calcular y mostrar el valor total del inventario (precio por unidad * cantidad en stock) y la cantidad de productos cuyo valor de inventario supere un valor ingresado.
- Mostrar los productos con stock bajo (menor o igual a 5 unidades).
*/

struct Libro
{
    int codigo;
    string descripcion;
    int stock;
    int precio;
};

struct Nodo
{
    Libro dato;
    Nodo* siguiente;
};

void insertarAlInicio(Nodo* &inicio, Libro datoLibro)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = datoLibro;
    nuevoNodo -> siguiente = inicio;
    inicio = nuevoNodo;
}

void insertarLibro(Nodo* &inicio, Libro datoLibro)
{
    cout << "Ingrese el codigo del libro (0 para finalizar): ";
    cin >> datoLibro.codigo;
    cin.ignore();

    while(datoLibro.codigo > 0)
    {
        cout << "Ingrese la descripcion del libro: ";
        getline(cin >> ws, datoLibro.descripcion);

        cout << "Ingrese la cantidad en stock del libro: ";
        cin >> datoLibro.stock;
        cin.ignore();

        cout << "Ingrese el precio por unidad del libro: $";
        cin >> datoLibro.precio;
        cin.ignore();

        insertarAlInicio(inicio, datoLibro);

        cout << "Ingrese el codigo del libro (0 para finalizar): ";
        cin >> datoLibro.codigo;
        cin.ignore();
    }
}

void eliminarLibro(Nodo* &inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay libros registrados en el sistema." << endl;
        return;
    }

    int codigoAux;
    cout << "Ingrese el codigo del libro a eliminar: ";
    cin >> codigoAux;

    Nodo* aux = inicio;
    Nodo* aEliminar;

    while(inicio != nullptr && inicio -> dato.codigo == codigoAux)
    {
        aEliminar = inicio;
        inicio = inicio -> siguiente;
        delete aEliminar;
        cout << "Eliminado con exito" << endl;
    }

    while(aux != nullptr && aux -> siguiente != nullptr)
    {
        if(aux -> siguiente -> dato.codigo == codigoAux)
        {
            aEliminar = aux -> siguiente;
            aux -> siguiente = aux -> siguiente -> siguiente;
            delete aEliminar;
            cout << "Eliminado con exito" << endl;
        }
        else
        {
            aux = aux -> siguiente;
        }
    }
}

void imprimirInfoInventario(Nodo* inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay libros registrados en el sistema." << endl;
        return;
    }

    Nodo* aux = inicio;
    int valorTotalInventario = 0;
    int precioAux;
    int contador = 0;

    cout << "Ingrese un precio de inventario para filtrar libros que superen ese monto: $";
    cin >> precioAux;

    while(aux != nullptr)
    {
        valorTotalInventario += aux -> dato.precio * aux -> dato.stock;

        if(aux -> dato.precio > precioAux)
        {
            contador++;
        }

        aux = aux -> siguiente;
    }

    cout << "La cantidad de libros que superan el precio de inventario ingresado es: " << contador << endl;
    cout << "El valor total del inventario es: $" << valorTotalInventario << endl;
}

void imprimirLibrosStockBajo(Nodo* inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay libros registrados en el sistema." << endl;
        return;
    }

    Nodo* aux = inicio;

    cout << "Libros con stock menor o igual a 5 unidades:" << endl;
    while(aux != nullptr)
    {
        if(aux -> dato.stock <= 5)
        {
            cout << "Codigo de libro: " << aux -> dato.codigo << endl;
            cout << "Descripcion del libro: " << aux -> dato.descripcion << endl;
            cout << "Precio del libro: $" << aux -> dato.precio << endl;
            cout << "Stock del libro: " << aux -> dato.stock << endl;
            cout << "----------" << endl;
        }
        aux = aux -> siguiente;
    }
}

int main()
{
    Nodo* inicio = nullptr;
    Libro datoLibro;

    insertarLibro(inicio, datoLibro);

    eliminarLibro(inicio);

    imprimirInfoInventario(inicio);

    imprimirLibrosStockBajo(inicio);

    return 0;
}