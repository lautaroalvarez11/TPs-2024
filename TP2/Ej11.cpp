#include <iostream>
#include <string>
using namespace std;

/*
Implementar un programa que almacene en un arreglo estático, los datos de los ciudadanos que solicitaron un certificado de antecedentes en el Registro Nacional de las Personas.
De cada ciudadano se conoce: nombre y apellido, fecha de nacimiento (tipo long: formato AAAAMMDD), dirección, número de documento, tipo de documento (tipo int: 1 -DNI-, 2 -Pasaporte-, 3 -Otro-) y sexo (tipo char: 'M', 'F').
a) Hacer un módulo de carga del arreglo, utilizando una condición de corte adecuada. Se debe validar el tipo de documento (1, 2 ó 3) y dejar al usuario en un bucle mientras ingrese un número inválido.
b) Imprimir el listado, con el siguiente formato de ejemplo:
    Nombre y apellido: Juan Perez
    Dirección: Levalle 132
    Fecha de nacimiento: 27/10/1979
    Tipo de documento: DNI
    Número de documento: 27439221
    Sexo: masculino
- La fecha debe mostrarse en formato dd/mm/aa.
- El tipo de documento debe mostrarse con su nombre.
- El género debe mostrar la palabra completa.
c) Implementar un módulo que, dado el arreglo original, cargue en otro arreglo los ciudadanos de sexo masculino únicamente. Imprimir este nuevo arreglo.
d) Hacer lo mismo que en el punto anterior, pero obteniendo sólo las mujeres. Modularizar para no repetir código.
*/

const int MAX_PERSONAS = 1000;

struct Ciudadano
{
    string nombreApellido;
    int fechaNacimiento;
    string direccion;
    int tipoDocumento;
    int numeroDocumento;
    char sexo;
};

void cargarCiudadano(Ciudadano ciudadanos[], int &dl)
{
    if (dl >= MAX_PERSONAS)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; dl < MAX_PERSONAS; i++)
    {
        cout << "Ingrese el nombre y apellido del ciudadano/a: ";
        getline(cin >> ws, ciudadanos[i].nombreApellido);

        cout << "Ingrese la direccion del ciudadano/a: ";
        getline(cin >> ws, ciudadanos[i].direccion);

        cout << "Ingrese la fecha de nacimiento (DD/MM/AAAA): ";
        cin >> ciudadanos[i].fechaNacimiento;
        cin.ignore();
        
        int tipoDocumentoTemporal;
        cout  << "Ingrese el tipo de documento del ciudadano (1 - DNI,  2 - Pasaporte, 3 - Otro): ";
        cin >> tipoDocumentoTemporal;
        cout << endl;
        while (tipoDocumentoTemporal < 1 || tipoDocumentoTemporal > 3)
        {
            cout << "Error, ingrese un tipo de documento valido (1, 2 o 3): ";
            cin >> tipoDocumentoTemporal;
        }
        cout << endl;
        ciudadanos[i].tipoDocumento = tipoDocumentoTemporal; // Guarda el tipo de documento que ingresó el usuario en la variable auxiliar.
        if  (tipoDocumentoTemporal == 1)
        {
            cout << "Ingrese el DNI del ciudadano: ";
            cin >> ciudadanos[i].numeroDocumento;
            cin.ignore();
        }
        else if  (tipoDocumentoTemporal == 2)
        {
            cout << "Ingrese el Pasaporte del ciudadano: ";
            cin >> ciudadanos[i].numeroDocumento;
            cin.ignore();
        }
        else
        {
            cout << "Ingrese el Otro documento del ciudadano: ";
            cin >> ciudadanos[i].numeroDocumento;
            cin.ignore();
        }

        cout << "Ingrese el sexo (M - Masculino, F - Femenino): ";
        cin >>  ciudadanos[i].sexo;
        cin.ignore();

        dl++;

        char respuesta;
        cout << "¿Desea agregar otro ciudadano? (S = Si / N = No): ";
        cin >> respuesta;
        while (respuesta != 'N' && respuesta != 'S')
        {
            cout << "Error, ingrese una respuesta valida (S = Si / N = No): ";
            cin >> respuesta;
        }
        if (respuesta == 'N' || respuesta == 'n')
        {
            break;
        }

        cout << "----------" << endl;
    }
}

void imprimirListado(Ciudadano ciudadanos[], int dl)
{
    cout << "Listado del Registro Nacional de las Personas:" << endl;
    for(int i = 0; i < dl; i++)
    {
        cout << "Ciudadano/a " << i+1 << ":" << endl;

        cout << "Nombre y apellido: " << ciudadanos[i].nombreApellido << endl;

        cout << "Direccion: " << ciudadanos[i].direccion << endl;
        
        int dia, mes, anio;
        dia = ciudadanos[i].fechaNacimiento % 100; // Obtiene el dia de la fecha de nacimiento.   
        mes = (ciudadanos[i].fechaNacimiento / 100) % 100; // Obtiene el mes de la fecha de nacimiento.
        anio = ciudadanos[i].fechaNacimiento / 10000; // Obtiene el año de la fecha de nacimiento.
        cout << "Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << endl;

        
        if(ciudadanos[i].tipoDocumento == 1)
        {
            cout << "Tipo de documento: DNI" << endl;
            cout << "Numero de documento: " << ciudadanos[i].numeroDocumento << endl;
        }
        else if(ciudadanos[i].tipoDocumento == 2)
        {
            cout << "Tipo de documento: Pasaporte" << endl;
            cout << "Numero de Pasaporte: " << ciudadanos[i].numeroDocumento << endl;
        }
        else
        {
            cout << "Tipo de documento: Otro" << endl;
            cout << "Numero de Otro documento: " << ciudadanos[i].numeroDocumento << endl;
        }

        if(ciudadanos[i].sexo == 'F')
        {
            cout << "Sexo: Femenino" << endl;
        }
        else
        {
            cout << "Sexo: Masculino " << endl;
        }

        cout << "----------" << endl;
    }
}

