#include <iostream>
#include <string>
using namespace std;

/*
Existe una convención con máximo 3000 participantes, cada participante tiene los siguientes datos:
    Nombre (string).
    Tipo de documento (string) (debe estar definido por defecto como DNI).
    Número de documento (int).
    Dirección (struct) (contiene):
        Piso (int).
        Localidad (string).
        Departamento (char).
        Calle (string).
Los participantes deben estar dentro de un arreglo.
A. Se debe crear una función que permita la acreditación de los participantes
(si el número de documento es 0 se termina la carga de datos).
B Se debe crear una función que permita la búsqueda de participante por DNI, si se encuentra al participante se debe mostrar
el mensaje "Participante validado satisfactoriamente", en caso contrario mostrar "Para validarse primero debe acreditarse".
C. Se debe crear una función que muestre todos los datos de todos los participantes acreditados.
*/

const int MAX_PARTICIPANTES = 3000;

struct Direccion
{
    int piso;
    string localidad;
    char departamento;
    string calle;
};

struct Convencion
{
    string nombre;
    string tipoDocumento = "DNI";
    int numeroDocumento;
    Direccion direcciones;
};

void acreditarParticipante(Convencion participantes[], int &dl)
{
    if(dl >= MAX_PARTICIPANTES)
    {
        cout << "Sistema lleno." << endl;
        return;
    }

    for(int i = dl; i < MAX_PARTICIPANTES; i++)
    {
        cout << "Ingrese el nombre del participante: ";
        getline(cin >> ws, participantes[i].nombre);

        cout << "Ingrese el numero de documento del participante: ";
        cin >> participantes[i].numeroDocumento;
        cin.ignore();

        if(participantes[i].numeroDocumento == 0)
        {
            cout << "Finalizando carga..." << endl;
            break;
        }

        cout << "Ingrese la localidad del participante: ";
        getline(cin >> ws, participantes[i].direcciones.localidad);

        cout << "Ingrese la calle del participante: ";
        getline(cin >> ws, participantes[i].direcciones.calle);

        cout << "Ingrese el piso del participante: ";
        cin >> participantes[i].direcciones.piso;
        cin.ignore();

        cout << "Ingrese el departamento del participante (caracter): ";
        cin >> participantes[i].direcciones.departamento;
        cin.ignore();

        dl++;
    }
}

void buscarParticipante(Convencion participantes[], int dl)
{
    int numDocumentoTemporal;
    cout << "Ingrese el numero de documento del participante a buscar: ";
    cin >> numDocumentoTemporal;

    bool encontrado = false;

    for(int i = 0; i < dl; i++)
    {
        if(participantes[i].numeroDocumento == numDocumentoTemporal)
        {
            encontrado = true;
            cout << "Participante validado satisfactoriamente." << endl;
            break;
        }
    }

    if(!encontrado)
    {
        cout << "Para validarse primero debe acreditarse." << endl;
    }
}

void imprimirParticipantes(Convencion participantes[], int dl)
{
    for(int i = 0; i < dl; i++)
    {
        cout << "Datos de participante " << i+1 << ":" << endl;
        cout << "Nombre: " << participantes[i].nombre << endl;
        cout << "Numero de DNI: " << participantes[i].numeroDocumento << endl;
        cout << "Localidad: " << participantes[i].direcciones.localidad << endl;
        cout << "Calle: " << participantes[i].direcciones.calle << endl;
        cout << "Piso: " << participantes[i].direcciones.piso << endl;
        cout << "Departamento: " << participantes[i].direcciones.departamento << endl;
        cout << "----------" << endl;
    }
}

int main()
{
    Convencion participantes[MAX_PARTICIPANTES];
    int dl = 0;

    acreditarParticipante(participantes, dl);
    buscarParticipante(participantes, dl);
    imprimirParticipantes(participantes, dl);

    return 0;
}