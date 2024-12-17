//
// Created by maria on 16/12/2024.
//
#include <vector>

#ifndef AVL_H
#define AVL_H
#include "../../includes/Arbol/NodeAVL.h"
#include <iostream>

using namespace std;


class AVL {
public:
    NodeAVL *raiz;

    AVL();

    void insertarNodo(Activo *activo);
    void eliminarNodo(string id);
    void exportarGrafo(string nombreArchivo);
    void generarDOT(NodeAVL *raiz, ofstream &archivo);
    void obtenerNodos();
    void modificarDescripcion(string id, string nuevaDescripcion);


private:
    void insertar(NodeAVL *ActivoValor, NodeAVL* &raiz);

    int obtenerAlturaMax(NodeAVL *node);

    int factorDeEq(NodeAVL *node);

    void rotacionIzq(NodeAVL *&node);

    void rotacionDer(NodeAVL *&node);

    void rotacionIzqDer(NodeAVL *&node);

    void rotacionDerIzq(NodeAVL *&node);

    void eliminar(string id, NodeAVL *&raiz);

    NodeAVL *haciaDerecha(NodeAVL *&node);

    bool esHoja(NodeAVL *node);

    void acumularNodos(NodeAVL *nodo, vector<Activo *> &objetos);

    NodeAVL* buscarNodoPorID(string id, NodeAVL* raiz);


};


#endif //AVL_H
