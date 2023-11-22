OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Bicing.o Estacion.o Bicicleta.o
	g++ -o program.exe *.o

program.o: program.cc Bicing.hh Estacion.hh Bicicleta.hh
	g++ -c program.cc $(OPCIONS)

Bicing.o: Bicing.cc Bicing.hh
	g++ -c Bicing.cc $(OPCIONS)

Estacion.o: Estacion.cc Estacion.hh
	g++ -c Estacion.cc $(OPCIONS)

Bicicleta.o: Bicicleta.cc Bicicleta.hh
	g++ -c Bicicleta.cc $(OPCIONS)

tar:
	tar -cvf practica.tar *.cc *.hh Makefile justificacion_metodos.txt

clear:
	rm -f *.o
	rm -f *-exe 

// añadir .hh en las clases que incluyan otra clase
// modificar el OPCIONS, ponerle el flag -fno-extended-identifiers
// OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
