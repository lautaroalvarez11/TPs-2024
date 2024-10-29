#include <iostream>
#include <string>
using namespace std;

/*
¿Qué salidas produce el siguiente código?:
int *p1, *p2;
p1 = new int;
p2 = new int;
*p1 = 10;
*p2 = 20;
cout << *p1 << " " << *p2 << endl;
*p1 = *p2;
cout << *p1 << " " << *p2 << endl;
*p2 = 30;
cout << *p1 << " " << *p2 << endl;

Salida:
10 20
20 20
20 30
*/