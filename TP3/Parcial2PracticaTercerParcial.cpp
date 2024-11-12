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

3)
Una importante librería requiere implementar un sistema que le permita llevar un registro de los libros que posee a la venta y el stock de cada uno de ellos.
Gran parte de los módulos para este sistema ya han sido desarrollados por un equipo. Solo faltarían implementar algunas funcionalidades, las cuales,
te han sido asignadas y tendrás que desarrollarlas según los requerimientos que se describen a continuación:
a) Carga de datos: Definir el struct a utilizar y el nodo correspondiente. De cada libro se tiene un código, título, precio y stock.
Almacenar los datos en una lista enlazada simple insertando al final.
b) Actualización de precios: El sistema debe permitir modificar el precio de un determinado libro.
Para eso se solicitará por teclado el ingreso del código del libro y si existe, se debe solicitar el nuevo precio. Se debe mostrar al usuario un mensaje de "Importe actualizado con éxito" o "No se encontró el libro".
c) Reporte: Informar la cantidad de libros cuyo stock supere las tres unidades y cuyo precio no supere los $25.000.
*/