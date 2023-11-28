#include "tablaJuanagrama.h"

int tablaJuanagrama::nTotal(){
    return nElem;
}

tablaJuanagrama::tablaJuanagrama (){
    nElem = 0;
}
int tablaJuanagrama::hash(string palabra) {
    int id = 0;
    for(int i = 0; i<palabra.length(); i++){
        id = id + (palabra[i]*67);
    }
    if (id<0)
    {
        id = id * (-1);
    }
    
    return id % TAMANO;
}

 void tablaJuanagrama::inserta (string palabra){
    string k = palabra;
    int id = hash(k);


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

string ordenarAlfabeticamente(string str) {
    sort(str.begin(), str.end());
    return str;
}
string tablaJuanagrama::anagrama(string palabra){
    int id=hash(palabra);
    list<string>::iterator itLista= listaPalabras[id].begin();
    while (itLista != listaPalabras[id].end())
    {
        string palabraOrdenada = ordenarAlfabeticamente(*itLista);
        string palabraOrdenada2 = ordenarAlfabeticamente(palabra);
        if(palabraOrdenada.compare(palabraOrdenada2) == 0){
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