#ifndef TABLAJUANAGRAMA_H
#define TABLAJUANAGRAMA_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

const int TAMANO_INICIAL = 1024;

class tablaJuanagrama {
  private:
     list<string> *listaPalabras;
     int nElem;
     string ordenarAlfabeticamente(string palabra);
  public:
     tablaJuanagrama ();
      ~tablaJuanagrama ();
     int hash (string k);
     void inserta (string& palabra);
     bool consulta(string& palabra);
     void vacia (void);
     int nTotal (void);
     string anagrama(string& palabra);
};

#endif
