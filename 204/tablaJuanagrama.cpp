#include "tablaJuanagrama.h"

int tablaJuanagrama::nTotal(){
    return nElem;
}

tablaJuanagrama::tablaJuanagrama (){
    nElem = 0;
}
//TODO: revisar funcion de dispersion no funciona bien con caracteres especiales
int tablaJuanagrama::hash(string palabra) {
    int id = 0;
    for(int i = 0; i<palabra.length(); i++){
        id = id + palabra[i];
    }
    if (id<0)
    {
        id = id * -1;
    }
    
    return id % TAMANO;
}

 void tablaJuanagrama::inserta (string palabra){
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

 bool tablaJuanagrama::consulta (string nombre){
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
string tablaJuanagrama::anagrama(string palabra){
    list<string>::iterator itLista= listaPalabras[hash(palabra)].begin();
    while (itLista != listaPalabras[hash(palabra)].end())
    {
        if(consulta(*itLista)){
            return *itLista;
        }
        itLista++;
    }
    return "";
}
 void tablaJuanagrama::vacia (){
    for(int i = 0; i<TAMANO; i++){
        listaPalabras[i].clear();
    }
    nElem = 0;
 }