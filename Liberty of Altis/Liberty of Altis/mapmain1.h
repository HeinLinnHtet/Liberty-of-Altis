#pragma once
#include "map.h"
#include "Position.h"
#include "environmentalObjs.h"

class mapmain1 :
	public map
{

private:
	//store total amt of objects
	const static int AmtofObjs = 48;

	//Array pointer of trees
	static environmentalObjs* trees[AmtofObjs];

	//total number of enemies in this level
	static int Amt_Lvl1_Enemy;

	static int Amt_Lvl1_Allies;

	int alliesdead, enemiesdead;

	gameui winloss;
public :
	mapmain1();
	void drawmap();

	//start level 1 
	void map1game(void);

	//Check attacking collision with enviroment 
	bool CheckAttack(Entity& main, Entity& other, char direction);

	//Check attacking collision with enviroment but for enemies 
	bool EnemyCheckAtk(Entity& ally, Entity& Enemy);

	//Check Enviromental collisions
	bool CheckEnviroCollide(Entity& main, char direction);
};

