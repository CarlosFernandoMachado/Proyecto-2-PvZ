#include "Zombie.h"
#include "Corredor.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Corredor::Corredor(int costo,int vida,int dano,int avanzar):Zombie(costo,vida,dano,avanzar){}
Corredor::~Corredor(){}
int Corredor::ataque(){
	return dano;
}
int Corredor::defensa(int dano){
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
int Corredor::move(){
	avanzar += 1;
	return avanzar;
}
int Corredor::getcosto(){
	return costo;
}
string Corredor::descripcion(){
	stringstream ss;
	ss << "Corredor CO\nHP: 200\nDano: 50\nCosto: 150\nAvanzar: 1 bloque\nCada turno se mueve un espacio mas";
	return ss.str();
}
string Corredor::tostring(){
	return "CO";
}
