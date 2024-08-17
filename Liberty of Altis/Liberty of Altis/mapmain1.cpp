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
	//SetStartPos(*level1Allies[0], 5, 2);
	SetStartPos(*level1Allies[1], 5, 4);
	SetStartPos(*level1Allies[2], 7, 4);
	SetStartPos(*level1Allies[3], 7, 6);
	SetStartPos(*level1Allies[4], 7, 8);
	SetStartPos(*level1Allies[5], 7, 10);
	SetStartPos(*level1Allies[6], 7, 12);

	//SetStartPos(*level1Enemy[0], 25 ,3);
	SetStartPos(*level1Enemy[1], 30, 4);
	SetStartPos(*level1Enemy[2], 28, 2);
	SetStartPos(*level1Enemy[3], 40, 4);
	SetStartPos(*level1Enemy[4], 30, 6);
	SetStartPos(*level1Enemy[5], 40, 6);
	SetStartPos(*level1Enemy[6], 28, 4);
	SetStartPos(*level1Enemy[7], 35, 3);
	SetStartPos(*level1Enemy[8], 23, 4);
	SetStartPos(*level1Enemy[9], 35, 5);
	
	//testing 
	SetStartPos(*level1Allies[0], 21, 16);
	SetStartPos(*level1Enemy[0], 25, 16);

	
	////Check if all enemies have died  ### To change
	bool test = false;

	while (test == false) {

		////////For player troops
		// Player choose action 
		

		//Movement 
		for (int i = 0; i < 7; i++) {
			bool ValidMove = false;

//Get user input, WASD to move or J to attack 
gotoxy(15, 25);
std::cout << "WASD to Move, J to Attack";
	
char choice = 'Z';

//prevent from reading in console
choice = _getch();
//caps
choice = toupper(choice);

if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
	//Movement Code
	while (ValidMove == false) {

		//allow to check movement is valid 
		bool CanMove = true;

		//Check collison with borders
		if (level1Allies[i]->BorderCollision(choice) == true) {
			gotoxy(15, 20);
			std::cout << "Collided border";
			CanMove = false;
		}

		//Check collison between Allies and Enemies
		if (CanMove == true) {
			for (int j = 0; j < 10; j++) {
				if (level1Allies[i]->Entitycollision(*level1Enemy[j], choice) == true) {
					gotoxy(15, 21);
					std::cout << "Collided Entity";
					CanMove = false;
				}
			}
		}

		//Check collison between Allies and Allies
		if (CanMove == true) {
			for (int j = 0; j < 7; j++) {
				if (level1Allies[i]->Entitycollision(*level1Allies[j], choice) == true) {
					gotoxy(15, 21);
					std::cout << "Collided Allies";
					CanMove = false;
				}
			}
		}

		//Check collison between Allies and environment 
		if (CanMove == true) {
			for (int j = 0; j < AmtofObjs; j++) {
				if (EnviroEntityCollide(*level1Allies[i], *trees[j], choice) == true) {
					gotoxy(15, 22);
					std::cout << "Collided Environment";
					CanMove = false;
				}
			}
		}

		//reflect movement of entity on screen 
		if (CanMove == true) {
			gotoxy(15, 20);
			std::cout << "                    ";
			gotoxy(15, 21);
			std::cout << "                    ";
			gotoxy(15, 22);
			std::cout << "                    ";
			gotoxy(15, 23);
			std::cout << "                    ";
			MoveEntity(*level1Allies[i], choice);
			ValidMove = true;
		}
		else if (CanMove == false) {
			gotoxy(15, 23);
			std::cout << "Invalid Movement";
			choice = _getch();
			choice = toupper(choice);
		}
	}
}
			//Attacking 
			else if (choice == 'J') {
				gotoxy(16, 24);
				std::cout << "going to attack";

				//Grab attack direction 
				char attackDir = 'Z';
				
				while (!(attackDir == 'w' || attackDir == 's' || attackDir == 'a' || attackDir == 'd')) {
					attackDir = _getch();
					gotoxy(15, 23);
					std::cout << "attack direction";
				}
				attackDir = toupper(attackDir);
				gotoxy(15, 24);
				std::cout << "Attacking";

				//Check if can attack any enemies 
				for (int j = 0; j < 10; j++) {
					if (CheckAttack(*level1Allies[i], *level1Enemy[j], attackDir) == true) {
						level1Allies[i]->DamageDealt(*level1Enemy[j]);

						gotoxy(15, 25);
						std::cout << "attack Dealt";
						gotoxy(15, 26);
						std::cout << level1Enemy[0]->GetHealth();
						break;
					}
				}

				////Check enemies    // currently broken
				//for (int j = 0; j < 10; j++) {
				//	//Check enviro objs
				//	for (int k = 0; k < AmtofObjs; k++) {
				//		//if attacking works
				//		if (level1Allies[i]->AlliesAtk(*level1Enemy[j], *trees[k], attackDir) == true) {
				//			level1Allies[i]->DamageDealt(*level1Enemy[j]);
				//			gotoxy(15, 25);
				//			std::cout << "attack dealt";

				//			gotoxy(15, 26);
				//			level1Enemy[j]->SetHealth(level1Enemy[j]->GetHealth() - 2);
				//			std::cout << " This enemies's health: " << level1Enemy[j]->GetHealth();
				//			break;
				//		}
				//	}
				//}
				//for (int k = 0; k < AmtofObjs; k++) {                          ///Broken pls fix 
				//	if (level1Allies[0]->AlliesAtk(*level1Enemy[0], *trees[k], attackDir) == true) {
				//		level1Allies[0]->DamageDealt(*level1Enemy[0]);
				//		gotoxy(15, 25);
				//		std::cout << "attack dealt";

				//		gotoxy(15, 26);
				//		level1Enemy[0]->SetHealth(level1Enemy[0]->GetHealth() - 2);
				//		std::cout << " This enemies's health: " << level1Enemy[0]->GetHealth();
				//		break;
				//	}
				//}
				
			}

		}
		//Player attacking 

		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
			std::cout << level1Allies[i]->Draw_Icon();
		}
		for (int i = 0; i < 10; i++) {
			gotoxy(level1Enemy[i]->PosXY.GetX(), level1Enemy[i]->PosXY.GetY());
			std::cout << level1Enemy[i]->Draw_Icon();
		}

		///////////////////////Remove
		int yee;
		std::cin >> yee;

		////////// For enemy troops 
		gotoxy(70, 10);
		int hp = level1Allies[0]->GetHealth();
		std::cout << hp;


		//Attacking 
		for (int i = 0; i < 10; i++) {

			//allow to check movement is valid 
			bool CanMove = true;

			int Option = 2;
			//Check if can attack first 
			for (int j = 0; j < 7; j++) {
				for (int k = 0; k < AmtofObjs; k++) {
					if (level1Enemy[i]->canattack(*level1Allies[j], *trees[k]) == true) {
						level1Enemy[i]->DamageDealt(*level1Allies[j]);
						Option = 1;
						gotoxy(50, 23);
						std::cout << "Enemy attacking " << i << " " << j;
						break;
					}
				}
			}
			gotoxy(70, 11);
			hp = level1Allies[0]->GetHealth();
			std::cout << hp;

			bool ValidMove = false;

			gotoxy(20, 19);
			std::cout << "Enemy moving....";

			//if attack fail, do movement 
			if (Option == 2) {

				//check if movement valid
				while (ValidMove == false) {


					//Random number generation
					int num = level1Enemy[i]->RandomNum();
					//convert to char
					char input = num + '0';

					//Check collison with borders
					if (level1Enemy[i]->BorderCollision(input) == true) {
						gotoxy(15, 20);
						std::cout << "Enemy Collided border";
						CanMove = false;
					}

					if (CanMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < 7; j++) {
							if (level1Enemy[i]->Entitycollision(*level1Allies[j], input) == true) {
								gotoxy(15, 21);
								std::cout << "Enemy Collided Entity";
								CanMove = false;
							}
						}
					}

					if (CanMove == true) {
						//Check collison between Enemies and Enemies
						for (int j = 0; j < 10; j++) {
							if (level1Enemy[i]->Entitycollision(*level1Enemy[j], input) == true) {
								gotoxy(15, 21);
								std::cout << "Enemy Collided Enemy";
								CanMove = false;
							}
						}
					}

					if (CanMove == true) {
						//Check collison between Enemies  and environment 
						for (int j = 0; j < AmtofObjs; j++) {
							if (EnviroEntityCollide(*level1Enemy[i], *trees[j], input) == true) {
								gotoxy(15, 22);
								std::cout << "Enemy Collided Environment";
								CanMove = false;
							}
						}
					}

					//reflect movement of entity on screen 
					if (CanMove == true) {
						MoveEntity(*level1Enemy[i], input);
						ValidMove = true;

					}
					else if (CanMove == false) {
						gotoxy(15, 23);
						std::cout << "Enemy Invalid Movement";
					}
				}
			}
		}

		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
			std::cout << level1Allies[i]->Draw_Icon();
		}
		for (int i = 0; i < 10; i++) {
			gotoxy(level1Enemy[i]->PosXY.GetX(), level1Enemy[i]->PosXY.GetY());
			std::cout << level1Enemy[i]->Draw_Icon();
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


//Check attack
bool mapmain1::CheckAttack(Entity &main, Entity& other, char direction)
{
	//a temp variable to store ture/false
	bool attackable = false;
	//Check if object is blocking
	bool objectblocking = false;

	//values 
	int x = main.PosXY.GetX();
	int y = main.PosXY.GetY();
	int Range = main.GetRange();
	int xother = other.PosXY.GetX();
	int yother = other.PosXY.GetY();
	//Store distance between enemy 
	int dx = xother - x;
	int dy = yother - y;

	//check EVERY object to see if any is obstructing player 
	for (int i = 0; i < AmtofObjs; i++) {

		int xobj = trees[i]->objPos.GetX();
		int yobj = trees[i]->objPos.GetY();
		int Endx = 0; int Endy = 0;

		//Store distance between enviromental objects
		//Check if obj is UP of entity
		if (yobj < y) {
			Endy = y - yobj;
		}
		else if (yobj > y) {
			Endy = yobj - y;
		}
		//Check if obj is LR of entity
		if (xobj < x) {
			Endx = x - xobj;
		}
		else if (xobj > x) {
			Endx = xobj - x;
		}


		//Up, range checks already implemented 
		if (direction == 'W') {
			//check if object blocking
			if (x == xobj && -Endy <= Range) {
				objectblocking = true;
				break;
			}
		}
		//Down
		else if (direction == 'S') {
			//check if object blocking
			if (x == xobj && Endy <= Range) {
				objectblocking = true;
				break;
			}
		}
		//Right 
		else if (direction == 'D') {
			//check if object blocking
			if (y == yobj && Endx <= Range) {
				objectblocking = true;
				break;
			}
		}
		//Left 
		else if (direction == 'A') {
			//check if object blocking
			if (y == yobj && -Endx <= Range) {
				objectblocking = true;
				break;
			}
		}
	}

	//if no object obstruct, check if enemy in range
	if (objectblocking == false) {
		if (direction == 'W' && -dy <= Range) {
			attackable = true;
		}
		else if (direction == 'S' && dy <= Range) {
			attackable = true;
		}
		else if (direction == 'D' && dx <= Range) {
			attackable = true;
		}
		else if (direction == 'A' && -dx <= Range) {
			attackable = true;
		}
	}

	return attackable;
}


