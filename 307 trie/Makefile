a.out: interprete.o  diccionarioPalabras.o 200.o ArbolTrie.o
	g++ -g -Wall 200.o interprete.o diccionarioPalabras.o normalizarPalabra.o ArbolTrie.o


200.o: 200.cpp interprete.o
	g++ -c -g -Wall 200.cpp
interprete.o: interprete.cpp interprete.h normalizarPalabra.o diccionarioPalabras.o ArbolTrie.o
	g++ -c -g -Wall interprete.cpp

diccionarioPalabras.o: diccionarioPalabras.cpp diccionarioPalabras.h ArbolTrie.o
	g++ -c -g -Wall diccionarioPalabras.cpp
ArbolTrie.o: ArbolTrie.cpp ArbolTrie.h
	g++ -c -g -Wall ArbolTrie.cpp
normalizarPalabra.o: normalizarPalabra.cpp normalizarPalabra.h
	g++ -c -g -Wall normalizarPalabra.cpp