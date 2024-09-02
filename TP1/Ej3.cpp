#include <iostream>
#include <string>
using namespace std;

/*
Escribe un programa que imprima un cuadrado de asteriscos de tamaño `n x n`,
donde `n` es un número ingresado por el usuario.
*/

int main()
{
    int numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;

    for(int i = 1; i <= numero; ++i) // Bucle que se encarga de controlar las filas, se inicializa con i = 1 para que no agregue una fila y una columna de más por el indice 0
    {
        for(int j = 1; j <= numero; ++j) // Bucle que se encarga de controlar las columnas
        {
            cout << '*';
        }
        cout << endl;
    }
}