#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
using namespace std;
class diccionarioPalabras{
private:
    list<string> palabras;
public:
diccionarioPalabras();
void insertarPalabra(string palabra);
bool consultarPalabra(string palabra);
void vaciarDiccionario();
int devolverTamano();
};
#endif