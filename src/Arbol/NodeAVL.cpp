#include "../../includes/Arbol/NodeAVL.h"
#include "../../includes/Activo.h"

NodeAVL::NodeAVL(Activo *activo) {
    this->activo = activo;
    this->factorEq = 0;
    this->derecho= nullptr;
    this->izquierdo = nullptr;
}

