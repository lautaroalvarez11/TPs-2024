#include <iostream>
#include <string>
using namespace std;

/*
PARTE 1:
Construir un sistema para la gestión de datos de un campeonato de burako.
Se requiere registrar sobre una tabla, los puntos obtenidos por cada equipo en cada partida de juego.
Se jugarán 3 partidas por equipo y los grupos estarán conformados por 4 jugadores.
En la tabla, cada fila corresponde a una partida y las columnas representan a un participante.
El valor de cada celda, indica el puntaje obtenido en una partida por un jugador.
La siguiente tabla es a modo de ejemplo:

 Partida/Jugador |  Jugador 1  |   Jugador 2  |  Jugador 3  |  Jugador 4
-----------------|-------------|--------------|-------------|-------------
    Partida 1    |     325     |     -220     |     130     |     410
    Partida 2    |     90      |      230     |     380     |    -205
    Partida 3    |     110     |      310     |    -90      |     150

1. Cargar los resultados de un grupo participante del torneo sobre una matriz 3x4.
2. Imprimir en pantalla el resultado final de cada jugador después de las tres partidas.
   (El resultado final de cada jugador se obtiene sumando los puntajes obtenidos en
   cada partida)
3. Imprimir en pantalla el ganador del grupo.
   (El ganador del grupo es aquel participante que haya obtenido el mayor puntaje final)
*/

const int Partidas = 3; // Filas
const int Jugadores = 4; // Columnas
const int dimFis = 12;

void cargarResultados(int matriz[Partidas][Jugadores], int dl)
{
	if(dl <= dimFis)
	{
		cout << "Tablero lleno";
		return;
	}
	
	for(int i = 0; i < Partidas; i++)
	{
		cout << "Partida " << i+1 << ":" << endl;
		for(int j = 0; j < Jugadores; j++)
		{
			cout << "Ingrese el resultado del jugador " << j+1 << " : ";
			cin >> matriz[i][j];
			dl++;
		}
		
	}
}

void mostrarPuntaje(int matriz[Partidas][Jugadores])
{
	int sumaPuntaje = 0;
	for(int i = 0; i < Jugadores; i++)
	{
		for(int j = 0; j < Partidas; j++)
		{
			sumaPuntaje += matriz[j][i];
		}
        cout << "El resultado final del jugador " << i+1 << " despues de 3 partidas es: " << sumaPuntaje << endl;
        sumaPuntaje = 0;
	}
}

void ganadorFinal(int matriz[Partidas][Jugadores])
{
	int sumaPuntajeFinal[Jugadores] = {0}, indiceGanador;

    for (int i = 0; i < Jugadores; i++)
    {
        for (int j = 0; j < Partidas; j++)
        {
            sumaPuntajeFinal[i] += matriz[j][i];
        }
    }
    
    int mayorPuntaje = sumaPuntajeFinal[0];  // Suponer que el primer jugador tiene el mayor puntaje
    for (int i = 1; i < Jugadores; i++)  // Comparar desde el segundo jugador
    {
        if (sumaPuntajeFinal[i] > mayorPuntaje)
        {
            mayorPuntaje = sumaPuntajeFinal[i];  // Actualizar el mayor puntaje
            indiceGanador = i;  // Guardar el índice del jugador con el mayor puntaje
        }
    }

    cout << "El ganador de la partida es el jugador " << indiceGanador + 1 << " con " << mayorPuntaje << " puntos." << endl;
}

void menu(int matriz[Partidas][Jugadores], int dl)
{
	char opciones;
	do
	{
		cout << "Bienvenido al sistema de Burako" << endl;
		cout << "A. Cargar resultados de 3 partidas." << endl;
		cout << "B. Mostrar resultado final de cada jugador en cada partida." << endl;
		cout << "C. Mostrar ganador de las 3 partidas." << endl;
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
				mostrarPuntaje(matriz);
				break;
			}
			
			case 'c':
			case 'C':
			{
				ganadorFinal(matriz);
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

/*
PARTE 2:
1. Dado el siguiente arreglo de números enteros:
    int numeros[150] = {2,4,3,6,8,7,10,9};
    ¿Cuál es la dimensión física? ¿Y la dimensión lógica?
    RESPUESTA:
    - Dimensión física: 150
    - Dimensión lógica: 8
2. Describir que hace la siguiente función:
    void funcion(int arreglo[], int dl)
    {
        for(int i = dl-1; i >= 0; i--)
        {
            cout << arreglo[i] << " ";
        }
    }
    RESPUESTA:
    - Imprime el arreglo de adelante para atrás
    - 9 10 7 8 6 3 4 2
3. Dado un arreglo llamado "nuevoArreglo" y su dimensión lógica "dl":
    ¿Cuál es la sentencia correcta para mostrar por pantalla el último elemento útil del arreglo?
    RESPUESTA:
    int nuevoArreglo[];
    int dl;
    for(int i = 0; i < dl; i++)
    {
        if(nuevoArreglo[i] == nuevoArreglo[dl-1])
        {
            cout << nuevoArreglo[i];
        }
    }
*/