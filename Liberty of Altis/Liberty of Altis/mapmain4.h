#pragma once
#include "map.h"
class mapmain4 :
	public map
{

private:

	const static int Amt_Build = 950;
	static environmentalObjs* buildings[Amt_Build];

	//total number of enemies in this level
	static int Amt_Lvl4_Enemy;

	static int Amt_Lvl4_Allies;

	int alliesdead, enemiesdead;

public:
	mapmain4();

	void drawmap();

	//void map4game(void);
};


