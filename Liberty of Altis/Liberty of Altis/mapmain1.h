#pragma once
#include "map.h"
#include "Position.h"
#include "environmentalObjs.h"

class mapmain1 :
	public map
{
public :
	mapmain1();
	void drawmap();

	//start level 1 
	void map1game(void);

	//ensure entity correcly moved on screen
	void MoveEntity(Entity& entity, char input);

	//Set starting positions for entity
	void SetStartPos(Entity& entity,int x, int y);

};

