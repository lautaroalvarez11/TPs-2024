#include <iostream>
#include <string>
using namespace std;

/*
Escribir una definición para una función llamada mas_uno que tiene un parámetro formal para un arreglo de enteros
e incrementa en uno el valor de cada elemento del arreglo. Añadir otros parámetros formales que se necesiten.
*/

const int dimFis = 5;

void mas_uno(int arreglo[], int dimLog)
{
    for(int i = 0; i <= dimLog; i++)
    {
        arreglo[i]++;
    }
}

int main()
{
    int arreglo[dimFis], dimLog, h;

    // Agregar números al arreglo
    cout << "Ingrese 5 numeros como máximo para el arreglo (ingrese un valor negativo para finalizar): ";
    for(int j = 0; j < dimFis; j++)
    {
        cin >> arreglo[j];
        if(arreglo[j] < 0) // Usar un número negativo para finalizar
        {
            break;
        }
    }

    // Averiguar la dimensión lógica
    h = 0;
    while (h < dimFis && arreglo[h] >= 0)
    {  // Verifica hasta llegar al final del arreglo o encontrar un número negativo
        h++;
    }
    dimLog = h;

    mas_uno(arreglo, dimLog);

    cout << "Arreglo nuevo:" << endl;

    for(int k = 0; k < dimLog; k++) // Mostrar el nuevo arreglo
    {
        cout << arreglo[k] << " ";
    }

    return 0;
}