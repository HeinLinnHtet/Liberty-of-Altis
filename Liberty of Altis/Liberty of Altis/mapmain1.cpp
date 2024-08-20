#include "mapmain1.h"
#include "environmentalObjs.h"
#include <iostream>

environmentalObjs* mapmain1::trees[AmtofObjs]{};

int mapmain1::Amt_Lvl1_Enemy = 10;
int mapmain1::Amt_Lvl1_Allies = 7;

mapmain1::mapmain1()
{
	alliesdead = 0;
	enemiesdead = 0;
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
//Function to start game 1
void mapmain1::map1game(void)
{
	//draw out map 
	drawmap();	

	alliesdead = 0;
	enemiesdead = 0;

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
		level1Allies[i] = new ATank;
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
	color(0x09);
	SetStartPos(*level1Allies[0], 5, 2);
	SetStartPos(*level1Allies[1], 5, 5);
	SetStartPos(*level1Allies[2], 7, 5);
	SetStartPos(*level1Allies[3], 7, 6);
	SetStartPos(*level1Allies[4], 7, 8);
	SetStartPos(*level1Allies[5], 7, 10);
	SetStartPos(*level1Allies[6], 7, 12);

	color(0x06);
	SetStartPos(*level1Enemy[0], 25, 3);
	SetStartPos(*level1Enemy[1], 30, 4);
	SetStartPos(*level1Enemy[2], 28, 2);
	SetStartPos(*level1Enemy[3], 40, 4);
	SetStartPos(*level1Enemy[4], 30, 6);
	SetStartPos(*level1Enemy[5], 40, 6);
	SetStartPos(*level1Enemy[6], 28, 4);
	SetStartPos(*level1Enemy[7], 35, 3);
	SetStartPos(*level1Enemy[8], 23, 4);
	SetStartPos(*level1Enemy[9], 35, 5);


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
				if (level1Allies[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << level1Allies[i]->Getname() << i + 1 << ": " << level1Allies[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level1Allies[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level1Allies[i]->GetRange();
				}
			}

			//machinegunner
			for (int i = 3; i < 5; i++) {
				if (level1Allies[i] != nullptr) {

					gotoxy(55, 6 + (i - 3));
					std::cout << level1Allies[i]->Getname() << i - 2 << ": " << level1Allies[i]->GetHealth() << " ";

					gotoxy(75, 6 + (i - 3));
					std::cout << level1Allies[i]->GetAttack();

					gotoxy(83, 6 + (i - 3));
					std::cout << level1Allies[i]->GetRange();
				}
			}

			//grenadier
			for (int i = 5; i < 7; i++) {
				if (level1Allies[i] != nullptr) {
					gotoxy(55, 8 + (i - 5));
					std::cout << level1Allies[i]->Getname() << i - 4 << ": " << level1Allies[i]->GetHealth() << " ";

					gotoxy(75, 8 + (i - 5));
					std::cout << level1Allies[i]->GetAttack();

					gotoxy(83, 8 + (i - 5));
					std::cout << level1Allies[i]->GetRange();
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
				if (level1Enemy[i] != nullptr) {
					gotoxy(55, 14 + i);
					std::cout << level1Enemy[i]->Getname() << i + 1 << ": " << level1Enemy[i]->GetHealth() << " ";

					gotoxy(75, 14 + i);
					std::cout << level1Enemy[i]->GetAttack();

					gotoxy(83, 14 + i);
					std::cout << level1Enemy[i]->GetRange();
				}
			}
			//machine gunner
			for (int i = 6; i < 8; i++) {
				if (level1Enemy[i] != nullptr) {
					gotoxy(55, 20 + (i - 6));
					std::cout << level1Enemy[i]->Getname() << i - 5 << ": " << level1Enemy[i]->GetHealth() << " ";

					gotoxy(75, 20 + (i - 6));
					std::cout << level1Enemy[i]->GetAttack();

					gotoxy(83, 20 + (i - 6));
					std::cout << level1Enemy[i]->GetRange();
				}
			}
			//Grenadier
			for (int i = 8; i < 10; i++) {
				if (level1Enemy[i] != nullptr) {
					gotoxy(55, 22 + (i - 8));
					std::cout << level1Enemy[i]->Getname() << i - 7 << ": " << level1Enemy[i]->GetHealth() << " ";

					gotoxy(75, 22 + (i - 8));
					std::cout << level1Enemy[i]->GetAttack();

					gotoxy(83, 22 + (i - 8));
					std::cout << level1Enemy[i]->GetRange();
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


			if (level1Allies[i] != nullptr) {
				//prevent from reading in console
				gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
				color(0x0D);
				std::cout << level1Allies[i]->Draw_Icon();
				choice = _getch();
				//caps
				choice = toupper(choice);
			}

			//Check if Ally is alive  (prevent crashes)
			if (level1Allies[i] != nullptr) {

				//Movement 
				if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
					//Movement Code
					while (ValidMove == false) {

						//allow to check movement is valid 
						bool CanMove = true;

						//Check collison with borders
						if (BorderCollision(*level1Allies[i],choice) == true) {
							gotoxy(15, 20);
							std::cout << "Collided border";
							CanMove = false;
						}

						//Check collison between Allies and Enemies
						if (CanMove == true) {
							for (int j = 0; j < 10; j++) {
								if (level1Enemy[j] != nullptr) {
									if (level1Allies[i]->Entitycollision(*level1Enemy[j], choice) == true) {
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
								if (level1Allies[j] != nullptr) {
									if (level1Allies[i]->Entitycollision(*level1Allies[j], choice) == true) {
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
						if (level1Enemy[j] != nullptr) {
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
			}
			//here for the null ptr part




			//Check if Enemy is alive 
			for (int j = 0; j < 10; j++) {

				if (!(level1Enemy[j] == nullptr)) {
					if (level1Enemy[j]->isEntityAlive() == false) {
						enemycposx = level1Enemy[j]->PosXY.GetX();
						enemycposy = level1Enemy[j]->PosXY.GetY();


						gotoxy(enemycposx, enemycposy);
						std::cout << 'X';

						//kill enemy 
						enemiesdead = enemiesdead + 1;
						delete level1Enemy[j];
						level1Enemy[j] = nullptr;
					}
				}
			}
		}

		//UI 
		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			if (level1Allies[i] != nullptr) {
				gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level1Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < 10; i++) {
			if (level1Enemy[i] != nullptr) {//error is here
				gotoxy(level1Enemy[i]->PosXY.GetX(), level1Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level1Enemy[i]->Draw_Icon();
			}
		}

		////////// For enemy troops 
		for (int i = 0; i < 10; i++) {

			//allow to check movement is valid 
			bool Moving = true;

			//Check if enemy is alive (prevent crashes) 
			if (level1Enemy[i] != nullptr) {

				//Attacking, Check if can attack first 
				for (int j = 0; j < 7; j++) {
					if (level1Allies[j] != nullptr) {
						if (EnemyCheckAtk(*level1Allies[j], *level1Enemy[i]) == true) {
							level1Enemy[i]->DamageDealt(*level1Allies[j]);
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
					int num = level1Enemy[i]->RandomNum();
					//convert to char
					char input = num + '0';

					//Check collison with borders
					if (BorderCollision(*level1Enemy[i],input) == true) {
						gotoxy(15, 20);
						std::cout << "Enemy Collided border";
						ValidMove = false;
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < 7; j++) {
							if (level1Allies[j] != nullptr) {
								if (level1Enemy[i]->Entitycollision(*level1Allies[j], input) == true) {
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
							if (level1Enemy[j] != nullptr) {
								if (level1Enemy[i]->Entitycollision(*level1Enemy[j], input) == true) {
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
						if (CheckEnviroCollide(*level1Enemy[i], input) == true) {
							gotoxy(15, 22);
							std::cout << "Enemy Collided Environment";
							ValidMove = false;
							break;
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

			//Check if allies are alive 
			for (int j = 0; j < 7; j++) {
				if (level1Allies[j] != nullptr) {
					if (level1Allies[j]->isEntityAlive() == false) {
						gotoxy(level1Allies[j]->PosXY.GetX(), level1Allies[j]->PosXY.GetY());
						std::cout << 'X';

						//kill alliies
						alliesdead = alliesdead + 1;
						delete level1Allies[j];
						level1Allies[j] = nullptr;
					}
				}
			}
		}

		//UI
		drawmap();
		//Update new position 
		for (int i = 0; i < 7; i++) {
			if (level1Allies[i] != nullptr) {
				color(0x09);
				//tank or artilery
				if (level1Allies[i]->Draw_Icon() == 'T' || level1Allies[i]->Draw_Icon() == 'A')
				{
					gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
					std::cout << level1Allies[i]->Draw_Icon();
					gotoxy(level1Allies[i]->PosXY.GetX() - 1, level1Allies[i]->PosXY.GetY());
					std::cout << level1Allies[i]->Draw_Icon();
					gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY() - 1);
					std::cout << level1Allies[i]->Draw_Icon();
					gotoxy(level1Allies[i]->PosXY.GetX() - 1, level1Allies[i]->PosXY.GetY() - 1);
					std::cout << level1Allies[i]->Draw_Icon();
				}
				//other troops
				else
				{
					gotoxy(level1Allies[i]->PosXY.GetX(), level1Allies[i]->PosXY.GetY());
					std::cout << level1Allies[i]->Draw_Icon();
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (level1Enemy[i] != nullptr) {
				gotoxy(level1Enemy[i]->PosXY.GetX(), level1Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level1Enemy[i]->Draw_Icon();
			}
		}

		//check win or lose
		if (alliesdead == Amt_Lvl1_Allies) {
			winloss.loss();
			map1game();
		}
		else if (enemiesdead == Amt_Lvl1_Enemy) {
			winloss.win();
			test = true;
		}
		else {
			test = false;
		}
	}


	//Delete backlog
	for (int i = 0; i < 7; i++) {
		if (level1Allies[i] != nullptr) {
			delete level1Allies[i];
			level1Allies[i] = nullptr;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (level1Enemy[i] != nullptr) {
			delete level1Enemy[i];
			level1Enemy[i] = nullptr;
		}
	}
	for (int i = 0; i < AmtofObjs; i++) {
		if (trees[i] != nullptr) {
			delete trees[i];
			trees[i] = nullptr;
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

// Check collision
bool mapmain1::CheckEnviroCollide(Entity& main, char direction)
{
	// Store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	// Check with EVERY object
	for (int i = 0; i < AmtofObjs; i++) {

		int XEnviro = trees[i]->objPos.GetX();
		int YEnviro = trees[i]->objPos.GetY();

		// Tank and artillery
		if (main.Draw_Icon() == 'T' || main.Draw_Icon() == 'A')
		{
			// Check if entity is LR of each other
			if ((XEntity == XEnviro) || (XEntity == XEnviro + 1)) {
				// Down
				if ((YEntity == YEnviro - 1) && direction == 'S') {
					return true;
				}
				// Up
				if ((YEntity == YEnviro + 2) && direction == 'W') {
					return true;
				}
			}

			// Check if entity is UP of each other
			if (YEntity == YEnviro || (YEntity == YEnviro + 1)) {
				// Right
				if ((XEntity == XEnviro - 1) && direction == 'D') {
					return true;
				}
				// Left
				if ((XEntity == XEnviro + 2) && direction == 'A') {
					return true;
				}
			}
		}

		// Other troops
		else
		{
			// Check if entity is LR of each other
			if (XEntity == XEnviro) {
				// Down
				if ((YEntity == YEnviro - 1) && direction == 'S') {
					return true;
				}
				// Up
				if ((YEntity == YEnviro + 1) && direction == 'W') {
					return true;
				}
			}

			// Check if entity is UP of each other
			if (YEntity == YEnviro) {
				// Right
				if ((XEntity == XEnviro - 1) && direction == 'D') {
					return true;
				}
				// Left
				if ((XEntity == XEnviro + 1) && direction == 'A') {
					return true;
				}
			}
		}
	}

	// If no collisions detected, return false
	return false;
}
