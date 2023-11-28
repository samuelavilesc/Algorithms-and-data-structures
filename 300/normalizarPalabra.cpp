#include "normalizarPalabra.h"
#include <string>
using namespace std;

string normalizarPalabra(string str){
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
                    palabraNormalizada.push_back('A');
                    break;
                case '\xA9':
                    palabraNormalizada.push_back('E');
                    break;
                case '\xAD':    
                    palabraNormalizada.push_back('I');
                    break; 
                case '\xB3':
                    palabraNormalizada.push_back('O');
                    break;
                case '\xBA':
                    palabraNormalizada.push_back('U');
                    break;
                case '\xB1':
                    palabraNormalizada.push_back(0xC3);
                    palabraNormalizada.push_back(0x91);
                    break;
                case '\xBC':
                    palabraNormalizada.push_back(0xC3);
                    palabraNormalizada.push_back(0x9C);
                    break;
                case '\x81':
                    palabraNormalizada.push_back('A');
                    break;
                case '\x89':
                    palabraNormalizada.push_back('E');
                    break;
                case '\x8D':
                    palabraNormalizada.push_back('I');
                    break;
                case '\x93':
                    palabraNormalizada.push_back('O');
                    break;
                case '\x9A':
                    palabraNormalizada.push_back('U');
                    break;
                case '\x9C':
                    palabraNormalizada.push_back(0xC3);
                    palabraNormalizada.push_back(0x9C);
                    break;
                case '\x91':
                    palabraNormalizada.push_back(0xC3);
                    palabraNormalizada.push_back(0x91);
                    break;
                default:
                //por si es otra letra con dos bytes
                    palabraNormalizada.push_back(static_cast<char>(0xC3));
                    palabraNormalizada.push_back(static_cast<char>(byte2));
                    break;
                }
                i+=2; //letra con 2 bytes
            } else{
                    palabraNormalizada.push_back(toupper(byte1));
                    i++; //letra con 1 byte
            }
        }
        
        
    return palabraNormalizada;
}