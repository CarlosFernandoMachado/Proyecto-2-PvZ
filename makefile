main: main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o Corredor.o Portero.o
	g++ main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o Corredor.o Portero.o -o a 
	
main.o:	main.cpp Padre.h Cherry.h Papa.h Planta.h Zombie.h Portero.h Corredor.h
	g++ -c main.cpp 

Padre.o:	Padre.cpp Padre.h
	g++ -c Padre.cpp 

Planta.o:	Planta.cpp Planta.h Padre.h
	g++ -c Planta.cpp

Cherry.o:	Cherry.cpp Cherry.h Planta.h
	g++ -c Cherry.cpp

Papa.o:	Papa.cpp Papa.h Planta.h
	g++ -c Papa.cpp

Zombie.o:	Zombie.cpp Zombie.h Padre.h
	g++ -c Zombie.cpp

Corredor.o: Corredor.cpp Corredor.h Zombie.h
	g++ -c Corredor.cpp 

Portero.o: Portero.cpp Portero.h Zombie.h
	g++ -c Portero.cpp
