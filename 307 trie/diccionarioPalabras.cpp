#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    // this->arbol=Arbol();/
    ArbolTrie arbol=ArbolTrie();
}

void diccionarioPalabras::insertarPalabra(const string palabra){
    arbol.insertar(normalizarPalabra(palabra));
}
bool diccionarioPalabras::consultarPalabra(const string palabra){
    return arbol.consultar(normalizarPalabra(palabra));
}
void diccionarioPalabras::vaciarDiccionario(){
    arbol.vaciar();
}
int diccionarioPalabras::devolverTamano(){
    return arbol.numElem();
}
string diccionarioPalabras::alarga(string prefijo){
    return arbol.alarga(normalizarPalabra(prefijo));
}

