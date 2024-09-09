#include <iostream>
#include <string>
using namespace std;

/*
Una matriz cuadrada A se dice que es simétrica si A(i,j) = A(j,i) para todo i, j.
Escribir un programa que decida si una matriz dada es o no simétrica.
*/

int main()
{
    int dimension;
    cout << "Ingrese el tamaño de filas y columnas: ";
    cin >> dimension;

    int matriz[dimension][dimension];

    cout << "Ingrese los elementos de la matriz: ";
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            cin >> matriz[i][j];
        }
    }

    bool esSimetrica = true;
    for(int h = 0; h < dimension; h++)
    {
        for(int p = 0; p < h; p++)
        {
            if(matriz[h][p] != matriz[p][h])
            {
                esSimetrica = false;
                break;
            }
        }
        if(esSimetrica == false)
        {
            break;
        }
    }

    if (esSimetrica)
    {
        cout << "La matriz es simetrica." << endl;
    }
    else
    {
        cout << "La matriz no es simetrica." << endl;
    }

    return 0;
}