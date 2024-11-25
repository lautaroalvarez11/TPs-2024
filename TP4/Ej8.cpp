#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba un string y lo retorne con sus caracteres invertidos.
*/

string invertirCadena(string cadena)
{
    if(cadena == "")
    {
        return 0;
    }
    if(cadena.length() == 1)
    {
        return cadena;
    }
    return cadena[cadena.length() - 1] + invertirCadena(cadena.substr(0, cadena.length() - 1));
}

int main()
{
    string cadena;
    cout << "Ingrese una frase: ";
    getline(cin >> ws, cadena);

    cout << "La cadena invertida es: " << invertirCadena(cadena);

    return 0;
}