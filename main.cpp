#include <iostream>
#include <string>
#include <random>
#include <limits>
#include <bits/atomic_wait.h>

#include "includes/MatrizDispersa/MatrizDispersa.h"
#include "includes/Arbol/AVL.h"
#include "includes/Activo.h"
#include "includes/Usuario.h"

using namespace std;

MatrizDispersa *matriz = nullptr;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menuPrincipal() {
    int option = 0;
    do {
        cout << "-------------Bienvenido a Renta de Activos-----------\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, intente de nuevo.\n";
            limpiarEntrada();
            option = 0;
        }
    } while (option < 1 || option > 2);

    return option;
}

int menuAdministrador() {
    int option = 0;
    do {
        cout << "-------------Bienvenido Administrador-----------\n";
        cout << "1. Registro de Usuario\n";
        cout << "2. Reporte Matriz Dispersa\n";
        cout << "3. Reporte Activos Disponibles de un Departamento\n";
        cout << "4. Reporte Activos Disponibles de una Empresa\n";
        cout << "5. Reporte de Transacciones\n";
        cout << "6. Reporte de Activos de un Usuario\n";
        cout << "7. Activos Rentados por un Usuario\n";
        cout << "8. Ordenar Transacciones\n";
        cout << "9. Salir al Menu Principal\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, intente de nuevo.\n";
            limpiarEntrada();
            option = 0;
        }
    } while (option < 1 || option > 9);

    return option;
}

int menuUsuario(Node *usuario) {
    int option = 0;
    do {
        cout << "--------------Bienvenido Usuario " << usuario->usuario->getNombre() << "------------\n";
        cout << "1. Agregar un Activo\n";
        cout << "2. Eliminar Activo\n";
        cout << "3. Modificar Activo\n";
        cout << "4. Rentar Activo\n";
        cout << "5. Activos Rentados\n";
        cout << "6. Mis Activos Rentados\n";
        cout << "7. Cerrar Sesion\n";
        cout << "Ingrese una opcion: ";
        cin >> option;

        if (cin.fail()) {
            cout << "Entrada inválida. Por favor, intente de nuevo.\n";
            limpiarEntrada();
            option = 0;
        }
    } while (option < 1 || option > 7);

    return option;
}

std::string generarIDUsuario() {
    const int longitud = 15;
    const std::string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<> distribucion(0, caracteres.size() - 1);

    std::string id;
    for (int i = 0; i < longitud; ++i) {
        id += caracteres[distribucion(generador)];
    }
    return id;
}

void RegistrarUsuario() {
    if (matriz == nullptr) {
        cout << "Error: La matriz dispersa no está inicializada.\n";
        return;
    }

    string nombre, password, Departamento, Empresa, username;
    cout << "-------------------Registrar Usuario----------------" << endl;
    cout << "Ingresa tu nombre: ";
    cin >> nombre;
    cout << "Ingresa tu username: ";
    cin >> username;
    cout << "Ingresa tu contrasena: ";
    cin >> password;
    cout << "Ingresa tu Departamento: ";
    cin >> Departamento;
    cout << "Ingresa tu Empresa: ";
    cin >> Empresa;

    if (matriz->existeElUsuario(username, Departamento, Empresa)) {
        cout << "Este usuario ya esta registrado" << endl;
    } else {
        Usuario *usuario1 = new Usuario(nombre, password, username);
        matriz->insertarUsuario(usuario1, Departamento, Empresa);
        cout << "Usuario Registrado Exitosamente" << endl;
    }
}

void registrarActivo(Node *usuario) {
    string id, descripcion, nombre;

    cout << "ID del Activo" << endl;
    id = generarIDUsuario();
    cout << id << endl;
    cout << "Descripcion de Activo" << endl;
    cin >> descripcion;
    cout << "Nombre del Activo" << endl;
    cin >> nombre;


    Activo *activoNuevo = new Activo(id, descripcion, nombre);
    usuario->usuario->registrarActivo(activoNuevo);
}

