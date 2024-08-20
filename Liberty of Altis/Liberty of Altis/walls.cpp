#include "walls.h"
#include "environmentalObjs.h"

walls::walls(int h, char sym, int xp, int yp) : health(h), environmentalObjs(sym, xp, yp)
{
}

void walls::sethealth(int a)
{
	health = a;
}

int walls::gethealth()
{
	return health;
}
