#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa en C++ que realice una búsqueda secuencial en un arreglo de números enteros ordenado de menor a mayor.
El programa debe solicitar al usuario que ingrese, por teclado, una serie de números (elegir una condición de corte apropiada).
Éstos deben ser almacenados en forma ordenada en un arreglo.
Por otra parte, se debe ofrecer una opción de búsqueda, donde se solicite al usuario ingresar un número e informar si se encuentra en el arreglo.
*/

const int dimFis = 100;

void cargarNumeros(int arregloOrdenado[], int &dl)
{
    int numeroIngresado, j;

    while(dl < dimFis) // Verificar que no se llene el arreglo
    {
        cout << "Ingrese un numero (-1 para finalizar): ";
        cin >> numeroIngresado;

        if(numeroIngresado <= -1)
        {
            break;
        }

        // Encontrar la posición donde se debe insertar el número para mantener el orden ascendente
        j = dl - 1; // j comienza en la última posición ocupada en el arreglo

        while(j >= 0 && arregloOrdenado[j] > numeroIngresado) // Desplazamiento hacia adelante
        {
            arregloOrdenado[j + 1] = arregloOrdenado[j]; // Desplazar elementos mayores hacia adelante
            j--;
        }

        arregloOrdenado[j + 1] = numeroIngresado; // Insertar el número en la posición correcta
        dl++; // Aumentar la cantidad de elementos en el arreglo
    }

    cout << "Numeros en el arreglo ordenado: ";
    for(int i = 0; i < dl; i++)
    {
        cout << arregloOrdenado[i] << " ";
    }
    cout << endl;
}

void buscarNumero(int arregloOrdenado[], int dl)
{
    int numeroBuscado, i = 0;
    bool encontrado = false;

    cout << "Ingrese el numero a buscar en el arreglo: ";
    cin >> numeroBuscado;

    /*
    Búsqueda secuencial mientras no se haya pasado del final del arreglo
    y mientras los números del arreglo sean menores o iguales al número buscado
    */
    while(i < dl && arregloOrdenado[i] <= numeroBuscado)
    {
        if(arregloOrdenado[i] == numeroBuscado)
        {
            encontrado = true;
            break;
        }
        i++;
    }

    if(encontrado)
    {
        cout << "El numero " << numeroBuscado << " se encuentra en la posicion " << i << endl;
    }
    else
    {
        cout << "El numero " << numeroBuscado << " no se encuentra en el arreglo" << endl;
    }
}

void menu(int arregloOrdenado[], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de numeros" << endl;
        cout << "A. Cargar numeros" << endl;
        cout << "B. Buscar numero en el arreglo" << endl;
        cout << "C. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch (opciones)
        {
            case 'a':
            case 'A':
            {
                cargarNumeros(arregloOrdenado, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                buscarNumero(arregloOrdenado, dl);
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
    int arregloOrdenado[dimFis], dl = 0;

    menu(arregloOrdenado, dl);

    return 0;
}