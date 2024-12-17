#include <iosfwd>
#include <iostream>
using namespace std;

#ifndef ACTIVO_H
#define ACTIVO_H

class Activo {
    public:


    string id;
    string descripcion;

    Activo(string id, string descripcion);

    void setDescripcion(string descripcion);

    string getDescripcion();
};

#endif //ACTIVO_H
