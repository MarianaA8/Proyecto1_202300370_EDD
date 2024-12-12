#include "Node.h"
#include <iostream>

using namespace std;

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H


class MatrizDispersa {

private:

    Node *cabeceraHor; //Node *cabeH
    Node *cabeceraVer; //Node *cabeV


    Node *cabeceraHorizontal(string nombreCabeH);
    Node *cabeceraVertical(string nombreCabeV);

    Node *insertarCabeceraHor(string nombreCabeH);
    Node *insertarCebeceraVer(string nombreCabeV);
    void insertarFinal(Usuario *usuario, Node *cabeceraHor, Node *cabeceraVer);


public:
    MatrizDispersa();

    bool existenCabeceras();

    void insertarUsuario(Usuario *usuario, string nombreCabeH, string nombreCabeV);

    /*void insertarFinalDeH(Node *usuario, Node *cabeceraHor);
    void insertarFinalDeV(Node *usuario, Node *cabeceraVer);
    void insertarMedioVer(Node *usuario, Node *vertial);

    Node *estaCabceraHor(Node *node);
    Node *estaCabceraVer(Node *node);

    bool masAbajo(Node *cabeceraVer, string cabeV);
    bool masDerecha(Node *cabeceraHor, string cabeH);*/


};



#endif //MATRIZDISPERSA_H
