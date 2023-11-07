#ifndef TABLAJUANAGRAMA_H
#define TABLAJUANAGRAMA_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

#define TAMANO 1024

class tablaJuanagrama {
  private:
     list<string> listaPalabras[TAMANO];
     int nElem;
  public:
     tablaJuanagrama ();
     int hash (string k);
     void inserta (string palabra);
     bool consulta(string palabra);
     void vacia (void);
     int nTotal (void);
     string anagrama(string palabra);
};

#endif