#include "../includes/Transaccion.h"
//
// Created by maria on 17/12/2024.
//
Transaccion::Transaccion(Activo *activo, int diasPorRentar) {
    this->activo = activo;
    this->diasPorRentar = 0;
}
