#include <iostream>
#include <string>
using namespace std;

/*
Crear un sistema para la gestión de los puntos obtenidos por 4 jugadores en 3 rondas de ajedrez.
Cada fila de la tabla representa una ronda y cada columna un jugador.
El valor de cada celda indica el puntaje obtenido en esa ronda por un jugador.

1. Cargar los resultados de cada jugador en una matriz 3x4 (3 rondas, 4 jugadores).
2. Imprimir en pantalla el puntaje total acumulado de cada jugador después de las tres rondas.
3. Determinar qué jugador obtuvo el puntaje total más bajo y cuál el más alto, e imprimirlos.
*/

const int Partidas = 3; // Filas
const int Jugadores = 4; // Columnas
const int dimFis = 12;

void cargarResultados(int matriz[Partidas][Jugadores], int dl)
{
    if(dl <= dimFis)
    {
        cout << "Todos los puntos cargados";
        return;
    }

    for(int i = 0; i < Partidas; i++)
    {
        cout << "Partida " << i+1 << ":" << endl;
        for(int j = 0; j < Jugadores; j++)
        {
            cout << "Puntos obtenidos por el jugador " << j+1 << " : ";
            cin >> matriz[i][j];
            dl++;
        }
    }
}

void puntajeTresRondas(int matriz[Partidas][Jugadores])
{
    int sumaPuntaje;

    for(int i = 0; i < Jugadores; i++)
    {
        for(int j = 0; j < Partidas; j++)
        {
            sumaPuntaje += matriz[j][i];
        }
        cout << "El puntaje despues de 3 rondas del jugador " << i+1 << " es: " << sumaPuntaje << endl;
        sumaPuntaje = 0;
    }
}

void puntaje_masBajo_masAlto(int matriz[Partidas][Jugadores])
{
    int sumaPuntajeFinal[Jugadores] = {0}, indiceGanador, indicePerdedor;

    
    for(int i = 0; i < Jugadores; i++)
    {
        for(int j = 0; j < Partidas; j++)
        {
            sumaPuntajeFinal[i] += matriz[j][i];
        }
    }

    int mayorPuntajeAlto = sumaPuntajeFinal[0]; // Suponer que el primer jugador fue el puntaje más alto
    for(int p = 1; p < Jugadores; p++) // Comparar desde el segundo jugador
    {
        if(sumaPuntajeFinal[p] > mayorPuntajeAlto) 
        {
            mayorPuntajeAlto = sumaPuntajeFinal[p];
            indiceGanador = p;
        }
    }
    
    int mayorPuntajeBajo = sumaPuntajeFinal[0];
    for(int q = 1; q < Jugadores; q++)
    {
        if(sumaPuntajeFinal[q] < mayorPuntajeBajo) 
        {
            mayorPuntajeBajo = sumaPuntajeFinal[q];
            indicePerdedor = q;
        }
    }

    cout << "El ganador de la partida es el jugador " << indiceGanador+1 << " con " << mayorPuntajeAlto << " puntos." << endl;
    cout << "El perdedor de la partida es el jugador " << indicePerdedor+1 << " con " << mayorPuntajeBajo << " puntos." << endl;
}

void menu(int matriz[Partidas][Jugadores], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de ajedrez" << endl;
        cout << "A. Cargar puntaje de jugadores." << endl;
        cout << "B. Mostrar puntaje total de cada jugador en 3 rondas." << endl;
        cout << "C. Mostrar jugador ganador y perdedor." << endl;
        cout << "D. Salir" << endl;
        cout << "Ingrese una opcion: ";
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
                puntajeTresRondas(matriz);
                break;
            }

            case 'c':
            case 'C':
            {
                puntaje_masBajo_masAlto(matriz);
                break;
            }

            case 'd':
            case 'D':
            {
                cout << "Saliendo del sistema";
                break;
            }

            default:
            {
                cout << "Opcion no valida, ingrese de nuevo";
                break;
            }
        }
    } while(opciones != 'd' && opciones != 'D');
}

int main()
{
    int matriz[Partidas][Jugadores], dl = 0;

    menu(matriz, dl);

    return 0;
}