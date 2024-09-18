#include <iostream>
#include <string>
using namespace std;

/*
Crear un sistema para una tienda de ropa que maneja un inventario de hasta 50 productos,
organizados en una tabla con las siguientes columnas: Código del producto, Cantidad en stock, Precio.

1. Crear un menú que permita cargar productos en la tabla hasta que se complete o se desee detener la carga.
2. Imprimir un informe con todos los productos que tienen un precio mayor a un valor ingresado por el usuario.
3. Permitir al usuario ingresar el código de un producto y aumentar o reducir su stock en una cantidad determinada.
*/

const int Filas = 50;
const int Columnas = 3;
const int dimFis = 150;

void cargarTabla(int matriz[Filas][Columnas], int &dl)
{
    if(dl == dimFis)
    {
        cout << "Tienda llena.";
        return;
    }

    for(int i = dl; i < Filas; i++)
    {
        cout << "Ingrese el codigo del producto (-1 para finalizar): ";
        cin >> matriz[i][0];
        if(matriz[i][0] < 0)
        {
            break;
        }
        cout << "Ingrese la cantidad en stock del producto: ";
        cin >> matriz[i][1];
        if(matriz[i][1] < 0)
        {
            cout << "El stock debe ser mayor o igual a cero.";
            break;
        }
        cout << "Ingrese el precio del producto: ";
        cin >> matriz[i][2];
        if(matriz[i][2] < 0)
        {
            cout << "El precio debe ser mayor o igual a cero";
            break;
        }
        dl++;
    }
}

void informarProductoMayor(int matriz[Filas][Columnas], int dl)
{
    int precioBuscado;
    cout << "Ingrese el precio de referencia para buscar productos con un precio mayor: ";
    cin >> precioBuscado;

    cout << "Productos con un precio mayor a $" << precioBuscado << ":" << endl;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(matriz[i][2] > precioBuscado)
        {
            encontrado = true;
            cout << "Codigo: #" << matriz[i][0] << endl;
            cout << "--------------------" << endl;
            cout << "Stock: " << matriz[i][1] << endl;
            cout << "--------------------" << endl;
            cout << "Precio: $" << matriz[i][2] << endl;
            cout << "- - - - - - - - - - " << endl;
        }
    }

    if(!encontrado)
    {
        cout << "No se encontraron productos con un precio mayor a $" << precioBuscado << "." << endl;
    }
}

void modificarStock(int matriz[Filas][Columnas], int dl)
{
    int codigoBuscado, stockNuevo, opcion;
    bool encontrado = false;

    cout << "Ingrese el codigo de un producto a buscar: ";
    cin >> codigoBuscado;

    for(int i = 0; i < dl; i++)
    {
        if(matriz[i][0] == codigoBuscado)
        {
            cout << "Codigo: #" << matriz[i][0] << endl;
            cout << "--------------------" << endl;
            cout << "Precio: $" << matriz[i][2] << endl;
            cout << "--------------------" << endl;
            cout << "Stock actual: " << matriz[i][1] << endl;
            cout << "--------------------" << endl;
            cout << "Ingrese el numero a modificar en el stock del producto: ";
            cin >> stockNuevo;
            if(stockNuevo < 0)
            {
                cout << "El stock debe ser mayor o igual a cero.";
                return;
            }

            encontrado = true;
            cout << "¿Desea aumentar o reducir en el stock el valor " << stockNuevo <<"? (1 AUMENTAR - 0 REDUCIR): ";
            cin >> opcion;

            if(opcion == 1)
            {
                matriz[i][1] += stockNuevo;
                cout << "El stock nuevo es: " << matriz[i][1] << endl;
            }
            else if (opcion == 0)
            {
                if (matriz[i][1] - stockNuevo >= 0) // Verificar que el stock no sea negativo
                {
                    matriz[i][1] -= stockNuevo;
                    cout << "El stock nuevo es: " << matriz[i][1] << endl;
                }
                else
                {
                    cout << "Error: No se puede reducir el stock por debajo de cero." << endl;
                }
            }
            else
            {
                cout << "Opcion invalida. Por favor, ingrese 1 para aumentar o 0 para reducir." << endl;
            }

            break;
        }
    }
}

void menu(int matriz[Filas][Columnas], int dl)
{
    char opciones;

    do
    {
        cout << "Bienvenido a la tienda virtual" << endl;
        cout << "A. Cargar productos." << endl;
        cout << "B. Buscar productos filtrando por el precio." << endl;
        cout << "C. Modificar stock de productos" << endl;
        cout << "D. Salir." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                cargarTabla(matriz, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                informarProductoMayor(matriz, dl);
                break;
            }

            case 'c':
            case 'C':
            {
                modificarStock(matriz, dl);
                break;
            }

            case 'd':
            case 'D':
            {
                cout << "Saliendo del sistema.";
                break;
            }

            default:
            {
                cout << "Ingrese una opcion valida.";
                break;
            }
        }
    } while (opciones != 'd' && opciones != 'D');
    
}

int main()
{
    int matriz[Filas][Columnas], dl = 0;

    menu(matriz, dl);

    return 0;
}