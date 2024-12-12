#include <iostream>
#include <string>
#include <random>

#include "includes/MatrizDispersa/MatrizDispersa.h"

using namespace std;

int menuPricipal() {

    cout << "-------------Bienvenido a Renta de Activos-----------\n";
    cout << "1. Iniciar Sesion\n";
    cout << "2. Registrarse\n";
    cout << "3. Salir" << endl;
    int option;
    cout << "Ingrese una opcion: " << endl;
    cin >> option;
    return option;

}

int menuAdministrador() {

    cout << "-------------Bienvenido Administrador-----------\n";
    cout << "¿Que deseas hacer hoy?" << endl;
    cout << "1. Regsitro de Usuario\n";
    cout << "2. Reporte Matriz Dispersa\n";
    cout << "3. Reporte Activos Disponibles de un Departamento" << endl;
    cout << "4. Reporte Activos Disponibles de una Empresa" << endl;
    cout << "5. Reporte de Transacciones" << endl;
    cout << "6. Reporte de Activos de un Usuario" << endl;
    cout << "7. Activos Rentados por un Usuario" << endl;
    cout << "8. Ordenar Transacciones" << endl;
    cout << "9. Salir al Menu Principal" << endl;
    int option;
    cout << "Ingrese una opcion: " << endl;
    cin >> option;
    return option;

}

int menuUsuario() {
    //Deberiamos pedir como parámetro el objeto usuario si lo encontro para iniciar sesion y asi utilizar el objeto que es.
    cout << "--------------Bievenido Usuario " << "xxxx" << "------------" << endl;
    cout << "Que deseas hacer hoy?\n";
    cout << "1. Agregar un Activo" << endl;
    cout << "2. Eliminar Activo" << endl;
    cout << "3. Modificar Activo" << endl;
    cout << "4. Rentar Activo" << endl;
    cout << "5. Activos Rentados" << endl;
    cout << "6. Mis Activos Rentados" << endl;
    cout << "7. Cerrar Sesion" << endl;
    int option;
    cout << "Ingrese una opcion: " << endl;
    cin >> option;
    return option;

}


std::string generarIDUsuario() {
    const int longitud = 15; // Longitud fija del ID
    const std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd; // Fuente de números aleatorios
    std::mt19937 generador(rd()); // Motor de generación de números
    std::uniform_int_distribution<> distribucion(0, caracteres.size() - 1); // Rango de índices

    std::string id;
    for (int i = 0; i < longitud; ++i) {
        id += caracteres[distribucion(generador)];
    }
    return id;
}

void RegistrarUsuario() {
    string nombre;
    string password;
    string Departamento;
    string Empresa;

    cout << "Ingresa tu nombre: " << endl;
    cin >> nombre;
    cout << "Ingresa tu contrasena: " << endl;
    cin >> password;
    cout << "Ingresa tu Departamento: " << endl;
    cin >> Departamento;
    cout << "Ingresa tu Empresa: " << endl;
    cin >> Empresa;

}


void inicioSesion() {
    string id;
    string password;

    cout << "Ingrese su ID: " << endl;
    cin >> id;
    cout << "Ingrese su contrasena: " << endl;
    cin >> password;

    if (id == "1" && password == "Admin") {
        int option = 0;
        while (option != 9) {
            option = menuAdministrador();
            switch (option) {
                case 1:
                    RegistrarUsuario();
                break;
                case 2:
                    cout << "Opción 2: Reporte Matriz Dispersa\n";
                break;
                case 3:
                    cout << "Opción 3: Reporte Activos Disponibles de un Departamento\n";
                break;
                case 4:
                    cout << "Opción 4: Reporte Activos Disponibles de una Empresa\n";
                break;
                case 5:
                    cout << "Opción 5: Reporte de Transacciones\n";
                break;
                case 6:
                    cout << "Opción 6: Reporte de Activos de un Usuario\n";
                break;
                case 7:
                    cout << "Opción 7: Activos Rentados por un Usuario\n";
                break;
                case 8:
                    cout << "Opción 8: Ordenar Transacciones\n";
                break;
                case 9:
                    cout << "Saliendo al Menu Principal...\n";
                break;
                default:
                    cout << "Opcion no valida. Intente de nuevo.\n";
            }
        }
    }else {
        cout << "Credenciales Incorrectas\n";
    }


    //Aqui faltarian hacer verificaciones dependiendo de la lista de usuarios, pero aun no tenemos la matriz dispersa
    int option = 0;
    while (option != 7) {
        option = menuUsuario();
        switch (option) {
            case 1:
                cout << "Opcion 1: Agregar Activo\n";
            break;
            case 2:
                cout << "Opcion 2: Eliminar Activo\n";
            break;
            case 3:
                cout << "Opcion 3: Modificar Activo\n";
            break;
            case 4:
                cout << "Opcion 4: Rentar Activo\n";
            break;
            case 5:
                cout << "Opcion 5: Activos Rentados\n";
            break;
            case 6:
                cout << "Opcion 6: Mis Activos Rentados\n";
            break;
            case 7:
                cout << "Opcion 7: Cerrar Sesion\n";
            break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }


    }
}



int main() {

  /*  int option = 0;

    while (option != 3) {
        option = menuPricipal();
        switch (option) {
            case 1:
                inicioSesion();
                break;
            case 2:
                RegistrarUsuario();
                cout << "Usuario Registrado Exitosamente\n";
                break;
            case 3:
                break;
            default:
                cout << "Opcion no valida!\n";

        }
    }*/

    MatrizDispersa *matriz = new MatrizDispersa();
    Usuario* usuario1 = new Usuario("Juan", "1234");

    matriz->insertarUsuario(usuario1, "Columna1", "Fila1");

    cout << "Hola Mundo" << endl;

    return 0;
}

