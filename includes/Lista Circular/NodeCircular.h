//
// Created by maria on 17/12/2024.
//
#include "../Transaccion.h"
#ifndef NODECIRCULAR_H
#define NODECIRCULAR_H



class NodeCircular {
public:

    Transaccion *transaccion;
    NodeCircular *siguiente;
    NodeCircular *anterior;

    NodeCircular(Transaccion *transaccion);


};



#endif //NODECIRCULAR_H
