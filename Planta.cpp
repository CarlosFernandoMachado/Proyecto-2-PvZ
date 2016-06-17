#include "Padre.h"
#include "Planta.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Planta::Planta(int costo,int vida,int dano):Padre(costo,vida,dano){}
Planta::~Planta(){}
int Planta::ataque(){
	return dano;
}
int Planta::defensa(int dano){
	if(vida > dano){
		vida -= dano;
		return 0;
	}else if(dano > vida){
		dano -= vida;
		return dano;
	}else{
		return -1;
	}
	return 0;
}
int Planta::getcosto(){
	return costo;
}
string Planta::descripcion(){
	stringstream ss;
	ss << "Planta Normal PL\nHP: 100\nDano: 50\nCosto: 50";
	return ss.str();
}
string Planta::tostring(){
	return "PL";
}
