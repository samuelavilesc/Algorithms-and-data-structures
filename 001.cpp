#include <iostream>
#include <string>
using namespace std;
int main() {
    string palabra;
    int contadorPalabras = 0;
    while (cin >> palabra)
    {
    contadorPalabras++;
    cout << contadorPalabras << ". " << palabra << endl;
    }
    return 0;
}