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

	///////////STATS
	//{
	//	//display the stats
	//	//allied troops live stats
	//	gotoxy(65, 1);
	//	std::cout << "Allied Troops";

	//	//stats
	//	gotoxy(65, 2);
	//	std::cout << "Health  Attack  Range";

	//	//for rifleman
	//	for (int i = 0; i < 3; i++) {
	//		gotoxy(55, 3 + i);
	//		std::cout << "Rifleman " << i + 1 << ": " << level1Allies[i]->GetHealth() << "      "
	//			<< level1Allies[i]->GetAttack() << "       " << level1Allies[i]->GetRange();
	//	}

	//	//machinegunner
	//	for (int i = 3; i < 5; i++) {
	//		gotoxy(55, 6 + (i - 3));
	//		std::cout << "McGunner " << i - 2 << ": " << level1Allies[i]->GetHealth() << "      "
	//			<< level1Allies[i]->GetAttack() << "       " << level1Allies[i]->GetRange();
	//	}

	//	//grenadier
	//	for (int i = 5; i < 7; i++) {
	//		gotoxy(55, 8 + (i - 5));
	//		std::cout << "Grenader " << i - 4 << ": " << level1Allies[i]->GetHealth() << "      "
	//			<< level1Allies[i]->GetAttack() << "       " << level1Allies[i]->GetRange();
	//	}

	//	//Enemy troops
	//	gotoxy(65, 12);
	//	std::cout << "Enemy Troops";

	//	//stats
	//	gotoxy(65, 13);
	//	std::cout << "Health  Attack  Range";

	//	//rifleman
	//	for (int i = 0; i < 6; i++) {
	//		gotoxy(55, 14 + i);
	//		std::cout << "Rifleman " << i + 1 << ": " << level1Enemy[i]->GetHealth() << "      "
	//			<< level1Enemy[i]->GetAttack() << "       " << level1Enemy[i]->GetRange();
	//	}
	//	//machine gunner
	//	for (int i = 6; i < 8; i++) {
	//		gotoxy(55, 20 + (i - 6));
	//		std::cout << "McGunner " << i - 5 << ": " << level1Enemy[i]->GetHealth() << "      "
	//			<< level1Enemy[i]->GetAttack() << "       " << level1Enemy[i]->GetRange();
	//	}
	//	//Grenadier
	//	for (int i = 8; i < 10; i++) {
	//		gotoxy(55, 22 + (i - 8));
	//		std::cout << "Grenader " << i - 7 << ": " << level1Enemy[i]->GetHealth() << "      "
	//			<< level1Enemy[i]->GetAttack() << "       " << level1Enemy[i]->GetRange();
	//	}
	//}

	//Set all troop positions
	//SetStartPos(*level1Allies[0], 5, 2);
	SetStartPos(*level1Allies[1], 5, 5);
	SetStartPos(*level1Allies[2], 7, 5);
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
	SetStartPos(*level1Allies[0], 23, 16);
	SetStartPos(*level1Enemy[0], 25, 16);

	
	////Check if all enemies have died  ### To change
	bool test = false;

	while (test == false) {

		///////////////////////// REMOVE
		int hi = 0, bye = 0;
		for (int a = 0; a < 10; a++) {
			gotoxy(60 + hi , 6);
			std::cout << level1Enemy[a]->PosXY.GetX() << " ";
			std::cout << level1Enemy[a]->PosXY.GetY() << " ";
			hi = hi + 6;
		}
		for (int a = 0; a < 7; a++) {
			gotoxy(60 + bye, 8);
			std::cout << level1Allies[a]->PosXY.GetX() << " ";
			std::cout << level1Allies[a]->PosXY.GetY() << " ";
			bye = bye + 5;
		}

		////////For player troops
		// Player choose action 
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

			//Movement 
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
						if (CheckEnviroCollide(*level1Allies[i], choice) == true) {
							gotoxy(15, 22);
							std::cout << "Collided Environment";
							CanMove = false;
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
					//reinput movement again
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

				//Check if can attack any enemies 
				for (int j = 0; j < 10; j++) {

					if (CheckAttack(*level1Allies[i], *level1Enemy[j], attackDir) == true) {
						level1Allies[i]->DamageDealt(*level1Enemy[j]);

						gotoxy(15, 25);
						std::cout << "attack Dealt";
						gotoxy(15, 26);
						std::cout << level1Enemy[j]->GetHealth() << " " << j << " " << i;
						break;
					}
				}
			}
			
		}

		//UI 
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


		////////// For enemy troops 
		//gotoxy(70, 10);
		//int hp = level1Allies[0]->GetHealth();
		//std::cout << hp;
		gotoxy(50, 23);
		std::cout << "                                        ";


		for (int i = 0; i < 10; i++) {

			//allow to check movement is valid 
			bool Moving = true;

			//Attacking, Check if can attack first 
			for (int j = 0; j < 7; j++) {
				if (EnemyCheckAtk(*level1Allies[j], *level1Enemy[i]) == true) {
					level1Enemy[i]->DamageDealt(*level1Allies[j]);
					gotoxy(50, 23);
					std::cout << "Enemy attacking " << i << " " << j << " " << level1Allies[0]->GetHealth();
					Moving = false;
					break;
				}
			}

			//gotoxy(70, 11);
			//hp = level1Allies[0]->GetHealth();
			//std::cout << hp;

			gotoxy(20, 20);
			std::cout << "Enemy moving....";


			//Movement 
			while (Moving == true) {

				bool ValidMove = true;

				//Random number generation
				int num = level1Enemy[i]->RandomNum();
				//convert to char
				char input = num + '0';

				//Check collison with borders
				if (level1Enemy[i]->BorderCollision(input) == true) {
					gotoxy(15, 20);
					std::cout << "Enemy Collided border";
					ValidMove = false;
				}

				if (ValidMove == true) {
					//Check collison between Enemies and Allies
					for (int j = 0; j < 7; j++) {
						if (level1Enemy[i]->Entitycollision(*level1Allies[j], input) == true) {
							gotoxy(15, 21);
							std::cout << "Enemy Collided Entity";
							ValidMove = false;
						}
					}
				}

				if (ValidMove == true) {
					//Check collison between Enemies and Enemies
					for (int j = 0; j < 10; j++) {
						if (level1Enemy[i]->Entitycollision(*level1Enemy[j], input) == true) {
							gotoxy(15, 21);
							std::cout << "Enemy Collided Enemy";
							ValidMove = false;
						}
					}
				}

				if (ValidMove == true) {
					//Check collison between Enemies and environment 
					if (CheckEnviroCollide(*level1Enemy[i], input) == true) {
						gotoxy(15, 22);
						std::cout << "Enemy Collided Environment";
						ValidMove = false;

					}
				}

				//reflect movement of entity on screen 
				if (ValidMove == true) {
					MoveEntity(*level1Enemy[i], input);
					Moving = false;

				}
				else if (ValidMove == false) {
					gotoxy(15, 23);
					std::cout << "Enemy Invalid Movement";
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
		if (level1Allies[i] != nullptr) {
			delete level1Allies[i];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (level1Enemy[i] != nullptr) {
			delete level1Enemy[i];
		}
	}
	for (int i = 0; i < AmtofObjs; i++) {
		if (trees[i] != nullptr) {
			delete trees[i];
		}
	}
}



//Check attack
bool mapmain1::CheckAttack(Entity& main, Entity& other, char direction)
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
	int dx = abs(xother - x);
	int dy = abs(yother - y);

	//Check if enemy within range
	if (dx <= Range && dy <= Range) {

		//Check if enemy is aligned 
		if (x == xother || y == yother) {

			//check EVERY object to see if any is obstructing player 
			for (int i = 0; i < AmtofObjs; i++) {

				int xobj = trees[i]->objPos.GetX();
				int yobj = trees[i]->objPos.GetY();
				int Endx = 0; int Endy = 0;

				//Store distance between enviromental objects
				//Check if obj is UP of entity
				Endx = abs(x - xobj);
				Endy = abs(y - yobj);

				//Up
				if (direction == 'W') {
					//Check for any objects aligned and above player 
					if (xobj == x && (yobj < y)) {
						//Check if within range
						if (Endy <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
				//Down
				else if (direction == 'S') {
					//Check for any objects aligned and above player 
					if (xobj == x && (yobj > y)) {
						//Check if within range
						if (Endy <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
				//Right
				else if (direction == 'D') {
					//Check for any objects aligned and above player 
					if (yobj == y && (xobj > x)) {
						//Check if within range
						if (Endx <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
				//Left
				else if (direction == 'A') {
					//Check for any objects aligned and above player 
					if (yobj == y && (xobj < x)) {
						//Check if within range
						if (Endx <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
			}
		}
		else 
			//if enemies not aligned cant attack
			objectblocking = true;
	}
	//if no enemies in range, cant attack
	else 
		objectblocking = true;

	//If no obstructions, attack
	if (objectblocking == false) {
		attackable = true;
	}

	return attackable;
}

//Check if enemy can attack
bool mapmain1::EnemyCheckAtk(Entity& ally, Entity& Enemy)
{
	//a temp variable to store ture/false
	bool attackable = false;
	//Check if object is blocking
	bool objectblocking = false;

	//values 
	int x = Enemy.PosXY.GetX();
	int y = Enemy.PosXY.GetY();
	int Range = Enemy.GetRange();	
	int xother = ally.PosXY.GetX();
	int yother = ally.PosXY.GetY();

	//Store distance between allies  and enemy
	int dx = abs(x - xother);
	int dy = abs(y - yother);

	//Check if enemy is within range
	if (dx <= Range && dy <= Range) {

		//Check if they are aligned
		//ally on y axis
		if (x == xother) {

			//check EVERY object to see if any is obstructing  
			for (int i = 0; i < AmtofObjs; i++) {

				int xobj = trees[i]->objPos.GetX();
				int yobj = trees[i]->objPos.GetY();
				int Endy = 0;

				//Store distance between enviromental objects
				Endy = abs(y - yobj);

				//If ally is above
				if (yother < y) {
					//check if enviroment obj above
					if ((x == xobj) && (yobj < y)) {
						//Check if object in range
						if (Endy <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
				//If ally is below 
				else if (yother > y) {
					//check if enviroment obj above
					if ((x == xobj) && (yobj > y)) {
						//Check if object in range
						if (Endy <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
			}
		}
		//Check if they are aligned
		//ally on x axis
		else if (y == yother) {

			//check EVERY object to see if any is obstructing  
			for (int i = 0; i < AmtofObjs; i++) {
				
				int xobj = trees[i]->objPos.GetX();
				int yobj = trees[i]->objPos.GetY();
				int Endx = 0;

				//Store distance between enviromental objects
				Endx = abs(x - xobj);

				//If ally is on the left
				if (xother < x) {
					//check if enviroment obj above
					if ((y == yobj) && (xobj < x)) {
						//Check if object is within range
						if (Endx <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
				//If ally is on the right 
				else if (xother > x) {
					//check if enviroment obj above
					if ((y == yobj) && (xobj > x)) {
						//Check if object is within range
						if (Endx <= Range) {
							objectblocking = true;
							break;
						}
					}
				}
			}
		}
		else
			objectblocking = true;
	}
	else
		//means cant attack 
		objectblocking = true;


	//if no object obstruct, attack
	if (objectblocking == false) {
		attackable = true;
	}

	return attackable;
}

//Check collision
bool mapmain1::CheckEnviroCollide(Entity& main, char direction)
{
	//store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	bool result = false;

	//Check with EVERY object
	for (int i = 0; i < AmtofObjs; i++) {

		int XEnviro = trees[i]->objPos.GetX();
		int YEnviro = trees[i]->objPos.GetY();

		//Check if enviroment is aligned hori or veritcally 
		if ((XEntity == XEnviro) || (YEntity == YEnviro)) {
			if ((YEntity == YEnviro - 1) && (direction == 'S' || direction == '1')) {
				result = true;
				break;
			}
			//Up
			else if ((YEntity == YEnviro + 1) && (direction == 'W' || direction == '0')) {
				result = true;
				break;
			}
			//Right
			if ((XEntity == XEnviro - 1) && (direction == 'D' || direction == '2')) {
				result = true;
				break;
			}
			//Left
			else if ((XEntity == XEnviro + 1) && (direction == 'A' || direction == '3')) {
				result = true;
				break;
			}
		}
	}

	return result;

}