void imprimirCiudadanosMasculinos(Ciudadano ciudadanos[], int dl, char sexo)
{
    Ciudadano ciudadanosMasculinos[MAX_PERSONAS]; // Arreglo para ciudadanos masculinos
    int indiceMasculinos = 0; // Índice para el nuevo arreglo

    for(int i = 0; i < dl; i++)
    {
        if(ciudadanos[i].sexo == 'M')
        {
            ciudadanosMasculinos[indiceMasculinos] = ciudadanos[i];
            indiceMasculinos++;
        }
    }

    for(int p = 0; p < indiceMasculinos; p++)
    {
        cout << "Ciudadano " << p + 1 << ":" << endl;
        cout << "Nombre y apellido: " << ciudadanosMasculinos[p].nombreApellido << endl;
        cout << "Direccion: " << ciudadanosMasculinos[p].direccion << endl;

        int dia, mes, anio;
        dia = ciudadanosMasculinos[p].fechaNacimiento % 100; // Obtiene el día
        mes = (ciudadanosMasculinos[p].fechaNacimiento / 100) % 100; // Obtiene el mes
        anio = ciudadanosMasculinos[p].fechaNacimiento / 10000; // Obtiene el año
        cout << "Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << endl;

        if(ciudadanosMasculinos[p].tipoDocumento == 1)
        {
            cout << "Tipo de documento: DNI" << endl;
        }
        else if(ciudadanosMasculinos[p].tipoDocumento == 2)
        {
            cout << "Tipo de documento: Pasaporte" << endl;
        }
        else
        {
            cout << "Tipo de documento: Otro" << endl;
        }

        cout << "Numero de documento: " << ciudadanosMasculinos[p].numeroDocumento << endl;
        cout << "Sexo: Masculino" << endl;

        cout << "----------" << endl;
    }
}

void imprimirCiudadanasFemeninos(Ciudadano ciudadanos[], int dl, char sexo)
{
    Ciudadano ciudadanasFemeninas[MAX_PERSONAS]; // Arreglo para ciudadanas femeninas
    int indiceFemeninas = 0; // Índice para el nuevo arreglo

    for(int i = 0; i < dl; i++)
    {
        if(ciudadanos[i].sexo == 'F')
        {
            ciudadanasFemeninas[indiceFemeninas] = ciudadanos[i];
            indiceFemeninas++;
        }
    }

    for(int p = 0; p < indiceFemeninas; p++)
    {
        cout << "Ciudadana " << p + 1 << ":" << endl;
        cout << "Nombre y apellido: " << ciudadanasFemeninas[p].nombreApellido << endl;
        cout << "Direccion: " << ciudadanasFemeninas[p].direccion << endl;

        int dia, mes, anio;
        dia = ciudadanasFemeninas[p].fechaNacimiento % 100; // Obtiene el día
        mes = (ciudadanasFemeninas[p].fechaNacimiento / 100) % 100; // Obtiene el mes
        anio = ciudadanasFemeninas[p].fechaNacimiento / 10000; // Obtiene el año
        cout << "Fecha de nacimiento: " << dia << "/" << mes << "/" << anio << endl;

        if(ciudadanasFemeninas[p].tipoDocumento == 1)
        {
            cout << "Tipo de documento: DNI" << endl;
        }
        else if(ciudadanasFemeninas[p].tipoDocumento == 2)
        {
            cout << "Tipo de documento: Pasaporte" << endl;
        }
        else
        {
            cout << "Tipo de documento: Otro" << endl;
        }

        cout << "Numero de documento: " << ciudadanasFemeninas[p].numeroDocumento << endl;
        cout << "Sexo: Femenino" << endl;

        cout << "----------" << endl;
    }
}

void menu(Ciudadano ciudadanos[], int &dl)
{
    char opciones;
    char sexo;
    do
    {
        cout << "Bienvenido al sistema del Registro Nacional de las Personas" << endl;
        cout << "A. Cargar ciudadanos al listado" << endl;
        cout << "B. Imprimir listado completo" << endl;
        cout << "C. Imprimir listado de ciudadanos masculinos" << endl;
        cout << "D. imprimir listado de ciudadanas femeninas" << endl;
        cout << "E. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'A':
            case 'a':
            {
                cargarCiudadano(ciudadanos, dl);
                break;
            }

            case 'B':
            case 'b':
            {
                imprimirListado(ciudadanos, dl);
                break;
            }

            case 'C':
            case 'c':
            {
                imprimirCiudadanosMasculinos(ciudadanos, dl, sexo);
                break;
            }

            case 'D':
            case 'd':
            {
                imprimirCiudadanasFemeninos(ciudadanos, dl, sexo);
                break;
            }

            case 'E':
            case 'e':
            {
                cout  << "Gracias por utilizar el sistema del Registro Nacional de las Personas" << endl;
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
    Ciudadano ciudadanos[MAX_PERSONAS];
    int dl = 0;

    menu(ciudadanos, dl);

    return 0;
}