#include <iostream>

using namespace std;

#include "../includes/Usuario.h"

Usuario::Usuario(string nombre, string password) {
    this->nombre = nombre;
    this->password = password;

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

