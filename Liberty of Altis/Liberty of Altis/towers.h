#pragma once
#include "environmentalObjs.h"
#include "Entity.h"
#include"Position.h"

class towers : public environmentalObjs
{
private:
	int health;
	int damage;
	int range;
public:
	towers(int h, int d, int r, char sym, int xp, int yp);

	void sethealth(int newh);
	int gethealth();

	void setdamage();
	int getdamage();

	void setrange();
	int getrange();

	void attack(Entity& target);
};
