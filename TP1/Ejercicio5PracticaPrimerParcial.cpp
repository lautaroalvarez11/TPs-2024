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
    if(dl == dimFis)
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

void mostrarResultadosCincoPruebas(int matriz[Pruebas][Atletas])
{
    int sumaTiempo;
    for(int i = 0; i < Atletas; i++)
    {
        for(int j = 0; j < Pruebas; j++)
        {
            sumaTiempo += matriz[j][i];
        }
        cout << "El tiempo total del atleta " << i+1 << " despues de 5 pruebas es: " << sumaTiempo << endl;
        sumaTiempo = 0;
    }
}

void mostrarGanador(int matriz[Pruebas][Atletas])
{
    int sumaTiempoGanador[Atletas] = {0}, indiceGanador;

    for(int i = 0; i < Atletas; i++)
    {
        for(int j = 0; j < Pruebas; j++)
        {
            sumaTiempoGanador[i] += matriz[j][i];
        }
    }

    int menorTiempo = sumaTiempoGanador[0];
    for(int p = 0; p < Atletas; p++)
    {
        if(sumaTiempoGanador[p] < menorTiempo)
        {
            menorTiempo = sumaTiempoGanador[p];
            indiceGanador = p;
        }
    }

    cout << "El ganador de las pruebas es el atleta numero " << indiceGanador+1 << " con " << menorTiempo << " minutos." << endl;
}

void menu(int matriz[Pruebas][Atletas], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de atletismo" << endl;
        cout << "A. Cargar tiempo de atletas." << endl;
        cout << "B. Mostrar tiempo total de cada atleta en 5 rondas." << endl;
        cout << "C. Mostrar atleta ganador." << endl;
        cout << "D. Salir." << endl;
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
                mostrarResultadosCincoPruebas(matriz);
                break;
            }

            case 'c':
            case 'C':
            {
                mostrarGanador(matriz);
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
    int matriz[Pruebas][Atletas], dl = 0;

    menu(matriz, dl);

    return 0;
}