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



int main()
{

    return 0;
}