#include <iostream>

using namespace std;

#include "../includes/Usuario.h"

Usuario::Usuario(string nombre, string password, string username) {
    this->nombre = nombre;
    this->password = password;
    this->username = username;
}

Usuario::~Usuario() {
    delete this;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getNombre() {
    return nombre;
}


void Usuario::setPassword(string password) {
    this->password = password;
}

string Usuario::getPassword() {
    return password;
}

void Usuario::setUsername(string username) {
    this->username = username;
}

string Usuario::getUsername() {
    return username;
}

void Usuario::registrarActivo(Activo *activo) {
    arbolAactivos.insertarNodo(activo);
    cout << "Activo agregado exitosamente al usuario " << nombre << ".\n";
}


void Usuario::eliminarActivo(string id) {
    arbolAactivos.eliminarNodo(id);
    cout << "Activo eliminado exitosamente al usuario\n";
};