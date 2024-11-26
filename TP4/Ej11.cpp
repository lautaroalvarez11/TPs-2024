#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne el primer número impar encontrado en el arreglo.
En caso de no haber números impares, debe retornar 0.
*/

const int dimFis = 10;

int encontrarImpar(int arreglo[], int dl)
{
    if (dl == 0) // Caso base: Si no hay elementos en el arreglo
    {
        return 0;
    }
    if (arreglo[dl - 1] % 2 != 0) // Caso recursivo: Verificar si el último elemento es imparpar
    {
        return arreglo[dl - 1];
    }
    return encontrarImpar(arreglo, dl - 1); // Si es par, sigue al siguiente elemento
}

int main()
{
    int arreglo[dimFis], dl = 0;

    for(int i = 0; i < dimFis; i++)
    {
        cout << "Ingrese numeros para el arreglo: ";
        cin >> arreglo[i];
        dl++;
    }

    int resultado = encontrarImpar(arreglo, dl);
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

/*
Como funciona este programa:
Ejemplo dl = 4 y arreglo = {2, 4, 6, 7}
1. Como dl no es igual a 0, entra al caso recursivo.
2. Toma el último elemento del arreglo, que es 7. Como 7 no es divisible entre 2 (resto distinto de 0), entra al if y retorna 7.
3. Como se encontró un número impar (7), no es necesario seguir llamando recursivamente a la función. Se retorna el valor inmediatamente.

Ejemplo dl = 4 y arreglo = {2, 4, 6, 8}
1. Como dl no es igual a 0, entra al caso recursivo.
2. Toma el último elemento del arreglo, que es 8. Como 8 es divisible entre 2 (resto 0), no entra al if y llama recursivamente a la función con dl = 3.
3. En la siguiente llamada, dl = 3. Toma el tercer elemento del arreglo, que es 6. Como 6 es divisible entre 2 (resto 0), no entra al if y llama recursivamente a la función con dl = 2.
4. En la siguiente llamada, dl = 2. Toma el segundo elemento del arreglo, que es 4. Como 4 es divisible entre 2 (resto 0), no entra al if y llama recursivamente a la función con dl = 1.
5. En la siguiente llamada, dl = 1. Toma el primer elemento del arreglo, que es 2. Como 2 es divisible entre 2 (resto 0), no entra al if y llama recursivamente a la función con dl = 0.
6. En la última llamada, dl = 0. Llega al caso base y retorna 0 porque no se encontró ningún número impar.
7. Finalmente, como no había números impares en el arreglo {2, 4, 6, 8}, la función retorna 0.
*/