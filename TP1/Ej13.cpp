#include <iostream>
#include <string>
using namespace std;

/*
Escribe un programa que sume dos matrices de 3x3 y muestre la matriz resultante
*/

int main()
{
    int matriz1[3][3];
    int matriz2[3][3];
    int matrizResultado[3][3];

    cout << "Introduce los elementos de la primera matriz 3x3:" << endl;
    for (int filaMatriz1 = 0; filaMatriz1 < 3; filaMatriz1++)
    {
        for (int columnaMatriz1 = 0; columnaMatriz1 < 3; columnaMatriz1++)
        {
            cin >> matriz1[filaMatriz1][columnaMatriz1];
        }
    }

    cout << "Introduce los elementos de la segunda matriz 3x3:" << endl;
    for (int filaMatriz2 = 0; filaMatriz2 < 3; filaMatriz2++)
    {
        for (int columnaMatriz2 = 0; columnaMatriz2 < 3; columnaMatriz2++)
        {
            cin >> matriz2[filaMatriz2][columnaMatriz2];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    cout << "La matriz resultado de la suma es:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "[ "<< matrizResultado[i][j] << " " << " ]";
        }
        cout << endl;
    }

    return 0;
}