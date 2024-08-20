#pragma once
#include "map.h"
#include "gameui.h"
class mapmain5 :
	public map
{
public:
	gameui winloss;

	mapmain5();

	void drawmap();

	//void map5game();
};
