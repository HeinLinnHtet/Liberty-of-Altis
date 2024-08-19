#include "mapmain3.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"


environmentalObjs* mapmain3::trees[Amt_Trees];
environmentalObjs* mapmain3::houses[Amt_House];

int mapmain3::Amt_Lvl2_Enemy = 10;
int mapmain3::Amt_Lvl2_Allies = 7;


mapmain3::mapmain3()
{
	alliesdead = 0;
	enemiesdead = 0;
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

	for (int i = 0; i < 10; i++)
	{
		trees[i] = new environmentalObjs(char(178), treexpos[i], treeypos[i]);
	}

	for (int i = 0; i < 9; i++)
	{
		houses[i] = new environmentalObjs(char(176), housexpos[i], houseypos[i]);
		houses[i + 9] = new environmentalObjs(char(176), housexpos[i] + 1, houseypos[i]);
		houses[i + 18] = new environmentalObjs(char(176), housexpos[i] - 1, houseypos[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		houses[i + 27] = new environmentalObjs(char(219), i + 3, 10);
		houses[i + 32] = new environmentalObjs(char(219), i + 3, 16);
	}
	for (int i = 0; i < 6; i++)
	{
		houses[i + 37] = new environmentalObjs(char(219), i + 3, 11);
		houses[i + 43] = new environmentalObjs(char(219), i + 3, 12);
		houses[i + 49] = new environmentalObjs(char(219), i + 3, 13);
		houses[i + 55] = new environmentalObjs(char(219), i + 3, 14);
		houses[i + 61] = new environmentalObjs(char(219), i + 3, 15);
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

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			gotoxy(i + 4, j + 1);
			objexist = false;

			//house
			for (int k = 0; k < 67; k++)
			{
				//check color for base
				color(0x0C);
				if (k > 26)
				{
					color(0x08);
				}
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
			//background
			if (!objexist)
			{
				color(0x0E);
				std::cout << char(178);
			}
		}
	}
}

void mapmain3::map3game(void)
{
	//draw out map 
	drawmap();

	///// #### NOT POLYMORHPHISM ####		
	// instantiating objects	

	//Spawn enemies 
	EnemyTroops* level3Enemy[10];
	//rifle man
	for (int i = 0; i < 6; i++) {
		level3Enemy[i] = new ERiflesman;
	}
	//Lmg
	for (int i = 6; i < 8; i++) {
		level3Enemy[i] = new EMachinegunner;
	}
	//Grenadier
	for (int i = 8; i < 10; i++) {
		level3Enemy[i] = new EGrenadier;
	}


	//Spawn allies 
	AlliedTroops* level3Allies[7];
	//rifle man 
	for (int i = 0; i < 3; i++) {
		level3Allies[i] = new ARiflesman;
	}
	//Lmg
	for (int i = 3; i < 5; i++) {
		level3Allies[i] = new AMachinegunner;
	}
	//Grenadier
	for (int i = 5; i < 7; i++) {
		level3Allies[i] = new AGrenadier;
	}


	//Set all troop positions
	color(0x09);
	SetStartPos(*level3Allies[0], 5, 2);
	SetStartPos(*level3Allies[1], 5, 5);
	SetStartPos(*level3Allies[2], 7, 5);
	SetStartPos(*level3Allies[3], 7, 6);
	SetStartPos(*level3Allies[4], 7, 8);
	SetStartPos(*level3Allies[5], 7, 10);
	SetStartPos(*level3Allies[6], 7, 12);

	color(0x06);
	SetStartPos(*level3Enemy[0], 25, 3);
	SetStartPos(*level3Enemy[1], 30, 4);
	SetStartPos(*level3Enemy[2], 28, 2);
	SetStartPos(*level3Enemy[3], 40, 4);
	SetStartPos(*level3Enemy[4], 30, 6);
	SetStartPos(*level3Enemy[5], 40, 6);
	SetStartPos(*level3Enemy[6], 28, 4);
	SetStartPos(*level3Enemy[7], 35, 3);
	SetStartPos(*level3Enemy[8], 23, 4);
	SetStartPos(*level3Enemy[9], 35, 5);


	////Check if all enemies have died  ### To change
	bool test = false;

	while (test == false) {

		int enemycposx, enemycposy;

		///////////STATS
		{
			//display the stats
			//allied troops live stats
			gotoxy(65, 1);
			color(0x09);
			std::cout << "Allied Troops";

			//stats
			gotoxy(65, 2);
			std::cout << "Health  Attack  Range";

			//for rifleman
			for (int i = 0; i < 3; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//machinegunner
			for (int i = 3; i < 5; i++) {
				if (level3Allies[i] != nullptr) {

					gotoxy(55, 6 + (i - 3));
					std::cout << "McGunner " << i - 2 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, 6 + (i - 3));
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, 6 + (i - 3));
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//grenadier
			for (int i = 5; i < 7; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, 8 + (i - 5));
					std::cout << "Grenader " << i - 4 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, 8 + (i - 5));
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, 8 + (i - 5));
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//Enemy troops
			gotoxy(65, 12);
			color(0x06);
			std::cout << "Enemy Troops";

			//stats
			gotoxy(65, 13);
			std::cout << "Health  Attack  Range";

			//rifleman
			for (int i = 0; i < 6; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 14 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 14 + i);
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 14 + i);
					std::cout << level3Enemy[i]->GetRange();
				}
			}
			//machine gunner
			for (int i = 6; i < 8; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 20 + (i - 6));
					std::cout << "McGunner " << i - 5 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 20 + (i - 6));
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 20 + (i - 6));
					std::cout << level3Enemy[i]->GetRange();
				}
			}
			//Grenadier
			for (int i = 8; i < 10; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 22 + (i - 8));
					std::cout << "Grenader " << i - 7 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 22 + (i - 8));
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 22 + (i - 8));
					std::cout << level3Enemy[i]->GetRange();
				}
			}
		}


		////////For player troops
		// Player choose action 
		for (int i = 0; i < 7; i++) {
			bool ValidMove = false;

			//Get user input, WASD to move or J to attack 
			gotoxy(15, 25);
			color(0x0F);
			std::cout << "WASD to Move, J to Attack";

			char choice = 'Z';


			if (level3Allies[i] != nullptr) {
				//prevent from reading in console
				gotoxy(level3Allies[i]->PosXY.GetX(), level3Allies[i]->PosXY.GetY());
				color(0x0D);
				std::cout << level3Allies[i]->Draw_Icon();
				choice = _getch();
				//caps
				choice = toupper(choice);
			}

			//Check if Ally is alive  (prevent crashes)
			if (level3Allies[i] != nullptr) {

				//Movement 
				if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
					//Movement Code
					while (ValidMove == false) {

						//allow to check movement is valid 
						bool CanMove = true;

						//Check collison with borders
						if (level3Allies[i]->BorderCollision(choice) == true) {
							gotoxy(15, 20);
							std::cout << "Collided border";
							CanMove = false;
						}

						//Check collison between Allies and Enemies
						if (CanMove == true) {
							for (int j = 0; j < 10; j++) {
								if (level3Enemy[j] != nullptr) {
									if (level3Allies[i]->Entitycollision(*level3Enemy[j], choice) == true) {
										gotoxy(15, 21);
										std::cout << "Collided Entity";
										CanMove = false;
										break;
									}
								}
							}
						}

						//Check collison between Allies and Allies
						if (CanMove == true) {
							for (int j = 0; j < 7; j++) {
								if (level3Allies[j] != nullptr) {
									if (level3Allies[i]->Entitycollision(*level3Allies[j], choice) == true) {
										gotoxy(15, 21);
										std::cout << "Collided Allies";
										CanMove = false;
										break;
									}
								}
							}
						}

						//Check collison between Allies and environment 
						if (CanMove == true) {
							if (CheckEnviroCollide(*level3Allies[i], choice) == true) {
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
							MoveEntity(*level3Allies[i], choice);
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
						if (level3Enemy[j] != nullptr) {
							if (CheckAttack(*level3Allies[i], *level3Enemy[j], attackDir) == true) {
								level3Allies[i]->DamageDealt(*level3Enemy[j]);

								gotoxy(15, 25);
								std::cout << "attack Dealt";
								gotoxy(15, 26);
								std::cout << level3Enemy[j]->GetHealth() << " " << j << " " << i;
								break;
							}
						}
					}
				}
			}

			//Check if Enemy is alive 
			for (int j = 0; j < 10; j++) {

				if (!(level3Enemy[j] == nullptr)) {
					if (level3Enemy[j]->isEntityAlive() == false) {
						enemycposx = level3Enemy[j]->PosXY.GetX();
						enemycposy = level3Enemy[j]->PosXY.GetY();


						gotoxy(enemycposx, enemycposy);
						std::cout << 'X';

						//kill enemy 
						enemiesdead = enemiesdead + 1;
						delete level3Enemy[j];
						level3Enemy[j] = nullptr;
					}
				}
			}
		}

		//UI 
		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			if (level3Allies[i] != nullptr) {
				gotoxy(level3Allies[i]->PosXY.GetX(), level3Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level3Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < 10; i++) {
			if (level3Enemy[i] != nullptr) {//error is here
				gotoxy(level3Enemy[i]->PosXY.GetX(), level3Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level3Enemy[i]->Draw_Icon();
			}
		}

		////////// For enemy troops 
		for (int i = 0; i < 10; i++) {

			//allow to check movement is valid 
			bool Moving = true;

			//Check if enemy is alive (prevent crashes) 
			if (level3Enemy[i] != nullptr) {

				//Attacking, Check if can attack first 
				for (int j = 0; j < 7; j++) {
					if (level3Allies[j] != nullptr) {
						if (EnemyCheckAtk(*level3Allies[j], *level3Enemy[i]) == true) {
							level3Enemy[i]->DamageDealt(*level3Allies[j]);
							/*gotoxy(50, 23);
							std::cout << "Enemy attacking " << i << " " << j << " " << level1Allies[0]->GetHealth();*/
							Moving = false;
							break;
						}
					}
				}

				//Movement 
				while (Moving == true) {

					gotoxy(20, 20);
					std::cout << "Enemy moving....";

					bool ValidMove = true;

					//Random number generation
					int num = level3Enemy[i]->RandomNum();
					//convert to char
					char input = num + '0';

					//Check collison with borders
					if (level3Enemy[i]->BorderCollision(input) == true) {
						gotoxy(15, 20);
						std::cout << "Enemy Collided border";
						ValidMove = false;
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < 7; j++) {
							if (level3Allies[j] != nullptr) {
								if (level3Enemy[i]->Entitycollision(*level3Allies[j], input) == true) {
									gotoxy(15, 21);
									std::cout << "Enemy Collided Entity";
									ValidMove = false;
									break;
								}
							}
						}
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Enemies
						for (int j = 0; j < 10; j++) {
							if (level3Enemy[j] != nullptr) {
								if (level3Enemy[i]->Entitycollision(*level3Enemy[j], input) == true) {
									gotoxy(15, 21);
									std::cout << "Enemy Collided Enemy";
									ValidMove = false;
									break;
								}
							}
						}
					}

					if (ValidMove == true) {
						//Check collison between Enemies and environment 
						if (CheckEnviroCollide(*level3Enemy[i], input) == true) {
							gotoxy(15, 22);
							std::cout << "Enemy Collided Environment";
							ValidMove = false;
							break;
						}
					}

					//reflect movement of entity on screen 
					if (ValidMove == true) {
						MoveEntity(*level3Enemy[i], input);
						Moving = false;

					}
					else if (ValidMove == false) {
						gotoxy(15, 23);
						std::cout << "Enemy Invalid Movement";
					}
				}
			}

			//Check if allies are alive 
			for (int j = 0; j < 7; j++) {
				if (level3Allies[j] != nullptr) {
					if (level3Allies[j]->isEntityAlive() == false) {
						gotoxy(level3Allies[j]->PosXY.GetX(), level3Allies[j]->PosXY.GetY());
						std::cout << 'X';

						//kill alliies
						alliesdead = alliesdead + 1;
						delete level3Allies[j];
						level3Allies[j] = nullptr;
					}
				}
			}
		}

		//UI
		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			if (level3Allies[i] != nullptr) {
				gotoxy(level3Allies[i]->PosXY.GetX(), level3Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level3Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < 10; i++) {
			if (level3Enemy[i] != nullptr) {
				gotoxy(level3Enemy[i]->PosXY.GetX(), level3Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level3Enemy[i]->Draw_Icon();
			}
		}

		//check win or lose
		if (alliesdead == Amt_Lvl2_Allies) {
			test = true;
		}
		else if (enemiesdead == Amt_Lvl2_Enemy) {
			test = true;
		}
		else {
			test = false;
		}
	}


	//Delete backlog
	for (int i = 0; i < 7; i++) {
		if (level3Allies[i] != nullptr) {
			delete level3Allies[i];
			level3Allies[i] = nullptr;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (level3Enemy[i] != nullptr) {
			delete level3Enemy[i];
			level3Enemy[i] = nullptr;
		}
	}
	for (int i = 0; i < Amt_Trees; i++) {
		if (trees[i] != nullptr) {
			delete trees[i];
			trees[i] = nullptr;
		}
	}
	for (int i = 0; i < Amt_House; i++) {
		if (houses[i] != nullptr) {
			delete houses[i];
			houses[i] = nullptr;
		}
	}
}

bool mapmain3::CheckAttack(Entity& main, Entity& other, char direction)
{
	//a temp variable to store ture/false
	bool attackable = false;
	////Check if object is blocking
	//bool objectblocking = false;

	////values 
	//int x = main.PosXY.GetX();
	//int y = main.PosXY.GetY();
	//int Range = main.GetRange();
	//int xother = other.PosXY.GetX();
	//int yother = other.PosXY.GetY();
	////Store distance between enemy 
	//int dx = abs(xother - x);
	//int dy = abs(yother - y);

	////Check if enemy within range
	//if (dx <= Range && dy <= Range) {

	//	//Check if enemy is aligned 
	//	if (x == xother || y == yother) {

	//		//check EVERY object to see if any is obstructing player 
	//		for (int i = 0; i < AmtofObjs; i++) {

	//			int xobj = trees[i]->objPos.GetX();
	//			int yobj = trees[i]->objPos.GetY();
	//			int Endx = 0; int Endy = 0;

	//			//Store distance between enviromental objects
	//			//Check if obj is UP of entity
	//			Endx = abs(x - xobj);
	//			Endy = abs(y - yobj);

	//			//Up
	//			if (direction == 'W') {
	//				//Check for any objects aligned and above player 
	//				if (xobj == x && (yobj < y)) {
	//					//Check if within range
	//					if (Endy <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//			//Down
	//			else if (direction == 'S') {
	//				//Check for any objects aligned and above player 
	//				if (xobj == x && (yobj > y)) {
	//					//Check if within range
	//					if (Endy <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//			//Right
	//			else if (direction == 'D') {
	//				//Check for any objects aligned and above player 
	//				if (yobj == y && (xobj > x)) {
	//					//Check if within range
	//					if (Endx <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//			//Left
	//			else if (direction == 'A') {
	//				//Check for any objects aligned and above player 
	//				if (yobj == y && (xobj < x)) {
	//					//Check if within range
	//					if (Endx <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else
	//		//if enemies not aligned cant attack
	//		objectblocking = true;
	//}
	////if no enemies in range, cant attack
	//else
	//	objectblocking = true;

	////If no obstructions, attack
	//if (objectblocking == false) {
	//	attackable = true;
	//}

	return attackable;
}

bool mapmain3::EnemyCheckAtk(Entity& ally, Entity& Enemy)
{
	////a temp variable to store ture/false
	bool attackable = false;
	////Check if object is blocking
	//bool objectblocking = false;

	////values 
	//int x = Enemy.PosXY.GetX();
	//int y = Enemy.PosXY.GetY();
	//int Range = Enemy.GetRange();
	//int xother = ally.PosXY.GetX();
	//int yother = ally.PosXY.GetY();

	////Store distance between allies  and enemy
	//int dx = abs(x - xother);
	//int dy = abs(y - yother);

	////Check if enemy is within range
	//if (dx <= Range && dy <= Range) {

	//	//Check if they are aligned
	//	//ally on y axis
	//	if (x == xother) {

	//		//check EVERY object to see if any is obstructing  
	//		for (int i = 0; i < Amt_Trees; i++) {

	//			int xobj = trees[i]->objPos.GetX();
	//			int yobj = trees[i]->objPos.GetY();
	//			int Endy = 0;

	//			//Store distance between enviromental objects
	//			Endy = abs(y - yobj);

	//			//If ally is above
	//			if (yother < y) {
	//				//check if enviroment obj above
	//				if ((x == xobj) && (yobj < y)) {
	//					//Check if object in range
	//					if (Endy <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//			//If ally is below 
	//			else if (yother > y) {
	//				//check if enviroment obj above
	//				if ((x == xobj) && (yobj > y)) {
	//					//Check if object in range
	//					if (Endy <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	//Check if they are aligned
	//	//ally on x axis
	//	else if (y == yother) {

	//		//check EVERY object to see if any is obstructing  
	//		for (int i = 0; i < Amt_Trees; i++) {

	//			int xobj = trees[i]->objPos.GetX();
	//			int yobj = trees[i]->objPos.GetY();
	//			int Endx = 0;

	//			//Store distance between enviromental objects
	//			Endx = abs(x - xobj);

	//			//If ally is on the left
	//			if (xother < x) {
	//				//check if enviroment obj above
	//				if ((y == yobj) && (xobj < x)) {
	//					//Check if object is within range
	//					if (Endx <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//			//If ally is on the right 
	//			else if (xother > x) {
	//				//check if enviroment obj above
	//				if ((y == yobj) && (xobj > x)) {
	//					//Check if object is within range
	//					if (Endx <= Range) {
	//						objectblocking = true;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else
	//		objectblocking = true;
	//}
	//else
	//	//means cant attack 
	//	objectblocking = true;


	////if no object obstruct, attack
	//if (objectblocking == false) {
	//	attackable = true;
	//}

	return attackable;
}

bool mapmain3::CheckEnviroCollide(Entity& main, char direction)
{
	//store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	bool result = false;

	//Check with EVERY object
	for (int i = 0; i < Amt_Trees; i++) {

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
