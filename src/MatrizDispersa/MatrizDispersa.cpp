#include "../../includes/MatrizDispersa/MatrizDispersa.h"
#include <fstream>

MatrizDispersa::MatrizDispersa(){

  this->cabeceraHor = nullptr;
  this->cabeceraVer = nullptr;

}

void MatrizDispersa::insertarUsuario(Usuario *usuario, string nombreCabeH, string nombreCabeV){

  Node *cabeceraHor = nullptr;
  Node *cabeceraVer = nullptr;

  Node *usuarioNuevo = new Node(usuario);


  if(existenCabeceras())

    Node *cabeceraH = insertarCabeceraHor(nombreCabeH);
    Node *cabeceraV = insertarCebeceraVer(nombreCabeV);

    insertarFinal(usuarioNuevo, cabeceraH, cabeceraV);

    return;

  }


  cabeceraHor = cabeceraHorizontal(nombreCabeH);
  cabeceraVer = cabeceraVertical(nombreCabeV);

  if (cabeceraHor == nullptr && cabeceraVer == nullptr) {

    cabeceraHor = insertarCabeceraHor(nombreCabeH);
    cabeceraVer = insertarCebeceraVer(nombreCabeV);

    insertarFinal(usuarioNuevo, cabeceraHor, cabeceraVer);

    return;

  }

  if (cabeceraHor != nullptr && cabeceraVer != nullptr) {
    insertarHaciaAtras(usuarioNuevo, nombreCabeH, nombreCabeV);
    return;
  }

  if (cabeceraHor == nullptr) {

    cabeceraHor = insertarCabeceraHor(nombreCabeH);

    insertarFinal(usuarioNuevo, cabeceraHor, cabeceraVer);
    return;
  }

  if (cabeceraVer == nullptr) {

    cabeceraVer = insertarCebeceraVer(nombreCabeV);

    insertarFinal(usuarioNuevo, cabeceraVer, cabeceraHor);

    return;
  }

  Node *auxiliarHor = cabeceraHor->abajo;
  Node *usuarioCabeVer;
  bool bajando;

  while (auxiliarHor !=nullptr) {
    usuarioCabeVer = estaCabceraVer(auxiliarHor);

    bajando = seguirAbajo(usuarioCabeVer, nombreCabeH);

    if (!bajando) break;

    auxiliarHor = auxiliarHor->abajo;
  }

  if (bajando) {
    insertarFinalDeH(usuarioNuevo, cabeceraHor);
  }else {
    insertarMedioHor(usuarioNuevo, auxiliarHor);
  }

  Node *auxiliarVer = cabeceraVer->sig;
  Node *usuarioCabeH;
  bool siguiendo = false;

  while (auxiliarVer != nullptr) {
    usuarioCabeH = estaCabceraHor(auxiliarVer);

    siguiendo = seguirDerecha(usuarioCabeH, nombreCabeV);

    if (!siguiendo) break;

    auxiliarVer = auxiliarVer->sig;
  }

  if (siguiendo) {
    insertarFinalDeV(usuarioNuevo, cabeceraVer);
  }else {
    insertarMedioVer(usuarioNuevo, auxiliarVer);
  }




}

void MatrizDispersa::insertarFinal(Node *usuario, Node *cabeceraHor, Node *cabeceraVer){

  insertarFinalDeH(usuario, cabeceraHor);

  insertarFinalDeV(usuario, cabeceraVer);

}



bool MatrizDispersa::existenCabeceras(){
  return this->cabeceraHor == nullptr;
}


Node *MatrizDispersa::cabeceraHorizontal (string nombreCabeH) {

  	if (existenCabeceras()) {
		  return nullptr;
          }

	Node *auxiliar = cabeceraHor;

    while(auxiliar != nullptr) {
		if(auxiliar->nombreCabecera == nombreCabeH){
			return auxiliar;
    	}
        auxiliar = auxiliar->sig;
    }

    return nullptr;

}

