#include <iostream>
#include <string>
using namespace std;

/*
"The Golden Gate Bridge" es el puente más famoso de la ciudad de San Francisco (California). Cuenta con una
longitud aproximada de 1280 metros y posee tres radares de toma de velocidad. Por cada móvil que se
desplaza por las vías principales se registra la siguiente información: sensor que lo captó (puede ser "norte",
"sur" o "medio"), patente (no tiene un formato único ya que difiere de un estado a otro y pueden transitar
autos extranjeros, aunque se sabe que están formadas sólo por letras y números) y velocidad en km/h.
A. Cargar las lecturas que hacen los sensores en una lista enlazada simple ordenando por patente y, para
la misma patente, ordenando por sensor (ya que un mismo automóvil puede ser captado por más de un sensor).
Finaliza con la patente "aaa99", que no se debe ingresar.
B. Dada la lista generada en el inciso anterior, armar tres listas: una por cada sensor (el orden de los
elementos tiene que ser el mismo que en la lista original). Luego, imprimir las tres listas.
*/

struct Radar
{
    string sensor;
    string patente;
    float velocidad;
};

struct Nodo
{
    Radar dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Radar infoAuto)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = infoAuto;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarOrdenado(Nodo* &inicio, Nodo* nuevoNodo)
{
    if (inicio == nullptr || inicio -> dato.patente > nuevoNodo -> dato.patente || (inicio -> dato.patente == nuevoNodo -> dato.patente && inicio -> dato.sensor > nuevoNodo -> dato.sensor))
    {
        nuevoNodo -> siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux -> siguiente != nullptr && (aux -> siguiente -> dato.patente < nuevoNodo -> dato.patente || (aux -> siguiente -> dato.patente == nuevoNodo -> dato.patente && aux -> siguiente -> dato.sensor <= nuevoNodo -> dato.sensor)))
        {
            aux = aux -> siguiente;
        }
        nuevoNodo -> siguiente = aux -> siguiente;
        aux -> siguiente = nuevoNodo;
    }
}

void cargarLecturas(Nodo*& inicio)
{
    Radar info;

    cout << "Ingrese la patente del vehiculo (aaa99 para finalizar): ";
    cin >> info.patente;

    while (info.patente != "aaa99")
    {
        do
        {
            cout << "Ingrese el sensor (Norte, Sur o Medio): ";
            cin >> info.sensor;
            if(info.sensor != "Norte" && info.sensor != "Sur" && info.sensor != "Medio")
            {
                cout << "Por favor ingrese una opcion valida" << endl;
            }
        } while (info.sensor != "Norte" && info.sensor != "Sur" && info.sensor != "Medio");
        
        cout << "Ingrese la velocidad en km/h: ";
        cin >> info.velocidad;

        Nodo* nuevoNodo = crearNodo(info);
        insertarOrdenado(inicio, nuevoNodo);

        cout << "Ingrese la patente del vehiculo (aaa99 para finalizar): ";
        cin >> info.patente;
    }
}

void separarLista(Nodo* inicio, Nodo* &listaNorte, Nodo* &listaSur, Nodo* &listaMedio)
{
    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        Nodo* nuevoNodo = crearNodo(aux -> dato);
        if (aux -> dato.sensor == "Norte")
        {
            insertarOrdenado(listaNorte, nuevoNodo);
        }
        else if (aux -> dato.sensor == "Sur")
        {
            insertarOrdenado(listaSur, nuevoNodo);
        }
        else if (aux -> dato.sensor == "Medio")
        {
            insertarOrdenado(listaMedio, nuevoNodo);
        }
        aux = aux -> siguiente;
    }
}

void imprimirLecturas(Nodo* inicio)
{
    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        cout << "Patente: " << aux -> dato.patente << ", Sensor: " << aux -> dato.sensor << ", Velocidad: " << aux -> dato.velocidad << " km/h" << endl;
        aux = aux -> siguiente;
    }
}

int main()
{
    Nodo* inicio = nullptr;
    Nodo* listaNorte = nullptr;
    Nodo* listaSur = nullptr;
    Nodo* listaMedio = nullptr;

    cargarLecturas(inicio);

    separarLista(inicio, listaNorte, listaSur, listaMedio);

    cout << "Lecturas del sensor norte:" << endl;
    imprimirLecturas(listaNorte);

    cout << "Lecturas del sensor sur:" << endl;
    imprimirLecturas(listaSur);

    cout << "Lecturas del sensor medio:" << endl;
    imprimirLecturas(listaMedio);

    return 0;
}