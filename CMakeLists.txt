cmake_minimum_required(VERSION 3.30)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto1 main.cpp
        includes/Usuario.h
        src/Usuario.cpp
        includes/MatrizDispersa/MatrizDispersa.h
        includes/MatrizDispersa/Node.h
        src/MatrizDispersa/MatrizDispersa.cpp
        src/MatrizDispersa/Node.cpp
        includes/Activo.h
        src/Activo.cpp
        includes/Arbol/NodeAVL.h
        src/Arbol/NodeAVL.cpp
        includes/Arbol/AVL.h
        src/Arbol/AVL.cpp
        includes/Transaccion.h
        src/Transaccion.cpp
        "includes/Lista Circular/NodeCircular.h"
        "src/Lista Circular/NodeCircular.cpp"
        "src/Lista Circular/ListaCircular.cpp"
        "includes/Lista Circular/ListaCircular.h"
)
