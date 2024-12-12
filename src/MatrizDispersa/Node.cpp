
#include "../../includes/MatrizDispersa/Node.h"
#include "../../includes/Usuario.h"


Node::Node(string nombreCabecera) {
    this->nombreCabecera = nombreCabecera;
    this->usuario = nullptr;
    this->sig = nullptr;
    this->ant = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

Node::Node(Usuario *usuario) {
    this->usuario = usuario;
    this->sig = nullptr;
    this->ant = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}
