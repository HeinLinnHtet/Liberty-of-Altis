#pragma once
#include "map.h"
class mapmain4 :
	public map
{

private:

	const static int Amt_Build = 950;
	static environmentalObjs* buildings[Amt_Build];



public:
	mapmain4();

	void drawmap();

	void map4game(void);
};


