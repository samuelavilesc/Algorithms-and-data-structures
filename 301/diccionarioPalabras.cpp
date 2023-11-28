#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    this->tabla=TablaHash();
    this->arbol=Arbol();
    this->arbolPartidas=ArbolPartidas();
}

void diccionarioPalabras::insertarPalabra(string palabra){
tabla.inserta(normalizarPalabra(palabra));
arbol.inserta(normalizarPalabra(palabra));
arbolPartidas.inserta(normalizarPalabra(palabra));
}
bool diccionarioPalabras::consultarPalabra(string palabra){
    return arbol.consultar(normalizarPalabra(palabra));
}
void diccionarioPalabras::vaciarDiccionario(){
    tabla.vacia();
    arbol.vaciar();
    arbolPartidas.vaciar();
}
int diccionarioPalabras::devolverTamano(){
    return arbol.nElementos();
}
string diccionarioPalabras::partidas(string palabra){
    return arbolPartidas.partidas(normalizarPalabra(palabra));
}

