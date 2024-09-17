#include <iostream>
#include <string>
using namespace std;

/*
En un equipo de Fórmula 1 utilizan tablas para ver el rendimiento de sus pilotos como por ejemplo:

 Vuelta/Piloto |  Piloto 1  |   Piloto 2  |  Piloto 3
---------------|------------|-------------|----------
    Vuelta 1   |     1      |      2      |     3
    Vuelta 2   |     4      |      5      |     6
    Vuelta 3   |     7      |      8      |     9

1. Cargar los resultados en una matriz 3x3
2. Imprimir en pantalla la posición final de largada de cada piloto despues de 3 vueltas.
   (La posición de largada se determina sumando los tiempos de las 3 vueltas. El piloto con menor
   tiempo larga primero, el que le sigue en tiempo segundo y así sucesivamente)
3. Imprimir en pantalla en que vuelta cada piloto tuvo su mejor desempeño
*/

const int dimFis = 9;
const int Vueltas = 3; // Filas
const int Pilotos = 3; // Columnas

void cargarResultados(int matriz[Vueltas][Pilotos], int dl)
{
    if(dl == dimFis)
    {
        cout << "Tabla con pilotos llena.";
        return;
    }

    for (int i = 0; i < Vueltas; i++)
    {
        for (int j = 0; j < Pilotos; j++)
        {
            cout << "Ingrese tiempo de la vuelta " << i + 1 << " del piloto " << j + 1 << ": ";
            cin >> matriz[i][j];
            dl++;
        }
    }
}

void determinarPosicion(int matriz[Vueltas][Pilotos])
{
    int sumaTiempos[Pilotos] = {0};
    int posiciones[Pilotos] = {0, 1, 2};

    // Sumar los tiempos de cada piloto (corregido)
    for (int i = 0; i < Pilotos; i++)
    {
        for (int j = 0; j < Vueltas; j++)
        {
            sumaTiempos[i] += matriz[j][i];
        }
    }

    // Ordenar los tiempos y las posiciones usando burbuja
    for (int i = 0; i < Pilotos - 1; i++)
    {
        for (int j = 0; j < Pilotos - i - 1; j++)
        {
            if (sumaTiempos[j] > sumaTiempos[j + 1])
            {
                // Intercambiar tiempos
                int tiempoTemporal = sumaTiempos[j];
                sumaTiempos[j] = sumaTiempos[j + 1];
                sumaTiempos[j + 1] = tiempoTemporal;
                
                // Intercambiar posiciones
                int posicionTemporal = posiciones[j];
                posiciones[j] = posiciones[j + 1];
                posiciones[j + 1] = posicionTemporal;
            }
        }
    }

    // Imprimir las posiciones finales
    cout << "Posiciones finales de largada:" << endl;
    for (int i = 0; i < Pilotos; i++)
    {
        cout << "El piloto " << posiciones[i] + 1 << " larga en la posición " << i + 1 << " con un tiempo total de " << sumaTiempos[i] << " minutos." << endl;
    }
}

void mejorRendimiento(int matriz[Vueltas][Pilotos])
{
    for (int piloto = 0; piloto < Pilotos; piloto++)
    {
        int mejorTiempo = matriz[0][piloto];  // Suponer que el mejor tiempo es el de la primera vuelta
        int mejorVuelta = 0;  // Guardar el índice de la mejor vuelta

        // Comparar el tiempo de cada vuelta para cada piloto
        for (int vuelta = 1; vuelta < Vueltas; vuelta++)
        {
            if (matriz[vuelta][piloto] < mejorTiempo)
            {
                mejorTiempo = matriz[vuelta][piloto];  // Actualizar el mejor tiempo
                mejorVuelta = vuelta;  // Guardar el índice de la vuelta con mejor tiempo
            }
        }

        // Imprimir el resultado para el piloto actual
        cout << "El piloto " << piloto + 1 << " tuvo su mejor rendimiento en la vuelta " << mejorVuelta + 1 << " con un tiempo de " << mejorTiempo << " minutos." << endl;
    }
}

void menu(int matriz[Vueltas][Pilotos], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de Formula 1" << endl;
        cout << "A. Cargar tiempos de vuelta de cada piloto." << endl;
        cout << "B. Mostrar posicion de largada de cada piloto." << endl;
        cout << "C. Mostrar vuelta de mejor rendimiento." << endl;
        cout << "D. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                cargarResultados(matriz, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                determinarPosicion(matriz);
                break;
            }

            case 'c':
            case 'C':
            {
                mejorRendimiento(matriz);
                break;
            }

            case 'd':
            case 'D':
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
    } while (opciones != 'd' && opciones != 'D');
}

int main()
{
    int matriz[Vueltas][Pilotos], dl = 0;

    menu(matriz, dl);

    return 0;
}