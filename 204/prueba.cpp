#include<iostream>
#include<algorithm>
#include<string>

string ordenarAlfabeticamente(string str) {
    sort(str.begin(), str.end());
    return str;
}

int main() {
    std::string str = "hola mundo";
    std::cout << ordenarAlfabeticamente(str) << std::endl;
    return 0;
}
