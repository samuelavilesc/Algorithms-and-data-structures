#include <iostream>
#include <string>
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
int main() {
    string palabra;
    int contadorPalabras = 0;
    while (cin >> palabra)
    {
    contadorPalabras++;
    cout << contadorPalabras << ". " << palabra <<" -> "<<normalizar(palabra)<< endl;
    }
    return 0;
}