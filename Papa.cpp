#include "Planta.h"
#include "Papa.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Papa::Papa(int costo,int vida,int dano,int escudo):Planta(costo,vida,dano),escudo(escudo){}
Papa::~Papa(){}
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
	ss << "Papa PA\nHP: 100\nDano: 25\nCosto: 200\nEscudo: 200";
	return ss.str();
}
string Papa::tostring(){
	return "PA";
}
