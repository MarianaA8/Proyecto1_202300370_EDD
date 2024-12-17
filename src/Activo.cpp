#include "../includes/Activo.h"

Activo::Activo(string id, string descripcion) {
    this->id = id;
    this->descripcion = descripcion;

}


void Activo::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Activo::getDescripcion() {
    return this->descripcion;
}