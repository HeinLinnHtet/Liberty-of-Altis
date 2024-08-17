#include "mapmain5.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"

mapmain5::mapmain5()
{

}

void mapmain5::drawmap()
{
	bool objexist = false;

	environmentalObjs* props[356];
	for (int i = 0; i < 50; i++)
	{
		props[i] = new environmentalObjs(char(219), i, 0);
		props[i + 50] = new environmentalObjs(char(219), i, 17);
	}
	for (int i = 0; i < 6; i++)
	{
		props[i + 100] = new environmentalObjs(char(219), 49, i + 1);
		props[i + 106] = new environmentalObjs(char(219), 49, i + 11);
	}
	for (int i = 0; i < 18; i++)
	{
		props[i + 112] = new environmentalObjs(char(219), 0, i + 1);
	}

	//door
	props[130] = new environmentalObjs(char(219), 48, 5);
	props[131] = new environmentalObjs(char(219), 48, 6);

	props[132] = new environmentalObjs(char(219), 48, 11);
	props[133] = new environmentalObjs(char(219), 48, 12);

	//tables
	//middle table
	for (int i = 0; i < 28; i++)
	{
		props[i + 134] = new environmentalObjs(char(219), i + 9, 1);
		props[i + 162] = new environmentalObjs(char(219), i + 9, 3);
		props[i + 190] = new environmentalObjs(char(219), i + 9, 5);
		props[i + 218] = new environmentalObjs(char(219), i + 9, 12);
		props[i + 246] = new environmentalObjs(char(219), i + 9, 14);
		props[i + 274] = new environmentalObjs(char(219), i + 9, 16);
	}

	//table near the door
	for (int i = 0; i < 5; i++)
	{
		props[i + 302] = new environmentalObjs(char(219), 40, i + 1);
		props[i + 307] = new environmentalObjs(char(219), 41, i + 1);

		props[i + 312] = new environmentalObjs(char(219), 44, i + 1);
		props[i + 317] = new environmentalObjs(char(219), 45, i + 1);

		props[i + 322] = new environmentalObjs(char(219), 40, i + 12);
		props[i + 327] = new environmentalObjs(char(219), 41, i + 12);

		props[i + 332] = new environmentalObjs(char(219), 44, i + 12);
		props[i + 337] = new environmentalObjs(char(219), 45, i + 12);
	}

	//middle table
	//sides
	for (int i = 0; i < 5; i++)
	{
		props[i + 342] = new environmentalObjs(char(219), i + 5, 7);
		props[i + 347] = new environmentalObjs(char(219), i + 5, 10);
	}
	//middle
	props[352] = new environmentalObjs(char(219), 8, 8);
	props[353] = new environmentalObjs(char(219), 9, 8);

	props[354] = new environmentalObjs(char(219), 8, 9);
	props[355] = new environmentalObjs(char(219), 9, 9);

	walls* barricade[8];
	//top
	barricade[0] = new walls(100, char(219), 23, 2);
	barricade[1] = new walls(100, char(219), 23, 4);
	//bottom
	barricade[2] = new walls(100, char(219), 23, 13);
	barricade[3] = new walls(100, char(219), 23, 15);
	//middle
	barricade[4] = new walls(100, char(219), 18, 6);
	barricade[5] = new walls(100, char(219), 21, 6);
	barricade[6] = new walls(100, char(219), 24, 6);
	barricade[7] = new walls(100, char(219), 27, 6);

	//border
	color(0x0F);
	for (int i = 4; i < 54; i++)
	{
		gotoxy(i, 0);
		std::cout << char(205);
		gotoxy(i, 19);
		std::cout << char(205);
	}
	for (int i = 1; i < 19; i++)
	{
		gotoxy(3, i);
		std::cout << char(186);
		gotoxy(54, i);
		std::cout << char(186);
	}

	//top left corner
	gotoxy(3, 0);
	std::cout << char(201);
	//bottom left corner
	gotoxy(3, 19);
	std::cout << char(200);
	//top right corner
	gotoxy(54, 0);
	std::cout << char(187);
	//bottom right corner
	gotoxy(54, 19);
	std::cout << char(188);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			gotoxy(i + 4, j + 1);
			objexist = false;

			//normal environmental objects
			for (int k = 0; k < 356; k++)
			{
				//outer wall color
				color(0x08);
				//check color for the door
				if (k > 129 && k < 134)
				{
					color(0x0F);
				}
				//check color for tables 
				if (k > 133)
				{
					color(0x0E);
				}
				if (props[k]->getx() == i and props[k]->gety() == j)
				{
					std::cout << props[k]->getsymbol();
					objexist = true;
				}
			}

			//barricade
			for (int k = 0; k < 8; k++)
			{
				if (barricade[k]->getx() == i and barricade[k]->gety() == j)
				{
					color(0x08);
					std::cout << barricade[k]->getsymbol();
					objexist = true;
				}
				//longer barricade
				if (k > 3)
				{
					for (int l = 0; l < 6; l++)
						if (barricade[k]->getx() == i and barricade[k]->gety() + l == j)
						{
							color(0x08);
							std::cout << barricade[k]->getsymbol();
							objexist = true;
						}
				}
			}

			if (!objexist)
			{
				color(0x0C);
				std::cout << char(219);
			}
		}
	}
}