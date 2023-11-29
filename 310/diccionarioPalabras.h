#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
#include"ArbolTrie.h"
#include "tablaJuanagrama.h"
using namespace std;
class diccionarioPalabras{
private:
    tablaJuanagrama* Juanagrama;
    ArbolTrie* arbol;
public:
diccionarioPalabras();
void insertarPalabra(string& palabra);
bool consultarPalabra(string& palabra);
void vaciarDiccionario();
int devolverTamano();
string alarga(string& prefijo);
string juanagra(string& palabra);
void liberarMemoria();
};
#endif