#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que calcule el producto de dos números naturales, usando sumas.
Ejemplo: 2*3 se puede calcular como 2+2+2.
*/

int sumatoria(int a, int b)
{
    if(a == 0 || b == 0)
    {
        return 0;
    }
    return a + sumatoria(a, b - 1);
}

int main()
{
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;

    cout << "El producto de " << a << " y " << b << " es: " << sumatoria(a, b);

    return 0;
}

/*
Como funciona este programa:
Ejemplo a = 2 ; b = 3
1. a y b son distintos de 0 entonces entra al caso recursivo
2. Sumar a, es decir, 2 y se llama recursivamente a productoNaturales(a, b - 1), es decir, productoNaturales(2, 2)
3. Dentro de la siguiente llamada recursiva, b es 2, por lo que sumamos nuevamente a 2 y se llama a productoNaturales(2, 1)
4. Dentro de la siguiente llamada recursiva, b es 1, por lo que sumamos nuevamente a 2 y se llama a productoNaturales(2, 0)
5. Dentro de la siguiente llamada recursiva, b es 0, entonces sale del caso recursivo
6. Luego, se suman todos los valores de a acumulados en cada llamada recursiva (2 + 2 + 2) = 6
*/