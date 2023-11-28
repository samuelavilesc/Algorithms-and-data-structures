#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
}

void diccionarioPalabras::insertarPalabra(const string palabra){
    arbol.insertar(normalizarPalabra(palabra));
    Juanagrama.inserta(normalizarPalabra(palabra));
}
bool diccionarioPalabras::consultarPalabra(const string palabra){
    return Juanagrama.consulta(normalizarPalabra(palabra)); //solo se puede hacer la busqueda en uno de ellos, dejo la tabla como podria ser cualquiera
}
void diccionarioPalabras::vaciarDiccionario(){
    arbol.vaciar();
    Juanagrama.vacia();
}
int diccionarioPalabras::devolverTamano(){
    return Juanagrama.nTotal();
}
string diccionarioPalabras::alarga(string prefijo){
    return arbol.alarga(normalizarPalabra(prefijo));
}

string diccionarioPalabras::juanagra(string palabra){
    string anagrama = Juanagrama.anagrama(palabra);
    if(anagrama.length()> 0){
        return anagrama;
    }
    return "";
}
