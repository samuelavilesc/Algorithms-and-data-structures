#include "tablaJuanagrama.h"

int tablaJuanagrama::nTotal(){
    return nElem;
}

tablaJuanagrama::tablaJuanagrama (){
    nElem = 0;
}
string ordenarAlfabeticamente(string str) {
    sort(str.begin(), str.end());
    return str;
}
int tablaJuanagrama::hash(string palabra) {
    string pal=ordenarAlfabeticamente(palabra);
    unsigned long hash = 5381;
    int c;
    for (int i = 0; i < pal.length(); i++) {
        c = pal[i];
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % TAMANO;
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


string tablaJuanagrama::anagrama(string palabra){
    string palabraOrdenada= ordenarAlfabeticamente(palabra);
    int id = hash(palabra);
    string anagrama="";
    list<string>::iterator itLista= listaPalabras[id].begin();
    while (itLista != listaPalabras[id].end())
    {
        if((*itLista).length() == palabra.length()){
            string aux = ordenarAlfabeticamente(*itLista);
            if(aux==palabraOrdenada){
                if(anagrama>(*itLista) || anagrama==""){
                    anagrama = (*itLista);
                }
            }
        }
        itLista++;
}
return anagrama;
}
 void tablaJuanagrama::vacia (){
    for(int i = 0; i<TAMANO; i++){
        listaPalabras[i].clear();
    }
    nElem = 0;
 }