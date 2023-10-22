#include "interprete.h"
diccionarioPalabras diccionario= diccionarioPalabras();
void insertar(){
    int i=0;
    string palabra;
    while (cin>>palabra)
    {
        if(palabra == "</insertar>"){
            break;
        }
        diccionario.insertarPalabra(normalizarPalabra(palabra)); //dice el enunciado que no guardamos las palabras
        i++;                                    //asi que solo ponemos el nombre de la clave, el valor es la cadena vacia
    }
    cout<<"Insertando: "<<i<<" palabras"<<endl;
    cout << "Total diccionario: " << diccionario.devolverTamano() <<" palabras"<< endl;
    
}
void buscar(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    if(diccionario.consultarPalabra(palabra)){
        cout <<"Buscando: "<<normalizarPalabra(palabra)<< " -> Encontrada" << endl;
    }else{
    cout <<"Buscando: "<<normalizarPalabra(palabra)<< " -> No encontrada" << endl;
    }
}
void partidas(){
    string palabra;
    cout<<"Partidas:";
    while (cin>>palabra)
    {
        if(palabra == "</partidas>"){
            cout<<endl<<"No implementado"<<endl;
            break;
        }
        palabra = normalizarPalabra(palabra);
        cout<<" "<<palabra;
    }
}
void alocado(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    cout<<"Alocado: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void cesar(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    cout<<"César: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void juanagra(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    cout<<"Juanagrama: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void saco(){
    string palabra;
    string palabra2;
    cin>>palabra>>palabra2;
    palabra = normalizarPalabra(palabra);
    palabra2=normalizarPalabra(palabra2);
    cout<<"Saco: "<<palabra<<" "<<palabra2<<endl;
    cout<<"No implementado"<<endl;
}
void consome(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    cout<<"Consomé: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void alarga(){
    string palabra;
    cin>>palabra;
    palabra = normalizarPalabra(palabra);
    cout<<"Alarga: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void vaciar(){
    cout<<"Vaciando"<<endl;
    diccionario.vaciarDiccionario();
    cout << "Total diccionario: " << diccionario.devolverTamano() <<" palabras"<< endl;
}
void elegir() {
    string comando;
    while(cin>>comando){
        
    
        if(comando == "<insertar>"){
            insertar();
        }else if(comando == "<vaciar>"){
            vaciar();
        }else if(comando == "<buscar>"){
            buscar();
        }else if(comando == "<partidas>"){
           partidas();
        }else if(comando == "<alocado>"){
            alocado();
        }else if(normalizarPalabra(comando) == "<CESAR>"){
            cesar();    
        }else if(comando == "<juanagra>"){
            juanagra();
        }else if(comando == "<saco>"){
            saco();
        }else if(normalizarPalabra(comando) == "<CONSOME>"){
            consome();
        }else if(comando == "<alarga>"){
            alarga();
        }else if(comando == "<exit>"){
            cout << "Saliendo..."<<endl;
            exit(0);
        }else{
            continue;
        }
    }
    
}

