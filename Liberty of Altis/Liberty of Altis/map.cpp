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