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

const int MAX_LIBROS = 2000;

struct Publicacion
{
    int infoDia;
    int infoMes;
    int infoAnio;
};

struct Libro
{
    int ISBN;
    string titulo;
    int cantidadEnExistencia;
    Publicacion publicaciones;
};

void altaLibros(Libro libros[], int &dl)
{
    if(dl >= MAX_LIBROS)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; i < MAX_LIBROS; i++)
    {
        cout << "Ingrese el ISBN del libro: ";
        cin >> libros[i].ISBN;
        cin.ignore();

        if(libros[i].ISBN == 0)
        {
            cout << "Finalizando la carga..." << endl;
            break;
        }

        cout << "Ingrese el titulo del libro: ";
        getline(cin >> ws, libros[i].titulo);

        cout << "Ingrese la cantidad en existencia de el libro " << "'" << libros[i].titulo << "'" << ": ";
        cin >> libros[i].cantidadEnExistencia;
        cin.ignore();
        
        cout << "Ingrese el dia que se publico el libro " << "'" << libros[i].titulo << "'" << ": ";
        cin >> libros[i].publicaciones.infoDia;
        cin.ignore();

        cout << "Ingrese el mes que se publico el libro " << "'" << libros[i].titulo << "'" << ": ";
        cin >> libros[i].publicaciones.infoMes;
        cin.ignore();

        cout << "Ingrese el anio que se publico el libro " << "'" << libros[i].titulo << "'" << ": ";
        cin.ignore();

        dl++;
    }
}

void incrementarStock(Libro libros[], int dl)
{
    int isbnTemporal;
    cout << "Ingrese el ISBN del libro a buscar: ";
    cin >> isbnTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(libros[i].ISBN == isbnTemporal)
        {
            encontrado = true;
            int cantAumentar;
            cout << "Stock actual: " << libros[i].cantidadEnExistencia << endl;
            cout << "Ingrese la cantidad de libros a sumar al stock: ";
            cin >> cantAumentar;
            libros[i].cantidadEnExistencia += cantAumentar;
            cout << "Stock nuevo: " << libros[i].cantidadEnExistencia << endl;
            break;
        }
    }

    if(!encontrado)
    {
        cout << "El ISBN ingresado no corresponde a ningun libro." << endl;
    }
}

void reporteLibros(Libro libros[], int dl)
{
    int anioTemporal;
    cout << "Ingrese el anio para buscar libros lanzados en ese anio: ";
    cin >> anioTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(libros[i].publicaciones.infoAnio == anioTemporal)
        {
            encontrado = true;
            cout << "Libro lanzado en el anio " << anioTemporal << ": " << libros[i].titulo << endl;
            cout << "Fecha de publicacion: " << libros[i].publicaciones.infoDia << "/" << libros[i].publicaciones.infoMes << "/" << anioTemporal << endl;
        }
    }

    if(!encontrado)
    {
        cout << "No hay libros lanzados en el anio ingresado." << endl;
    }
}

int main()
{
    Libro libros[MAX_LIBROS];
    int dl = 0;

    altaLibros(libros, dl);
    incrementarStock(libros, dl);
    reporteLibros(libros, dl);

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