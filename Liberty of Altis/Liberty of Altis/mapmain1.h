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

public :
	mapmain1();
	void drawmap();

	//start level 1 
	void map1game(void);

};

