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
const int Vueltas = 3;
const int Pilotos = 3;

void cargarResultados(int matriz[Vueltas][Pilotos], int &dl)
{
    if(dl == dimFis)
    {
        cout << "Tabla con pilotos llena.";
        return;
    }

    for(int i = dl; i < Vueltas; i++)
    {
        cout << "Ingrese resultado de minuto en la vuelta " << i << " del piloto " << i << " : ";
        cin >> matriz[i][0];
        cout << "Ingrese resultado de minuto en la vuelta " << i << " del piloto " << i << " : ";
        cin >> matriz[i][1];
        cout << "Ingrese resultado de minuto en la vuelta " << i << " del piloto " << i << " : ";
        cin >> matriz[i][2];
        dl++;
    }
}

void determinarPosicion(int matriz[Vueltas][Pilotos], int &dl)
{
    int PosicionPiloto1;
    for(int i = 0; i < Vueltas; i++)
    {
        for(int j = 0; j < Pilotos; j++)
        {
            
            
        }
    }
}

int main()
{
    int matriz[Vueltas][Pilotos], dl = 0;

    return 0;
}