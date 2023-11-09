a.out: interprete.o TablaHash.o diccionarioPalabras.o 200.o tablaJuanagrama.o AVL.o
	g++ 200.o interprete.o TablaHash.o diccionarioPalabras.o normalizarPalabra.o tablaJuanagrama.o AVL.o


200.o: 200.cpp interprete.o
	g++ -c 200.cpp
interprete.o: interprete.cpp interprete.h normalizarPalabra.o diccionarioPalabras.o TablaHash.o tablaJuanagrama.o AVL.o
	g++ -c interprete.cpp

diccionarioPalabras.o: diccionarioPalabras.cpp diccionarioPalabras.h TablaHash.o tablaJuanagrama.o AVL.o
	g++ -c diccionarioPalabras.cpp
AVL.o: AVL.cpp AVL.h
	g++ -c AVL.cpp
TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp
tablaJuanagrama.o: tablaJuanagrama.cpp tablaJuanagrama.h
	g++ -c tablaJuanagrama.cpp
normalizarPalabra.o: normalizarPalabra.cpp normalizarPalabra.h
	g++ -c normalizarPalabra.cpp