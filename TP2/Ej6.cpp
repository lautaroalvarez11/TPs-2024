#include <iostream>
#include <string>
using namespace std;

/*
Considerando la siguiente definición de struct, ¿Qué salidas producirá el siguiente código?

struct TipoZapato
{
    string estilo;
    double precio;
};

TipoZapato zapato1, zapato2;
zapato1.estilo = "Sandalia";
zapato1.precio = 9.99;
cout << zapato1.estilo << " $" << zapato1.precio << endl;
zapato2 = zapato1;
zapato2.precio = zapato2.precio / 9;
cout << zapato2.estilo << " $" << zapato2.precio << endl;

Primer cout: Sandalia $9.99
Segundo cout: Sandalia $1.11
*/

int main()
{
    return 0;
}