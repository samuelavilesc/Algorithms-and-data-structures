#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
#include "TablaHash.h"
using namespace std;
class diccionarioPalabras{
private:
    TablaHash tabla;
public:
diccionarioPalabras();
void insertarPalabra(string palabra);
bool consultarPalabra(string palabra);
void vaciarDiccionario();
int devolverTamano();
};
#endif