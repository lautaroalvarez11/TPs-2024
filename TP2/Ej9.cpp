#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa que almacene en un arreglo los datos de los alumnos de una escuela luego de finalizado el año académico.
Como máximo, puede haber 5.000 alumnos.
De cada alumno se debe guardar el nombre y la calificación obtenida en el primer, segundo y tercer trimestre del año académico.
Imprimir el listado de nombres de alumnos mostrando un mensaje de "APTO" si el alumno supera o iguala la calificación de 5 para todas las notas o "NO APTO" si no lo alcanza.
Utilizar un arreglo como campo del struct para almacenar las tres calificaciones.
*/

const int MAX_ALUMNOS = 5000;
const int MAX_CALIFICACIONES = 3;

struct Alumno
{
    string nombre;
    float calificaciones[MAX_CALIFICACIONES];
};

void cargarAlumno(Alumno alumnos[], int &dl)
{
    if(dl >= MAX_ALUMNOS)
    {
        cout << "No hay espacio disponible para almacenar más alumnos." << endl;
        return;
    }

    for(int i = dl; i < MAX_ALUMNOS; i++)
    {
        cout << "Ingrese el nombre del alumno ('Fin' para finalizar): ";
        getline(cin >> ws,  alumnos[i].nombre);

        if(alumnos[i].nombre == "Fin")
        {
            cout << "Finalizando la carga" << endl;
            break;
        }

        for(int j = 0; j < MAX_CALIFICACIONES; j++)
        {
            cout << "Ingrese la calificación del trimestre "<< j+1 << ": ";
            cin >> alumnos[i].calificaciones[j];
            cin.ignore();
        }

        dl++;
    }
}

void imprimirAptitud(Alumno alumnos[], int dl)
{
    for (int i = 0; i < dl; i++)
    {
        bool alumnoApto = true;

        for (int j = 0; j < MAX_CALIFICACIONES; j++)
        {
            if (alumnos[i].calificaciones[j] < 5)
            {
                alumnoApto = false;
                break;
            }
        }

        cout << "Alumno: " << alumnos[i].nombre << " - ";
        if (alumnoApto)
        {
            cout << "APTO" << endl;
        }
        else
        {
            cout << "NO APTO" << endl;
        }
    }
}

void menu(Alumno alumnos[], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema escolar" << endl;
        cout << "A. Cargar alumno al sistema" << endl;
        cout << "B. Imprimir aptitud de aprobacion de cada alumno" << endl;
        cout << "C. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'A':
            case 'a':
            {
                cargarAlumno(alumnos, dl);
                break;
            }

            case 'B':
            case 'b':
            {
                imprimirAptitud(alumnos, dl);
                break;
            }

            case 'C':
            case 'c':
            {
                cout  << "Gracias por utilizar el sistema escolar" << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }
    } while(opciones != 'C' && opciones != 'c');  
}

int main()
{
    Alumno alumnos[MAX_ALUMNOS];
    int dl = 0;

    menu(alumnos, dl);

    return 0;
}