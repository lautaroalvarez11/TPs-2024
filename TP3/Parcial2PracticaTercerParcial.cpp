#include <iostream>
#include <string>
using namespace std;

/*
1)
Dado los siguientes punteros:
int* a = new int;
int* b = a;
Escribir las instrucciones para:
a) Almacenar el número 20 en el espacio de memoria apuntado por a.
b) Imprimir el valor apuntado por a.
c) Almacenar el número 15 en el espacio de memoria apuntado por b.
d) Imprimir el valor apuntado por b y luego el apuntado por a. ¿Qué número imprimirá cada una y por qué?


Solución:
a) a = 20;
b) cout << *a << endl;
c) b = 15;
d) cout << *b << " - " << *a << endl;
Imprime 15 - 15 porque a y b apuntan al mismo espacio de memoria,
por lo tanto si se modifica el valor apuntado por b, también se modifica el valor apuntado por a.


2)
Dado los siguientes structs:
struct Direccion
{
    string calle;
    int nro;
    string localidad;
};

struct Paciente
{
    string nombre;
    int dni;
    Direccion direccion;
};
Escribir las instrucciones necesarias para:
a) Declarar una variable de tipo puntero a Paciente y reservar memoria.
b) Pedir al usuario que ingrese por teclado los siguientes datos del paciente:
    - Número de DNI
    - Nombre y apellido
    - Dirección
Almacenar los datos en el Paciente apuntado por el puntero declarado en el inciso anterior.
c) El usuario se equivocó al ingresar el número de puerta (campo "nro"). Por lo tanto, hay que modificar este dato guardado
en el paciente apuntado por el puntero anterior. El nuevo valor es 195.
d) Imprimir todos los datos de los pacientes.


Solución:
a) Paciente* pacientes = new Paciente();
b)
    - cout << "Ingrese el DNI del paciente: ";
      cin >> pacientes -> dni;
    - cout << "Ingrese el nombre y apellido del paciente: ";
      getline(cin >> ws, pacientes -> nombre);
    - cout << "Ingrese la calle del paciente: ";
      getline(cin >> ws, pacientes -> direccion.calle);
      cout << "Ingrese el número de domicilio del paciente: ";
      cin >> pacientes -> direccion.nro;
      cout << "Ingrese la localidad del paciente: ";
      getline(cin >> ws, pacientes -> direccion.localidad);
c) pacientes -> direccion.nro = 195;
d) cout << "Datos del Paciente:" << endl;
   cout << "Nombre: " << pacientes -> nombre << endl;
   cout << "DNI: " << pacientes -> dni << endl;
   cout << "Calle: " << pacientes -> direccion.calle << endl;
   cout << "Numero: " << pacientes -> direccion.nro << endl;
   cout << "Localidad: " << pacientes -> direccion.localidad << endl;


3)
Una importante librería requiere implementar un sistema que le permita llevar un registro de los libros que posee a la venta y el stock de cada uno de ellos.
Gran parte de los módulos para este sistema ya han sido desarrollados por un equipo. Solo faltarían implementar algunas funcionalidades, las cuales,
te han sido asignadas y tendrás que desarrollarlas según los requerimientos que se describen a continuación:
a) Carga de datos: Definir el struct a utilizar y el nodo correspondiente. De cada libro se tiene un código, título, precio y stock.
Almacenar los datos en una lista enlazada simple insertando al final.
b) Actualización de precios: El sistema debe permitir modificar el precio de un determinado libro.
Para eso se solicitará por teclado el ingreso del código del libro y si existe, se debe solicitar el nuevo precio.
Se debe mostrar al usuario un mensaje de "Importe actualizado con éxito" o "No se encontró el libro".
c) Reporte: Informar la cantidad de libros cuyo stock supere las tres unidades y cuyo precio no supere los $25.000.


Solución:
struct Libro
{
    int codigo;
    string titulo;
    int precio;
    int stock;
};

struct Nodo
{
    Libro dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Libro libros)
{
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo -> dato = libros;
    nuevoNodo -> siguiente = nullptr;
    return nuevoNodo;
}

void insertarAlFinal(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr)
    {
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while(aux -> siguiente != nullptr)
        {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }
}

void cargaDeDatos(Nodo* &inicio)
{
    Libro libros;

    cout << "Ingrese el codigo del libro (0 para finalizar): ";
    cin >> libros.codigo;
    cin.ignore();

    while(libros.codigo != 0)
    {
        cout << "Ingrese el titulo del libro: ";
        getline(cin >> ws, libros.titulo);

        cout << "Ingrese el precio del libro: $";
        cin >> libros.precio;
        cin.ignore();

        cout << "Ingrese la cantidad en stock del libro: ";
        cin >> libros.stock;
        cin.ignore();

        Nodo* nuevoLibro = crearNodo(libros);
        insertarAlFinal(inicio, nuevoLibro);

        cout << "Ingrese el codigo del libro (0 para finalizar): ";
        cin >> libros.codigo;
        cin.ignore();
    }
}

void actualizacionDePrecios(Nodo* inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay libros en el listado" << endl;
        return;
    }

    int codigoAux;
    cout << "Ingrese el codigo de un libro para modificarle el precio: ";
    cin >> codigoAux;

    bool encontrado = false;

    Nodo* aux = inicio;

    while(aux != nullptr)
    {
        if(aux -> dato.codigo == codigoAux)
        {
            encontrado = true;
            cout << "Ingrese el nuevo precio del libro: $";
            cin >> aux -> dato.precio;
            cout << "Importe actualizado con exito" << endl;
            break;
        }
        aux = aux -> siguiente;
    }

    if(!encontrado)
    {
        cout << "No se encontro el libro" << endl;
    }
}

void reporte(Nodo* inicio)
{
    if(inicio == nullptr)
    {
        cout << "No hay libros en el listado" << endl;
    }

    int contador = 0;

    Nodo* aux = inicio;
    while(aux != nullptr)
    {
        if(aux -> dato.stock > 3 && aux -> dato.precio <= 25000)
        {
            contador++;
        }
        aux = aux -> siguiente;
    }

    cout << "La cantidad de libros con stock mayor a 3 con precio menor o igual a $25.000 es: " << contador << endl;
}


*/