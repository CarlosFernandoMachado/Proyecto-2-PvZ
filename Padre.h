#pragma once
#include <string>

using std::string;

class Padre{
protected:
	int x,y,costo,vida,dano;
public:
	Padre(int,int,int,int,int);
	virtual ~Padre();
	virtual int getx()=0;
	virtual int gety()=0;
	virtual int ataque()=0;
	virtual int defensa(int)=0;
	virtual int getcosto()=0;
	virtual string descripcion()=0;
	virtual string tostring()=0;
};
