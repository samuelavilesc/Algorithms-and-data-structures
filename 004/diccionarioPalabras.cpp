#include "diccionarioPalabras.h"

using namespace std;
diccionarioPalabras::diccionarioPalabras(){
    this->palabras = list<string>();
}
void diccionarioPalabras::insertarPalabra(string palabra){
    string palabraNormalizada=normalizarPalabra(palabra);
    if(palabras.empty()){
    palabras.push_back(palabraNormalizada);
    return;
    }
    list<string>::iterator it = palabras.begin();

    while(it!=palabras.end()&&*it<palabraNormalizada){
        it++;
    }
    if(it==palabras.end()|| *it!= palabraNormalizada){
        palabras.insert(it,palabraNormalizada);
        return;
    }

}
bool diccionarioPalabras::consultarPalabra(string palabra){
    string palabraNormalizada=normalizarPalabra(palabra);
    list<string>::iterator it = palabras.begin();
    while(it!=palabras.end()&&*it!=palabraNormalizada){
        it++;
    }
    if(it==palabras.end()){
        return false;
    }else{
        return true;
    }
}
void diccionarioPalabras::vaciarDiccionario(){
    palabras.clear();
}
int diccionarioPalabras::devolverTamano(){
    return palabras.size();
}

