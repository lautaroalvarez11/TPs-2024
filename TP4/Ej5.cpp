#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que calcule la suma de los cuadrados de los N primeros números positivos.
Ejemplo: Si N = 4 la suma es 1^2 + 2^2 + 3^2 + 4^2 = 30.
*/

int sumatoria(int a)
{
    if(a == 0)
    {
        return 0;
    }
    return a * a + sumatoria(a - 1);
}

int main()
{
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << "La suma de los cuadrados de los " << numero << " primeros numeros positivos es: " << sumatoria(numero);

    return 0;
}

/*
Como funciona este programa:
Ejemplo a = 2
1. a es distinto de 0 entonces entra al caso recursivo
2. Al 2 lo multiplica por si mismo (obtiene el cuadrado) y le suma recursivamente el cuadrado de su anterior
3. Volvio a entrar a la funcion pero ahora a vale 1

1. a es distinto de 0 entonces entra al caso recursivo
2. Al 1 lo multiplica por si mismo (obtiene el cuadrado) y le suma recursivamente el cuadrado de su anterior
3. Volvio a entrar a la funcion pero ahora a vale 0
4. Como a es igual a 0 sale de la funcion

Y el codigo queda de la siguiente manera:
a = 2 -> (2 * 2) + (1 * 1) = 5
*/