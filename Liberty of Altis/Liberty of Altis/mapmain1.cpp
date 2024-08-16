#include "mapmain1.h"
#include "environmentalObjs.h"
#include <iostream>

environmentalObjs* mapmain1:: trees[AmtofObjs]{};

mapmain1::mapmain1()
{
}

//Function to start game 1
void mapmain1::drawmap()
{
	bool objexist = false;
	int count = 0;

	//random position list for trees
	int treexpos[30] = {
		3,  7, 18, 29, 34, 15, 49, 11,  5, 38,
	   12, 42,  6,  0, 31,  8,  11, 19, 35, 28,
	   16, 17, 47, 14,  2, 33, 30, 48, 10, 32
	};

	int treeypos[30] = {
		2,  5, 11,  8, 14,  3,  7, 16,  1,  9,
		4, 12,  6,  0, 10, 15, 13, 17,  2, 11,
		7,  9,  4,  8,  3, 12,  5,  6,  0,  1
	};


	//trees next to the road
	for (int i = 0; i < 9; i++)
	{
		trees[i] = new environmentalObjs(char(176), 20, i * 4);

		trees[i + 9] = new environmentalObjs(char(176), 28, i * 4 + 1);
	}

	//trees that are randomly placed around the map
	for (int i = 0; i < 30; i++)
	{
		trees[i + 18] = new environmentalObjs(char(176), treexpos[i], treeypos[i]);
	}


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


	//render
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			gotoxy(i + 4, j + 1);
			objexist = false;
			//check if a tree is in the position
			for (int k = 0; k < 48; k++)
			{
				if (trees[k]->getx() == i and trees[k]->gety() == j)
				{
					color(0x0A);
					std::cout << trees[k]->getsymbol();
					objexist = true;
				}
			}
			if (!objexist)
			{
				//road color
				if (i < 27 && i > 21)
				{
					color(0x08);
				}
				//grass color
				else
				{
					color(0x02);
				}
				std::cout << char(178);
			}
		}
	}


	//Shift to position
	for (int i = 0; i < 48; i++) {
		trees[i]->setx(trees[i]->getx() + 4);
		trees[i]->sety(trees[i]->gety() + 1);
	}


}



//Function to start game 1
void mapmain1::map1game(void)
{
	//draw out map 
	drawmap();

	///// #### NOT POLYMORHPHISM ####		
	// instantiating objects																																																																																	
	//Spawn enemies 
	EnemyTroops* level1Enemy[10];
	//rifle man
	for (int i = 0; i < 6; i++) {
		level1Enemy[i] = new ERiflesman;
	}
	//Lmg
	for (int i = 6; i < 8; i++) {
		level1Enemy[i] = new EMachinegunner;
	}
	//Grenadier
	for (int i = 8; i < 10; i++) {
		level1Enemy[i] = new EGrenadier;
	}


	//Spawn allies 
	AlliedTroops* level1Allies[7];
	//rifle man 
	for (int i = 0; i < 3; i++) {
		level1Allies[i] = new ARiflesman;
	}
	//Lmg
	for (int i = 3; i < 5; i++) {
		level1Allies[i] = new AMachinegunner;
	}
	//Grenadier
	for (int i = 5; i < 7; i++) {
		level1Allies[i] = new AGrenadier;
	}


	//Set all troop positions
	SetStartPos(*level1Allies[0], 5, 2);
	SetStartPos(*level1Allies[1], 5, 4);
	SetStartPos(*level1Allies[2], 7, 4);
	SetStartPos(*level1Allies[3], 7, 6);
	SetStartPos(*level1Allies[4], 7, 8);
	SetStartPos(*level1Allies[5], 7, 10);
	SetStartPos(*level1Allies[6], 7, 12);

	//SetStartPos(*level1Enemy[0], 25 ,3);
	//SetStartPos(*level1Enemy[1], 30, 4);
	//SetStartPos(*level1Enemy[2], 28, 2);
	//SetStartPos(*level1Enemy[3], 40, 4);
	//SetStartPos(*level1Enemy[4], 30, 6);
	//SetStartPos(*level1Enemy[5], 40, 6);
	//SetStartPos(*level1Enemy[6], 28, 4);
	//SetStartPos(*level1Enemy[7], 35, 3);
	//SetStartPos(*level1Enemy[8], 23, 4);
	//SetStartPos(*level1Enemy[9], 35, 5);



	//Testing 
	SetStartPos(*level1Enemy[0], 6, 18);

	
	////Check if all enemies have died  ### To change
	bool test = false;

	while (test == false) {
		
		//////////For player troops
		// Player choose action 
		//Movement 
		for (int i = 0; i < 7; i++) {
			bool ValidMove = false;

			//Movement Code
			while (ValidMove == false) {

				gotoxy(65, 10);
				std::cout << "Enter your move";
				//store user input
				char input;
				std::cin >> input;

				//allow to check movement is valid 
				bool CanMove = true;


				//Check collison with borders
				if (level1Allies[i]->BorderCollision(input) == true) {
					gotoxy(15, 20);
					std::cout << "Collided border";
					CanMove = false;
				}

				//Check collison between Allies and Enemies
				for (int j = 0; j < 10; j++) {
					if (level1Allies[i]->Entitycollision(*level1Enemy[j], input) == true) {
						gotoxy(15, 21);
						std::cout << "Collided Entity";
						CanMove = false;
					}
				}

				//Check collison between Allies and Allies
				for (int j = 0; j < 7; j++) {
					if (level1Allies[i]->Entitycollision(*level1Allies[j], input) == true) {
						gotoxy(15, 21);
						std::cout << "Collided Allies";
						CanMove = false;
					}
				}

				////Check collison between Allies and environment 
				for (int j = 0; j < AmtofObjs; j++) {
					if (EnviroEntityCollide(*level1Allies[i], *trees[j], input) == true) {
						gotoxy(15, 22);
						std::cout << "Collided Environment";
						CanMove = false;
					}
				}

				//reflect movement of entity on screen 
				if (CanMove == true) {
					MoveEntity(*level1Allies[i], input);
					ValidMove = true;
				}
				else if (CanMove == false) {
					gotoxy(15, 23);
					std::cout << "Invalid Movement";
				}
			}
		}
		//Player attacking 

		
		////////// For enemy troops 
		//Attacking 
		


		//Movement (Ainsley doing now)
		

		//level1Enemy[0]->M1Movement();
		drawmap();
		gotoxy(level1Enemy[0]->PosXY.GetX(), level1Enemy[0]->PosXY.GetY());
		std::cout << level1Enemy[0]->Draw_Icon();

		//Update new position 
		for (int i = 0; i < 7; i++) {
			gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
			std::cout << level1Allies[i]->Draw_Icon();
		}


	}





	



	//Delete backlog
	for (int i = 0; i < 7; i++) {
		if (level1Enemy[i] != nullptr) {
			delete level1Enemy[i];
		}
		if (level1Allies[i] != nullptr) {
			delete level1Allies[i];
		}
	}

}


