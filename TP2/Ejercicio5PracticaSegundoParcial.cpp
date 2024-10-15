#include <iostream>
#include <string>
using namespace std;

/*
PARTE 1:
Se solicita desarrollar un programa en C++ que permita llevar un registro de los jugadores de un club de vole.
De cada jugador se almacena la siguiente información:
    Nombre y apellido (string)
    DNI (int)
    Edad (int)
    Estatura en cm (int)
El club tiene capacidad para 50 jugadores.
El programa debe realizar las siguientes operaciones:
- Alta: Realizar la carga de la información de los jugadores. La carga finaliza con el DNI igual a 0.
- Actualizar estatura: El sistema debe permitir actualizar la estatura de un jugador.
Para ello se debe ingresar el DNI del jugador y si corresponde a un jugador, solicitar la nueva estatura a actualizar.
Se debe mostrar al usuario el mensaje "Estatura actualizada" o "El DNI no corresponde a un jugador". 
- Listar equipo: Generar un listado de todos los jugadores cuya edad sea mayor o igual a una ingresada por teclado.
Se debe informar de cada jugador su nombre, apellido, edad, estatura y DNI.
Por ejemplo, para un equipo +30 se deben listar todos los jugadores cuya edad sea igual o superior a 30.
*/

int main()
{

    return 0;
}

/*
PARTE 2:
Considerando la siguiente definición de struct:
struct Materia
{
    string nombre;
    int nota;
};

struct Estudiante
{
    int legajo;
    string apellido;
    string nombre;
    Materia materias[5];
}

1. Definir un arreglo para almacenar todos los estudiantes de primer año de Ing. en Informática. El cupo es de 200 estudiantes.
    Solución:

2. Completar el código de la función que muestra en pantalla el nombre de los estudiantes y las materias que aprobaron.
(La materia se aprueba si la nota es mayor o igual a 4).
void listado(Estudiante arreglo[], int dl)
{
    cout << "*** Listado de estudiantes y materias aprobadas ***" << endl;
    for(int i = 0; i < dl; i++)
    {
        cout << "Estudiante: ";
        . . . . . . . . . . . .
        . . . . . . . . . . . .
        . . . . . . . . . . . .
        cout << " ";
    }
}
    Solución:

3. ¿Qué modificación harías en el struct Materia para que el campo nota tenga por defecto el valor 0?
    Solución:
*/