#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa en C++ que realice una búsqueda secuencial en un arreglo desordenado de cadena de caracteres.
El programa debe solicitar al usuario que ingrese, por teclado, nombres de diferentes colores (elegir una condición de corte apropiada).
Éstos deben ser almacenados en un arreglo.
Por otra parte, se debe ofrecer una opción de búsqueda, donde se solicite al usuario ingresar el nombre de un color e informar si dicho color se encuentra o no en el arreglo.
*/

const int dimFis = 10000000; // Aproximadamente todos los colores del mundo

void cargarColores(string colores[], int dl)
{
    for(int i = 0; i < dimFis; i++)
    {
        cout << "Ingrese un color ('ff' para finalizar): ";
        if(colores[i] == "ff")
        {
            break;
        }
        cin >> colores[i];
        dl++;
        cout << endl;
    }
}

void buscarColor(string colores[], int dl)
{
    string colorBuscado;
    cout << "Ingrese el color a buscar: ";
    cin >> colorBuscado;

    for(int i = 0; i < dl; i++)
    {
        if(colores[i] == colorBuscado)
        {
            cout << "Color " << colorBuscado << " encontrado en la posicion " << i+1 << endl;
        }
        else
        {
            cout << "El color no fue encontrado en el arreglo";
        }
    }
}

void menu(string colores[], int dl)
{
    char opciones;
    do
    {
        cout << ""
    }
}

int main()
{


    return 0;
}