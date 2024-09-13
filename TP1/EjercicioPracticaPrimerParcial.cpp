#include <iostream>
#include <string>
using namespace std;

/*
En la tienda, los productos (100 como máximo) están organizados en una tabla con las siguiente columnas:
    - Código del producto
    - Cantidad en stock del producto
    - Precio del producto
Construir un sistema que permita mediante un menú:
    1. Cargar productos hasta que no tenga más lugar la tabla de 100 filas o haya una condición de corte
    2. Imprimir el listado de todos los productos.
    3. Informar todos los productos con stock menor a un determinado valor ingresado por el usuario
    4. Ingresar un código de producto, un determinado porcentaje y un valor que indique si es aumento o baja,
    para actualizar el precio de dicho producto en el determinado porcentaje
    5. Salir
*/

int const Filas = 100;
int const Columnas = 3;

void cargarProducto(int matriz[Filas][Columnas], int &dl)
{
    if(dl == Filas)
    {
        cout << "No se puede agregar más elementos a la tienda";
    }

    for(int i = dl; i < Filas; i++)
    {
        cout << "Ingrese un codigo de producto (Numero negativo para finalizar): ";
        cin >> matriz[i][0];
        cout << endl;
        if(matriz[i][0] < 0)
        {
            break;
        }
        cout << "Ingrese una cantidad de stock del producto: ";
        cin >> matriz[i][1];
        cout << endl;
        cout << "Ingrese un precio del producto: ";
        cin >> matriz[i][2];
        cout << endl;
        dl++;
    }
}

void imprimirListado(int matriz[Filas][Columnas], int dl)
{
    cout << endl;
    cout << "Listado de productos:" << endl;
    for(int i = 0; i < dl; i++)
    {
        cout << "Codigo del producto: " << matriz[i][0] << endl;
        cout << "--------------------" << endl;
        cout << "Stock del producto: " << matriz[i][1] << endl;
        cout << "--------------------" << endl;
        cout << "Precio del producto: " << matriz[i][2] << endl;
        cout << "--------------------" << endl;
    }
}

void infoStock(int matriz[Filas][Columnas], int dl)
{
    int valor;
    cout << "Ingrese un valor a comparar: ";
    cin >> valor;
    for(int i = 0; i < dl; i++)
    {
        if(matriz[i][1] < valor)
        {
            cout << "Productos con stock menor a " << valor << ":" << endl;
            cout << "Codigo: #" << matriz[i][0] << endl;
            cout << "--------------------" << endl;
            cout << "Precio: $" << matriz[i][2] << endl;
            cout << "--------------------" << endl;
        }
    }
}

void modificarPrecio(int matriz[Filas][Columnas], int dl)
{
    float porcentaje;
    int codigo, opcion;
    bool encontrado = false;

    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;
    
    

    for (int i = 0; i < dl; i++)
    {
        if (matriz[i][0] == codigo)
        {
            cout << "Ingrese un valor de porcentaje a actualizar en el precio: ";
            cin >> porcentaje;
            if (porcentaje < 0)
            {
                cout << "El porcentaje debe ser un valor positivo." << endl;
                return; // Termina la función si el porcentaje es inválido.
            }

            encontrado = true;
            cout << "¿Desea incrementar o disminuir en el precio el valor " << porcentaje << "%? (1: INCREMENTAR - 0: DISMINUIR): ";
            cin >> opcion;

            if (opcion == 0)
            {
                matriz[i][2] = matriz[i][2] * (1 - (porcentaje / 100.0));
                cout << "El precio actualizado es: $" << matriz[i][2] << endl;
            }
            else if (opcion == 1)
            {
                matriz[i][2] = matriz[i][2] * (1 + (porcentaje / 100.0));
                cout << "El precio actualizado es: $" << matriz[i][2] << endl;
            }
            else
            {
                cout << "Opción inválida. Por favor, ingrese 1 para incrementar o 0 para disminuir." << endl;
            }

            break; // Una vez que el producto ha sido encontrado y procesado, salimos del bucle.
        }
    }

    if (!encontrado) {
        cout << "El codigo no se encuentra en la lista." << endl;
    }
}

int main()
{
    int matriz[Filas][Columnas], dl = 0;
    char opciones;

    do
    {
        cout << "¡Bienvenido al sistema!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "A. Cargar productos al sistema" << endl;
        cout << "B. Imprimir el listado de productos" << endl;
        cout << "C. Obtener informacion de stock" << endl;
        cout << "D. Aumentar o disminuir precio de un producto" << endl;
        cout << "E. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                cargarProducto(matriz, dl);
                break;
            }
            
            case 'b':
            case 'B':
            {
                imprimirListado(matriz, dl);
                break;
            }

            case 'c':
            case 'C':
            {
                infoStock(matriz, dl);
                break;
            }

            case 'd':
            case 'D':
            {
                modificarPrecio(matriz, dl);
                break;
            }

            case 'e':
            case 'E':
            {
                cout << "Saliendo del sistema";
                break;
            }

            default:
            {
                cout << "Opcion no valida, ingrese de nuevo";
                break;
            }
        }
    } while(opciones != 'e' && opciones != 'E');

    return 0;
}