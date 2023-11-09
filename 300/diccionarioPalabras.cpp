#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    this->tabla=TablaHash();
    this->arbol=Arbol();
}

void diccionarioPalabras::insertarPalabra(string palabra){
tabla.inserta(normalizarPalabra(palabra));
arbol.inserta(normalizarPalabra(palabra));
}
bool diccionarioPalabras::consultarPalabra(string palabra){
    return arbol.consultar(normalizarPalabra(palabra));
}
void diccionarioPalabras::vaciarDiccionario(){
    tabla.vacia();
    arbol.vaciar();
}
int diccionarioPalabras::devolverTamano(){
    return arbol.nElementos();
}

