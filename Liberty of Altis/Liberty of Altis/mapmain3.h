#pragma once
#include "map.h"
#include "gameui.h"
class mapmain3 :
	public map
{


private:

	const static int Amt_Trees = 10;
	const static int Amt_House = 67;

	static environmentalObjs* trees[Amt_Trees];
	static environmentalObjs* houses[Amt_House];

	//total number of enemies in this level
	static int Amt_Lvl3_Enemy;

	static int Amt_Lvl3_Allies;

	int alliesdead, enemiesdead;


public:
	gameui winloss;

	mapmain3();

	void drawmap();

	void map3game(
	int rifleamount,
	int mcgunamount,
	int grendamount,
	int motaramount,
	int artilamount,
	int tankamount,
	int ifvamount);

	static const int numberofenemies = 10;

	//Check attacking collision with enviroment 
	bool CheckAttack(Entity& main, Entity& other, char direction);

	//Check attacking collision with enviroment but for enemies 
	bool EnemyCheckAtk(Entity& ally, Entity& Enemy);

	//Check Enviromental collisions
	bool CheckEnviroCollide(Entity& main, char direction);
};


