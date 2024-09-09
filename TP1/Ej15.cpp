#include <iostream>
#include <string>
using namespace std;

/*
Escribe un programa que busque un número en una matriz dada y devuelva su posición.
Si el número no se encuentra, debe indicarlo.
*/

int main()
{
    int filas, columnas;
    cout << "Ingrese el tamaño de filas que va a tener la matriz: ";
    cin >> filas;
    cout << "Ingrese el tamaño de columnas que va a tener la matriz: ";
    cin >> columnas;
    int matriz[filas][columnas];

    // Llenar la matriz
    cout << "Ingrese los numeros de la matriz:" << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cin >> matriz[i][j];
        }
    }

    int numero;
    bool encontrado = false; // 
    cout << "Ingrese el numero a buscar en la matriz: ";
    cin >> numero;

    // Buscar el número en la matriz y devolver su posición
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] == numero)
            {
                cout << "El numero " << numero << " aparece en la posicion (" << i << ", " << j << ")." << endl;
                encontrado = true; // Se encontró el número
            }
        }
    }

    if (encontrado == false)
    {
        cout << "El numero " << numero << " no pertenece a la matriz." << endl;
    }

    return 0;
}