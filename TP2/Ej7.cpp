#include <iostream>
#include <string>
using namespace std;

/*
Realizar un algoritmo que almacene información de, como máximo, 500 libros en un arreglo estático.
Un libro se define como un struct con los siguientes campos: titulo, autor, ISBN, editorial, cantidadHojas.
El algoritmo finaliza luego de cargar el libro "El hobbit", el cual debe procesarse o cuando ya no quede espacio en el arreglo (lo que suceda primero).
Finalmente, imprimir el arreglo resultante mostrando todos los datos de cada libro.
*/

struct Biblioteca
{
    string titulo;
    string autor;
    int ISBN;
    string editorial;
    int cantidadHojas;
};

const int maxLibros = 500; // Dimensión física del struct

void cargarLibros(Biblioteca libros[], int &dl)
{
    if (dl >= maxLibros) // Si el arreglo está lleno, no se puede cargar más libros
    {
        cout << "No hay más espacio para agregar libros." << endl;
        return;
    }

    for (int i = dl; i < maxLibros; i++)
    {
        cout << "Ingrese un titulo ('El hobbit' para finalizar): ";
        getline(cin >> ws, libros[i].titulo); // Usar `ws` para limpiar espacios en blanco

        if (libros[i].titulo == "El hobbit")
        {
            cout << "Libro 'El hobbit' detectado. Finalizando la carga..." << endl;
            dl++; // Incrementa dl para contar también este libro
            break;
        }

        cout << "Ingrese el autor: ";
        getline(cin, libros[i].autor);
        cout << "Ingrese el ISBN: ";
        cin >> libros[i].ISBN;
        cin.ignore(); // Ignorar el salto de línea después de ingresar el número
        cout << "Ingrese la editorial: ";
        getline(cin, libros[i].editorial);
        cout << "Ingrese la cantidad de hojas: ";
        cin >> libros[i].cantidadHojas;
        cin.ignore(); // Ignorar el salto de línea
        cout << "----------" << endl;

        dl++;

        if (dl >= maxLibros)
        {
            cout << "Se alcanzó el máximo número de libros permitidos." << endl;
            break;
        }
    }
}

void imprimirLibros(Biblioteca libros[], int dl)
{
    cout << "Libros cargados:" << endl;
    for (int i = 0; i < dl; i++)
    {
        cout << "Libro " << i+1 << ":" << endl;
        cout << "Titulo: " << libros[i].titulo << endl;
        cout << "Autor: " << libros[i].autor << endl;
        cout << "ISBN: " << libros[i].ISBN << endl;
        cout << "Editorial: " << libros[i].editorial << endl;
        cout << "Cantidad de hojas: " << libros[i].cantidadHojas << endl;
        cout << "----------" << endl;
    }
}

void menu(Biblioteca libros[], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de la biblioteca" << endl;
        cout << "A. Cargar libros" << endl;
        cout << "B. Imprimir libros" << endl;
        cout << "C. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opciones;

        switch (opciones)
        {
            case 'a':
            case 'A':
            {
                cargarLibros(libros, dl);
                break;
            }

            case 'b':
            case 'B':
            {
                imprimirLibros(libros, dl);
                break;
            }

            case 'c':
            case 'C':
            {
                cout << "Saliendo del sistema..." << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opcion valida." << endl;
                break;
            }
        }
    } while (opciones != 'C' && opciones != 'c');
}

int main()
{
    int dl = 0;
    Biblioteca libros[maxLibros];
    menu(libros, dl);
    return 0;
}