#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne la suma de los elementos pares almacenados en el arreglo.
En caso de no haber números pares, debe retornar 0.
*/

const int dimFis = 10;

int sumaPares(int arreglo[], int dl)
{
    if (dl == 0) // Caso base: Si no hay elementos en el arreglo
    {
        return 0;
    }

    if (arreglo[dl - 1] % 2 == 0) // Caso recursivo: Verificar si el último elemento es par
    {
        return arreglo[dl - 1] + sumaPares(arreglo, dl - 1); // Si es par, se suma y sigue con el resto del arreglo
    }
    else
    {
        return sumaPares(arreglo, dl - 1); // Si no es par, seguir con el resto del arreglo
    }
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

    int resultado = sumaPares(arreglo, dl);

    if(resultado != 0)
    {
        cout << "La suma de los numeros pares en el arreglo es: " << resultado;
    }
    else
    {
        cout << "No hay numeros pares en el arreglo";
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo dl = 3 y arreglo = {1, 2, 4}
1. Como dl no es igual a 0, entra al caso recursivo.
2. Toma el último elemento del arreglo, que es 4. Como 4 es divisible entre 2 (resto 0), entra al if y llama recursivamente a la función con dl = 2.
3. En la siguiente llamada, dl = 2. Toma el penúltimo elemento del arreglo, que es 2. Como 2 es divisible entre 2 (resto 0), entra al if y llama recursivamente a la función con dl = 1.
4. En la siguiente llamada, dl = 1. Toma el primer elemento del arreglo, que es 1. Como 1 no es divisible entre 2 (resto distinto de 0), entra al else y llama recursivamente a la función con dl = 0.
5. En la última llamada, dl = 0. Llega al caso base y retorna 0.
6. Al retornar de las llamadas recursivas, en dl = 1 retorna 0 porque 1 no era par. En dl = 2 retorna 2 (porque 2 es par). En dl = 3 suma 4 (el último elemento) con 2 (de la llamada anterior), obteniendo 6.
7. Finalmente, la suma de los números pares del arreglo {1, 2, 4} es 6.
*/