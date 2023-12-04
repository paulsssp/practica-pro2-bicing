OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Bicing.o Estacion.o Cjo_bicis.o Bicicleta.o 
	g++ -o program.exe *.o

program.o: program.cc Bicing.hh Estacion.hh Cjo_bicis.hh Bicicleta.hh 
	g++ -c program.cc $(OPCIONS)

Bicing.o: Bicing.cc Bicing.hh Estacion.hh Cjo_bicis.hh
	g++ -c Bicing.cc $(OPCIONS)

Estacion.o: Estacion.cc Estacion.hh
	g++ -c Estacion.cc $(OPCIONS)

Cjo_bicis.o: Cjo_bicis.cc Cjo_bicis.hh Bicicleta.hh Estacion.hh Bicing.hh
	g++ -c Cjo_bicis.cc $(OPCIONS)

Bicicleta.o: Bicicleta.cc Bicicleta.hh
	g++ -c Bicicleta.cc $(OPCIONS)

clear:
	rm -f *.o
	rm -f *.exe 
