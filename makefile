OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program.exe: program.o Categorias.o Circuito.o Cjt_Jugadores.o Jugador.o Torneo.o
	g++ -o program.exe *.o

Categorias.o: Categorias.cc Categorias.hh
	g++ -c Categorias.cc $(OPCIONS)

Circuito.o: Circuito.cc Circuito.hh Torneo.hh Cjt_Jugadores.hh Categorias.hh
	g++ -c Circuito.cc $(OPCIONS)

Cjt_Jugadores.o: Cjt_Jugadores.cc Cjt_Jugadores.hh
	g++ -c Cjt_Jugadores.cc $(OPCIONS)

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

Torneo.o: Torneo.cc Torneo.hh Cjt_Jugadores.hh Categorias.hh
	g++ -c Torneo.cc $(OPCIONS)

program.o: program.cc Categorias.hh Circuito.hh Cjt_Jugadores.hh
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe

practica.tar : *.cc *.hh makefile html.zip
	tar -cvf practica.tar *.cc *.hh makefile html.zip
