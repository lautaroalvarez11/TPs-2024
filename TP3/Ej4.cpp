#include <iostream>
#include <string>
using namespace std;

/*
Dados los siguientes structs:
    struct Producto
    {
        string descripcion;
        float precio;
    };

    struct Venta
    {
        Producto producto;
        int cantidad;
    };
Escribir y luego ejecutar las instrucciones necesarias para:
a) Declarar una variable puntero a Venta y reservar memoria.
b) Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
c) Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
d) Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad).
*/

struct Producto
{
    string descripcion;
    float precio;
};

struct Venta
{
    Producto producto;
    int cantidad;
};

int main()
{
    // PUNTO A
    Venta* ventas = new Venta;

    // PUNTO B
    cout << "Ingrese la cantidad vendida: ";
    cin >> ventas -> cantidad;
    cout << "Ingrese la descripcion del producto: ";
    cin >> ventas -> producto.descripcion;
    cout << "Ingrese el precio del producto: ";
    cin >> ventas -> producto.precio;

    // PUNTO C
    float descuento, precioDescuento;
    descuento = (ventas -> producto.precio * 0.15);
    precioDescuento = ventas -> producto.precio - descuento;
    cout << "El precio inicial es: " << ventas -> producto.precio << endl;
    cout << "El precio con el 15% de descuento es: " << precioDescuento << endl;

    // PUNTO D
    cout << "Descripcion del producto: " << ventas -> producto.descripcion << endl;
    cout << "Monto total: " << ventas -> producto.precio * ventas -> cantidad << endl;

    delete ventas;

    return 0;
}