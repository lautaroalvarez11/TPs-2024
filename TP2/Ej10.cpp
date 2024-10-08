#include <iostream>
#include <string>
using namespace std;

/*
La universidad posee información histórica sobre los estudiantes (no más de 1.000) de una materia determinada.
De cada uno almacena: nombre y apellido, legajo, cantidad de inasistencias a clase, calificación obtenida.
Almacenar esta información en un arreglo de structs. Se solicita generar los siguientes reportes:
a) Imprimir nombre y apellido de los alumnos que tuvieron más de 5 inasistencias.
b) Imprimir número de legajo de los alumnos cuya calificación sea mayor o igual a la calificación promedio total (requiere calcular un promedio de las calificaciones de todos los alumnos en el listado).
c) Imprimir el número de legajo de aquellos alumnos que tienen promedio mayor o igual a 9.
d) Dado el legajo de un alumno, eliminarlo del listado.
*/

struct Alumno
{
    string nombre;
    string apellido;
    int legajo;
    int inasistencias;
    float calificacion;
};

const int dimFisAlumnos = 1000;

void cargarAlumno(Alumno alumnos[], int &dl)
{
    if (dl >= dimFisAlumnos) {
        cout << "Sistema lleno" << endl;
        return;
    }

    for (int i = dl; i < dimFisAlumnos; i++) {
        cout << "Ingrese el nombre del alumno ('Fin' para finalizar): ";
        getline(cin >> ws, alumnos[i].nombre);

        if (alumnos[i].nombre == "Fin") {
            cout << "Finalizando la carga..." << endl;
            break;
        }

        cout << "Ingrese el apellido: ";
        getline(cin, alumnos[i].apellido);
        cout << "Ingrese el legajo: ";
        cin >> alumnos[i].legajo;
        cin.ignore();
        cout << "Ingrese la cantidad de inasistencias del alumno: ";
        cin >> alumnos[i].inasistencias;
        cin.ignore();
        cout << "Ingrese la calificacion: ";
        cin >> alumnos[i].calificacion;
        cin.ignore();
        cout << "----------" << endl;
        dl++;
    }
}

void imprimirAlumnosInasistencias(Alumno alumnos[], int dl)
{
    int inasistenciasMaximas = 5;
    cout << "Alumnos con mas de 5 inasistencias:" << endl;
    for(int i = 0; i < dl; i++)
    {
        if(alumnos[i].inasistencias > inasistenciasMaximas)
        {
            cout << "Alumno " << i+1 << ": " << alumnos[i].nombre << " " << alumnos[i].apellido << endl;
        }
    }
}

void imprimirCalificaciones(Alumno alumnos[], int dl)
{
    float calificacionPromedioTotal = 0.0;
    for(int i = 0; i < dl; i++)
    {
        calificacionPromedioTotal += alumnos[i].calificacion; // Sumar todas las calificaciones
    }

    calificacionPromedioTotal = calificacionPromedioTotal / dl; // Calcular el promedio total del curso

    cout << "Legajos de estudiantes con calificacion mayor o igual al promedio total:" << endl;
    for (int i = 0; i < dl; i++)
    {
        if (alumnos[i].calificacion >= calificacionPromedioTotal)
        {
            cout << "Legajo: " << alumnos[i].legajo << endl;
        }
    }

    cout << "Alumnos con promedio mayor o igual a nueve:" << endl;
    for(int j = 0; j < dl; j++)
    {
        if(alumnos[j].calificacion >= 9.0)
        {
            cout << "Alumno con legajo: " << alumnos[j].legajo << endl;
        }
    } 
}

void eliminarAlumno(Alumno alumnos[], int &dl)
{
    int alumnoEliminar;
    cout << "Ingrese el legajo del alumno a eliminar: ";
    cin >> alumnoEliminar;

    bool encontrado = false;
    for (int i = 0; i < dl; i++)
    {
        if (alumnoEliminar == alumnos[i].legajo)
        {
            encontrado = true;
            for (int j = i; j < dl - 1; j++)
            {
                alumnos[j] = alumnos[j + 1];
            }
            dl--;
            cout << "Alumno con legajo " << alumnoEliminar << " eliminado." << endl;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Alumno con legajo " << alumnoEliminar << " no encontrado en el listado." << endl;
    }
}

void imprimirListadoCompleto(Alumno alumnos[], int dl)
{
    cout << "Listado completo de alumnos:" << endl;
    for(int i = 0; i < dl; i++)
    {
        cout << "Alumno " << i+1 << ":" << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Apellido: " << alumnos[i].apellido << endl;
        cout << "Legajo: " << alumnos[i].legajo << endl;
        cout << "Inasistencias: " << alumnos[i].inasistencias << endl;
        cout << "Calificacion: " << alumnos[i].calificacion << endl;
        cout << "----------" << endl;
    }
}

void menu(Alumno alumnos[], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema escolar" << endl;
        cout << "A. Cargar alumnos al listado" << endl;
        cout << "B. Imprimir nombre y apellido de los alumnos que tuvieron mas de 5 inasistencias" << endl;
        cout << "C. Imprimir numero de legajo de los alumnos cuya calificacion es mayor o igual a la calificacion promedio total del curso" << endl;
        cout << "e imprimir el numero de legajo de aquellos alumnos que tienen promedio mayor o igual a 9" << endl;
        cout << "D. Eliminar alumno del listado" << endl;
        cout << "E. Imprimir listado de alumnos" << endl;
        cout << "F. Salir" << endl;
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
                imprimirAlumnosInasistencias(alumnos, dl);
                break;
            }

            case 'C':
            case 'c':
            {
                imprimirCalificaciones(alumnos, dl);
                break;
            }

            case 'D':
            case 'd':
            {
                eliminarAlumno(alumnos, dl);
                break;
            }

            case 'E':
            case 'e':
            {
                imprimirListadoCompleto(alumnos, dl);
                break;
            }

            case 'F':
            case 'f':
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
    } while(opciones != 'F' && opciones != 'f');  
}

int main()
{
    Alumno alumnos[dimFisAlumnos];
    int dl = 0;

    menu(alumnos, dl);

    return 0;
}