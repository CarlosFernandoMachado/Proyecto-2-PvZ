#include "Planta.h"
#include "Cherry.h"
#include <iostream>
#include <sstream>
#include <string>

using std::stringstream;
using std::string;

Cherry::Cherry(int x,int y,int costo,int vida,int dano,bool doubledmg):Planta(x,y,costo,vida,dano),doubledmg(doubledmg){}
Cherry::~Cherry(){}
int Cherry::getx(){
	return x;
}
int Cherry::gety(){
	return y;
}
int Cherry::ataque(){
	if(doubledmg){
		doubledmg = false;
		return (dano*2);
	}else{
		doubledmg = true;
		return dano;
	}
	return dano;
}
int Cherry::defensa(int dano){
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
int Cherry::getcosto(){
	return costo;
}
string Cherry::descripcion(){
	stringstream ss;
	ss << "Cherry CH\nHP: 150\nDano: 150 o 300\nCosto: 200\nSu ataque va alternando";
	return ss.str();
}
string Cherry::tostring(){
	return "CH";
}
