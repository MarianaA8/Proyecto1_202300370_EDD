//
// Created by maria on 17/12/2024.
//

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NodeCircular.h"


class ListaCircular {
    private:

    Transaccion *transaccion;
    int size;
    NodeCircular *cabeza;

    public:

    ListaCircular(Transaccion *transaccion);

    ~ListaCircular();

    void insertarElementoInicio(Transaccion *transaccion);
    void insertarElementoFinal(Transaccion *transaccion);

    void eliminar(Transaccion *transaccion);
    void imprimir();

    bool estaVacia();
    int obtenerTamano();

};



#endif //LISTACIRCULAR_H
