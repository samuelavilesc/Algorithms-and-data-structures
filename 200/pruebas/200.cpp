#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main (){
unordered_map<string,string> map;
auto fun=map.hash_function();
    cout << "Hash function for a = " << fun("a")%100 << endl;
   cout << "Hash function for A = " << fun("A") << endl;
    return 0;
}