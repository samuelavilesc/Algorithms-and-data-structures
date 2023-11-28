#include "ArbolTrie.h"
using namespace std;

NodoTrie::NodoTrie() {
    sig = NULL;
    ptr = NULL;
}

NodoTrie::~NodoTrie() {
    delete sig;
    delete ptr;
}


void NodoTrie::inserta(char letra, NodoTrie *p) {
    NodoTrie* nodo = new NodoTrie();
    nodo->letra = letra;
    nodo->ptr = p;
    if (this->ptr == NULL) {
        this->ptr = nodo;
    } else {
        NodoTrie* h = this->ptr;
        while (h->sig != NULL) {
            h = h->sig;
        }
        h->sig = nodo;
    }
}

NodoTrie* NodoTrie::consulta(char letra) {
    NodoTrie* nodo = this->ptr;
    while (nodo != NULL && nodo->letra != letra) {
        nodo = nodo->sig;
    }
    return nodo;
}


ArbolTrie::ArbolTrie() {
    raiz = new NodoTrie();
    nElem = 0;
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}

void ArbolTrie::insertar(string palabra) {
    NodoTrie* nodo = raiz;
    for (char letra : palabra) {
        NodoTrie* sig = nodo->consulta(letra);
        if (sig == NULL) {
            nodo->inserta(letra, NULL);
            sig = nodo->consulta(letra);
        }
        nodo = sig;
    }
    if (nodo->consulta('$') == NULL) {
        nodo->inserta('$', NULL);
        nElem++;
    }
}

bool ArbolTrie::consultar(string palabra) {
    NodoTrie* nodo = raiz;
    for (char letra : palabra) {
        nodo = nodo->consulta(letra);
        if (nodo == NULL) {
            return false;
        }
    }
    return nodo->consulta('$') != NULL;
}

void ArbolTrie::vaciar() {
    delete raiz;
    raiz = new NodoTrie();
    nElem = 0;
}

int ArbolTrie::numElem() {
    return nElem;
}
