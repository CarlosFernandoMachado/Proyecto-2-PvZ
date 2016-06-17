#include "Zombie.h"
#pragma once
#include <string>

using std::string;

class Portero : public Zombie{
	int casco;
public:
	Portero(int=300,int=300,int=100,int=0,int=200);
	virtual ~Portero();
	virtual int ataque();
	virtual int defensa(int);
	virtual int move();
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
