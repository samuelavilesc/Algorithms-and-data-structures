#include<iostream>
#include<string>
#include"TablaHash.h"

int main (){
    TablaHash tabla=TablaHash();
    string palabra="hola";
    tabla.inserta(palabra);
    tabla.inserta("adios");
    tabla.inserta("hola");
    cout<<tabla.consulta("hola")<<endl;
    cout<<tabla.nTotal()<<endl;
    cout<<tabla.consulta("adios")<<endl;
    cout<<tabla.hash("hola")<<endl;
    cout<<tabla.hash("hola")<<endl;
    cout<<tabla.hash("adios")<<endl;
    cout<<tabla.hash("holacomoteencuentras")<<endl;
    
        

    return 0;
}