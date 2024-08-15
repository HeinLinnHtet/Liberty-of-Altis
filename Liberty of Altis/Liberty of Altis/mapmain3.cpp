#include "mapmain3.h"
#include <iostream>
#include "environmentalObjs.h"

mapmain3::mapmain3()
{

}

void mapmain3::drawmap()
{
	bool objexist = false;

	//environmentalObjs* props[10];
	//props[0] = new environmentalObjs('E', 1, 1);
	//props[1] = new environmentalObjs('E', 2, 1);
	//props[2] = new environmentalObjs('E', 3, 1);
	//props[3] = new environmentalObjs('E', 4, 1);
	//props[4] = new environmentalObjs('E', 5, 1);
	//props[5] = new environmentalObjs('E', 6, 1);
	//props[6] = new environmentalObjs('E', 7, 1);
	//props[7] = new environmentalObjs('E', 8, 1);
	//props[8] = new environmentalObjs('E', 9, 1);
	//props[9] = new environmentalObjs('E', 10, 1);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			gotoxy(i, j);
			color(0x0A);
			objexist = false;
			for (int k = 0; k < 10; k++)
			{
				//if (props[k]->getx() == i and props[k]->gety() == j)
				//{
				//	std::cout << props[k]->getsymbol();
				//	objexist = true;
				//}
			}
			if (!objexist)
			{
				std::cout << char(178);
			}
		}
	}
}