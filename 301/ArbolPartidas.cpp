#include "ArbolPartidas.h"

NodoPartidas::NodoPartidas()
{
    izq = NULL;
    der = NULL;
    h = 1;
}

NodoPartidas::~NodoPartidas()
{
    delete izq;
    delete der;
}

int NodoPartidas::altura()
{
    if (this == NULL)
    {
        return 0;
    }

    return this->h;
}

int NodoPartidas::alturaMaxima(int a, int b)
{
    if ( a > b )
        return a;
    return b;
}

int NodoPartidas::fBalance()
{
    if (this == NULL)
        return 0;
    return this->izq->altura() - this->der->altura();
}

NodoPartidas* NodoPartidas::RSD()
{
    NodoPartidas *B = this->der;
    NodoPartidas *C = B->izq;
    B->izq = this;
    this->der = C;

    this->h =this->alturaMaxima(  this->izq->altura(),  this->der->altura() ) + 1;
    B->h =B->alturaMaxima(  B->izq->altura(),  B->der->altura() ) + 1;

    return B;
}

NodoPartidas* NodoPartidas::RSI() 
{
    NodoPartidas *B = this->izq;
    NodoPartidas *C = B->der;
    B->der = this;
    this->izq = C;

    this->h =this->alturaMaxima(  this->izq->altura(),  this->der->altura() ) + 1;
    B->h =B->alturaMaxima(  B->izq->altura(),  B->der->altura() ) + 1;
    return B;
}
bool NodoPartidas::consultar(string palabra)
{
    if (this->palabra == palabra)
    {
        return true;
    }

    if (this->palabra.compare(palabra) > 0)
    {
        if (this->izq == NULL)
        {
            return false;
        }
        else
        {
            return this->izq->consultar(palabra);
        }
    }
    else
    {
        if (this->der == NULL)
        {
            return false;
        }
        else
        {
            return this->der->consultar(palabra);
        }
    }
}

NodoPartidas* insertar(string palabra, NodoPartidas *nodo)
{
    if( nodo == NULL )
    {
        nodo = new NodoPartidas;
        nodo->palabra = palabra;
        return nodo;
        
    }
    if(palabra.compare(nodo->palabra) < 0 )
    {
        nodo->izq = insertar(palabra, nodo->izq);
    } else if ( palabra.compare(nodo->palabra) > 0 )
    {
        nodo->der = insertar(palabra, nodo->der);
    } else 
    {
        nodo->palabra = palabra;
        return nodo;
    }
    //rebalancear
    nodo->h=1+nodo->alturaMaxima(nodo->izq->altura(), nodo->der->altura());
    int fBal = nodo->fBalance();

    if ( fBal > 1 )
    {
        if ( palabra.compare( nodo->izq->palabra ) < 0)
        {
            return nodo->RSI();
        }
        else 
        {
            nodo->izq = nodo->izq->RSD();
            return nodo->RSI();
        }

    }
    else if ( fBal < -1 )
    {
        if ( palabra.compare( nodo->der->palabra) > 0)
        {
            return nodo->RSD();
        }
        else 
        {
            nodo->der = nodo->der->RSI();
            return nodo->RSD();
        }
    }
    return nodo;
}

ArbolPartidas::ArbolPartidas()
{
    raiz = NULL;
    nElem = 0;
}

ArbolPartidas::~ArbolPartidas()
{
    delete raiz;
}

void ArbolPartidas::inserta(string palabra)
{
    if(consultar(palabra))
    {
        return;
    }
    nElem++;
    raiz = insertar(palabra, raiz);
}

bool ArbolPartidas::consultar(string palabra)
{
    if (raiz == NULL)
    {
        return false;
    }
    else
    {
        return raiz->consultar(palabra);
    }
}
int ArbolPartidas::nElementos()
{
    return nElem;
}
void ArbolPartidas::vaciar(){
    this->~ArbolPartidas();
    raiz=NULL;
    nElem=0;
}
string ordenarAlfabeticamente(string str) {
    sort(str.begin(), str.end());
    return str;
}
string salida="";
int contador=0;
void inOrden(NodoPartidas *raiz, string palabra){

    NodoPartidas *arbol=raiz;
    if (arbol==NULL){
        return;
    }
    else{
        inOrden(arbol->izq,palabra);
        if(ordenarAlfabeticamente(arbol->palabra)==ordenarAlfabeticamente(palabra)){
            if(contador==0){
                salida.append(arbol->palabra);
                contador++;
            }
            else{
                salida.append(" ");
                salida.append(arbol->palabra);
            }
        }
        inOrden(arbol->der,palabra);
    }
}

string ArbolPartidas::partidas(string palabra){
    salida="";
    contador=0;
    inOrden(raiz,palabra);
    return salida;
}