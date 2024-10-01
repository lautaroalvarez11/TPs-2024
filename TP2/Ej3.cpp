#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa en C++ que realice una búsqueda binaria en un arreglo de números enteros donde algunos
números pueden llegar a repetirse. El programa debe encontrar la primera aparición del número buscado e
informarlo en pantalla.
*/

const int dimFis = 100;

// FUNCIÓN UTILIZADA DEL EJERCICIO ANTERIOR
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
    int numeroBuscado;
    cout << "Ingrese un numero a buscar en el arreglo: ";
    cin >> numeroBuscado;

    int principio = 0;
    int fin = dl - 1;
    bool encontrado = false; // Variable para indicar si se encontró el número

    // Ciclo de búsqueda binaria
    while (principio <= fin)
    {
        int medio = (principio + fin) / 2;

        // Si se encuentra el número
        if (arregloOrdenado[medio] == numeroBuscado)
        {
            cout << "El numero " << numeroBuscado << " se encuentra en la posicion " << medio + 1<< endl;
            encontrado = true;
            break; // Salir del ciclo si se encuentra el número
        }

        // Si el número está en la mitad izquierda
        else if (arregloOrdenado[medio] > numeroBuscado)
        {
            fin = medio - 1;
        }

        // Si el número está en la mitad derecha
        else
        {
            principio = medio + 1;
        }
    }

    // Si no se encontró el número
    if (!encontrado)
    {
        cout << "El numero " << numeroBuscado << " no se encuentra en el arreglo." << endl;
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