cmake_minimum_required(VERSION 3.30)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto1 main.cpp
        includes/Usuario.h
        src/Usuario.cpp
        includes/MatrizDispersa/MatrizDispersa.h
        includes/MatrizDispersa/Node.h
        src/MatrizDispersa/MatrizDispersa.cpp
        src/MatrizDispersa/Node.cpp)
