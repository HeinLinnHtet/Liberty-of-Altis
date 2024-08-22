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
	color(0x0F);
	std::cout << "X";
	entity.Movement(input);
	gotoxy(entity.PosXY.GetX(), entity.PosXY.GetY());
	color(0x09);
	std::cout << entity.Draw_Icon();
}

//Sets starting position for entity 
void map::SetStartPos(Entity& entity, int x, int y)
{
	entity.SetPosition(x, y);
	gotoxy(x, y);
	std::cout << entity.Draw_Icon();
}

//Check if entity if collide with obj 
bool map::EnviroEntityCollide(Entity& entity, environmentalObjs& obj, char direction)
{
	direction = toupper(direction);

	//store position
	int XEntity = entity.PosXY.GetX();
	int YEntity = entity.PosXY.GetY();
	int XEnviro = obj.objPos.GetX();
	int YEnviro = obj.objPos.GetY();

	bool result = false;

	//tank and artilery
	if (entity.Draw_Icon() == 'T' || entity.Draw_Icon() == 'A')
	{
		//Check if entity is LR of each other 
		if (XEntity == XEnviro) {
			//Down 
			if ((YEntity == YEnviro - 1) && direction == 'S') {
				result = true;
			}
			//Up
			else if ((YEntity == YEnviro + 2) && direction == 'W') {
				result = true;
			}
			else
				result = false;
		}
		if (XEntity == XEnviro + 1) {
			//Down 
			if ((YEntity == YEnviro - 1) && direction == 'S') {
				result = true;
			}
			//Up
			else if ((YEntity == YEnviro + 2) && direction == 'W') {
				result = true;
			}
			else
				result = false;
		}

		//Check if entity if UP of each other 
		if (YEntity == YEnviro) {
			//Right
			if ((XEntity == XEnviro - 1) && direction == 'D') {
				result = true;
			}
			//Left
			else if ((XEntity == XEnviro + 2) && direction == 'A') {
				result = true;
			}
			else
				result = false;
		}
		if (YEntity == YEnviro - 1) {
			//Right
			if ((XEntity == XEnviro - 1) && direction == 'D') {
				result = true;
			}
			//Left
			else if ((XEntity == XEnviro + 2) && direction == 'A') {
				result = true;
			}
			else
				result = false;
		}
	}

	//other troops
	else
	{
		//Check if entity is LR of each other 
		if (XEntity == XEnviro) {
			//Down 
			if ((YEntity == YEnviro - 1) && direction == 'S') {
				result = true;
			}
			//Up
			else if ((YEntity == YEnviro + 1) && direction == 'W') {
				result = true;
			}
			else
				result = false;
		}
		//Check if entity if UP of each other 
		if (YEntity == YEnviro) {
			//Right
			if ((XEntity == XEnviro - 1) && direction == 'D') {
				result = true;
			}
			//Left
			else if ((XEntity == XEnviro + 1) && direction == 'A') {
				result = true;
			}
			else
				result = false;
		}
	}
	
	return result;
}

//Check border collison
bool map::ABorderCollision(Entity& entity, char direction)
{
	direction = toupper(direction);

	int result = false;
	//tanks and artilery

		//Up 
		if (direction == 'W') {
			if (entity.PosXY.GetY() - 1 == 0) {
				result = true;
			}
		}
		//Down
		else if (direction == 'S') {
			if (entity.PosXY.GetY() + 1 == 19) {
				result = true;
			}
		}
		//left
		else if (direction == 'D') {
			if (entity.PosXY.GetX() + 1 == 54) {
				result = true;
			}
		}
		//right 
		else if (direction == 'A') {
			if (entity.PosXY.GetX() - 1 == 3) {
				result = true;
			}
		}


	return result;
}

bool map::EBorderCollision(Entity& entity, char direction)
{

	int result = false;
	//tanks and artilery
		//Up 
		if (direction == '0') {
			if (entity.PosXY.GetY() - 1 == 0) {
				result = true;
			}
		}
		//Down
		else if (direction == '1') {
			if (entity.PosXY.GetY() + 1 == 19) {
				result = true;
			}
		}
		//left
		else if (direction == '2') {
			if (entity.PosXY.GetX() + 1 == 54) {
				result = true;
			}
		}
		//right 
		else if (direction == '3') {
			if (entity.PosXY.GetX() - 1 == 3) {
				result = true;
			}
		}

	return result;
}

