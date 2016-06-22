#include "Planta.h"
#include "Papa.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Papa::Papa(int x,int y,int costo,int vida,int dano,int escudo):Planta(x,y,costo,vida,dano),escudo(escudo){}
Papa::~Papa(){}
int Papa::getx(){
	return x;
}
int Papa::gety(){
	return y;
}
int Papa::ataque(){
	return dano;
}
int Papa::defensa(int dano){
	if(escudo > dano){
		escudo -= dano;
		return 0;
	}else if(dano > escudo){
		dano -= escudo;
		escudo = 0;
		if(vida > dano){
			vida -= dano;
			return 0;
		}else if(dano > vida){
			dano -= vida;
			return dano;
		}else{
			return -1;
		}
	}else{
		escudo = 0;
		return 0;
	}
	return 0;
}
int Papa::getcosto(){
	return costo;
}
string Papa::descripcion(){
	stringstream ss;
	ss << "Papa PA\nHP: 200\nDano: 25\nCosto: 150\nEscudo: 200\nEscudo bloquea dano";
	return ss.str();
}
string Papa::tostring(){
	return "PA";
}
