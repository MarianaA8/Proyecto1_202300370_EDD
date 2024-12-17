#include "../../includes/Activo.h"

#ifndef NODEAVL_H
#define NODEAVL_H



class NodeAVL {
public:

    int factorEq;
    NodeAVL *izquierdo;
    NodeAVL *derecho;
    Activo  *activo;


    NodeAVL(Activo *activo);

    /*void setNombre(string nombre);
    void setPassword(string password);

    string getNombre();
    string getPassword();*/


};



#endif //NODEAVL_H
