#pragma once
#include "map.h"
class mapmain4 :
	public map
{

private:

	const static int Amt_Build = 949;
	static environmentalObjs* buildings[Amt_Build];


	int alliesdead, enemiesdead;

public:
	mapmain4();

	void drawmap();

	void map4game(void);

	//Check collisions
	bool CheckBorder(Entity& main, char direction);

	//Check attacking collision with enviroment 
	bool CheckAttack(Entity& main, Entity& other, char direction);

	//Check Enviromental collisions
	bool CheckEnviroCollide(Entity& main, char direction);

	//Check attacking collision with enviroment but for enemies 
	bool EnemyCheckAtk(Entity& ally, Entity& Enemy);

};


