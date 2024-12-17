#include "../includes/Activo.h"

#ifndef TRANSACCION_H
#define TRANSACCION_H


class Transaccion {
public:
    Activo *activo;
    int diasPorRentar;

    Transaccion(Activo *_activo, int diasPorRentar);


};


#endif //TRANSACCION_H