Node *MatrizDispersa::insertarCabeceraHor(string valorCabeH){

  Node *nuevaCabecera = new Node(valorCabeH);

  if(this->cabeceraHor == nullptr){
    this->cabeceraHor = nuevaCabecera;
    return nuevaCabecera;
  }

  Node *auxiliar = cabeceraHor;

  while (auxiliar->sig != nullptr) {
    auxiliar = auxiliar->sig;
  }

  auxiliar->sig = nuevaCabecera;
  nuevaCabecera->ant = auxiliar;

  return nuevaCabecera;
}


Node *MatrizDispersa::insertarCebeceraVer(string valorCabeV){

  Node *nuevaCabecera = new Node(valorCabeV);

  if(this->cabeceraVer == nullptr){
    this->cabeceraVer = nuevaCabecera;
    return nuevaCabecera;
  }

  Node *auxiliar = cabeceraVer;

  while (auxiliar->abajo != nullptr) {
    auxiliar = auxiliar->abajo;
  }

  auxiliar->abajo = nuevaCabecera;
  nuevaCabecera->arriba = auxiliar;

  return nuevaCabecera;
}


Node *MatrizDispersa::cabeceraVertical (string nombreCabeV) {

  	if (existenCabeceras()) {
		  return nullptr;
    }

	Node *auxiliar = cabeceraVer;

    while(auxiliar != nullptr) {
		if(auxiliar->nombreCabecera == nombreCabeV){
			return auxiliar;
    	}
        auxiliar = auxiliar->abajo;
    }

    return nullptr;

}

void MatrizDispersa::insertarFinalDeH(Node *usuario, Node *cabeceraHor) {

  Node *auxiliar = cabeceraHor;


  while(auxiliar->abajo != nullptr){
    auxiliar = auxiliar->abajo;
  }

  auxiliar->abajo = usuario;
  usuario->arriba = auxiliar;

}

void MatrizDispersa::insertarFinalDeV(Node *usuario, Node *cabeceraVer) {

  Node *auxiliar = cabeceraVer;

  while(auxiliar->sig != nullptr){
    auxiliar = auxiliar->sig;
  }

  auxiliar->sig = usuario;
  usuario->ant = auxiliar;


}


Node *MatrizDispersa::estaCabceraHor(Node *node) {

  Node *auxiliar = node;

  while (auxiliar->arriba != nullptr) {

    auxiliar = auxiliar->arriba;

  }

  return auxiliar;

}

Node *MatrizDispersa::estaCabceraVer(Node *node) {

  Node *auxiliar = node;

  while (auxiliar->ant != nullptr) {

    auxiliar = auxiliar->ant;
  }

  return auxiliar;

}

bool MatrizDispersa::seguirDerecha(Node *cabeceraHor, string cabeH) {

  Node *auxiliar = cabeceraHor;

  while (auxiliar != nullptr) {
    if (auxiliar->nombreCabecera == cabeH) return true;



    auxiliar = auxiliar->sig;
  }

  return false;

}


bool MatrizDispersa::seguirAbajo(Node *cabeceraVer, string cabeV) {

  Node *auxiliar = cabeceraVer;

  while (auxiliar != nullptr) {
    if (auxiliar->nombreCabecera == cabeV) return true;

    auxiliar = auxiliar->abajo;
  }

  return false;

}

void MatrizDispersa::insertarMedioVer(Node *usuario, Node *vertical) {

  vertical->ant->sig = usuario;
  usuario->sig = vertical;
  usuario->ant = vertical->ant;
  vertical->ant = usuario;

}

void MatrizDispersa::insertarMedioHor(Node *usuario, Node *horizontal) {

  horizontal->arriba->abajo = usuario;
  usuario->abajo = horizontal;
  usuario->arriba = horizontal->arriba;
  horizontal->arriba = usuario;

}

Node* MatrizDispersa::busquedad(string nombreCabeH, string nombreCabeV) {

  Node* cabeceraH = cabeceraHorizontal(nombreCabeH);
  Node* cabeceraV = cabeceraVertical(nombreCabeV);

  Node* actual = cabeceraH->abajo;
  while (actual != nullptr) {

    Node* auxiliar = actual;
    while (auxiliar != nullptr) {
      if (auxiliar == cabeceraV) {
        return actual;
      }
      auxiliar = auxiliar->ant;
    }
    actual = actual->abajo;
  }

  return nullptr;
}



