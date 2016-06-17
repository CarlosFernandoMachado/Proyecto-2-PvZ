#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Cherry : public Planta{
	bool doubledmg;
public:
	Cherry(int=200,int=150,int=150,bool=true);
	virtual ~Cherry();
	virtual int ataque();
	virtual int defensa(int);
	virtual int getcosto();
	virtual string descripcion();
	virtual string tostring();
};
