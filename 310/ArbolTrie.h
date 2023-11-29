#ifndef ARBOLTRIE_H
#define ARBOLTRIE_H

#include <string>
using namespace std;
class NodoTrie {
    friend class ArbolTrie;
    private:
        char letra;
        NodoTrie *sig, *ptr;
    public:
        NodoTrie();
        ~NodoTrie();
        NodoTrie* consulta(char letra);
        void inserta(char letra, NodoTrie *p);
};

class ArbolTrie {
    private:
        NodoTrie *raiz;
        int nElem;
        int longitudPalabra(string& palabra);
    public:
        ArbolTrie();
        ~ArbolTrie();
        void insertar(string& palabra);
        bool consultar(string& palabra);
        int numElem(void);
        void vaciar(void);
        string alarga(string& prefijo);
};

#endif