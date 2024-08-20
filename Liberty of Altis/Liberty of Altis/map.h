#pragma once
#include "environmentalObjs.h"
#include "gameui.h"
#include "walls.h"
#include "towers.h"
#include "ARiflesman.h"
#include "AArtillery.h"
#include "AGrenadier.h"
#include "AMachinegunner.h"
#include "ATank.h"
#include "AMotar.h"
#include "AIFV.h"

#include "ERiflesman.h"
#include "EArtillery.h"
#include "EGrenadier.h"
#include "EMachinegunner.h"
#include "ETank.h"
#include "EMotar.h"
#include "EIFV.h"

#include <conio.h> // for _getch
#include <windows.h>
#include <iostream>


class map :
	public environmentalObjs
{
public :
	map();

	void gotoxy(int x, int y);
	virtual void drawmap();
	void color(int c);

	//ensure entity correcly moved on screen
	void MoveEntity(Entity& entity, char input);

	//Set starting positions for entity
	void SetStartPos(Entity& entity, int x, int y);

	//Check collision between entity and enviromnet
	bool EnviroEntityCollide(Entity& entity, environmentalObjs& obj, char direction);
};

