#include <iostream>
#include <string>
using namespace std;

/*
Crear un sistema para gestionar los tiempos obtenidos por 3 atletas en 5 pruebas de atletismo.
Se debe registrar los tiempos en una tabla donde cada fila corresponde a una prueba y las columnas
representan a un atleta. El valor de cada celda indica el tiempo en segundos que tomó completar la prueba.

1. Cargar los tiempos de los atletas en una matriz 5x3 (5 pruebas, 3 atletas).
2. Imprimir el tiempo total de cada atleta después de las cinco pruebas.
3. Determinar qué atleta ganó más pruebas (el que tuvo el menor tiempo en más ocasiones).
*/

const int Pruebas = 5; // Filas
const int Atletas = 3; // Columnas
const int dimFis = 15;

void cargarResultados(int matriz[Pruebas][Atletas], int dl)
{
    if(dl <= dimFis)
    {
        cout << "Todos los puntos fueron cargados";
        return;
    }

    for(int i = 0; i < Pruebas; i++)
    {
        cout << "Prueba " << i+1 << ":" << endl;
        for(int j = 0; j < Atletas; j++)
        {
            cout << "Ingresar el tiempo (minutos) del atleta " << j+1 << ": ";
            cin >> matriz[i][j];
            dl++;
        }
    }
}

int main()
{

}