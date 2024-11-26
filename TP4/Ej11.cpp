#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne el primer número impar encontrado en el arreglo.
En caso de no haber números impares, debe retornar 0.
*/

const int dimFis = 10;

int encontrarImpar(int arreglo[], int dl, int indice = 0)
{
    if (indice >= dl) // Caso base: Si recorrió todo el arreglo, retorna 0
    {
        return 0;
    }
    if (arreglo[indice] % 2 != 0) // Caso base: Si el elemento actual es impar, lo retorna
    {
        return arreglo[indice];
    }
    return encontrarImpar(arreglo, dl, indice + 1); // Llamada recursiva: Avanza al siguiente índice
}

int main()
{
    int arreglo[dimFis], dl = 0, indice = 0;

    for(int i = 0; i < dimFis; i++)
    {
        cout << "Ingrese numeros para el arreglo: ";
        cin >> arreglo[i];
        dl++;
    }

    int resultado = encontrarImpar(arreglo, dl, indice);
    if(resultado != 0)
    {
        cout << "El primer numero impar es: " << resultado;
    }
    else
    {
        cout << "No se encontraron numeros impares";
    }
    
    return 0;
}