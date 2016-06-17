#include "Portero.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Portero::Portero(int costo,int vida,int dano,int avanzar,int casco):Zombie(costo,vida,dano,avanzar),casco(casco){}
Portero::~Portero(){}
int Portero::ataque(){
	return dano;
}
int Portero::defensa(int dano){
	if(casco > dano){
		casco -= dano;
		return 0;
	}else if(dano > casco){
		dano -= casco;
		casco = 0;
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
		casco = 0;
		return 0;
	}
	return 0;
}
int Portero::move(){
	avanzar += 1;
	return avanzar;
}
int Portero::getcosto(){
	return costo;
}
string Portero::descripcion(){
	stringstream ss;
	ss << "Portero PO\nHP: 300\nDano: 100\nCosto: 300\nAvanzar: 1 bloque\nCasco: 300\nCada turno se mueve un espacio mas, Casco bloquea dano";
	return ss.str();
}
string Portero::tostring(){
	return "PO";
}
