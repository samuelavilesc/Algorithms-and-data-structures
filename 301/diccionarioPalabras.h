#ifndef DICCIONARIOPALABRAS_H
#define DICCIONARIOPALABRAS_H
#include<list>
#include<string>
#include "normalizarPalabra.h"
#include "TablaHash.h"
#include "AVL.h"
#include "ArbolPartidas.h"
using namespace std;
class diccionarioPalabras{
private:
    TablaHash tabla;
    Arbol arbol;
    ArbolPartidas arbolPartidas;
    string ordenarPalabra(string palabra);
public:
diccionarioPalabras();
void insertarPalabra(string palabra);
bool consultarPalabra(string palabra);
void vaciarDiccionario();
int devolverTamano();
string partidas(string palabra);
};
#endif