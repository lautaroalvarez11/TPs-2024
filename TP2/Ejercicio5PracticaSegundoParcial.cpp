#include <iostream>
#include <string>
using namespace std;

/*
PARTE 1:
Se solicita desarrollar un programa en C++ que permita llevar un registro de los jugadores de un club de voley.
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

const int MAX_JUGADORES = 50;

struct Jugador
{
    string nombreApellido;
    int DNI;
    int edad;
    int estatura;
};

void altaJugadores(Jugador jugadores[], int &dl)
{
    if(dl >= MAX_JUGADORES)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; i < MAX_JUGADORES; i++)
    {
        cout << "Ingrese el nombre y apellido del jugador: ";
        getline(cin >> ws, jugadores[i].nombreApellido);

        cout << "Ingrese el DNI del jugador (0 para finalizar la carga): ";
        cin >> jugadores[i].DNI;
        cin.ignore();

        if(jugadores[i].DNI == 0)
        {
            cout << "Finalizando la carga..." << endl;
            break;
        }

        cout << "Ingrese la edad del jugador: ";
        cin >> jugadores[i].edad;
        cin.ignore();

        cout << "Ingrese la estatura del jugador (en cm): ";
        cin >> jugadores[i].estatura;
        cin.ignore();

        dl++;
    }
}

void actualizarEstatura(Jugador jugadores[], int dl)
{
    int dniTemporal;
    cout << "Ingrese el DNI del jugador a buscar: ";
    cin >> dniTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(jugadores[i].DNI == dniTemporal)
        {
            encontrado = true;
            cout << "Estatura actual: " << jugadores[i].estatura << " cm" << endl;
            cout << "Ingrese la nueva estatura del jugador (en cm): ";
            cin >> jugadores[i].estatura;
            cin.ignore();
            break;
        }
    }

    if(!encontrado)
    {
        cout << "El DNI ingresado no corresponde a ningun jugador." << endl;
    }
}

void listarPorEdad(Jugador jugadores[], int dl)
{
    int edadBuscada;
    cout << "Ingrese la edad para mostrar los jugadores de dicha edad o superior: ";
    cin >> edadBuscada;

    bool encontrado = false;

    cout << "Jugadores +" << edadBuscada << ":" << endl;
    for(int i = 0; i < dl; i++)
    {
        if(jugadores[i].edad >= edadBuscada)
        {
            encontrado = true;
            cout << "Nombre y apellido: " << jugadores[i].nombreApellido << endl;
            cout << "DNI: " << jugadores[i].DNI << endl;
            cout << "Estatura: " << jugadores[i].estatura << endl;
            cout << "----------" << endl;
        }
    }

    if(!encontrado)
    {
        cout << "No hay jugadores registrados con esa edad o superior." << endl;
    }
}

int main()
{
    Jugador jugadores[MAX_JUGADORES];
    int dl = 0;

    altaJugadores(jugadores, dl);
    actualizarEstatura(jugadores, dl);
    listarPorEdad(jugadores, dl);

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
    Estudiante estudiantes[200];

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
    cout << "Estudiante: " << arreglo[i].nombre << " " << arreglo[i].apellido << endl;
    cout << "Materias aprobadas:" << endl;
    for(int j = 0; j < 5; j++)
    {
        if(arreglo[i].materias[j].nota >= 4)
        {
            cout << "Materia: " << arreglo[i].materias[j].nombre << endl;
            cout << "Nota: " << arreglo[i].materias[j].nota << endl;
            cout << "----------" << endl;
        }
    }

3. ¿Qué modificación harías en el struct Materia para que el campo nota tenga por defecto el valor 0?
    Solución:
    int nota = 0;
*/