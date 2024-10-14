#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa para gestionar las sucursales de una empresa.
a) Almacenar en un arreglo (máximo 2.000 elementos) los datos de los empleados: Legajo, nombre y DNI.
En otro arreglo (máximo 20 elementos) almacenar la información de las sucursales: Nombre de la sucursal y legajo del encargado. Cada vez que se ingrese un legajo del encargado de una sucursal, se debe validar si corresponde a un empleado existente. Si no existe, dejar al usuario en un bucle hasta que ingrese un número de legajo existente.
b) Dado el legajo de un empleado, informar su nombre.
c) Imprimir un listado de sucursales, mostrando nombre de sucursal y nombre del empleado encargado.
*/

const int MAX_EMPLEADOS = 2000;
const int MAX_SUCURSALES = 200;

struct Empleado
{
    string nombreEmpleado;
    int dniEmpleado, legajoEmpleado;
};

struct Sucursal
{
    string nombreSucursal;
    int legajoEncargado;
};

void cargarInformacion(Empleado empleados[], int &dlEmpleados, Sucursal sucursales[], int &dlSucursal)
{
    if(dlEmpleados >= MAX_EMPLEADOS)
    {
        cout << "Sistema de empleados lleno" << endl;
        return;
    }

    for(int i = dlEmpleados; i < MAX_EMPLEADOS; i++)
    {
        cout << "Ingrese el nombre del empleado " << i+1 << " ('Fin' para finalizar): ";
        getline(cin >> ws, empleados[i].nombreEmpleado);
        if(empleados[i].nombreEmpleado == "Fin")
        {
            cout << "Finalizando carga..." << endl;
            break;
        }

        cout << "Ingrese el DNI del empleado: ";
        cin >> empleados[i].dniEmpleado;
        cin.ignore();
        if(empleados[i].dniEmpleado < 1000000 || empleados[i].dniEmpleado > 99999999)
        {
            cout << "Ingrese un DNI valido: ";
            cin >> empleados[i].dniEmpleado;
            cin.ignore();
        }

        cout << "Ingrese el legajo del empleado: ";
        cin >>  empleados[i].legajoEmpleado;
        cin.ignore();

        cout << "----------" << endl;

        dlEmpleados++;
    }

    if(dlSucursal >= MAX_SUCURSALES)
    {
        cout << "Sistema de sucursales lleno" << endl;
        return;
    }

    for(int j = dlSucursal; j < MAX_SUCURSALES; j++)
    {
        cout << "Ingrese el nombre de la sucursal " << j+1 << " ('Fin' para finalizar): ";
        getline(cin >> ws, sucursales[j].nombreSucursal);
        if(sucursales[j].nombreSucursal == "Fin")
        {
            cout << "Finalizando carga..." << endl;
            break;
        }

        bool legajoValido = false;  // Bandera para validar el legajo

        while (!legajoValido)
        {
            cout << "Ingrese el legajo del encargado: ";
            cin >> sucursales[j].legajoEncargado;
            cin.ignore();

            // Verificar si el legajo existe entre los empleados
            for (int p = 0; p < dlEmpleados; p++)
            {
                if (sucursales[j].legajoEncargado == empleados[p].legajoEmpleado)
                {
                    legajoValido = true;
                    break;
                }
            }

            if (!legajoValido)
            {
                cout << "Legajo invalido. Ingrese un legajo de encargado que corresponda a un empleado existente." << endl;
            }
        }

        cout << "----------" << endl;

        dlSucursal++;
    }
}

void informarNombreEmpleado(Empleado empleados[], int dl)
{
    int legajoTemporal;
    cout << "Ingrese el legajo del empleado a buscar: ";
    cin >> legajoTemporal;
    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(empleados[i].legajoEmpleado == legajoTemporal)
        {
            encontrado = true;
            cout << "Nombre del empleado:  " << empleados[i].nombreEmpleado << endl;
            break;
        }
    }
    
    if(!encontrado)
    {
        cout << "El legajo ingresado no pertenece a ningun empleado" << endl;
    }
}

void informarEncargadoSucursal(Sucursal sucursales[], int dlSucursal, Empleado empleados[], int dlEmpleados)
{
    cout << "Listado de sucursales y sus encargados:" << endl;
    for (int i = 0; i < dlSucursal; i++)
    {
        cout << "Sucursal: " << sucursales[i].nombreSucursal << " - Encargado: ";
        
        // Buscar el nombre del encargado según su legajo
        bool encargadoEncontrado = false;
        for (int j = 0; j < dlEmpleados; j++)
        {
            if (sucursales[i].legajoEncargado == empleados[j].legajoEmpleado)
            {
                cout << empleados[j].nombreEmpleado << endl;
                encargadoEncontrado = true;
                break;
            }
        }

        if (!encargadoEncontrado)
        {
            cout << "Encargado no encontrado." << endl;
        }
    }
}

void menu(Empleado empleados[], Sucursal sucursales[], int dlEmpleado, int dlSucursal)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de sucursales" << endl;
        cout << "A. Cargar datos del empleado y sucursales" << endl;
        cout << "B. Buscar nombre de empleado por legajo" << endl;
        cout << "C. Imprimir sucursales con su empleado encargado" << endl;
        cout << "D. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'A':
            case 'a':
            {
                cargarInformacion(empleados, dlEmpleado, sucursales, dlSucursal);
                break;
            }

            case 'B':
            case 'b':
            {
                informarNombreEmpleado(empleados, dlEmpleado);
                break;
            }

            case 'C':
            case 'c':
            {
                informarEncargadoSucursal(sucursales, dlSucursal, empleados, dlEmpleado);
                break;
            }

            case 'D':
            case 'd':
            {
                cout  << "Gracias por utilizar el sistema" << endl;
                break;
            }

            default:
            {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }
    } while(opciones != 'D' && opciones != 'd');
}

int main()
{
        Empleado empleados[MAX_EMPLEADOS];
        Sucursal sucursales[MAX_SUCURSALES];
        int dlEmpleado = 0,  dlSucursal = 0;

        menu(empleados, sucursales, dlEmpleado, dlSucursal);

    return 0;
}