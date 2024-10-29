#include <iostream>
#include <string>
using namespace std;

/*
Dados los siguientes punteros a char:
    char* x = new char;
    char* z = x;
Escribir y ejecutar las instrucciones para hacer lo siguiente:
a) Almacenar el carácter 'M' en el espacio de memoria apuntado por x.
b) Imprimir el carácter apuntado por x.
c) Almacenar el carácter 'P' en el espacio de memoria apuntado por z.
d) Imprimir el carácter apuntado por z y luego el apuntado por x.
¿Qué carácter crees que imprimirá cada una y por qué?
e) Eliminar el dato apuntado por x.
¿Qué sucedería si a continuación se intentara imprimir *z y por qué?
f) Obtener un nuevo espacio de memoria para un char, almacenando su dirección en w.
g) Permitir al usuario ingresar un char por teclado y almacenarlo en el nuevo espacio apuntado por x.
h) Si el carácter ingresado por el usuario en el inciso anterior es '*', imprimir "asterisco".
*/

int main()
{
    char* x = new char;
    char* z = x;
    // PUNTO A
    *x = 'M';
    // PUNTO B
    cout << *x << endl;
    // PUNTO C
    *z = 'P';
    // PUNTO D
    cout << *z << " " << *x << endl;
    /*
    Se imprime P P porque tanto x como z apuntan a la misma dirección de memoria,
    por lo tanto si se modifica z, también se va a modificar x.
    */
    // PUNTO E
    delete x;
    /*
    Si se intentara imprimir z ocurriría un error porque se eliminó el espacio de memoria
    que apunta z, es decir x.
    */
    // PUNTO F
    char* w = new char;
    // PUNTO G
    cout << "Ingrese un caracter: ";
    cin >> *w;
    // PUNTO H
    if(*w == '*')
    {
        cout << "Asterisco" << endl;
    }
    delete w;
    return 0;
}