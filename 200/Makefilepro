a.out: interprete.o TablaHash.o diccionarioPalabras.o
	g++ 200.o interprete.o TablaHash.o diccionarioPalabras.o normalizarPalabra.o

200.o: 200.cpp InterpreteComandos.o
	g++ -c 200.cpp
interprete.o: interprete.cpp interprete.h normalizarPalabra.o
	g++ -c interprete.cpp

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

diccionarioPalabras.o: diccionarioPalabras.cpp diccionarioPalabras.h
	g++ -c diccionarioPalabras.cpp

normalizarPalabra.o: normalizarPalabra.cpp normalizarPalabra.h
	g++ -c normalizarPalabra.cpp