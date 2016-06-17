#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Papa : public Planta{
	int escudo;
public:
	Papa(int=200,int=100,int=25,int=200);
	virtual ~Papa();
	virtual int ataque();
	virtual int defensa(int);
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
