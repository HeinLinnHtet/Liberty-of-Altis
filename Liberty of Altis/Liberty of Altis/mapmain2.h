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




public:
	mapmain2();

	void drawmap();

	void map2game(void);
};


