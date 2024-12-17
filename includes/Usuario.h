#include <iostream>
#include "../includes/Arbol/AVL.h"
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
private:
    string username;
    string nombre;
    string password;

public:
    Usuario(string nombre, string password, string username);
    ~Usuario();

    AVL arbolAactivos;

    void setNombre(string nombre);
    void setPassword(string password);
    void setUsername(string username);

    string getNombre();
    string getPassword();
    string getUsername();

    void registrarActivo(Activo *activo);
    void eliminarActivo(string id);


};



#endif //USUARIO_H
