#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
#include"ArbolTrie.h"
using namespace std;
class diccionarioPalabras{
private:
    ArbolTrie arbol;
public:
diccionarioPalabras();
void insertarPalabra(const string palabra);
bool consultarPalabra(const string palabra);
void vaciarDiccionario();
int devolverTamano();
string alarga(string prefijo);
};
#endif