#include <iostream>
#include <string>
using namespace std;

/*
Implementar un sistema que permita administrar datos de clientes de un comercio para enviarles promociones.
De cada cliente se tiene: nombre y apellido, DNI, e-mail, fecha de cumpleaños en formato DDMM, monto total de compras en el último año.
A. Realizar el módulo de carga. La misma finaliza con el nombre "zz". Los clientes deben almacenarse ordenados por número de DNI.
B. Informar cuántos clientes cumplen años en cada uno de los 12 meses del año. Utilizar un arreglo auxiliar para contabilizarlos.
C. Informar el nombre del cliente con el mayor monto de compras.
*/

const int MAX_CLIENTES = 1000;

struct Cliente
{
    string nombreApellido;
    int DNI;
    string email;
    int fechaNacimiento;
    int montoComprasUltimoAnio;
};

void ordenarClientes(Cliente clientes[], int &dl, Cliente nuevoCliente) //Algoritmo de ordenamiento: Inserción
{
    int i = dl - 1;
    
    // Desplazar los elementos hacia la derecha para hacer espacio
    while (i >= 0 && clientes[i].DNI > nuevoCliente.DNI)
    {
        clientes[i + 1] = clientes[i];
        i--;
    }
    
    // Insertar el nuevo cliente en la posición correcta
    clientes[i + 1] = nuevoCliente;
    
    // Incrementar el número de clientes
    dl++;
}

void cargarClientes(Cliente clientes[], int &dl)
{
    if(dl >= MAX_CLIENTES)
    {
        cout << "Sistema lleno" << endl;
        return;
    }

    for(int i = dl; i < MAX_CLIENTES; i++)
    {
        Cliente nuevoCliente;
        cout << "Ingrese el nombre y apellido del cliente ('zz' para finalizar): ";
        getline(cin >> ws, clientes[i].nombreApellido);
        if(clientes[i].nombreApellido == "zz")
        {
            cout << "Finalizando la carga..." << endl;
            break;
        }

        cout << "Ingrese el DNI del cliente: ";
        cin >> clientes[i].DNI;
        cin.ignore();

        cout << "Ingrese el email del cliente: ";
        getline(cin >> ws, clientes[i].email);

        cout << "Ingrese la fecha de nacimiento del cliente (formato DDMM): ";
        cin >> clientes[i].fechaNacimiento;
        cin.ignore();

        cout << "Ingrese la cantidad de compras totales en el ultimo anio: ";
        cin >> clientes[i].montoComprasUltimoAnio;
        cin.ignore();

        dl++;

        ordenarClientes(clientes, dl, nuevoCliente);
    }
}

void informarCumpleanios(Cliente clientes[], int dl)
{
    int meses[12] = {0};

    for (int i = 0; i < dl; i++)
    {
        int mes = clientes[i].fechaNacimiento % 100;  // Obtener los dos últimos dígitos que corresponden al mes
        if (mes >= 1 && mes <= 12)
        {
            meses[mes - 1]++;  // Incrementar el contador del mes correspondiente (mes - 1 porque el arreglo empieza en 0)
        } else
        {
            cout << "Error: Fecha de nacimiento invalida para el cliente: " << clientes[i].nombreApellido << endl;
        }
    }

    // Imprimir el resultado
    for (int i = 0; i < 12; i++)
    {
        cout << "Clientes que cumplen en el mes " << i + 1 << ": " << meses[i] << endl;
    }
}

void informarMayorComprador(Cliente clientes[], int dl)
{
    if (dl == 0)
    {
        cout << "No hay clientes en el sistema." << endl;
        return;
    }

    int montoMaximo = clientes[0].montoComprasUltimoAnio;
    string nombreApellidoMontoMaximo = clientes[0].nombreApellido;

    for (int i = 0; i < dl; i++)
    {
        if (clientes[i].montoComprasUltimoAnio > montoMaximo)
        {
            montoMaximo = clientes[i].montoComprasUltimoAnio;
            nombreApellidoMontoMaximo = clientes[i].nombreApellido;
        }
    }

    cout << "El cliente con el mayor monto de compras es: " << nombreApellidoMontoMaximo << " con un monto de $" << montoMaximo << endl;
}

void menu(Cliente clientes[], int dl)
{
    char opciones;
    do
    {
        cout << "Bienvenido al sistema de clientes" << endl;
        cout << "A. Cargar datos del cliente" << endl;
        cout << "B. Imprimir cuantos cumplen anios en cada mes" << endl;
        cout << "C. Imprimir el mayor comprador del ultimo anio" << endl;
        cout << "D. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opciones;

        switch(opciones)
        {
            case 'A':
            case 'a':
            {
                cargarClientes(clientes, dl);
                break;
            }

            case 'B':
            case 'b':
            {
                informarCumpleanios(clientes, dl);
                break;
            }

            case 'C':
            case 'c':
            {
                informarMayorComprador(clientes, dl);
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
    Cliente clientes[MAX_CLIENTES];
    int dl = 0;

    menu(clientes, dl);

    return 0;
}