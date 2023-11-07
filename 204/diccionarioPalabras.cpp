#include "diccionarioPalabras.h"
using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    this->tabla=TablaHash();
    this->Juanagrama=tablaJuanagrama();
}

void diccionarioPalabras::insertarPalabra(string palabra){
tabla.inserta(normalizarPalabra(palabra));
Juanagrama.inserta(normalizarPalabra(palabra));

}
bool diccionarioPalabras::consultarPalabra(string palabra){
    return tabla.consulta(normalizarPalabra(palabra));
}
void diccionarioPalabras::vaciarDiccionario(){
    Juanagrama.vacia();
    tabla.vacia();
}
int diccionarioPalabras::devolverTamano(){
    return tabla.nTotal();
}
string diccionarioPalabras::juanagra(string palabra){
    string palabraNormalizada = normalizarPalabra(palabra);
    string anagrama = Juanagrama.anagrama(palabraNormalizada);
    if(tabla.consulta(anagrama)){
            return anagrama;
    }
    return "";
}

