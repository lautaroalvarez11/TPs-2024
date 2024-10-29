#include <iostream>
#include <string>
using namespace std;

/*
Dado el siguiente programa, indicar la salida en cada punto señalado:
*/

int main()
{
    int *p1, *p2; // Se declaran dos punteros a int, p1 y p2, pero no les asigna ningún valor inicial (apuntan a direcciones no definidas).

    p1 = new int; // Se asigna memoria dinámica para un entero y hace que p1 apunte a esta nueva dirección de memoria.
    *p1 = 42; // Se asigna el valor 42 a la dirección de memoria a la que apunta p1.
    p2 = p1; // Se asigna la dirección de memoria de p1 a p2, haciendo que ambos punteros apunten a la misma dirección.
    cout << *p1 << endl; // Se imprime el valor al que apunta p1, que es 42.
    cout << *p2 << endl; // Se imprime el valor al que apunta p2, que también es 42 (ya que p2 apunta a la misma dirección que p1).

    *p2 = 53; // Se cambia el valor en la dirección de memoria compartida por p1 y p2 a 53.
    cout << *p1 << endl; // Se imprime el valor al que apunta p1, que ahora es 53.
    cout << *p2 << endl; // Se imprime el valor al que apunta p2, que también es 53.

    p1 = new int; // Se asigna una nueva dirección de memoria a p1, rompiendo la referencia compartida con p2.
    *p1 = 88; // Se asigna el valor 88 a la nueva dirección de memoria a la que apunta p1.
    cout << *p1 << endl; // Se imprime el valor al que apunta p1, que es 88.
    cout << *p2 << endl; // Se imprime el valor al que apunta p2, que es 53 (p2 aún apunta a la primera dirección asignada, con el valor 53).
    cout << "FIN";

    return 0;
}

/*
Salida:
42
42
53
53
88
53*/