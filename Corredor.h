#include "Zombie.h"
#pragma once
#include <string>

using std::string;

class Corredor : public Zombie{
public:
	Corredor(int,int,int=150,int=200,int=50,int=0);
	virtual ~Corredor();
	virtual int getx();
	virtual int gety();
	virtual void setx(int);
	virtual int ataque();
	virtual int defensa(int);
	virtual int move();
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
