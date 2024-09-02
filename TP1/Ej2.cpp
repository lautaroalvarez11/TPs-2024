#include <iostream>
#include <string>
using namespace std;

/*
Escribe un programa que imprima la tabla de multiplicar del 1 al 10 utilizando estructuras de control anidadas
*/

int main()
{
    for(int i = 0; i <= 10; i++) 
    {
        for(int j = 0; j <= 10; j++) 
        {
            cout << i*j << " ";
        }
        cout << endl;
    }
}