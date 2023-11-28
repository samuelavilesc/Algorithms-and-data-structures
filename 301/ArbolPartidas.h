#ifndef ARBOLPARTIDAS_H
#define ARBOLPARTIDAS_H
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class NodoPartidas {
   friend class ArbolPartidas;
   public:
      NodoPartidas* izq;
      NodoPartidas* der; 
      string palabra;
      int h;

      NodoPartidas ();
      ~NodoPartidas ();
      int fBalance ();
      int alturaMaxima (int a, int b);
      int altura ();
      NodoPartidas* RSI();
      NodoPartidas* RSD();
      NodoPartidas* insertar(string palabra);
      bool consultar(string palabra);
};

class ArbolPartidas {
   private:
      NodoPartidas *raiz;
      int nElem;
   public:
      ArbolPartidas ();
      ~ArbolPartidas ();
      void inserta (string palabra);
      bool consultar (string palabra);
      int nElementos ();
      void vaciar();
      string partidas(string palabra);
};

#endif