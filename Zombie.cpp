#include "Padre.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Zombie::Zombie(int costo,int vida,int dano,int avanzar):Padre(costo,vida,dano),avanzar(avanzar){}
Zombie::~Zombie(){}
int Zombie::ataque(){
	return dano;
}
int Zombie::defensa(int dano){
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
int Zombie::move(){
	return avanzar;
}
int Zombie::getcosto(){
	return costo;
}
string Zombie::descripcion(){
	stringstream ss;
	ss << "Zombie Normal ZO\nHP: 150\nDano: 50\nCosto: 50";
	return ss.str();
}
string Zombie::tostring(){
	return "ZO";
}