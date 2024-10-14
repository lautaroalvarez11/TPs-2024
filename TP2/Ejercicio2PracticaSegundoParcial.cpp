#include <iostream>
#include <string>
using namespace std;

/*
PARTE 1:
Se nos solicita un programa que permita llevar un registro de los libros presentes en una nueva edición de la Feria del Libro.
Cómo máximo puede haber 2000 libros.
De cada libro se requiere almacenar la siguiente información:
    ISBN (int).
    Título (string).
    Cantidad en existencia (int).
    Fecha de publicación (struct) (debe contener):
        Información del día (int).
        Mes (int).
        Año (int).
El programa debe ser capaz de realizar las siguientes operaciones:
- Alta: Realizar la carga de la información de los libros presentes en la feria. La carga finaliza cuando se ingresa el ISBN igual a cero.
- Incrementar stock: Incrementar la cantidad de un determinado libro. Para eso se solicitará por teclado el ingreso del ISBN y si existe se debe solicitar la cantidad de unidades a incrementar.
Se debe mostrar al usuario un mensaje de "Cantidad actualizada" o "No se encontró el libro".
- Reporte: Generar un listado de todos los título de los libros publicados en un determinado año ingresado por teclado, informando el título del libro y la fecha de publicación completa.
*/

int main()
{

    return 0;
}

/*
PARTE 2:
Considerando la siguiente definición de struct:
struct Equipo
{
    string nombre;
    int cant_Participantes;
    int puntajes[10];
};
1) Declarar un arreglo para almacenar todos los equipos que participan en el torneo. El cupo es de 30 equipos.
2) Completar el código de la función que muestra el puntaje total de todos los equipos participantes. Las líneas de punto son solo ilustrativas, no indica la cantidad de sentencias.
void listado(Equipo arreglo[], int dl)
{
    cout << "**** Listado Puntaje de Equipos ****" << endl;
    for(int i = 0, i < dl; i++)
    {
        cout << "Equipo: ";
        . . . . . . . . . .
        . . . . . . . . . .
        . . . . . . . . . .
        cout << "Puntaje: ";
    }
}
*/