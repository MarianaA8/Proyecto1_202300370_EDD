#include "../../includes/Arbol/AVL.h"
#include <iostream>
#include <fstream>

using namespace std;

AVL::AVL() {
    this->raiz = nullptr;
}

void AVL::insertarNodo(Activo *activo) {
    NodeAVL *node = new NodeAVL(activo);

    insertar(node, this->raiz);
}

void AVL::eliminarNodo(string id) {

    eliminar(id, this->raiz);
}

void AVL::insertar(NodeAVL *ActivoValor, NodeAVL *&raiz) {
    if (raiz == nullptr) {
        raiz = ActivoValor;
        raiz->factorEq = factorDeEq(raiz);
        return;
    }

    if (ActivoValor->activo->id < raiz->activo->id) {
        insertar(ActivoValor, raiz->izquierdo);
    } else {
        insertar(ActivoValor, raiz->derecho);
    }

    raiz->factorEq = factorDeEq(raiz);

    if (raiz->factorEq < -1) {
        if (raiz->izquierdo->factorEq > 0) {
            rotacionDerIzq(raiz);
            return;
        }
        rotacionIzq(raiz);
        return;
    }

    if (raiz->factorEq > 1) {
        if (raiz->derecho->factorEq < 0) {
            rotacionIzqDer(raiz);
            return;
        }
        rotacionDer(raiz);
        return;
    }
}

void AVL::eliminar(string id, NodeAVL *&raiz) {

    if (raiz == nullptr) {
        cout << "Error al eliminar." << " No existe el nodo" << endl;
        return;
    }

    if (id == raiz->activo->id) {
        if (esHoja(raiz)) {
            raiz = nullptr;
            return;
        }

        if (raiz->izquierdo == nullptr) {
            raiz = raiz->derecho;
            return;
        }

        if (raiz->derecho == nullptr) {
            raiz = raiz->izquierdo;
            return;
        }

        NodeAVL *nodoReemplazo = haciaDerecha(raiz->izquierdo);
        raiz->activo = nodoReemplazo->activo;

        eliminar(nodoReemplazo->activo->id, raiz->izquierdo);
    }

    if (id < raiz->activo->id) {
        eliminar(id, raiz->izquierdo);
    }

    if (id > raiz->activo->id) {
        eliminar(id, raiz->derecho);
    }

    raiz->factorEq = factorDeEq(raiz);

    if (raiz->factorEq < -1) {
       if (raiz->izquierdo->factorEq > 0) {
           rotacionDerIzq(raiz);
           return;
       }
        rotacionDer(raiz);
        return;
    }

    if (raiz->factorEq > 1) {
        if (raiz->derecho->factorEq < 0) {
            rotacionIzqDer(raiz);
            return;
        }
        rotacionIzq(raiz);
        return;
    }
}


int AVL::obtenerAlturaMax(NodeAVL *node) {
    if (node == nullptr) return 0;

    int alturaIzq = obtenerAlturaMax(node->izquierdo);
    int alturaDer = obtenerAlturaMax(node->derecho);

    return alturaIzq > alturaDer ? alturaIzq + 1 : alturaDer + 1;
}

int AVL::factorDeEq(NodeAVL *node) {
    return obtenerAlturaMax(node->derecho) - obtenerAlturaMax(node->izquierdo);

}
void AVL::rotacionIzq(NodeAVL *&node) {

    NodeAVL *auxiliar = node->izquierdo;

    node->izquierdo = auxiliar->derecho;
    auxiliar->derecho = node;
    node = auxiliar;

    node->factorEq = factorDeEq(node);
    node->derecho->factorEq = factorDeEq(node->derecho);

    if (node->izquierdo == nullptr) return;

    node->izquierdo->factorEq = factorDeEq(node->izquierdo);


}

void AVL::rotacionDer(NodeAVL *&node) {

    NodeAVL *auxiliar = node->derecho;

    node->derecho = auxiliar->izquierdo;
    auxiliar->izquierdo = node;
    node = auxiliar;

    node->factorEq = factorDeEq(node);
    node->izquierdo->factorEq = factorDeEq(node->izquierdo);

    if (node->derecho == nullptr) return;

    node->derecho->factorEq = factorDeEq(node->derecho);
}

void AVL::rotacionDerIzq(NodeAVL *&node) {
    rotacionDer(node->izquierdo);
    rotacionIzq(node);
}

void AVL::rotacionIzqDer(NodeAVL *&node) {
    rotacionIzq(node->derecho);
    rotacionDer(node);
}

NodeAVL *AVL::haciaDerecha(NodeAVL *&node) {
    if (node->derecho == nullptr) {
        return node;
    }

    return haciaDerecha(node->derecho);
}

bool AVL::esHoja(NodeAVL *node) {
    return node->izquierdo == nullptr && node->derecho == nullptr;
}

void AVL::obtenerNodos() {
    vector<Activo *> objetos;
    acumularNodos(this->raiz, objetos);

    for (Activo *obj : objetos) {
        cout << "Nombre: " << obj->getNombre() << "ID: " << obj->id << "   Descripcion:  " << obj->getDescripcion() << endl;
    }
}

void AVL::acumularNodos(NodeAVL *nodo, vector<Activo *> &objetos) {
    if (nodo == nullptr) return;
    acumularNodos(nodo->izquierdo, objetos);
    objetos.push_back(nodo->activo);
    acumularNodos(nodo->derecho,objetos);
}

void AVL::generarDOT(NodeAVL *raiz, ofstream &archivo) {
    if (raiz == nullptr) return;

    archivo << "    \"" << raiz->activo->id << "\""
            << " [label=\"" << raiz->activo->id << "\\nFE: " << raiz->factorEq
            << "\", shape=circle, style=filled, fillcolor=lightblue];\n";

    if (raiz->izquierdo != nullptr) {
        archivo << "    \"" << raiz->activo->id << "\" -> \""
                << raiz->izquierdo->activo->id << "\";\n";
        generarDOT(raiz->izquierdo, archivo);
    }

    if (raiz->derecho != nullptr) {
        archivo << "    \"" << raiz->activo->id << "\" -> \""
                << raiz->derecho->activo->id << "\";\n";
        generarDOT(raiz->derecho, archivo);
    }
}

void AVL::exportarGrafo(string nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo DOT." << endl;
        return;
    }

    archivo << "digraph AVL {\n";
    archivo << "    node [fontname=\"Arial\"];\n";

    generarDOT(this->raiz, archivo);

    archivo << "}\n";
    archivo.close();

    cout << "El archivo DOT ha sido generado exitosamente: " << nombreArchivo << endl;

    string comando = "dot -Tpng " + nombreArchivo + " -o arbol_avl.png";
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << "La imagen ha sido generada exitosamente!" << endl;
    } else {
        cout << "Error al generar la imagen con Graphviz." << endl;
    }
}

void AVL::modificarDescripcion(string id, string nuevaDescripcion) {
    NodeAVL* nodo = buscarNodoPorID(id, this->raiz);

    if (nodo != nullptr) {
        nodo->activo->setDescripcion(nuevaDescripcion);
        cout << "Descripción modificada con éxito." << endl;
    } else {
        cout << "No se encontró un activo con el ID: " << id << endl;
    }
}

NodeAVL* AVL::buscarNodoPorID(string id, NodeAVL* raiz) {
    if (raiz == nullptr) return nullptr;

    if (id == raiz->activo->id) {
        return raiz;
    }

    if (id < raiz->activo->id) {
        return buscarNodoPorID(id, raiz->izquierdo);
    } else {
        return buscarNodoPorID(id, raiz->derecho);
    }
}





