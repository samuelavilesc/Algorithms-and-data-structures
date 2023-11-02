a.out: interprete.o TablaHash.o diccionarioPalabras.o 200.o
	g++ 200.o interprete.o TablaHash.o diccionarioPalabras.o normalizarPalabra.o

200.o: 200.cpp interprete.o
	g++ -c 200.cpp
interprete.o: interprete.cpp interprete.h normalizarPalabra.o diccionarioPalabras.o TablaHash.o
	g++ -c interprete.cpp

diccionarioPalabras.o: diccionarioPalabras.cpp diccionarioPalabras.h TablaHash.o 
	g++ -c diccionarioPalabras.cpp

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

normalizarPalabra.o: normalizarPalabra.cpp normalizarPalabra.h
	g++ -c normalizarPalabra.cpp