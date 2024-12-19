#include <iosfwd>
#include <iostream>
using namespace std;

#ifndef ACTIVO_H
#define ACTIVO_H

class Activo {
    public:


    string id;
    string descripcion;
    string nombre;

    Activo(string id, string descripcion, string nombre);

    void setDescripcion(string descripcion);

    string getDescripcion();

    string getNombre();
};

#endif //ACTIVO_H
