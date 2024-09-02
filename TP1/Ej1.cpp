#include <iostream>
#include <string>
using namespace std;

/*
Escribe un programa que solicite al usuario ingresar un carácter y un número entero positivo. Luego imprime en
pantalla un triángulo formado por el carácter ingresado, con altura igual al número que se ingresó.
*/

int main()
{
    int numero;
    char caracter;

    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << "Ingrese un caracter: ";
    cin >> caracter;

    for(int i = 0; i <= numero; i++) // Bucle que se encarga de controlar cuantas veces se imprime el caracter por renglón
    {
        for(int j = 0; j < i; j++) // Bucle que se encarga de controlar que se imprima el caracter
        {
            cout << caracter;
        }
        cout << endl;
    }
}