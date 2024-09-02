#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función llamada cantidad_ocurrencias que reciba como parámetro un arreglo de tipo int,
su dimensión lógica y un parámetro con un valor de tipo int también.
La función debe retornar la cantidad de ocurrencias del valor en el arreglo.
*/

const int dimFis = 5;

int cantidad_ocurrencias(int arreglo[], int dimLog, int numero)
{
    int contador = 0;

    for(int i = 0; i <= dimLog; i++)
    {
        if(arreglo[i] == numero)
        {
            contador++;
        }
    }

    return contador;
}

int main()
{
    int arreglo[dimFis], dimLog, numero, h;

    cout << "Ingrese numeros 5 numeros como maximo para el arreglo (numero negativo para finalizar): ";
    for(int j = 0; j < dimFis; j++)
    {
        cin >> arreglo[j];
        if(arreglo[j] < 0)
        {
            break;
        }
    }

    // Ingresar el numero a buscar en el arreglo
    cout << "Ingrese un numero a buscar en el arreglo: ";
    cin >> numero;

    h = 0;
    while(h < dimFis && arreglo[h] >= 0)
    {
        h++;
    }
    dimLog = h;

    cout << "El numero " << numero << " aparece: " << cantidad_ocurrencias(arreglo, dimLog, numero) << " veces en el arreglo";

    return 0;
}