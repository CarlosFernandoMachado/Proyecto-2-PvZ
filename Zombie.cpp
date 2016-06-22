#include "Padre.h"
#include "Zombie.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Zombie::Zombie(int x,int y,int costo,int vida,int dano,int avanzar):Padre(x,y,costo,vida,dano),avanzar(avanzar){}
Zombie::~Zombie(){}
int Zombie::getx(){
	return x;
}
int Zombie::gety(){
	return y;
}
void Zombie::setx(int x){
	this->x = x;
}
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
	ss << "Zombie Normal ZO\nHP: 150\nDano: 50\nCosto: 50\nAvance: 1 bloque";
	return ss.str();
}
string Zombie::tostring(){
	return "ZO";
}
