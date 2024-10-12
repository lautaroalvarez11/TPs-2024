#include <iostream>
#include <string>
using namespace std;

/*
Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta. El salón donde se realizará, tiene capacidad máxima para 150 personas.
De cada invitado se conoce su nombre, apellido, sexo y edad. Se ingresarán datos hasta que el nombre sea igual a “ZZZ” o hasta que la capacidad del salón esté completa.
Una vez finalizada la carga:
A. Informar la cantidad de invitados que asistirán a la fiesta.
B. Realizar una función que liste los nombres de las mujeres cuya edad sea <= 20.
C. Realizar una función que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder asistir.
*/

const int MAX_INVITADOS = 150;

struct Invitado
{
    string nombre;
    string apellido;
    char sexo;
    int edad;
};

void cargarInvitados(Invitado invitados[], int &dl)
{
    if(dl >= MAX_INVITADOS)
    {
        cout << "Salón lleno";
        return;
    }

    for(int i = dl; i < MAX_INVITADOS; i++)
    {
        cout << "Ingrese los siguientes datos del invitado/a " << i+1 << " para registrarlo/a a la fiesta:" << endl;

        cout << "Nombre del invitado/a ('ZZZ' para finalizar): ";
        getline(cin >> ws, invitados[i].nombre);

        if (invitados[i].nombre == "ZZZ")
        {
            cout << "Finalizando la carga..." << endl;
            break;
        }

        cout << "Apellido del invitado/a: ";
        getline(cin >> ws, invitados[i].apellido);
        cout << "Sexo del invitado/a (M - m/F - f): ";
        cin >> invitados[i].sexo;
        cin.ignore();
        cout << "Edad del invitado/a: ";
        cin >> invitados[i].edad;
        cin.ignore();
        cout << "----------" << endl;
        dl++;
    }
    cout << "----------" << endl;
}

void informarCantidadInvitados(Invitado invitados[], int dl)
{
    int sumaInvitados = 0;
    sumaInvitados += dl;
    cout << "La cantidad de invitados totales son: " << sumaInvitados << endl;
    cout << "----------" << endl;
}

void informarMujeresMenorVeinte(Invitado invitados[], int dl)
{
    cout << "Invitadas con 20 anios o menos:" << endl;
    for(int i = 0; i < dl; i++)
    {
        if(invitados[i].sexo == 'F' || invitados[i].sexo == 'f' && invitados[i].edad <= 20)
        {
            cout << "Nombre de la invitada: " << i+1 << ": " << invitados[i].nombre << endl;
        }
    }
    cout << "----------" << endl;
}

void eliminarInvitado(Invitado invitados[], int &dl)
{
    string nombreInvitadoEliminar, apellidoInvitadoEliminar;
    cout << "Ingrese el nombre del invitado/a a eliminar de la fiesta: ";
    cin >> nombreInvitadoEliminar;
    cout << "Ingrese el apellido del invitado/a a eliminar de la fiesta: ";
    cin >> apellidoInvitadoEliminar;

    bool encontrado = false;
    for(int i = 0; i < dl; i++)
    {
        if(invitados[i].nombre == nombreInvitadoEliminar && invitados[i].apellido == apellidoInvitadoEliminar)
        {
            encontrado = true;
            for (int j = i; j < dl - 1; j++)
            {
                invitados[j] = invitados[j + 1];
            }
            dl--;
            cout << "Invitado/a eliminado/a de la fiesta" << endl;
            break;
        }
    }
    if(!encontrado)
    {
        cout << "Invitado/a no encontrado en la lista";
    }
    cout << "----------" << endl;
}

void menu(Invitado invitados[], int &dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de fiesta" << endl;
        cout << "A. Cargar invitados al listado" << endl;
        cout << "B. Imprimir cantidad de invitados totales" << endl;
        cout << "C. Imprimir listado de mujeres con 20 años o menos" << endl;
        cout << "D. Eliminar invitado/a del listado" << endl;
        cout << "E. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'A':
            case 'a':
            {
                cargarInvitados(invitados, dl);
                break;
            }

            case 'B':
            case 'b':
            {
                informarCantidadInvitados(invitados, dl);
                break;
            }

            case 'C':
            case 'c':
            {
                informarMujeresMenorVeinte(invitados, dl);
                break;
            }

            case 'D':
            case 'd':
            {
                eliminarInvitado(invitados, dl);
                break;
            }

            case 'E':
            case 'e':
            {
                cout  << "Gracias por utilizar el sistema de fiesta" << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }
    } while(opciones != 'E' && opciones != 'e');  
}

int main()
{
    Invitado invitados[MAX_INVITADOS];
    int dl = 0;

    menu(invitados, dl);

    return 0;
}