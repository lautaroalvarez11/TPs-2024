#include <iostream>
#include <string>
using namespace std;

/*
1)
Dado los siguientes punteros:
char* a = new int;
char* b = a;
Escribir las instrucciones para:
a) Almacenar el caracter # en el espacio de memoria apuntado por a.
b) Imprimir el valor apuntado por a.
c) Almacenar el caracter $ en el espacio de memoria apuntado por b.
d) Imprimir el valor apuntado por b y luego el apuntado por a. ¿Qué número imprimirá cada una y por qué?


Solución:



2)
Dados los siguientes structs:
struct Persona
{
    string nombre;
    string apellido;
    string dni;
};

struct Alumno
{
    Persona persona;
    int legajo;
    string condicion;
};
Escribir las instrucciones necesarias para:
a) Declarar una variable de tipo puntero a Alumno y reservar memoria.
b) Pedir al usuario que ingrese por teclado los siguientes datos del Alumno:
    - Nombre
    - Apellido
    - Número de DNI
    - Legajo
    - Condición ("Regular", "Libre", "Egresado")
Almacenar los datos en el Alumno apuntado por el puntero declarado en el inciso anterior.
c) El usuario se equivocó al ingresar el DNI. Por lo tanto, hay que modificar este dato guardado
en el Alumno apuntado por el puntero anterior. El nuevo valor debe ser: 45123987.
d) Imprimir todos los datos de los Alumno.


Solución:


3)
Una empresa de servicios de remises/taxis requiere implementar un sistema que le permita llevar un registro de su flota de vehículos
y los kilómetros recorridos por cada uno de ellos. Una parte de los módulos de este sistema ya han sido desarrollados por un equipo
de programadores, y ustedes han sido seleccionados para implementar las funcionalidades faltantes que se describen a continuación:
a) Carga de datos: De cada vehículo se necesita conocer: Patente, marca, modelo, año de fabricación, conductor y cantidad de kilómetros recorridos.
Almacenar los datos en una lista enlazada simple ordenada por año de fabricación. Definir el struct a utilizar y el nodo correspondiente.
b) Actualización de kilómetros: Se debe permitir actualizar los kilómetros de un vehículo, para ellos se solicitará por teclado la patente de un vehículo,
y si existe, se deben solicitar los kilómetros realizados en el último viaje y sumarlos al valor que ya se encuentra almacenado.
El sistema deberá informar si se logró actualizar el dato, o se ingresó una patente inexistente.
c) Listado: Informar la cantidad de vehículos que superan los 100000 kilómetros recorridos.


Solución:
*/