#include "mapmain2.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"
#include "towers.h"

mapmain2::mapmain2()
{

}

void mapmain2::drawmap()
{
	bool objexist = false;

	//prison walls vertical
	walls* wallver[8];
	wallver[0] = new walls(100, char(219), 14, 2);
	wallver[1] = new walls(100, char(219), 14, 5);
	wallver[2] = new walls(100, char(219), 14, 8);
	wallver[3] = new walls(100, char(219), 14, 11);
	wallver[4] = new walls(100, char(219), 14, 14);
	wallver[5] = new walls(100, char(219), 14, 15);

	//virgil cage
	wallver[6] = new walls(100, char(178), 4, 8);
	wallver[7] = new walls(100, char(178), 4, 9);

	//prison walls horizontal
	walls* wallhor[14];
	wallhor[0] = new walls(100,char(219), 1, 1);
	wallhor[1] = new walls(100,char(219), 4, 1);
	wallhor[2] = new walls(100,char(219), 7, 1);
	wallhor[3] = new walls(100,char(219), 10, 1);
	wallhor[4] = new walls(100, char(219), 13, 1);
	
	wallhor[5] = new walls(100, char(219), 1, 16);
	wallhor[6] = new walls(100, char(219), 4, 16);
	wallhor[7] = new walls(100, char(219), 7, 16);
	wallhor[8] = new walls(100, char(219), 10, 16);
	wallhor[9] = new walls(100, char(219), 13, 16);

	//virgil cage
	wallhor[10] = new walls(100, char(219), 1, 6);
	wallhor[11] = new walls(100, char(219), 3, 6);
	wallhor[12] = new walls(100, char(219), 1, 11);
	wallhor[13] = new walls(100, char(219), 3, 11);

	//barricade
	environmentalObjs* barricade[12];
	for (int i = 0; i < 4; i++)
	{
		barricade[i] = new environmentalObjs(char(178), 21, i + 3);
	}
	for (int i = 4; i < 8; i++)
	{
		barricade[i] = new environmentalObjs(char(178), 24, i + 9);
	}
	for (int i = 8; i < 12; i++)
	{
		barricade[i] = new environmentalObjs(char(178), 30, i);
	}

	towers* tower[2];
	tower[0] = new towers(15, 5, 100, char(219), 12, 3);
	tower[1] = new towers(15, 5, 100, char(219), 12, 14);
	
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

			//vertical walls
			for (int k = 0; k < 8; k++)
			{
				//check if the color is for walls or cage
				color(0x04);
				if (k > 5)
				{
					color(0x08);
				}

				if (wallver[k]->getx() == i and wallver[k]->gety() == j)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}

				if (wallver[k]->getx() == i and wallver[k]->gety() == j + 1)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}
				if (wallver[k]->getx() == i and wallver[k]->gety() == j - 1)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}

				if (wallver[k]->getx() == i - 1 and wallver[k]->gety() == j)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}

				if (wallver[k]->getx() == i - 1 and wallver[k]->gety() == j + 1)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}
				if (wallver[k]->getx() == i - 1 and wallver[k]->gety() == j - 1)
				{
					std::cout << wallver[k]->getsymbol();
					objexist = true;
				}
			}

			//horizontal walls
			for (int k = 0; k < 14; k++)
			{
				//check if the color is for walls or cage
				color(0x04);
				if (k > 9)
				{
					color(0x08);
				}

				if (wallhor[k]->getx() == i and wallhor[k]->gety() == j)
				{
					std::cout << wallhor[k]->getsymbol();
					objexist = true;
				}

				if (wallhor[k]->getx() == i + 1 and wallhor[k]->gety() == j)
				{
					std::cout << wallhor[k]->getsymbol();
					objexist = true;
				}
				if (wallhor[k]->getx() == i - 1 and wallhor[k]->gety() == j)
				{
					std::cout << wallhor[k]->getsymbol();
					objexist = true;
				}
			}

			//barricade
			for (int k = 0; k < 12; k++)
			{
				color(0x08);

				if (barricade[k]->getx() == i and barricade[k]->gety() == j)
				{
					std::cout << barricade[k]->getsymbol();
					objexist = true;
				}
			}

			//towers
			for (int k = 0; k < 2; k++)
			{
				color(0x0E);

				if (tower[k]->getx() == i and tower[k]->gety() == j)
				{
					std::cout << tower[k]->getsymbol();
					objexist = true;
				}
				if (tower[k]->getx() == i - 1 and tower[k]->gety() == j)
				{
					std::cout << tower[k]->getsymbol();
					objexist = true;
				}
			}

			if (!objexist)
			{
				if (i == 2 && j == 8)
				{
					color(0x09);
					std::cout << "V";
				}
				else if( i < 14 && j < 16 && j > 1)
				{
					color(0x0C);
				}
				else
				{
					color(0x08);
				}
				std::cout << char(219);
			}
		}
	}

	tower[0]->attack();
	tower[1]->attack();
}