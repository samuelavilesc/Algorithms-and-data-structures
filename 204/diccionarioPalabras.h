#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
#include "TablaHash.h"
#include "tablaJuanagrama.h"
using namespace std;
class diccionarioPalabras{
private:
    TablaHash tabla;
    tablaJuanagrama Juanagrama;
public:
diccionarioPalabras();
void insertarPalabra(string palabra);
bool consultarPalabra(string palabra);
void vaciarDiccionario();
int devolverTamano();
string juanagra(string palabra);
string ordenarPalabra(string palabra);
};
#endif