void eliminarActivo(Node *usuario) {
    cout << "-------------------Eliminar Activo--------------------" << endl;

    cout << "Activos en el arbol de " << usuario->usuario->getNombre() << endl;
    usuario->usuario->arbolAactivos.obtenerNodos();
    cout << "--------------------------------------------------" << endl;

    string id;

    cout << "Ingresa el ID del activo a eliminar" << endl;
    cin >> id;

    usuario->usuario->eliminarActivo(id);
}

void modificarActivo(Node *usuario) {
    cout << "---------------Modificar Activo----------------" << endl;

    cout << "Activos en el arbol de " << usuario->usuario->getNombre() << endl;
    usuario->usuario->arbolAactivos.obtenerNodos();
    cout << "--------------------------------------------------" << endl;

    string id, descripcionNueva;

    cout << "Ingresa el ID del Activo que desas modificar:" << endl;
    cin >> id;
    cout << "Ingresa la nueva descripción:" << endl;
    cin >> descripcionNueva;

    usuario->usuario->arbolAactivos.modificarDescripcion(id, descripcionNueva);
}

void mostrarArbol() {
    cout << "-------------Resporte Activos de un Usuario----------" << endl;
    string username;
    cout << "Ingrese el username del usuario del cual desea ver el arbol AVL: " << endl;
    cin >> username;


    auto usuarioEncontrado = matriz->buscarUsuario(username);
    if (usuarioEncontrado != nullptr) {
        cout << "Usuario encontrado" << endl;
        usuarioEncontrado->usuario->arbolAactivos.exportarGrafo("arbol");
    } else {
        cout << "Usuario no encontrado :(" << endl;
    }
}

void rentarUnActivo() {
    cout << "-------------Rentar Activos-----------" << endl;
}


void inicioSesion() {
    string id, password;
    cout << "Ingrese su nombre: ";
    cin >> id;
    cout << "Ingrese su contrasena: ";
    cin >> password;

    if (id == "1" && password == "Admin") {
        int option = 0;
        while ((option = menuAdministrador()) != 9) {
            switch (option) {
                case 1:
                    RegistrarUsuario();
                    break;
                case 2:
                    matriz->generarGraficoMatriz();
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    mostrarArbol();
                    break;
                default:
                    cout << "Opción aún no implementada.\n";
            }
        }
    } else if (matriz->validarCredenciales(id, password)) {
        auto usuarioEncontrado = matriz->buscarUsuario(id);
        if (usuarioEncontrado != nullptr) {
            int option = 0;
            while ((option = menuUsuario(usuarioEncontrado)) != 7) {
                switch (option) {
                    case 1:
                        registrarActivo(usuarioEncontrado);
                        break;
                    case 2:
                        eliminarActivo(usuarioEncontrado);
                        break;
                    case 3:
                        modificarActivo(usuarioEncontrado);
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Opción no válida.\n";
                }
            }
        } else {
            cout << "Error: Usuario no encontrado.\n";
        }
    } else {
        cout << "Credenciales Erroneas o el usuario no existe\n";
    }
}


