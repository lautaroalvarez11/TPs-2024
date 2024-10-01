#include <iostream>
#include <string>
using namespace std;

/*
En un comercio de artículos electrónicos se lleva un registro de los precios de los productos disponibles.
El administrador desea ordenar estos precios de menor a mayor para facilitar su visualización.
Como desarrollador, te han solicitado implementar un programa en C++ que realice esta tarea utilizando el algoritmo de
ordenamiento por inserción.
Requerimientos:
    - El programa debe permitir al usuario ingresar la cantidad de productos y sus respectivos precios.
    - Se debe implementar el algoritmo de ordenamiento por inserción para ordenar los precios en orden ascendente.
    - Una vez ordenados, el programa debe mostrar los precios ordenados en pantalla.
Instrucciones adicionales:
    - Utilizar un arreglo para almacenar los precios.
    - Implementar una función separada que realice el ordenamiento por inserción.
    - La cantidad de productos y los precios deben ser ingresados por el usuario.
*/

const int dimFis = 1000;

void cargarPrecios(int arregloPrecios[], int &dl)
{
    int cantidadProductos;
    cout << "Ingrese la cantidad de productos: ";
    cin >> cantidadProductos;

    if (cantidadProductos <= 0)
    {
        cout << "Cantidad de productos invalida. Saliendo del sistema." << endl;
        return;
    }

    // Verificar si el arreglo tiene espacio para los nuevos productos
    if (dl + cantidadProductos > dimFis)
    {
        cout << "No hay espacio en el arreglo para almacenar todos los productos." << endl;
        return;
    }

    // Cargar los precios de los productos
    for (int i = 0; i < cantidadProductos; i++)
    {
        cout << "Ingrese el precio del producto " << i + 1 << ": ";
        cin >> arregloPrecios[dl];  // dl es la cantidad actual de productos ingresados
        dl++;  // Aumentar el tamaño del arreglo
    }
}

void ordenarPrecios(int arregloPrecios[], int dl)
{
    // Recorrer el arreglo desde el segundo elemento (índice 1) hasta el final
    for (int i = 1; i < dl; i++)
    {
        // Guardar el valor del elemento actual a "insertar" en el lugar correcto
        int temp = arregloPrecios[i];
        
        // Inicializar j como el índice del elemento anterior al actual
        int j = i - 1;

        /*
        Este bucle desplaza hacia la derecha los elementos mayores que 'temp'
        mientras se busca la posición correcta para insertar 'temp'
        */
        while (j >= 0 && temp < arregloPrecios[j])
        {
            // Desplazar el elemento en arregloPrecios[j] una posición a la derecha
            arregloPrecios[j+1] = arregloPrecios[j];
            
            // Decrementar j para seguir revisando elementos anteriores
            j--;
        }

        // Finalmente, insertar 'temp' en su posición correcta
        arregloPrecios[j+1] = temp;
    }
    
    cout << "Precios ordenados:" << endl;
    for(int i = 0; i < dl; i++)
    {
        cout << arregloPrecios[i] << " ";
    }
    cout << endl;
}

void menu(int arregloPrecios[], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de productos" << endl;
        cout << "A. Cargar productos y precios" << endl;
        cout << "B. Ordenar precios en el arreglo" << endl;
        cout << "C. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch (opciones)
        {
            case 'a':
            case 'A':
            {
                cargarPrecios(arregloPrecios, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                ordenarPrecios(arregloPrecios, dl);
                break;
            }

            case 'c':
            case 'C':
            {
                cout << "Saliendo del sistema..." << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opción válida." << endl;
                break;
            }
        }
    } while (opciones != 'C' && opciones != 'c');
}

int main()
{
    int arregloPrecios[dimFis], dl = 0;

    menu(arregloPrecios, dl);

    return 0;
}