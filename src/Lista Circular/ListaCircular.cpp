#include "../../includes/Lista Circular/ListaCircular.h"
#include <iostream>

using namespace std;

ListaCircular::ListaCircular(Transaccion *transaccion) {
    this->transaccion = transaccion;
    this->size = 0;
    this->cabeza = nullptr;
}

ListaCircular::~ListaCircular() {
    if (!estaVacia()) {
        NodeCircular* temp = cabeza;
        do {
            NodeCircular* nextNode = temp->siguiente;
            delete temp;
            temp = nextNode;
        } while (temp != cabeza);
    }
}

void ListaCircular::insertarElementoInicio(Transaccion *transaccion) {
    NodeCircular* nuevo = new NodeCircular(transaccion);

    if (estaVacia()) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        NodeCircular* cola = cabeza->anterior;
        nuevo->siguiente = cabeza;
        nuevo->anterior = cola;
        cabeza->anterior = nuevo;
        cola->siguiente = nuevo;
        cabeza = nuevo;
    }
    size++;
}

void ListaCircular::insertarElementoFinal(Transaccion *transaccion) {
    NodeCircular* nuevo = new NodeCircular(transaccion);

    if (estaVacia()) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        NodeCircular* cola = cabeza->anterior;
        nuevo->siguiente = cabeza;
        nuevo->anterior = cola;
        cola->siguiente = nuevo;
        cabeza->anterior = nuevo;
    }
    size++;
}

void ListaCircular::eliminar(Transaccion *transaccion) {
    if (estaVacia()) return;

    NodeCircular* temp = cabeza;
    do {
        if (temp->transaccion == transaccion) {
            if (temp == cabeza) {
                cabeza = temp->siguiente;
            }
            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;
            delete temp;
            size--;
            return;
        }
        temp = temp->siguiente;
    } while (temp != cabeza);
}

void ListaCircular::imprimir() {
    if (estaVacia()) {
        cout << "Lista vacía." << endl;
        return;
    }

    NodeCircular* temp = cabeza;
    do {
        temp = temp->siguiente;
    } while (temp != cabeza);
    cout << endl;
}

bool ListaCircular::estaVacia() {
    return size == 0;
}

int ListaCircular::obtenerTamano() {
    return size;
}
