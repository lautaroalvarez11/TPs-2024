#include <iostream>
#include <string>
using namespace std;

/*
Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club. Para ello, almacenar en un arreglo los números de DNI de los socios que pagaron. El club no tiene más de 200 socios.
Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día". Si no está, imprimir "Socio con deuda".
También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado erróneamente.
Finalmente, imprimir todo el arreglo.
*/

const int dimFis = 200;

void AgregarDNI(int arreglo[], int &dimLog)
{
    cout << "Ingrese un DNI (numero negativo para finalizar): ";
    for (int k = dimLog; k < dimFis; k++)
    {
        cin >> arreglo[k];
        if (arreglo[k] < 0)
        {
            break;
        }
        dimLog++;
    }
    if (dimLog == dimFis)
    {
        cout << "El arreglo alcanzo su capacidad total." << endl;
    }
}

bool BuscarDni(int arreglo[], int dimLog, int DNIaBuscar)
{
    for(int i = 0; i < dimLog; i++)
    {
        if(arreglo[i] == DNIaBuscar)
        {
            return true;
        }
    }
    return false;
}

void EliminarDNI(int arreglo[], int &dimLog, int DNIaEliminar)
{
    for(int i = 0; i < dimLog; i++)
    {
        if(arreglo[i] == DNIaEliminar)
        {
            for(int j = i; j < dimLog - 1; j++)
            {
                arreglo[j] = arreglo[j+1];
            }
            dimLog--;
            break;
        }
    }
}

void MostrarArreglo(int arreglo[], int dimLog)
{
    cout << "El arreglo es:" << endl;
    for(int i = 0; i < dimLog; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arreglo[dimFis], dimLog = 0, DNI;
    char opciones;

    do
    {
        cout << "Bienvenido al sistema" << endl;
        cout << "A. Agregar un DNI de socio que pago." << endl;
        cout << "B. Verificar estado de cuota." << endl;
        cout << "C. Eliminar un DNI del sistema." << endl;
        cout << "D. Mostrar todos los socios." << endl;
        cout << "E. Salir del programa." << endl;
        
        cout << "Elija una opcion: ";
        cin >> opciones;
        
        switch(opciones)
        {
            case 'a':
            case 'A':
            {
                AgregarDNI(arreglo, dimLog);
                break;
            }

            case 'b':
            case 'B':
            {
                cout << "Ingrese un DNI a buscar: ";
                cin >> DNI;
                if(BuscarDni(arreglo, dimLog, DNI))
                {
                    cout << "El DNI " << DNI << " se encuentra al dia." << endl;
                }
                else
                {
                    cout << "El DNI " << DNI << " no se encuentra registrado." << endl;
                }
                break;
            }

            case 'c':
            case 'C':
            {
                cout << "Ingrese DNI a eliminar: ";
                cin >> DNI;
                EliminarDNI(arreglo, dimLog, DNI);
                cout << "El arreglo nuevo es:" << endl;
                MostrarArreglo(arreglo, dimLog);
                break;
            }

            case 'd':
            case 'D':
            {
                MostrarArreglo(arreglo, dimLog);
                break;
            }

            case 'e':
            case 'E':
            {
                cout << "Saliendo del programa." << endl;
                break;
            }
            
            default:
                cout << "Ingrese una opcion valida." << endl;
        }
        
    } while(opciones != 'e' && opciones != 'E');
    
    return 0;
}