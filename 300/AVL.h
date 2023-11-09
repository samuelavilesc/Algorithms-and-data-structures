#ifndef AVL_H
#define AVL_H
#include <string>
using namespace std;

class Nodo {
   friend class Arbol;
   public:
      Nodo* izq;
      Nodo* der; 
      string palabra;
      int h;

      Nodo ();
      ~Nodo ();
      int fBalance ();
      int alturaMaxima (int a, int b);
      int altura ();
      Nodo* RSI();
      Nodo* RSD();
      Nodo* insertar(string palabra);
      bool consultar(string palabra);
};

class Arbol {
   private:
      Nodo *raiz;
      int nElem;
   public:
      Arbol ();
      ~Arbol ();
      void inserta (string palabra);
      bool consultar (string palabra);
      int nElementos ();
      void vaciar();
};

#endif