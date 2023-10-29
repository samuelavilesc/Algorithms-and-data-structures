#include "diccionarioPalabras.h"

using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    this->tabla=TablaHash();
}
void diccionarioPalabras::insertarPalabra(string palabra){
tabla.inserta(normalizarPalabra(palabra));
}
bool diccionarioPalabras::consultarPalabra(string palabra){
    return tabla.consulta(normalizarPalabra(palabra));
}
void diccionarioPalabras::vaciarDiccionario(){
    tabla.vacia();
}
int diccionarioPalabras::devolverTamano(){
    return tabla.nTotal();
}

