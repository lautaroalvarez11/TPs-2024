#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba una palabra y retorne true si es palíndromo, false si no lo es.
Diferenciando mayúsculas y minúsculas.
Ejemplo: Si la palabra es "radar" retorna true.
*/

bool informarPalindromo(string cadena)
{
    if(cadena.length() <= 1)
    {
        return true;
    }
    if(cadena[0] != cadena[cadena.length() - 1]) // Compara el primer y último carácter para ver si son distintos
    {
        return false;
    }
    return informarPalindromo(cadena.substr(1, cadena.length() - 2));
}

int main()
{
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;

    if(!informarPalindromo(palabra))
    {
        cout << "La palabra ingresada no es un palindromo";
    }
    else
    {
        cout << "La palabra ingresada es un palindromo";
    }

    return 0;
}

/*
Como funciona este programa:
Ejemplo "radar"
1. La longitud de "radar" es mayor a 1 entonces entra al caso recursivo
2. Compara el primer y ultimo caracter, como son iguales entra al else y llama recursivamente a la funcion pero esta vez sin el primer y ultimo caracter, es decir, palindromo("ada")
3. La longitud de "ada" es mayor a 1 entonces entra al caso recursivo
4. Compara el primer y ultimo caracter, como son iguales entra al else y llama recursivamente a la funcion pero esta vez sin el primer y ultimo caracter, es decir, palindromo("d")
5. Como la longitud de "d" es igual a 1 entonces entra al caso base y sale de la funcion
6. En todas las llamadas de recursion el primer y ultimo caracter son iguales, entonces "radar" es un palindromo
*/