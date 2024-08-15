#include "map.h"
#include <windows.h>
#include <iostream>

map::map()
{

}

void map::gotoxy(int x, int y) {
	COORD srcn;
	HANDLE userhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	srcn.X = x; srcn.Y = y;
	SetConsoleCursorPosition(userhandle, srcn);
}

void map::color(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}

void map::drawmap()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			gotoxy(i * 2, j);
			color(0x0A);
			std::cout << "*";
			color(0x08);
		}
	}
}

//Function to correcly display entity movement 
void map::MoveEntity(Entity& entity, char input)
{
	gotoxy(entity.PosXY.GetX(), entity.PosXY.GetY());
	std::cout << "X";
	entity.Movement(input);
	gotoxy(entity.PosXY.GetX(), entity.PosXY.GetY());
	std::cout << entity.Draw_Icon();
}

//Sets starting position for entity 
void map::SetStartPos(Entity& entity, int x, int y)
{
	gotoxy(x, y);
	entity.SetPosition(x, y);
	std::cout << entity.Draw_Icon();
}

//Check if entity if collide with obj 
bool map::EnviroEntityCollide(Entity& entity, environmentalObjs& obj, char direction)
{
	//store position
	int XEntity = entity.PosXY.GetX();
	int YEntity = entity.PosXY.GetY();
	int XEnviro = obj.getx();
	int YEnviro = obj.gety();

	bool result = false;

	//Check if entity is LR of each other 
	if (XEntity == XEnviro) {
		//Down 
		if ((YEntity == YEnviro - 1) && direction == 'S')  {
			result = true;
		}
		//Up
		else if ((YEntity == YEnviro + 1) && direction == 'W') {
			result = true;
		}
		else 
			result  = false;
	}
	//Check if entity if UP of each other 
	if (YEntity == YEnviro) {
		//Right
		if ((XEntity == XEntity - 1) && direction == 'D') {
			result = true;
		}
		//Left
		else if ((XEntity == XEntity + 1) && direction == 'A') {
			result = true;
		}
		else
			result = false;
	}
	
	return result;
}

////Check all collisions                         ////////////////////Maybe remove
//void map::CheckAllCollide(Entity& entity, char input)
//{
//	//true if can move
//	bool result = false;d
//	
//	//Check border collisons
//	if (entity.BorderCollision(input) == false) {
//		result = true;
//	}
//	//Check entity collisons
//	if (entity.Entitycollision(entity, input) == false) {
//		result = true;
//	}
//	
//
//}
