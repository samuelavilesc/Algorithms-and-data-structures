#include "TablaHash.h"

int TablaHash::nTotal(){
    return nElem;
}

TablaHash::TablaHash (){
    nElem = 0;
}

int TablaHash::hash(string palabra) {
int suma = 0;

    for(int i = 0; i < palabra.length(); i++) {
        int codigo = palabra[i];
        suma = (suma * 37) + codigo; 
    }

	if(suma < 0){
		suma = suma * -1;
	}
    return suma % TAM;
}

 void TablaHash::inserta (string palabra){
    string k = palabra;
    int id = hash(k);

    //TODO: comprobar que no se repita
    list<string>::iterator itLista = listaPalabras[id].begin();

	while (itLista != listaPalabras[id].end() && (*itLista).compare(palabra) < 0){
		itLista++;
	}
	if((itLista == listaPalabras[id].end() || (*itLista).compare(palabra)) > 0){
		listaPalabras[id].insert(itLista, palabra); //make pair
        nElem = nElem + 1;
	} else {
		(*itLista) = palabra;
	}
 }

 bool TablaHash::consulta (string nombre){
    int id = hash(nombre);

    list<string>::iterator itLista = listaPalabras[id].begin();

	while (itLista != listaPalabras[id].end() && (*itLista).compare(nombre) < 0){
		itLista++;
	}
	if (itLista == listaPalabras[id].end() || (*itLista).compare(nombre) > 0){
		return false;
	} else {
		return true;
	}
 }

 void TablaHash::vacia (){
    for(int i = 0; i<TAM; i++){
        listaPalabras[i].clear();
    }
    nElem = 0;
 }