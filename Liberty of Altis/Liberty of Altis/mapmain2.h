#pragma once
#include "map.h"
class mapmain2 :
	public map
{

private:
	const static int Amt_WallVer = 8;
	const static int Amt_WallHor = 14;
	const static int Amt_Barricade = 12;
	const static int Amt_Tower = 2;

	static walls* wallver[Amt_WallVer];
	static walls* wallhor[Amt_WallHor];
	static environmentalObjs* barricade[Amt_Barricade];
	static towers* tower[Amt_Tower];


	int alliesdead, enemiesdead;

public:
	mapmain2();

	void drawmap();

	void map2game(void);

	//Check attacking collision with enviroment 
	bool CheckAttack(Entity& main, Entity& other, char direction);

	//Check attacking collision with enviroment but for enemies 
	bool EnemyCheckAtk(Entity& ally, Entity& Enemy);

	//Check Enviromental collisions
	bool CheckEnviroCollide(Entity& main, char direction);
};


