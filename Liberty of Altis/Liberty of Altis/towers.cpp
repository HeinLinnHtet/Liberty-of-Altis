#include "towers.h"
#include "environmentalObjs.h"
#include "Position.h"
#include "Entity.h"

towers::towers(int h, int d, int r, char sym, int xp, int yp) : health(h), damage(d), range(r), environmentalObjs(sym, xp, yp)
{
}

void towers::sethealth(int newh)
{
	health = newh;
}

int towers::gethealth()
{
	return health;
}

void towers::attack(Entity& target)
{
	if (target.PosXY.attackrange(target.PosXY, range)) {
		target.SetHealth(target.GetHealth() - damage);
	}
}