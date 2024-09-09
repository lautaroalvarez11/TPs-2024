#include <iostream>
#include <string>
using namespace std;

int main()
{
    //A. Declarar un arreglo de enteros de 7 filas y 10 columnas
    int matriz[7][10];

    //B. Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
    matriz[1][4] = 105;

    //C. Asignar en todas las posiciones de la cuarta fila el valor 5.
    for(int columna = 0; columna < 10; columna++)
    {
        matriz[3][columna] = 5; // Cuarta fila = fila con índice 3
    }

    //D. Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
    for (int fila = 0; fila < 7; fila++)
    {
        for (int columna = 0; columna < 10; columna++)
        {
            cout << matriz[fila][columna] << " ";
        }
        cout << endl;
    }

    //E. Permutar las columnas 3 y 5.
    for (int i = 0; i < 7; ++i)
    {
        // Guardar el valor de la columna 3
        int temporal = matriz[i][2];
        
        // Copiar el valor de la columna 5 en la columna 3
        matriz[i][2] = matriz[i][4];
        
        // Copiar el valor temporal en la columna 5
        matriz[i][4] = temporal;
    }

    //F. Sumar todos los elementos de las filas 2 y 6.
    int suma = 0;
    for(int columna = 0; columna < 10; columna++)
    {
        suma = suma + matriz[1][columna];
        suma = suma + matriz[5][columna]; 
    }
    cout << "Resultado: " << suma;

    //G. Imprimir todos los valores de la tercera columna.
    for(int fila = 0; fila < 7; fila++)
    {
        cout << matriz[fila][2];
    }
    
    //H. Hallar en qué fila y columna se encuentra almacenado el mayor elemento.
    const int filas = 7;
    const int columnas = 10;
    float Matriz[filas][columnas];
    // Rellenar la matriz con valores

    // Inicializar el mayor elemento con el primer elemento de la matriz
    int mayor = Matriz[0][0];
    int fila_mayor = 0;
    int columna_mayor = 0;

    // Recorrer la matriz para encontrar el mayor elemento y sus índices
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
                fila_mayor = i;
                columna_mayor = j;
            }
        }
    }

    // Imprimir el resultado
    cout << "El mayor elemento se encuentra en la fila " << fila_mayor << " y columna " << columna_mayor << "." << endl;

    return 0;
}