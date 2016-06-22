#include "Padre.h"
#pragma once
#include <string>

using std::string;

class Planta : public Padre{
public:
	Planta(int,int,int=50,int=100,int=50);
	virtual ~Planta();
	virtual int getx();
	virtual int gety();
	virtual int ataque();
	virtual int defensa(int);
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
