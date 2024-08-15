#pragma once
#include "environmentalObjs.h"

class towers : public environmentalObjs
{
private:
	int health;
	int damage;
	int range;
public:
	towers(int h, int d, int r, char sym, int xp, int yp);

	void sethealth();
	int gethealth();

	void setdamage();
	int getdamage();

	void setrange();
	int getrange();

	void attack();
};
