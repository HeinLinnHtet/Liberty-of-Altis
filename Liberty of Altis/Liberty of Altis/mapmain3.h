#pragma once
#include "map.h"
class mapmain3 :
	public map
{


private:

	const static int Amt_Trees = 10;
	const static int Amt_House = 27;

	static environmentalObjs* trees[Amt_Trees];
	static environmentalObjs* houses[Amt_House];


public:
	mapmain3();

	void drawmap();

	void map3game(void);
};


