#pragma once
#include "environmentalObjs.h"

class walls : public environmentalObjs
{
private:
	int health;
public:
	walls(int h, char sym, int xp, int yp);

	void sethealth();
	int gethealth();
};

