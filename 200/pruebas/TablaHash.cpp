#include "TablaHash.h"

int TablaHash::nTotal(){
    return nElem;
}

TablaHash::TablaHash (){
    nElem = 0;
}
int TablaHash::hash(string k){
    int e = 10;
    int suma = 0;
    int part = 0;
    
    if (k.length() % 2 == 0){
        for (int i = 0; i < k.length(); i++){
            if (i % 2){
                part += k[i];
                suma+=part;
            } else {
                part = e*k[i];
            }
        }
    } else {
        for (int i = 0; i < k.length(); i++){
            if (i % 2){
                part = e*k[i];
            } else {
                part+= k[i];
                suma+=part;
            }
        }
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

 string TablaHash::consulta (string nombre){
    int id = hash(nombre);

    list<string>::iterator itLista = listaPalabras[id].begin();

	while (itLista != listaPalabras[id].end() && (*itLista).compare(nombre) < 0){
		itLista++;
	}
	if (itLista == listaPalabras[id].end() || (*itLista).compare(nombre) > 0){
		return NULL;
	} else {
		string encontrado = (*itLista);
		return encontrado;
	}
 }

 void TablaHash::vacia (){
    for(int i = 0; i<TAM; i++){
        listaPalabras[i].clear();
    }
    nElem = 0;
 }