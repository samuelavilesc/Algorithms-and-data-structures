// Tabla Hash //
#ifndef __TABLA__HASH
#define __TABLA__HASH

#include <iostream>
#include <string>
#include <list>

using namespace std;

 #define TAM 1024

class TablaHash {
  private:
     list<string> listaPalabras[TAM];
     int nElem;
  public:
     TablaHash ();
     int hash (string k);
     void inserta (string palabra);
     bool consulta(string palabra);
     void vacia (void);
     int nTotal (void);
};

#endif