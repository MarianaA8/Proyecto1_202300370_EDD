#include <iostream>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
private:
    string nombre;
    string password;

public:
    Usuario(string nombre, string password);
    ~Usuario();

    void setNombre(string nombre);
    void setPassword(string password);

    string getNombre();
    string getPassword();

    void agregarActivo();
    void eliminarActivo();
    void modificarActivo();
    void rentarActivo();
    void activosRentados();
    void misActivosRentados();

};



#endif //USUARIO_H
