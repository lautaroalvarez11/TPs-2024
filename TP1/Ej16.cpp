#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa para ser utilizado en una ventanilla de venta de entradas de un pequeño teatro con
capacidad para 50 personas. Las filas están identificadas de la 0 a la 4 y cada fila tiene asientos numerados
de 1 a 10. Se debe registrar, por cada asiento, si está libre o no. Al iniciar el programa, todos los asientos
están libres.
Cuando alguien desea comprar una entrada, se deben informar qué localidades están libres.
Entonces el cliente deberá elegir su asiento (indicando fila y número de asiento) y éste se marcará como
vendido. Si ya se vendieron todas las entradas, no se debe permitir elegir asiento.
*/

const int dimFis = 50;
const int numFilas = 5;
const int numColumnas = 10;

void mostrarEstadoAsientos(int matriz[numFilas][numColumnas])
{
    cout << "Estado de los asientos:" << endl;
    for (int i = 0; i < numFilas; i++)
    {
        cout << "Fila " << i << ": ";
        for (int j = 0; j < numColumnas; j++)
        {
            if (matriz[i][j])
            {
                cout << "R "; // Si el valor es 1 (asiento reservado), se imprime R 
            }
            else 
            {
                cout << "L "; // Si el valor es 0 (asiento libre), se imprime L
            }
        }
        cout << endl;
    }
}

void comprarEntrada(int matriz[numFilas][numColumnas], int &dl)
{
    if(dl == dimFis)
    {
        cout << "Teatro lleno. No quedan asientos disponibles." << endl;
        return;
    }

    mostrarEstadoAsientos(matriz);

    int fila, asiento;

    cout << "Ingrese un numero de fila (-1 para finalizar): ";
    cin >> fila;
    if(fila == -1)
    {
        return;
    }
    cout << "Ingrese un numero de asiento (de 1 a 10): ";
    cin >> asiento;

    if(fila >= 0 && fila < numFilas && asiento > 0 && asiento <= numColumnas) // Para verificar si el número de fila y asiento elegido está dentro de la matriz
    {
        if (matriz[fila][asiento - 1] == 0) // Para verificar si el asiento está libre
        {
            matriz[fila][asiento - 1] = 1; // Marcar asiento como vendido
            dl++; // Incrementar el contador de asientos vendidos
            cout << "Entrada comprada con exito!" << endl;
        }
        else
        {
            cout << "El asiento ya esta vendido." << endl;
        }
    }
    else
    {
        cout << "Fila o asiento no validos." << endl;
    }
}

void menu(int matriz[numFilas][numColumnas], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al teatro" << endl;
        cout << "A. Reservar asiento" << endl;
        cout << "B. Mostrar estado de asientos" << endl;
        cout << "C. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                comprarEntrada(matriz, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                mostrarEstadoAsientos(matriz);
                break;
            }

            case 'c':
            case 'C':
            {
                cout << "Saliendo del sistema.";
                break;
            }

            default:
            {
                cout << "Opcion no valida, ingrese de nuevo";
                break;
            }
        }
    } while (opciones != 'c' && opciones != 'C');
}

int main()
{
    int matriz[numFilas][numColumnas] = {0}; // Para iniciar todos los asientos libres
    int dl = 0;

    menu(matriz, dl);

    return 0;
}