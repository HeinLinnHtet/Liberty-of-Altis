#include "environmentalObjs.h"
#include <iostream>

environmentalObjs::environmentalObjs(char sym, int xp, int yp)
{
	objsymbol = sym;
	objPos.SetX(xp);
	objPos.SetY(yp);
}

environmentalObjs::environmentalObjs()
{

}

void environmentalObjs::drawEnvObj()
{
	std::cout << objsymbol;
}

char environmentalObjs::getsymbol()
{
	return objsymbol;
}

int environmentalObjs::getx()
{
	return objPos.GetX();
}

int environmentalObjs::gety()
{
	return objPos.GetY();
}