void MatrizDispersa::insertarHaciaAtras(Node *usuario, string nombreCabeH, string nombreCabeV) {

  Node* nodoExistente = busquedad(nombreCabeH, nombreCabeV);

  if (!nodoExistente) {
    std::cerr << "Error: No hay nodo en la intersección de las cabeceras." << std::endl;
    return;
  }

  usuario->adelante = nodoExistente;
  usuario->atras = nodoExistente->atras;

  if (nodoExistente->atras != nullptr) {
    nodoExistente->atras->adelante = usuario;
  }

  nodoExistente->atras = usuario;
}


bool MatrizDispersa::existeElUsuario(string nombre, string nombreCabeH, string nombreCabeV) {

  Node* cabeceraH = cabeceraHorizontal(nombreCabeH);
  Node* cabeceraV = cabeceraVertical(nombreCabeV);

  if (cabeceraH == nullptr || cabeceraV == nullptr) {
    return false;
  }

  Node* NodoCreado = busquedad(nombreCabeH, nombreCabeV);

  if (NodoCreado == nullptr) return false;

  if (NodoCreado) {
    if (existe( nombre)) {
      return true;
    }
    return false;
  }
}

bool MatrizDispersa::validarCredenciales(string username, string contraseña) {

  Node* tempH = cabeceraHor;


  while (tempH != nullptr) {
    Node* tempV = tempH->abajo;


    while (tempV != nullptr) {
      Node* tempProfundidad = tempV;


      while (tempProfundidad != nullptr) {
        if (tempProfundidad->usuario != nullptr) {

          if (tempProfundidad->usuario->getUsername() == username &&
              tempProfundidad->usuario->getPassword() == contraseña) {
            return true;
              }
        }
        tempProfundidad = tempProfundidad->atras;
      }

      tempV = tempV->sig;
    }
    tempH = tempH->sig;
  }

  return false;
}


bool MatrizDispersa::existe(string nombre) {
  Node* auxiliarHorizontal = cabeceraHor;

  while (auxiliarHorizontal != nullptr) {
    Node* auxiliarVertical = auxiliarHorizontal->abajo;

    while (auxiliarVertical != nullptr) {
      Node* auxiliarProfun = auxiliarVertical;

      while (auxiliarProfun != nullptr) {
        if (auxiliarProfun->usuario != nullptr) {
          if (auxiliarProfun->usuario->getUsername() == nombre) {
            return true;
          }
        }
        auxiliarProfun = auxiliarProfun->atras;
      }

      auxiliarHorizontal = auxiliarVertical->sig;
    }
    auxiliarHorizontal = auxiliarHorizontal->sig;
  }

  return false;
}

