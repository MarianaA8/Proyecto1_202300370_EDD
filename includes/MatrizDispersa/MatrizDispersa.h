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
    void insertarFinal(Node *usuario, Node *cabeceraHor, Node *cabeceraVer);

    bool verificarExtistencia(string nombre);
    void insertarUsuarioProfuncidad(Node *usuario, string nombreCabeH, string nombreCabeV);


public:
    MatrizDispersa();

    bool existenCabeceras();

    void insertarUsuario(Usuario *usuario, string nombreCabeH, string nombreCabeV);

    void insertarFinalDeH(Node *usuario, Node *cabeceraHor);
    void insertarFinalDeV(Node *usuario, Node *cabeceraVer);
    void insertarMedioVer(Node *usuario, Node *vertical);
    void insertarMedioHor(Node *usuario, Node *horizontal);

    Node *estaCabceraHor(Node *node);
    Node *estaCabceraVer(Node *node);

    bool verificarExistenciaUsuario(string nombre, string nombreCabeH, string nombreCabeV);
    bool seguirAbajo(Node *cabeceraVer, string cabeV);
    bool seguirDerecha(Node *cabeceraHor, string cabeH);

    bool validarCredenciales(string nombreUsuario, string password);

    void generarGraficoMatriz();

    Node *busquedaDeNodo(string nombreCabeH, string nombreCabeV);

    Node* buscarUsuario(string nombreUsuario);
};



#endif //MATRIZDISPERSA_H
