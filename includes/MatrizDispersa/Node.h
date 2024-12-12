#include <iostream>
#include <string>
#include "../Usuario.h"

using namespace std;

#ifndef NODE_H
#define NODE_H



class Node {

public:

    string nombreCabecera;
    Usuario* usuario;

    Node *sig;
    Node *ant;

    Node *arriba;
    Node *abajo;

    Node *adelante;
    Node *atras;

    Node(string nombreCabecera);

    Node(Usuario *usuario);

    ~Node();

};



#endif //NODE_H
