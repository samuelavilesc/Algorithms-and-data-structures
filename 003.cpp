#include <iostream>
#include <string>
#include<map>
using namespace std;
string normalizar(string str){
    string palabraNormalizada;
    size_t i = 0;
        while (i<str.length())
        {
            char byte1 =str[i];
            if(byte1=='\xC3'){
                char byte2 = str[i+1];
                switch (byte2)
                {
                case '\xA1':
                    palabraNormalizada.push_back(static_cast<char>(0x41));
                    break;
                case '\xA9':
                    palabraNormalizada.push_back(static_cast<char>(0x45));
                    break;
                case '\xAD':    
                    palabraNormalizada.push_back(static_cast<char>(0x49));
                    break; 
                case '\xB3':
                    palabraNormalizada.push_back(static_cast<char>(0x4F));
                    break;
                case '\xBA':
                    palabraNormalizada.push_back(static_cast<char>(0x55));
                    break;
                case '\xB1':
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(0x91));
                    break;
                case '\xBC':
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(0x9C));
                    break;
                case '\x81':
                    palabraNormalizada.push_back(static_cast<char>(0x41));
                    break;
                case '\x89':
                    palabraNormalizada.push_back(static_cast<char>(0x45));
                    break;
                case '\x8D':
                    palabraNormalizada.push_back(static_cast<char>(0x49));
                    break;
                case '\x93':
                    palabraNormalizada.push_back(static_cast<char>(0x4F));
                    break;
                case '\x9A':
                    palabraNormalizada.push_back(static_cast<char>(0x55));
                    break;
                case '\x9C':
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(0x9C));
                    break;
                case '\x91':
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(0x91));
                    break;
                default:
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(byte2));
                    break;
                }
                i+=2; //letra con 2 bytes
            } else{
                    palabraNormalizada.push_back(static_cast<char>(toupper(byte1)));
                    i++; //letra con 1 byte
            }
        }
        
        
    return palabraNormalizada;
}

multimap<string,string> diccionario;


void insertar(){
    int i=0;
    string palabra;
    while (cin>>palabra)
    {
        if(palabra == "</insertar>"){
            break;
        }
        diccionario.insert(make_pair(normalizar(palabra),"")); //dice el enunciado que no guardamos las palabras
        i++;                                    //asi que solo ponemos el nombre de la clave, el valor es la cadena vacia
    }
    cout<<"Insertando: "<<i<<" palabras"<<endl;
    cout << "Total diccionario: " << diccionario.size() <<" palabras"<< endl;
    
}
void buscar(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout <<"Buscando: "<<normalizar(palabra)<< " -> No encontrada" << endl;
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
        palabra = normalizar(palabra);
        cout<<" "<<palabra;
    }
}
void alocado(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout<<"Alocado: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void cesar(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout<<"César: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void juanagra(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout<<"Juanagrama: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void saco(){
    string palabra;
    string palabra2;
    cin>>palabra>>palabra2;
    palabra = normalizar(palabra);
    palabra2=normalizar(palabra2);
    cout<<"Saco: "<<palabra<<" "<<palabra2<<endl;
    cout<<"No implementado"<<endl;
}
void consome(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout<<"Consomé: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void alarga(){
    string palabra;
    cin>>palabra;
    palabra = normalizar(palabra);
    cout<<"Alarga: "<<palabra<<endl;
    cout<<"No implementado"<<endl;
}
void vaciar(){
    cout<<"Vaciando"<<endl;
    diccionario.clear();
    cout << "Total diccionario: " << diccionario.size() <<" palabras"<< endl;
}
int main() {
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
        }else if(normalizar(comando) == "<CESAR>"){
            cesar();    
        }else if(comando == "<juanagra>"){
            juanagra();
        }else if(comando == "<saco>"){
            saco();
        }else if(comando == "<consomé>"){
            consome();
        }else if(comando == "<alarga>"){
            alarga();
        }else if(comando == "<exit>"){
            cout << "Saliendo..." ;
            exit(0);
        }else{
            continue;
        }
    }
    return 0;
}
