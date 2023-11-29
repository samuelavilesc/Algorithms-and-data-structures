#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    arbol = new ArbolTrie();
    Juanagrama = new tablaJuanagrama();
}

void diccionarioPalabras::insertarPalabra(string& palabra){
    arbol->insertar(palabra);
    Juanagrama->inserta(palabra);
}
bool diccionarioPalabras::consultarPalabra(string& palabra){
    //solo se puede hacer la busqueda en uno de ellos, dejo el arbol como podria ser cualquiera
    return arbol->consultar(palabra);
}
void diccionarioPalabras::vaciarDiccionario(){
    arbol->vaciar();
    Juanagrama->vacia();
}
int diccionarioPalabras::devolverTamano(){
    return arbol->numElem();
}
string diccionarioPalabras::alarga(string& prefijo){
    return arbol->alarga(prefijo);
}

string diccionarioPalabras::juanagra(string& palabra){
    string anagrama = Juanagrama->anagrama(palabra);
    return anagrama;
}
void diccionarioPalabras::liberarMemoria(){
    delete arbol;
    delete Juanagrama;
}
