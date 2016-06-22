#include "Padre.h"
#include "Planta.h"
#include "Papa.h"
#include "Cherry.h"
#include "Zombie.h"
#include "Corredor.h"
#include "Portero.h"
#include <string>
#include <ncurses.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;

int ataqueplantas(vector<Padre*>&);
int ataquezombies(vector<Padre*>&);
void imprimirtablero(vector<Padre*>&);
void movezombies(vector<Padre*>&);
void guardarArchivo(vector<Padre*>&);
void leerArchivo(vector<Padre*>&);

int main(int argc, char*argv[]){
	initscr();
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_RED);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	init_pair(3,COLOR_BLACK,COLOR_WHITE);
	init_pair(4,COLOR_GREEN,COLOR_YELLOW);
	init_pair(5,COLOR_YELLOW,COLOR_GREEN);
	bkgd(COLOR_PAIR(3));
	Planta ejemploplanta(-1,-1);
	Cherry ejemplocherry(-1,-1);
	Papa ejemplopapa(-1,-1);
	Zombie ejemplozombie(-1,-1);
	Portero ejemploportero(-1,-1);
	Corredor ejemplocorredor(-1,-1);
	vector<Padre*> tablero;
	//valor maximo para x es 7, valor maximo para y es 4
	int menuprincipal = 0,dineroplantas,dinerozombies,masdineroplantas = 0,masdinerozombies = 0, opcion = 0, zombiespormatar = 0,x,y;
	bool existe;
	while(menuprincipal <= 0 || menuprincipal > 3){
		clear();
		addstr("\n\tBIENVENIDO!!\n1) Nueva partida\n2) Cargar Partida\n3) Salir\nUsted elije: ");
		scanw("%d",&menuprincipal);
	}
	while(menuprincipal != 3){
		if(menuprincipal == 1){
			while(zombiespormatar <= 0){
				clear();
				addstr("Cuantos zombies desea matar: ");
				scanw("%d",&zombiespormatar);
			}
			if(opcion != 5){
				clear();
				printw("\tINSTRUCCIONES!!\nPlants vs Zombies juego de dos personas 1v1\nLos jugadores escogen un bando ya sea plantas o zombies\nPlantas\nLas plantas empiezan siempre, estas pueden plantar plantas en cualquier lado\ndel mapa excepto en la ultima columna y ganan cuando matan %d de zombies\nlas plantas no pueden compartir un espacio con nadie\nZombies\nLos zombies solo pueden empezar en la ultima columna y ganan cuando llegan al\notro lado del mapa, varios zombies pueden compartir un espacio entre ellos\npero no con una planta\nPasos en el juego\n1) Turno de plantas\n2) Turno de zombies\n3) Zombies se mueven\n4) Zombies atacan\n5) Plantas atacan\n6) Los jugadores se reabastecen de dinero (100) o guardan y salen",zombiespormatar);
				refresh();
				getch();
			}
			opcion = 0;
			dineroplantas = 100+masdineroplantas,dinerozombies = 100+masdinerozombies;
			while(opcion != 5){
				existe = false;
				do{
					clear();
					imprimirtablero(tablero);
					addstr("\n\tJUGADOR 1\n");
					printw("Usted tiene %d dinero disponible y gana %d extra por turno\nQue Desea hacer?\n1) Colocar Planta\n2) Colocar Cherry\n3) Colocar Papa\n4) Invertir dinero\n5) Pasar turno\n6) Informacion acerca de las plantas\nUsted elije: ",dineroplantas,masdineroplantas);
					scanw("%d",&opcion);
				}while(opcion <= 0 || opcion > 6);
				clear();
				if(opcion == 1){
					if(dineroplantas >= ejemploplanta.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en x(0 - 6): ");
							scanw("%d",&x);
						}while(x < 0 || x > 6);
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						for(int i = 0 ; i < tablero.size() ; i++){
							if(tablero[i]->getx() == x && tablero[i]->gety() == y)
								existe = true;
						}
						if(!existe){
							tablero.push_back(new Planta(x,y));
							clear();
							addstr("HA COLOCADO SU PLANTA");
							dineroplantas -= ejemploplanta.getcosto();
							refresh();
							getch();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 2){
					if(dineroplantas >= ejemplocherry.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en x(0 - 6): ");
							scanw("%d",&x);
						}while(x < 0 || x > 6);
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						for(int i = 0 ; i < tablero.size() ; i++){
							if(tablero[i]->getx() == x && tablero[i]->gety() == y)
								existe = true;
						}
						if(!existe){
							tablero.push_back(new Cherry(x,y));
							clear();
							addstr("HA COLOCADO SU CHERRY");
							dineroplantas -= ejemplocherry.getcosto();
							refresh();
							getch();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 3){
					if(dineroplantas >= ejemplopapa.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en x(0 - 6): ");
							scanw("%d",&x);
						}while(x < 0 || x > 6);
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						for(int i = 0 ; i < tablero.size() ; i++){
							if(tablero[i]->getx() == x && tablero[i]->gety() == y)
								existe = true;
						}
						if(!existe){
							tablero.push_back(new Papa(x,y));
							clear();
							addstr("HA COLOCADO SU PAPA");
							dineroplantas -= ejemplopapa.getcosto();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 4){
					int temp = 0;
					while(temp <= 0){
						clear();
						printw("Usted tiene %d dinero disponible\nEl dinero que gana extra por turno es %d\nA lo que gana por turno se le agregara la mitad de lo que invierta ahorita\nCuanto desea invertir: ",dineroplantas,masdineroplantas);
						scanw("%d",&temp);
						if(temp > dineroplantas)
							temp = 0;
						if(dineroplantas <= 0)
							break;
					}
					if(temp % 2 == 0){
						masdineroplantas += (temp/2);
						dineroplantas -= temp;
						clear();
						addstr("Se ha aumentado sus ganancias");
						refresh();
						getch();
					}else{
						masdineroplantas += ((temp+1)/2);
						dineroplantas -= temp;
						clear();
						addstr("Se ha aumentado sus ganancias");
						refresh();
						getch();
					}
				}else if(opcion == 6){
					clear();
					addstr(ejemploplanta.descripcion().c_str());
					refresh();
					getch();
					clear();
					addstr(ejemplocherry.descripcion().c_str());
					refresh();
					getch();
					clear();
					addstr(ejemplopapa.descripcion().c_str());
					refresh();
					getch();
				}
			}
			opcion = 0;
			while(opcion != 5){
				existe = false;
				do{
					clear();
					imprimirtablero(tablero);
					x = 7;
					addstr("\n\tJUGADOR 2\n");
					printw("Usted tiene %d dinero disponible y gana %d extra por turno\nQue Desea hacer?\n1) Colocar Zombie\n2) Colocar Corredor\n3) Colocar Portero\n4) Invertir dinero\n5) Pasar turno\n6) Informacion acerca de los Zombies\nUsted elije: ",dinerozombies,masdinerozombies);
					scanw("%d",&opcion);
				}while(opcion <= 0 || opcion > 6);
				clear();
				if(opcion == 1){
					if(dinerozombies >= ejemplozombie.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						if(!existe){
							tablero.push_back(new Zombie(x,y));
							clear();
							addstr("HA COLOCADO SU ZOMBIE");
							dinerozombies -= ejemplozombie.getcosto();
							refresh();
							getch();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 2){
					if(dinerozombies >= ejemplocorredor.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						if(!existe){
							tablero.push_back(new Corredor(x,y));
							clear();
							addstr("HA COLOCADO SU Corredor");
							dinerozombies -= ejemplocorredor.getcosto();
							refresh();
							getch();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 3){
					if(dinerozombies >= ejemploportero.getcosto()){
						do{
							clear();
							addstr("Escriba su coordena en y(0 - 4): ");
							scanw("%d",&y);
						}while(y < 0 || y > 4);
						if(!existe){
							tablero.push_back(new Portero(x,y));
							clear();
							addstr("HA COLOCADO SU PORTERO");
							dinerozombies -= ejemploportero.getcosto();
						}else{
							addstr("Esa posicion esta ocupada");
							refresh();
							getch();
						}
					}else{
						clear();
						addstr("No tiene suficiente dinero!");
						refresh();
						getch();
					}
				}else if(opcion == 4){
					int temp = 0;
					while(temp <= 0){
						clear();
						printw("Usted tiene %d dinero disponible\nEl dinero que gana extra por turno es %d\nA lo que gana por turno se le agregara la mitad de lo que invierta ahorita\nCuanto desea invertir: ",dinerozombies,masdinerozombies);
						scanw("%d",&temp);
						if(temp > dinerozombies)
							temp = 0;
						if(dinerozombies <= 0)
							break;
					}
					if(temp % 2 == 0){
						masdinerozombies += (temp/2);
						dinerozombies -= temp;
						clear();
						addstr("Se ha aumentado sus ganancias");
						refresh();
						getch();
					}else{
						masdinerozombies += ((temp+1)/2);
						dinerozombies -= temp;
						clear();
						addstr("Se ha aumentado sus ganancias");
						refresh();
						getch();
					}
				}else if(opcion == 6){
					clear();
					addstr(ejemplozombie.descripcion().c_str());
					refresh();
					getch();
					clear();
					addstr(ejemplocorredor.descripcion().c_str());
					refresh();
					getch();
					clear();
					addstr(ejemploportero.descripcion().c_str());
					refresh();
					getch();
				}
			}
			movezombies(tablero);
			for(int i = 0; i < tablero.size(); i++){
				if(dynamic_cast<Zombie*>(tablero[i]) != NULL){
					Zombie* zombie = dynamic_cast<Zombie*>(tablero[i]);
					if(zombie->getx() == 0){
						addstr("JUGADOR 2 HA GANADO");
						menuprincipal = 3;
						refresh();
						getch();
					} 
				}
			}
			ataquezombies(tablero);
			zombiespormatar -= ataqueplantas(tablero);
			if(zombiespormatar <= 0){
				clear();
				addstr("JUGADOR 1 HA GANADO");
				menuprincipal = 3;
				refresh();
				getch();
			}
			do{
				addstr("1) Guardar y salir\n2) Guardar y seguir\n3) Hacer nada\nUsted elije: ");
				scanw("%d",&opcion);
			}while(opcion > 3 || opcion < 1);
			if(opcion == 1){
				addstr("No guarda");
				refresh();
				getch();
				//guardarArchivo(tablero);
				menuprincipal = 3;
			}else if(opcion == 2){
				addstr("No guarda");
				refresh();
				getch();
				//guardarArchivo(tablero);
			}
			opcion = 5;
		}else if(menuprincipal == 2){
			addstr("No lee archivos :c");
			refresh();
			getch();
			menuprincipal = 1;
		}
	}
	addstr("Adios GG WP");
	refresh();
	getch();
	endwin();
	return 0;
}
void guardarArchivo(vector<Padre*> tablero){
	FILE *guardarpartida;
	guardarpartida = fopen("planta.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Planta*>(tablero[i]) != NULL && dynamic_cast<Cherry*>(tablero[i]) == NULL && dynamic_cast<Papa*>(tablero[i]) == NULL){
			Planta* planta = dynamic_cast<Planta*>(tablero[i]);
			fwrite(planta,sizeof(Planta),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
	guardarpartida = fopen("cherry.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Cherry*>(tablero[i]) != NULL){
			Cherry* cherry = dynamic_cast<Cherry*>(tablero[i]);
			fwrite(cherry,sizeof(Cherry),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
	guardarpartida = fopen("papa.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Papa*>(tablero[i]) != NULL){
			Papa* papa = dynamic_cast<Papa*>(tablero[i]);
			fwrite(papa,sizeof(Papa),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
	guardarpartida = fopen("zombie.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Zombie*>(tablero[i]) != NULL && dynamic_cast<Corredor*>(tablero[i]) == NULL && dynamic_cast<Portero*>(tablero[i]) == NULL){
			Zombie* zombie = dynamic_cast<Zombie*>(tablero[i]);
			fwrite(zombie,sizeof(Zombie),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
	guardarpartida = fopen("corredor.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Corredor*>(tablero[i]) != NULL){
			Corredor* corredor = dynamic_cast<Corredor*>(tablero[i]);
			fwrite(corredor,sizeof(Corredor),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
	guardarpartida = fopen("portero.bin","w");
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Portero*>(tablero[i]) != NULL){
			Portero* portero = dynamic_cast<Portero*>(tablero[i]);
			fwrite(portero,sizeof(Portero),1,guardarpartida);
		}
	}
	fclose(guardarpartida);
}
void leerArchivo(vector<Padre*> tablero){/*
	FILE  *leerpartida;
	leerpartida = fopen("planta.bin","r");
	fread(planta,sizeof(Planta),1,leerpartida);
	fclose(leerpartida);*/
}
/*
void guardarArchivo(vector<Padre*>& tablero){
	char filename1[20] = "planta.bin";
	ofstream output(filename1, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Planta*>(tablero[i]) != NULL){
			Planta* planta = dynamic_cast<Planta*>(tablero[i]);
			output.write(reinterpret_cast<char*>(planta), sizeof(Planta));
		}
	}
	output.close();
	char filename2[20] = "cherry.bin";
	output(filename2, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Cherry*>(tablero[i]) != NULL){
			Cherry* cherry = dynamic_cast<Cherry*>(tablero[i]);
			output.write(reinterpret_cast<char*>(cherry), sizeof(Cherry));
		}
	}
	output.close();
	char filename3[20] = "papa.bin";
	output(filename3, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Papa*>(tablero[i]) != NULL){
			Papa* papa = dynamic_cast<Papa*>(tablero[i]);
			output.write(reinterpret_cast<char*>(papa), sizeof(Papa));
		}
	}
	output.close();
	char filename4[20] = "zombie.bin";
	output(filename4, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Zombie*>(tablero[i]) != NULL){
			Zombie* zombie = dynamic_cast<Zombie*>(tablero[i]);
			output.write(reinterpret_cast<char*>(zombie), sizeof(Zombie));
		}
	}
	output.close();
	char filename5[20] = "corredor.bin";
	output(filename5, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Corredor*>(tablero[i]) != NULL){
			Corredor* corredor = dynamic_cast<Corredor*>(tablero[i]);
			output.write(reinterpret_cast<char*>(corredor), sizeof(Corredor));
		}
	}
	output.close();
	char filename6[20] = "portero.bin";
	output(filename6, ios::binary);
	for(int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Portero*>(tablero[i]) != NULL){
			Portero* portero = dynamic_cast<Portero*>(tablero[i]);
			output.write(reinterpret_cast<char*>(portero), sizeof(Portero));
		}
	}
	output.close();
}
void leerArchivo(vector<Padre*>& tablero){
	char filename1[20] = "planta.bin";
	Planta planta(0,0);
	Cherry cherry(0,0);
	Papa papa(0,0);
	Zombie zombie(0,0);
	Corredor corredor(0,0);
	Portero portero(0,0);
	ifstream input(filename1, ios::binary);
	while (input.read(reinterpret_cast<char*>(&planta), sizeof(Planta)))
		tablero.push_back(&planta);
	input.close();
	char filename2[20] = "cherry.bin";
	input(filename2, ios::binary);
	while (input.read(reinterpret_cast<char*>(&cherry), sizeof(Cherry)))
		tablero.push_back(&cherry);
	input.close();
	char filename3[20] = "papa.bin";
	input(filename3, ios::binary);
	while (input.read(reinterpret_cast<char*>(&papa), sizeof(Papa)))
		tablero.push_back(&papa);
	input.close();
	char filename4[20] = "zombie.bin";
	input(filename4, ios::binary);
	while (input.read(reinterpret_cast<char*>(&zombie), sizeof(Zombie)))
		tablero.push_back(&zombie);
	input.close();
	char filename5[20] = "corredor.bin";
	input(filename5, ios::binary);
	while (input.read(reinterpret_cast<char*>(&corredor), sizeof(Corredor)))
		tablero.push_back(&corredor);
	input.close();
	char filename6[20] = "portero.bin";
	input(filename6, ios::binary);
	while (input.read(reinterpret_cast<char*>(&portero), sizeof(Portero)))
		tablero.push_back(&portero);
	input.close();
}*/
void movezombies(vector<Padre*>& tablero){
	int newx = 0;
	for (int i = 0; i < tablero.size(); i++){
		if(dynamic_cast<Portero*>(tablero[i]) != NULL){
			Portero* tempportero = dynamic_cast<Portero*>(tablero[i]);
			newx = (tempportero->getx() - tempportero->move());
			if(newx < 0)
				newx = 0;
			for(int j = 0; j < tablero.size(); j++){
				if(newx == tempportero->getx())
					break;
				if(dynamic_cast<Planta*>(tablero[j]) != NULL){
					if(tablero[j]->gety() == tempportero->gety() && tablero[j]->getx() == newx){
						newx += 1;
						j = 0;
					}
				}
				tempportero->setx(newx);
			}
		}else if(dynamic_cast<Corredor*>(tablero[i]) != NULL){
			Corredor* tempcorredor = dynamic_cast<Corredor*>(tablero[i]);
			newx = (tempcorredor->getx() - tempcorredor->move());
			if(newx < 0)
				newx = 0;
			for(int j = 0; j < tablero.size(); j++){
				if(newx == tempcorredor->getx())
					break;
				if(dynamic_cast<Planta*>(tablero[j]) != NULL){
					if(tablero[j]->gety() == tempcorredor->gety() && tablero[j]->getx() == newx){
						newx += 1;
						j = 0;
					}
				}
				tempcorredor->setx(newx);
			}
		}else if(dynamic_cast<Zombie*>(tablero[i]) != NULL){
			Zombie* tempzombie = dynamic_cast<Zombie*>(tablero[i]);
			newx = (tempzombie->getx() - tempzombie->move());
			if(newx < 0)
				newx = 0;
			for(int j = 0; j < tablero.size(); j++){
				if(newx == tempzombie->getx())
					break;
				if(dynamic_cast<Planta*>(tablero[j]) != NULL){
					if(tablero[j]->gety() == tempzombie->gety() && tablero[j]->getx() == newx){
						newx += 1;
						j = 0;
					}
				}
			}
				tempzombie->setx(newx);
		}
	}
}
void imprimirtablero(vector<Padre*>& tablero){
	string espacio = "";
	bool alternar = true;
	attron(COLOR_PAIR(3));
	for (int i = 0; i < 8; i++){
		if(i == 0)
			printw("     %d    ",i);
		else
			printw("    %d    ",i);
	}
	printw("%c\n",'x');
	for(int y = 0; y < 5; y++){
		attron(COLOR_PAIR(3));
		printw("%d",y);
		for(int x = 0; x < 8; x++){
			if(alternar){
				alternar = false;
				if(y % 2 == 0)
					attron(COLOR_PAIR(1));
				else
					attron(COLOR_PAIR(4));
			}else{
				alternar = true;
				if(y % 2 == 0)
					attron(COLOR_PAIR(2));
				else
					attron(COLOR_PAIR(5));
			}
			for(int i = 0; i < tablero.size(); i++){
				if(tablero[i]->getx() == x && tablero[i]->gety() == y){
					espacio += tablero[i]->tostring();
					espacio += ",";
				}
			}
			if(espacio.size() < 9){
				for(int i = espacio.size(); i < 9; i++)
					espacio += " ";
			}
			if(espacio != ""){
				espacio[espacio.size()-1] = ' ';
				addstr(espacio.c_str());
				espacio = "";
			}else{
				addstr("         ");
			}
		}
		if(alternar)
			alternar = false;
		else
			alternar = true;
		addstr("\n");
	}
	attron(COLOR_PAIR(3));
	printw("%c\n",'y');
}
int ataqueplantas(vector<Padre*>& tablero){
	int dano,muertes = 0;
	for(int j = 0; j < 5; j++){
		dano = 0;
		for(int i = 0; i < tablero.size(); i++){
			if(tablero[i]->gety() == j){
				if(dynamic_cast<Cherry*>(tablero[i]) != NULL){
					Cherry* tempcherry = dynamic_cast<Cherry*>(tablero[i]);
					dano += tempcherry->ataque();
				}else if(dynamic_cast<Papa*>(tablero[i]) != NULL){
					Papa* temppapa = dynamic_cast<Papa*>(tablero[i]);
					dano += temppapa->ataque();
				}else if(dynamic_cast<Planta*>(tablero[i]) != NULL){
					Planta* tempplanta = dynamic_cast<Planta*>(tablero[i]);
					dano += tempplanta->ataque();
				}
			}
		}
		for(int i = 0; i < tablero.size(); i++){
			if(tablero[i]->gety() == j){
				if(dynamic_cast<Portero*>(tablero[i]) != NULL){
					Portero* tempportero = dynamic_cast<Portero*>(tablero[i]);
					dano = tempportero->defensa(dano);
					if (dano == 0){
						break;
					}else if(dano == -1 || dano > 0){
						tablero.erase(tablero.begin()+i);
						delete tempportero;
						muertes += 1;
					}
				}else if(dynamic_cast<Corredor*>(tablero[i]) != NULL){
					Corredor* tempcorredor = dynamic_cast<Corredor*>(tablero[i]);
					dano = tempcorredor->defensa(dano);
					if (dano == 0){
						break;
					}else if(dano == -1 || dano > 0){
						tablero.erase(tablero.begin()+i);
						delete tempcorredor;
						muertes += 1;
					}
				}else if(dynamic_cast<Zombie*>(tablero[i]) != NULL){
					Zombie* tempzombie = dynamic_cast<Zombie*>(tablero[i]);
					dano = tempzombie->defensa(dano);
					if (dano == 0){
						break;
					}else if(dano == -1 || dano > 0){
						tablero.erase(tablero.begin()+i);
						delete tempzombie;
						muertes += 1;
					}
				}
			}
		}
	}
	return muertes;
}
int ataquezombies(vector<Padre*>& tablero){
	for(int y = 0; y < 5; y++){
		for(int x = 1; x < 8;x++){
			for(int i = 0; i < tablero.size();i++){
				if(tablero[i]->getx() == x && tablero[i]->gety() == y){
					if(dynamic_cast<Portero*>(tablero[i]) != NULL){
						Portero* tempportero = dynamic_cast<Portero*>(tablero[i]);
						for(int j = 0; j < tablero.size();j++){
							if(tablero[j]->getx() == x-1 && tablero[j]->gety() == y){
								if(dynamic_cast<Cherry*>(tablero[j]) != NULL){
									Cherry* tempcherry = dynamic_cast<Cherry*>(tablero[j]);
									if(tempcherry->defensa(tempportero->ataque()) > 0 || tempcherry->defensa(tempportero->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempcherry;
									}
								}else if(dynamic_cast<Papa*>(tablero[j]) != NULL){
									Papa* temppapa = dynamic_cast<Papa*>(tablero[j]);
									if(temppapa->defensa(tempportero->ataque()) > 0 || temppapa->defensa(tempportero->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete temppapa;
									}
								}else if(dynamic_cast<Planta*>(tablero[j]) != NULL){
									Planta* tempplanta = dynamic_cast<Planta*>(tablero[j]);
									if(tempplanta->defensa(tempportero->ataque()) > 0 || tempplanta->defensa(tempportero->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempplanta;
									}
								}
							}
						}
					}else if(dynamic_cast<Corredor*>(tablero[i]) != NULL){
						Corredor* tempcorredor = dynamic_cast<Corredor*>(tablero[i]);
						for(int j = 0; j < tablero.size();j++){
							if(tablero[j]->getx() == x-1 && tablero[j]->gety() == y){
								if(dynamic_cast<Cherry*>(tablero[j]) != NULL){
									Cherry* tempcherry = dynamic_cast<Cherry*>(tablero[j]);
									if(tempcherry->defensa(tempcorredor->ataque()) > 0 || tempcherry->defensa(tempcorredor->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempcherry;
									}
								}else if(dynamic_cast<Papa*>(tablero[j]) != NULL){
									Papa* temppapa = dynamic_cast<Papa*>(tablero[j]);
									if(temppapa->defensa(tempcorredor->ataque()) > 0 || temppapa->defensa(tempcorredor->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete temppapa;
									}
								}else if(dynamic_cast<Planta*>(tablero[j]) != NULL){
									Planta* tempplanta = dynamic_cast<Planta*>(tablero[j]);
									if(tempplanta->defensa(tempcorredor->ataque()) > 0 || tempplanta->defensa(tempcorredor->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempplanta;
									}
								}
							}
						}
					}else if(dynamic_cast<Zombie*>(tablero[i]) != NULL){
						Zombie* tempzombie = dynamic_cast<Zombie*>(tablero[i]);
						for(int j = 0; j < tablero.size();j++){
							if(tablero[j]->getx() == x-1 && tablero[j]->gety() == y){
								if(dynamic_cast<Cherry*>(tablero[j]) != NULL){
									Cherry* tempcherry = dynamic_cast<Cherry*>(tablero[j]);
									if(tempcherry->defensa(tempzombie->ataque()) > 0 || tempcherry->defensa(tempzombie->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempcherry;
									}
								}else if(dynamic_cast<Papa*>(tablero[j]) != NULL){
									Papa* temppapa = dynamic_cast<Papa*>(tablero[j]);
									if(temppapa->defensa(tempzombie->ataque()) > 0 || temppapa->defensa(tempzombie->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete temppapa;
									}
								}else if(dynamic_cast<Planta*>(tablero[j]) != NULL){
									Planta* tempplanta = dynamic_cast<Planta*>(tablero[j]);
									if(tempplanta->defensa(tempzombie->ataque()) > 0 || tempplanta->defensa(tempzombie->ataque()) == -1){
										tablero.erase(tablero.begin()+j);
										delete tempplanta;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
