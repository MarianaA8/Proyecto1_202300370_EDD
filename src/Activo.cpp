#include "../includes/Activo.h"

Activo::Activo(string id, string descripcion, string nombre) {
    this->id = id;
    this->descripcion = descripcion;
    this->nombre = nombre;

}


void Activo::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Activo::getDescripcion() {
    return this->descripcion;
}

string Activo::getNombre() {
    return this->nombre;
}