#pragma once
#include "environmentalObjs.h"
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



class map :
	public environmentalObjs
{
public :
	map();

	void gotoxy(int x, int y);
	virtual void drawmap();
	void color(int c);
};