int main() {
    matriz = new MatrizDispersa();

    Usuario *user1 = new Usuario("Elian Estrada", "1234", "elian_estrada");
    Usuario *user2 = new Usuario("Juan Perez", "4567", "juanito");
    Usuario *user3 = new Usuario("Pedro Rodriguez", "48956", "pedrito");
    Usuario *user4 = new Usuario("Maria Fernanda", "54321", "mafer");
    Usuario *user5 = new Usuario("Juan Manuel", "32897", "juanma");
    Usuario *user6 = new Usuario("Carlos Perez", "721896", "casimiro");
    Usuario *user7 = new Usuario("Fernando Mendez", "891346", "fuego03");
   // Usuario *user8 = new Usuario("Alejandra Guzman", "780145", "Alcachofa");
    //Usuario *user9 = new Usuario("Iraldo MArtinez", "201598", "incrediboy");
    Usuario *user10 = new Usuario("Antonio Lopez", "20435", "alcachofa");

    matriz->insertarUsuario(user1, "guatemala", "iggs");
    matriz->insertarUsuario(user2, "jutiapa", "max");
    matriz->insertarUsuario(user3, "jalapa", "usac");
    matriz->insertarUsuario(user4, "peten", "cinepolis");
    matriz->insertarUsuario(user5, "guatemala", "usac");
    matriz->insertarUsuario(user6, "guatemala", "max");
    matriz->insertarUsuario(user7, "jutiapa", "cinepolis");
  //  matriz->insertarUsuario(user8, "jutiapa", "usac");
  //  matriz->insertarUsuario(user9, "jutiapa", "max");
    matriz->insertarUsuario(user10, "jutiapa", "usac");


    Activo *activo1 = new Activo(generarIDUsuario(), "Madera para albañil", "madera");
    Activo *activo2 = new Activo(generarIDUsuario(), "Martillos para madera", "martillos");
    Activo *activo3 = new Activo(generarIDUsuario(), "Caladora para cortar maderas prefabricadas", "caladora");
    Activo *activo4 = new Activo(generarIDUsuario(), "Barreno para concreto", "barreno");
    Activo *activo5 = new Activo(generarIDUsuario(), "Balanza con máximo de 25kg", "balanza");
    Activo *activo6 = new Activo(generarIDUsuario(), "Canastas para frutas y verduras", "canastas");
    Activo *activo7 = new Activo(generarIDUsuario(), "Linternas para alumbrar cuartos oscuros", "linternas");
    Activo *activo8 = new Activo(generarIDUsuario(), "Cargadores de teléfonos tipo C", "cargadores");
    Activo *activo9 = new Activo(generarIDUsuario(), "Cables de todo tipo", "cables");
    Activo *activo10 = new Activo(generarIDUsuario(), "Lazos para tender ropa", "lazos");
    Activo *activo11 = new Activo(generarIDUsuario(), "Pequeños termos para bebidas calientes", "termos");
    Activo *activo12 = new Activo(generarIDUsuario(), "Maletas desde pequeñas a grandes", "maletas");
    Activo *activo13 = new Activo(generarIDUsuario(), "Todo tipo de películas de acción", "peliculas");
    Activo *activo14 = new Activo(generarIDUsuario(), "Cassettes con música de todo tipo", "casets");
    Activo *activo15 = new Activo(generarIDUsuario(), "Pantallas para proyección", "pantallas");
    Activo *activo16 = new Activo(generarIDUsuario(), "Cañonera para proyección", "cañonera");
    Activo *activo17 = new Activo(generarIDUsuario(), "Toldo para eventos al exterior", "toldo");
    Activo *activo18 = new Activo(generarIDUsuario(), "Audífonos para grabaciones de estudio", "audifonos");
    Activo *activo19 = new Activo(generarIDUsuario(), "Micrófonos de todo tipo", "microfonos");
    Activo *activo20 = new Activo(generarIDUsuario(), "Pedestales para micrófonos grandes y pequeños", "pedestales");
    Activo *activo21 = new Activo(generarIDUsuario(), "Atriles para colocar hojas con gancho", "atriles");

    user1->registrarActivo(activo1);
    user1->registrarActivo(activo2);
    user1->registrarActivo(activo3);
    user1->registrarActivo(activo4);
    user6->registrarActivo(activo5);
    user6->registrarActivo(activo6);
    user6->registrarActivo(activo7);
    user6->registrarActivo(activo8);
    user6->registrarActivo(activo9);
    user6->registrarActivo(activo10);
    user7->registrarActivo(activo11);
    user7->registrarActivo(activo12);
    user7->registrarActivo(activo13);
  //  user9->registrarActivo(activo14);
  //  user9->registrarActivo(activo15);
//user9->registrarActivo(activo16);
//user9->registrarActivo(activo17);
    user4->registrarActivo(activo18);
    user4->registrarActivo(activo19);
    user4->registrarActivo(activo20);
    user4->registrarActivo(activo21);


    int option = 0;
    while ((option = menuPrincipal()) != 2) {
        switch (option) {
            case 1:
                inicioSesion();
                break;
            case 2:
                cout << "Saliendo... ¡Hasta luego!\n";
                break;
        }
    }

    delete matriz;
    return 0;
}
