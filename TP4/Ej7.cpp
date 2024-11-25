#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva para calcular la potencia de un número.
La función recibirá como parámetros al número y un exponente (ambos enteros positivos), y retornará la potencia.
- Nota 1: Cualquier número elevado a la 0 da como resultado 1.
  El 0 elevado a cualquier número positivo dará siempre como resultado 0.
- Nota 2: Puede definirse que X^n = X * X^n-1
*/

int calcularPotencia(int base, int exponente)
{
    if(exponente == 0)
    {
        return 1;
    }
    if(base == 0)
    {
        return 0;
    }
    return base * calcularPotencia(base, exponente - 1);
}

int main()
{
    int base, exponente;
    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese el exponente: ";
    cin >> exponente;

    cout << "La potencia es: " << calcularPotencia(base, exponente) << endl;

    return 0;
}

/*
Como funciona este programa:
Ejemplo numero = 2 y exponente = 3
1. Como numero y exponente son distintos de 0 entonces entra al caso recursivo
2. Se multiplica el numero, es decir, 2 y se llama recursivamente a potencia(numero, exponente - 1), es decir, potencia(2, 2)
3. Dentro de la siguiente llamada recursiva, exponente es 2, por lo que se multiplica nuevamente a 2 y se llama a potencias(2, 1)
4. Dentro de la siguiente llamada recursiva, exponente es 1, por lo que se multiplica nuevamente a 2 y se llama a potencias(2, 0)
5. Dentro de la siguiente llamada recursiva, exponente es 0, entonces sale del caso recursivo
6. Luego se multiplican todos los valores de numero almacenados en cada llamada recursiva (2*2*2) = 8
*/