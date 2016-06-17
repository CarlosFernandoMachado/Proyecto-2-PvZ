#include "Padre.h"
#pragma once
#include <string>

using std::string;

class Zombie : public Padre{
	int avanzar;
public:
	Zombie(int=50,int=150,int=50,int=1);
	virtual ~Zombie();
	virtual int ataque();
	virtual int defensa(int);
	virtual int move();
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
