#include "mapmain3.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"

mapmain3::mapmain3()
{

}

void mapmain3::drawmap()
{
	bool objexist = false;

	int housexpos[9] = {
		9, 11, 5, 14, 15, 5, 16, 9, 3
	};
	int houseypos[9] = {
		2,  4, 4,  6,  4, 1,  1, 7, 8
	};

	int treexpos[10] = {
		8, 5, 23, 41, 32, 27, 19, 46, 38, 33
	};
	int treeypos[10] = {
		4, 6,  7, 12, 16,  5, 10, 14,  8,  6
	};

	environmentalObjs* trees[10];

	for (int i = 0; i < 10; i++)
	{
		trees[i] = new environmentalObjs(char(178), treexpos[i], treeypos[i]);
	}

	environmentalObjs* houses[27];
	for (int i = 0; i < 9; i++)
	{
		houses[i] = new environmentalObjs(char(176), housexpos[i], houseypos[i]);
		houses[i + 9] = new environmentalObjs(char(176), housexpos[i] + 1, houseypos[i]);
		houses[i + 18] = new environmentalObjs(char(176), housexpos[i] - 1, houseypos[i]);
	}

	walls* Ebase;
	Ebase = new walls(100, char(219), 5, 13);

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

			//house
			for (int k = 0; k < 27; k++)
			{
				color(0x0C);
				if (houses[k]->getx() == i and houses[k]->gety() == j)
				{
					std::cout << houses[k]->getsymbol();
					objexist = true;
				}
			}

			//trees
			for (int k = 0; k < 10; k++)
			{
				color(0x0A);
				if (trees[k]->getx() == i and trees[k]->gety() == j)
				{
					std::cout << trees[k]->getsymbol();
					objexist = true;
				}
			}

			//base
			color(0x08);
			if (Ebase->getx() == i and Ebase->gety() == j ||
				Ebase->getx() == i and Ebase->gety() == j + 1 ||
				Ebase->getx() == i and Ebase->gety() == j - 1 ||
				Ebase->getx() == i and Ebase->gety() == j + 2 ||
				Ebase->getx() == i and Ebase->gety() == j - 2 ||
				Ebase->getx() == i and Ebase->gety() == j + 3 ||
				Ebase->getx() == i and Ebase->gety() == j - 3 ||

				Ebase->getx() == i + 1 and Ebase->gety() == j ||
				Ebase->getx() == i + 1 and Ebase->gety() == j + 1 ||
				Ebase->getx() == i + 1 and Ebase->gety() == j - 1 ||
				Ebase->getx() == i + 1 and Ebase->gety() == j + 2 ||
				Ebase->getx() == i + 1 and Ebase->gety() == j - 2 ||
				Ebase->getx() == i + 1 and Ebase->gety() == j + 3 ||
				Ebase->getx() == i + 1 and Ebase->gety() == j - 3 ||

				Ebase->getx() == i - 1 and Ebase->gety() == j ||
				Ebase->getx() == i - 1 and Ebase->gety() == j - 1 ||
				Ebase->getx() == i - 1 and Ebase->gety() == j + 1 ||
				Ebase->getx() == i - 1 and Ebase->gety() == j - 2 ||
				Ebase->getx() == i - 1 and Ebase->gety() == j + 2 ||
				Ebase->getx() == i - 1 and Ebase->gety() == j - 3 ||
				Ebase->getx() == i - 1 and Ebase->gety() == j + 3 ||
				
				Ebase->getx() == i + 2 and Ebase->gety() == j ||
				Ebase->getx() == i + 2 and Ebase->gety() == j - 1 ||
				Ebase->getx() == i + 2 and Ebase->gety() == j + 1 ||
				Ebase->getx() == i + 2 and Ebase->gety() == j - 2 ||
				Ebase->getx() == i + 2 and Ebase->gety() == j + 2 ||
				Ebase->getx() == i + 2 and Ebase->gety() == j - 3 ||
				Ebase->getx() == i + 2 and Ebase->gety() == j + 3 ||

				Ebase->getx() == i - 2 and Ebase->gety() == j ||
				Ebase->getx() == i - 2 and Ebase->gety() == j - 1 ||
				Ebase->getx() == i - 2 and Ebase->gety() == j + 1 ||
				Ebase->getx() == i - 2 and Ebase->gety() == j - 2 ||
				Ebase->getx() == i - 2 and Ebase->gety() == j + 2 ||
				Ebase->getx() == i - 2 and Ebase->gety() == j - 3 ||
				Ebase->getx() == i - 2 and Ebase->gety() == j + 3 ||

				Ebase->getx() == i - 3 and Ebase->gety() == j ||
				Ebase->getx() == i - 3 and Ebase->gety() == j + 1 ||
				Ebase->getx() == i - 3 and Ebase->gety() == j - 1 ||
				Ebase->getx() == i - 3 and Ebase->gety() == j + 2 ||
				Ebase->getx() == i - 3 and Ebase->gety() == j - 2
				)
			{
				std::cout << Ebase->getsymbol();
				objexist = true;
			}
			//background
			if (!objexist)
			{
				color(0x0E);
				std::cout << char(178);
			}
		}
	}
}