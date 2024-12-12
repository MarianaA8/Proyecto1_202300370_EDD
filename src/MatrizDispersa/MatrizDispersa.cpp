#include "../../includes/MatrizDispersa/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa(){

  this->cabeceraHor = nullptr;
  this->cabeceraVer = nullptr;

}

void MatrizDispersa::insertarUsuario(Usuario *usuario, string nombreCabeH, string nombreCabeV){

  if(existenCabeceras()){

    Node *cabeceraH = insertarCabeceraHor(nombreCabeH);
    Node *cabeceraV = insertarCebeceraVer(nombreCabeV);

    insertarFinal(usuario, cabeceraH, cabeceraV);

  }

}

void MatrizDispersa::insertarFinal(Usuario *usuario, Node *cabeceraHor, Node *cabeceraVer){

  Node *usuarioNuevo = new Node(usuario);

  Node *auxiliarH = cabeceraHor;
  Node *auxiliarV = cabeceraVer;

  while(auxiliarH->abajo != nullptr){
    auxiliarH = auxiliarH->abajo;
  }

  auxiliarH->abajo = usuarioNuevo;
  usuarioNuevo->arriba = auxiliarH;

  while(auxiliarV->sig != nullptr){
    auxiliarV = auxiliarV->sig;
  }

  auxiliarV->sig = usuarioNuevo;
  usuarioNuevo->ant = auxiliarV;

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

  if(cabeceraHor == nullptr){
    cabeceraHor = nuevaCabecera;
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

  if(cabeceraVer == nullptr){
    cabeceraVer = nuevaCabecera;
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





