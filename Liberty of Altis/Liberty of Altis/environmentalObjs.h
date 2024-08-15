#pragma once
#include "Position.h"
class environmentalObjs
{
private:
	char objsymbol;
public :
	Position objPos;

	environmentalObjs(char sym, int xp, int yp);
	environmentalObjs();

	char getsymbol();
	int getx();
	int gety();

	void drawEnvObj();
};

