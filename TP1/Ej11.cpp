#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa que permita al usuario ingresar números enteros positivos (los números ingresados no deben almacenarse).
Al finalizar, informar la cantidad de veces que apareció cada dígito (del 0 al 9) en todos los números.
*/

const int dimFis = 10; // Números del 0 al 9

int main()
{
    int arreglo[dimFis] = {0}; // arreglo que almacena cuántas veces aparece cada dígito. Todos sus elementos se inicializan en 0.
    int numero;
    
    cout << "Ingrese numeros enteros positivos (ingrese un numero negativo para finalizar):" << endl;

    while (true)
    {
        cin >> numero;

        if (numero < 0)
        {
            break;
        }

        // Procesar cada dígito del número
        while (numero > 0)
        {
            int digito = numero % 10; // Obtener el último dígito del número
            arreglo[digito]++; // Incrementar el contador correspondiente al dígito
            numero = numero / 10; // Eliminar el último dígito del número
        }
    }

    cout << "Cantidad de veces que aparecio cada digito:" << endl;
    for (int i = 0; i < dimFis; i++)
    {
        cout << "Digito " << i << ": " << arreglo[i] << " veces" << endl;
    }

    return 0;
}