void MatrizDispersa::generarGraficoMatriz() {
    std::ofstream file("matriz_disperza.dot");

    // Inicia el gráfico
    file << "digraph G {" << std::endl;
    file << "rankdir=LR;" << std::endl; // Establecer la dirección de los nodos (de izquierda a derecha)
    file << "node [shape=rect, style=filled, fillcolor=lightyellow];" << std::endl; // Estilo para los usuarios

    // Crear los nodos de las cabeceras horizontales (usando rectángulos)
    Node* cabeceraHorAux = cabeceraHor;
    while (cabeceraHorAux != nullptr) {
        file << "\"" << cabeceraHorAux->nombreCabecera << "\" [shape=rect, style=filled, fillcolor=lightblue];" << std::endl;
        cabeceraHorAux = cabeceraHorAux->sig;
    }

    // Crear los nodos de las cabeceras verticales (usando rectángulos)
    Node* cabeceraVerAux = cabeceraVer;
    while (cabeceraVerAux != nullptr) {
        file << "\"" << cabeceraVerAux->nombreCabecera << "\" [shape=rect, style=filled, fillcolor=lightgreen];" << std::endl;
        cabeceraVerAux = cabeceraVerAux->abajo;
    }

    // Crear los nodos de los usuarios y sus conexiones
    cabeceraHorAux = cabeceraHor;
    while (cabeceraHorAux != nullptr) {
        Node* cabeceraVerAux = cabeceraVer;
        while (cabeceraVerAux != nullptr) {
            // Recorremos las intersecciones de las cabeceras para verificar si hay un nodo de usuario
            Node* usuarioAux = cabeceraHorAux->abajo;
            while (usuarioAux != nullptr) {
                if (usuarioAux->arriba == cabeceraVerAux) {
                    // Nodo de usuario encontrado en la intersección
                    file << "\"" << usuarioAux->usuario->getNombre() << "\" [shape=rect, style=filled, fillcolor=lightyellow];" << std::endl;

                    // Conectar cabecera horizontal a usuario (usamos una flecha hacia el usuario)
                    file << "\"" << cabeceraHorAux->nombreCabecera << "\" -> \"" << usuarioAux->usuario->getNombre() << "\" [label=\"\"];" << std::endl;

                    // Conectar cabecera vertical a usuario (usamos una flecha hacia el usuario)
                    file << "\"" << cabeceraVerAux->nombreCabecera << "\" -> \"" << usuarioAux->usuario->getNombre() << "\" [label=\"\"];" << std::endl;

                    // Mostrar las conexiones entre los usuarios (punteros)
                    // Conectar el usuario hacia su "adelante" (derecha)
                    if (usuarioAux->adelante != nullptr) {
                        file << "\"" << usuarioAux->usuario->getNombre() << "\" -> \"" << usuarioAux->adelante->usuario->getNombre() << "\" [label=\"adelante\"];" << std::endl;
                    }
                    // Conectar el usuario hacia su "atras" (izquierda)
                    if (usuarioAux->atras != nullptr) {
                        file << "\"" << usuarioAux->usuario->getNombre() << "\" -> \"" << usuarioAux->atras->usuario->getNombre() << "\" [label=\"atras\"];" << std::endl;
                    }
                    // Conectar el usuario hacia su "arriba"
                    if (usuarioAux->arriba != nullptr) {
                        file << "\"" << usuarioAux->usuario->getNombre() << "\" -> \"" << usuarioAux->arriba->usuario->getNombre() << "\" [label=\"arriba\"];" << std::endl;
                    }
                    // Conectar el usuario hacia su "abajo"
                    if (usuarioAux->abajo != nullptr) {
                        file << "\"" << usuarioAux->usuario->getNombre() << "\" -> \"" << usuarioAux->abajo->usuario->getNombre() << "\" [label=\"abajo\"];" << std::endl;
                    }
                }
                usuarioAux = usuarioAux->abajo;
            }
            cabeceraVerAux = cabeceraVerAux->abajo;
        }
        cabeceraHorAux = cabeceraHorAux->sig;
    }

    // Cerrar el gráfico
    file << "}" << std::endl;
    file.close();

    std::cout << "El archivo DOT ha sido generado. Ahora generando la imagen..." << std::endl;

    // Ejecutar el comando de Graphviz para generar la imagen PNG
    string comando = "dot -Tpng matriz_disperza.dot -o matriz_disperza.png";
    int resultado = system(comando.c_str());

    if (resultado == 0) {
        std::cout << "La imagen ha sido generada exitosamente: matriz_disperza.png" << std::endl;
    } else {
        std::cout << "Error al generar la imagen con Graphviz." << std::endl;
    }
}

Node* MatrizDispersa::buscarUsuario(string nombreUsuario) {
  if (this->cabeceraHor == nullptr) {
    return nullptr;
  }

  Node* cabeceraHorizontalActual = this->cabeceraHor;

  while (cabeceraHorizontalActual != nullptr) {
    Node* nodoActual = cabeceraHorizontalActual->abajo;

    while (nodoActual != nullptr) {
      Node* nodoProfun = nodoActual;

      while (nodoProfun != nullptr) {
        if (nodoProfun->usuario != nullptr) {

          if (nodoProfun->usuario->getUsername() == nombreUsuario) {
            return nodoProfun;
              }
        }
        nodoProfun = nodoProfun->atras;
      }
      nodoActual = nodoActual->abajo;
    }
    cabeceraHorizontalActual = cabeceraHorizontalActual->sig;
  }

  return nullptr;
}
