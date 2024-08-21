#pragma once
#include "map.h"
#include "gameui.h"
class mapmain5 : public map
{
private:
	const static int Amt_Props = 356;

	static environmentalObjs* props[Amt_Props];

	//total number of enemies in this level
	static int Amt_Lvl5_Enemy;

	static int Amt_Lvl5_Allies;

	int alliesdead, enemiesdead;

	static bool GameOver;

public:
	gameui winloss;

	mapmain5();

	void drawmap();

	void map5game(int rifleamount,
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

	bool GetGameOver(void);
};
