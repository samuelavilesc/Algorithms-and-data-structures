#include "AVL.h"

Nodo::Nodo()
{
    izq = NULL;
    der = NULL;
    h = 1;
}

Nodo::~Nodo()
{
    delete izq;
    delete der;
}

int Nodo::altura()
{
    if (this == NULL)
    {
        return 0;
    }

    return this->h;
}

int Nodo::alturaMaxima(int a, int b)
{
    if ( a > b )
        return a;
    return b;
}

int Nodo::fBalance()
{
    if (this == NULL)
        return 0;
    return this->izq->altura() - this->der->altura();
}

Nodo* Nodo::RSD()
{
    Nodo *B = this->der;
    Nodo *C = B->izq;
    B->izq = this;
    this->der = C;

    this->h =this->alturaMaxima(  this->izq->altura(),  this->der->altura() ) + 1;
    B->h =B->alturaMaxima(  B->izq->altura(),  B->der->altura() ) + 1;

    return B;
}

Nodo* Nodo::RSI() 
{
    Nodo *B = this->izq;
    Nodo *C = B->der;
    B->der = this;
    this->izq = C;

    this->h =this->alturaMaxima(  this->izq->altura(),  this->der->altura() ) + 1;
    B->h =B->alturaMaxima(  B->izq->altura(),  B->der->altura() ) + 1;
    return B;
}
bool Nodo::consultar(string palabra)
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

Nodo* insertar(string palabra, Nodo *nodo)
{
    if( nodo == NULL )
    {
        nodo = new Nodo;
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

Arbol::Arbol()
{
    raiz = NULL;
    nElem = 0;
}

Arbol::~Arbol()
{
    delete raiz;
}

void Arbol::inserta(string palabra)
{
    if(consultar(palabra))
    {
        return;
    }
    nElem++;
    raiz = insertar(palabra, raiz);
}

bool Arbol::consultar(string palabra)
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
int Arbol::nElementos()
{
    return nElem;
}
void Arbol::vaciar(){
    this->~Arbol();
    raiz=NULL;
    nElem=0;
}