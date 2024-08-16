#include "mapmain4.h"
#include <iostream>
#include "environmentalObjs.h"

mapmain4::mapmain4()
{

}

void mapmain4::drawmap()
{
	bool objexist = false;

	environmentalObjs* buildings[950];

	//parliment
	for (int i = 0; i < 6; i++)
	{
		buildings[i] = new environmentalObjs(char(219), i + 37, 11);
		buildings[i + 6] = new environmentalObjs(char(219), i + 37, 12);
	}

	for (int i = 0; i < 6; i++)
	{
		buildings[i + 12] = new environmentalObjs(char(219), i + 37, 10);
		buildings[i + 18] = new environmentalObjs(char(219), i + 37, 9);
		buildings[i + 24] = new environmentalObjs(char(219), i + 37, 13);
		buildings[i + 30] = new environmentalObjs(char(219), i + 37, 14);
	}
	for (int i = 0; i < 4; i++)
	{
		buildings[i + 36] = new environmentalObjs(char(219), i + 33, 11);
		buildings[i + 40] = new environmentalObjs(char(219), i + 33, 12);
		buildings[i + 44] = new environmentalObjs(char(219), i + 43, 11);
		buildings[i + 48] = new environmentalObjs(char(219), i + 43, 12);
	}
	buildings[52] = new environmentalObjs(char(219), 36, 10);
	buildings[53] = new environmentalObjs(char(219), 43, 10);
	buildings[54] = new environmentalObjs(char(219), 36, 13);
	buildings[55] = new environmentalObjs(char(219), 43, 13);

	for (int i = 0; i < 5; i++)
	{
		buildings[i + 56] = new environmentalObjs(char(219), i + 32, 9);
		buildings[i + 61] = new environmentalObjs(char(219), i + 32, 14);
		buildings[i + 66] = new environmentalObjs(char(219), i + 43, 9);
		buildings[i + 71] = new environmentalObjs(char(219), i + 43, 14);
	}
	for (int i = 0; i < 4; i++)
	{
		buildings[i + 76] = new environmentalObjs(char(219), i + 32, 10);
		buildings[i + 80] = new environmentalObjs(char(219), i + 32, 13);
		buildings[i + 84] = new environmentalObjs(char(219), i + 44, 10);
		buildings[i + 88] = new environmentalObjs(char(219), i + 44, 13);
	}
	buildings[92] = new environmentalObjs(char(219), 32, 11);
	buildings[93] = new environmentalObjs(char(219), 32, 12);
	buildings[94] = new environmentalObjs(char(219), 47, 11);
	buildings[95] = new environmentalObjs(char(219), 47, 12);

	for (int i = 0; i < 16; i++)
	{
		buildings[i + 96] = new environmentalObjs(char(219), i + 32, 15);
	}


	// Other buildings
	for (int i = 0; i < 8; i++)
	{
		buildings[i + 112] = new environmentalObjs(char(219), i, 2);
		buildings[i + 120] = new environmentalObjs(char(219), i, 3);

		buildings[i + 128] = new environmentalObjs(char(219), i, 5);
		buildings[i + 136] = new environmentalObjs(char(219), i, 6);

		buildings[i + 144] = new environmentalObjs(char(219), i, 9);
		buildings[i + 152] = new environmentalObjs(char(219), i, 10);

		buildings[i + 160] = new environmentalObjs(char(219), i, 13);
		buildings[i + 168] = new environmentalObjs(char(219), i, 14);

		buildings[i + 735] = new environmentalObjs(char(219), i, 17);
		buildings[i + 743] = new environmentalObjs(char(219), i, 18);
		buildings[i + 751] = new environmentalObjs(char(219), i, 19);
		buildings[i + 759] = new environmentalObjs(char(219), i, 20);

		buildings[i + 767] = new environmentalObjs(char(219), i, 23);

		buildings[i + 775] = new environmentalObjs(char(219), i + 45, 21);
		buildings[i + 783] = new environmentalObjs(char(219), i + 45, 22);
		buildings[i + 791] = new environmentalObjs(char(219), i + 45, 23);

		buildings[i + 813] = new environmentalObjs(char(219), i + 63, 13);
		buildings[i + 821] = new environmentalObjs(char(219), i + 63, 14);
	}

	for (int i = 0; i < 11; i++)
	{
		buildings[i + 176] = new environmentalObjs(char(219), i + 10, 0);
		buildings[i + 187] = new environmentalObjs(char(219), i + 10, 1);
		buildings[i + 198] = new environmentalObjs(char(219), i + 10, 2);
		buildings[i + 209] = new environmentalObjs(char(219), i + 10, 3);

		buildings[i + 220] = new environmentalObjs(char(219), i + 10, 5);
		buildings[i + 231] = new environmentalObjs(char(219), i + 10, 6);

		buildings[i + 242] = new environmentalObjs(char(219), i + 25, 0);
		buildings[i + 253] = new environmentalObjs(char(219), i + 25, 1);

		buildings[i + 264] = new environmentalObjs(char(219), i + 37, 0);
		buildings[i + 275] = new environmentalObjs(char(219), i + 37, 1);

		buildings[i + 381] = new environmentalObjs(char(219), i + 68, 17);
		buildings[i + 392] = new environmentalObjs(char(219), i + 68, 18);

		buildings[i + 523] = new environmentalObjs(char(219), i + 12, 13);
		buildings[i + 534] = new environmentalObjs(char(219), i + 12, 14);

		buildings[i + 683] = new environmentalObjs(char(219), i + 23, 17);
		buildings[i + 694] = new environmentalObjs(char(219), i + 23, 18);
	}

	for (int i = 0; i < 5; i++)
	{
		buildings[i + 286] = new environmentalObjs(char(219), i + 49, 0);
		buildings[i + 291] = new environmentalObjs(char(219), i + 49, 1);

		buildings[i + 296] = new environmentalObjs(char(219), i + 25, 4);
		buildings[i + 301] = new environmentalObjs(char(219), i + 25, 5);
		buildings[i + 306] = new environmentalObjs(char(219), i + 25, 6);

		buildings[i + 311] = new environmentalObjs(char(219), i + 31, 4);
		buildings[i + 316] = new environmentalObjs(char(219), i + 31, 5);
		buildings[i + 321] = new environmentalObjs(char(219), i + 31, 6);

		buildings[i + 326] = new environmentalObjs(char(219), i + 37, 4);
		buildings[i + 331] = new environmentalObjs(char(219), i + 37, 5);
		buildings[i + 336] = new environmentalObjs(char(219), i + 37, 6);

		buildings[i + 341] = new environmentalObjs(char(219), i + 43, 4);
		buildings[i + 346] = new environmentalObjs(char(219), i + 43, 5);
		buildings[i + 351] = new environmentalObjs(char(219), i + 43, 6);

		buildings[i + 356] = new environmentalObjs(char(219), i + 49, 4);
		buildings[i + 361] = new environmentalObjs(char(219), i + 49, 5);
		buildings[i + 366] = new environmentalObjs(char(219), i + 49, 6);

		buildings[i + 371] = new environmentalObjs(char(219), i + 75, 21);
		buildings[i + 376] = new environmentalObjs(char(219), i + 75, 22);
	}

	for (int i = 0; i < 6; i++)
	{
		buildings[i + 403] = new environmentalObjs(char(219), i + 57, 4);
		buildings[i + 409] = new environmentalObjs(char(219), i + 57, 5);
		buildings[i + 415] = new environmentalObjs(char(219), i + 57, 6);

		buildings[i + 421] = new environmentalObjs(char(219), i + 64, 4);
		buildings[i + 427] = new environmentalObjs(char(219), i + 64, 5);
		buildings[i + 433] = new environmentalObjs(char(219), i + 64, 6);

		buildings[i + 439] = new environmentalObjs(char(219), i + 74, 4);
		buildings[i + 445] = new environmentalObjs(char(219), i + 74, 5);
		buildings[i + 451] = new environmentalObjs(char(219), i + 74, 6);

		buildings[i + 457] = new environmentalObjs(char(219), i + 68, 21);
		buildings[i + 463] = new environmentalObjs(char(219), i + 68, 22);

		buildings[i + 469] = new environmentalObjs(char(219), i + 13, 21);
		buildings[i + 475] = new environmentalObjs(char(219), i + 13, 22);
		buildings[i + 481] = new environmentalObjs(char(219), i + 13, 23);

		buildings[i + 487] = new environmentalObjs(char(219), i + 28, 21);
		buildings[i + 493] = new environmentalObjs(char(219), i + 28, 22);
		buildings[i + 499] = new environmentalObjs(char(219), i + 28, 23);

		buildings[i + 505] = new environmentalObjs(char(219), i + 38, 21);
		buildings[i + 511] = new environmentalObjs(char(219), i + 38, 22);
		buildings[i + 517] = new environmentalObjs(char(219), i + 38, 23);

		buildings[i + 545] = new environmentalObjs(char(219), i + 74, 0);
		buildings[i + 551] = new environmentalObjs(char(219), i + 74, 1);
		buildings[i + 557] = new environmentalObjs(char(219), i + 74, 2);
	}

	for (int i = 0; i < 7; i++)
	{
		buildings[i + 563] = new environmentalObjs(char(219), i + 20, 21);
		buildings[i + 570] = new environmentalObjs(char(219), i + 20, 22);
		buildings[i + 577] = new environmentalObjs(char(219), i + 20, 23);

		buildings[i + 584] = new environmentalObjs(char(219), i + 72, 13);
		buildings[i + 591] = new environmentalObjs(char(219), i + 72, 14);

		buildings[i + 598] = new environmentalObjs(char(219), i + 52, 9);
		buildings[i + 605] = new environmentalObjs(char(219), i + 52, 10);

		buildings[i + 799] = new environmentalObjs(char(219), i + 73, 9);
		buildings[i + 806] = new environmentalObjs(char(219), i + 73, 10);
	}

	for (int i = 0; i < 16; i++)
	{
		buildings[i + 612] = new environmentalObjs(char(219), i + 12, 9);
		buildings[i + 628] = new environmentalObjs(char(219), i + 12, 10);
	}

	for (int i = 0; i < 13; i++)
	{
		buildings[i + 644] = new environmentalObjs(char(219), i + 57, 0);
		buildings[i + 657] = new environmentalObjs(char(219), i + 57, 1);
		buildings[i + 670] = new environmentalObjs(char(219), i + 57, 2);
	}

	for (int i = 0; i < 15; i++)
	{
		buildings[i + 705] = new environmentalObjs(char(219), i + 38, 17);
		buildings[i + 720] = new environmentalObjs(char(219), i + 38, 18);
	}

	for (int i = 0; i < 10; i++)
	{
		buildings[i + 829] = new environmentalObjs(char(219), i + 52, 13);
		buildings[i + 839] = new environmentalObjs(char(219), i + 52, 14);

		buildings[i + 849] = new environmentalObjs(char(219), i + 57, 17);
		buildings[i + 859] = new environmentalObjs(char(219), i + 57, 18);

		buildings[i + 893] = new environmentalObjs(char(219), i + 57, 21);
		buildings[i + 903] = new environmentalObjs(char(219), i + 57, 22);
		buildings[i + 913] = new environmentalObjs(char(219), i + 57, 23);
	}

	for (int i = 0; i < 12; i++)
	{
		buildings[i + 869] = new environmentalObjs(char(219), i + 60, 9);
		buildings[i + 881] = new environmentalObjs(char(219), i + 60, 10);
	}

	for (int i = 0; i < 9; i++)
	{
		buildings[i + 923] = new environmentalObjs(char(219), i + 13, 17);
		buildings[i + 932] = new environmentalObjs(char(219), i + 13, 18);
	}

	for (int i = 0; i < 4; i++)
	{
		buildings[i + 941] = new environmentalObjs(char(219), i + 24, 13);
		buildings[i + 945] = new environmentalObjs(char(219), i + 24, 14);
	}

	//border
	color(0x0F);
	for (int i = 4; i < 84; i++)
	{
		gotoxy(i, 0);
		std::cout << char(205);
		gotoxy(i, 25);
		std::cout << char(205);
	}
	for (int i = 1; i < 25; i++)
	{
		gotoxy(3, i);
		std::cout << char(186);
		gotoxy(84, i);
		std::cout << char(186);
	}

	//top left corner
	gotoxy(3, 0);
	std::cout << char(201);
	//bottom left corner
	gotoxy(3, 25);
	std::cout << char(200);
	//top right corner
	gotoxy(84, 0);
	std::cout << char(187);
	//bottom right corner
	gotoxy(84, 25);
	std::cout << char(188);

	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			gotoxy(i + 4, j + 1);
			objexist = false;
			for (int k = 0; k < 949; k++)
			{
				if (buildings[k]->getx() == i and buildings[k]->gety() == j)
				{
					color(0x0E);
					if (k < 12)
					{
						color(0x0E);
					}
					if (k > 11 && k < 56)
					{
						if (k > 17 && k < 24)
						{
							color(0x0A);
						}
						else
						{
							color(0x04);
						}
					}
					if (k > 55 && k < 112)
					{
						color(0x0A);
					}
					std::cout << buildings[k]->getsymbol();
					objexist = true;
				}
			}
			if (!objexist)
			{
				color(0x07);
				std::cout << char(219);
			}
		}
	}
}