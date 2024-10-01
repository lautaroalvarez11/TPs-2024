#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa en C++ que realice una búsqueda secuencial en un arreglo desordenado de cadena de caracteres.
El programa debe solicitar al usuario que ingrese, por teclado, nombres de diferentes colores (elegir una condición de corte apropiada).
Éstos deben ser almacenados en un arreglo.
Por otra parte, se debe ofrecer una opción de búsqueda, donde se solicite al usuario ingresar el nombre de un color e informar si dicho color se encuentra o no en el arreglo.
*/

const int dimFis = 1000;

void cargarColores(string colores[], int &dl)
{
    for (int i = dl; i < dimFis; i++)
    {
        cout << "Ingrese un color ('ff' para finalizar): ";
        cin >> colores[i];

        if (colores[i] == "ff")
        {
            break;
        }

        dl++;
    }
}

void buscarColor(string colores[], int dl)
{
    string colorBuscado;
    bool encontrado = false; // Variable para saber si se encontró el color

    cout << "Ingrese el color a buscar: ";
    cin >> colorBuscado;

    // Búsqueda secuencial
    for (int i = 0; i < dl; i++)
    {
        if (colores[i] == colorBuscado)
        {
            cout << "Color " << colorBuscado << " encontrado en la posicion " << i+1 << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "El color no fue encontrado en el arreglo." << endl;
    }
}

/*
FUNCIÓN PROPUESTA EN PDF DE TEORÍA:
int busquedaSecuencialDesordenada(string colores[], int dl, string colorBuscado)
{
    int i = 0;
    
    cout << "Ingrese el color a buscar: ";
    cin >> colorBuscado;

    while (i < dl && colores[i] != colorBuscado)
    {
        i++;
    }
    if (i < dl)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
*/

void menu(string colores[], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de colores" << endl;
        cout << "A. Cargar colores" << endl;
        cout << "B. Buscar color en el arreglo" << endl;
        cout << "C. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch (opciones)
        {
            case 'a':
            case 'A':
            {
                cargarColores(colores, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                buscarColor(colores, dl);
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
    string colores[dimFis], colorBuscado; // Arreglo de colores y variable para buscar el color
    int dl = 0; // Dimensión lógica inicializada en 0

    menu(colores, dl); // Llama al menú principal

    return 0;
}