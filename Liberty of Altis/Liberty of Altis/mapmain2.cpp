#include "mapmain2.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"
#include "towers.h"

//environmental objects
walls* mapmain2::wallver[Amt_WallVer];
walls* mapmain2::wallhor[Amt_WallHor];
environmentalObjs* mapmain2::barricade[Amt_Barricade];
towers* mapmain2::tower[Amt_Tower];


mapmain2::mapmain2()
{
	alliesdead = 0;
	enemiesdead = 0;
}

void mapmain2::drawmap()
{
	bool objexist = false;

	//prison walls vertical
	wallver[0] = new walls(60, char(219), 14, 2);
	wallver[1] = new walls(60, char(219), 14, 5);
	wallver[2] = new walls(60, char(219), 14, 8);
	wallver[3] = new walls(60, char(219), 14, 11);
	wallver[4] = new walls(60, char(219), 14, 14);
	wallver[5] = new walls(60, char(219), 14, 15);

	//virgil cage
	wallver[6] = new walls(60, char(178), 4, 8);
	wallver[7] = new walls(60, char(178), 4, 9);

	//prison walls horizontal
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

	/*tower[0]->attack();
	tower[1]->attack();*/


	//Shift to position
	for (int i = 0; i < Amt_Barricade; i++) {
		barricade[i]->setx(barricade[i]->getx() + 4);
		barricade[i]->sety(barricade[i]->gety() + 1);
	}
	//Shift to position
	for (int i = 0; i < Amt_WallVer; i++) {
		wallver[i]->setx(wallver[i]->getx() + 4);
		wallver[i]->sety(wallver[i]->gety() + 1);
	}
	//Shift to position
	for (int i = 0; i < Amt_WallHor; i++) {
		wallhor[i]->setx(wallhor[i]->getx() + 4);
		wallhor[i]->sety(wallhor[i]->gety() + 1);
	}
	//Shift to position
	for (int i = 0; i < Amt_Tower; i++) {
		tower[i]->setx(tower[i]->getx() + 4);
		tower[i]->sety(tower[i]->gety() + 1);
	}


}




//Start game 2
void mapmain2::map2game(void)
{
	//draw map
	drawmap();

	

	const int Enemy_lvl2 = 5;
	const int Allies_lvl2 = 7;

	//Spawn the characters
	//Spawn enemies 
	EnemyTroops* level2Enemy[Enemy_lvl2];
	//rifle man
	for (int i = 0; i < 2; i++) {
		level2Enemy[i] = new ERiflesman;
	}
	//Machine gunner
	for (int i = 2; i < 4; i++) {
		level2Enemy[i] = new EMachinegunner;
	}
	//Grenadier
	for (int i = 4; i < Enemy_lvl2; i++) {
		level2Enemy[i] = new EGrenadier;
	}

	//Spawn allies 
	AlliedTroops* level2Allies[Allies_lvl2];
	//rifle man 
	for (int i = 0; i < 3; i++) {
		level2Allies[i] = new ARiflesman;
	}
	for (int i = 3; i < 5; i++) {
		level2Allies[i] = new AMachinegunner;
	}
	for (int i = 5; i < Allies_lvl2; i++) {
		level2Allies[i] = new AGrenadier;
	}

	//Spawning locations
	color(0x09);
	//SetStartPos(*level2Allies[0], 43, 6);
	SetStartPos(*level2Allies[1], 49, 8);
	SetStartPos(*level2Allies[2], 45, 7);
	SetStartPos(*level2Allies[3], 41, 11);
	SetStartPos(*level2Allies[4], 43, 3);
	SetStartPos(*level2Allies[5], 49, 14);
	SetStartPos(*level2Allies[6], 43, 15);

	color(0x06);
	//SetStartPos(*level2Enemy[0], 21, 8);
	SetStartPos(*level2Enemy[1], 21, 12);
	SetStartPos(*level2Enemy[2], 23, 11);
	SetStartPos(*level2Enemy[3], 25, 14);
	SetStartPos(*level2Enemy[4], 27, 9);

	SetStartPos(*level2Enemy[0], 24, 5);
	//SetStartPos(*level2Enemy[1], 20, 12);
	//SetStartPos(*level2Enemy[2], 20, 11);
	//SetStartPos(*level2Enemy[3], 20, 14);
	//SetStartPos(*level2Enemy[4], 20, 9);

	//SetStartPos(*level2Enemy[0], 20, 8);
	SetStartPos(*level2Allies[0], 20, 9);


	//Check if enemy died will need change later #####
	bool test = false;

	while (test == false) {

		enemiesdead = 0;
		alliesdead = 0;

		int enemycposx, enemycposy;

		///////////STATS
		{
			//display the stats
			//allied troops live stats
			gotoxy(65, 1);
			color(0x06);
			std::cout << "Enemy Troops";

			//stats
			gotoxy(65, 2);
			std::cout << "Health  Attack  Range";

			//rifleman
			for (int i = 0; i < 2; i++) {
				if (level2Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level2Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level2Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level2Enemy[i]->GetRange();
				}
			}
			//machine gunner
			for (int i = 2; i < 4; i++) {
				if (level2Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "McGunner " << i - 1 << ": " << level2Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level2Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level2Enemy[i]->GetRange();
				}
			}
			//Grenadier
			for (int i = 4; i < Enemy_lvl2; i++) {
				if (level2Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "Grenader " << i - 3 << ": " << level2Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level2Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level2Enemy[i]->GetRange();
				}
			}


			//Enemy troops
			gotoxy(65, 12);
			color(0x09);
			std::cout << "Allied Troops";

			//stats
			gotoxy(65, 13);
			std::cout << "Health  Attack  Range";

			//for rifleman
			for (int i = 0; i < 3; i++) {
				if (level2Allies[i] != nullptr) {
					gotoxy(55, 14 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level2Allies[i]->GetHealth() << " ";

					gotoxy(75, 14 + i);
					std::cout << level2Allies[i]->GetAttack();

					gotoxy(83, 14 + i);
					std::cout << level2Allies[i]->GetRange();
				}
			}

			//machinegunner
			for (int i = 3; i < 5; i++) {
				if (level2Allies[i] != nullptr) {

					gotoxy(55, 14 + i);
					std::cout << "McGunner " << i - 2 << ": " << level2Allies[i]->GetHealth() << " ";

					gotoxy(75, 14 + i);
					std::cout << level2Allies[i]->GetAttack();

					gotoxy(83, 14 + i);
					std::cout << level2Allies[i]->GetRange();
				}
			}

			//grenadier
			for (int i = 5; i < Allies_lvl2; i++) {
				if (level2Allies[i] != nullptr) {
					gotoxy(55, 14 + i);
					std::cout << "Grenader " << i - 4 << ": " << level2Allies[i]->GetHealth() << " ";

					gotoxy(75, 14 + i);
					std::cout << level2Allies[i]->GetAttack();

					gotoxy(83, 14 + i);
					std::cout << level2Allies[i]->GetRange();
				}
			}
		}


		////////For player troops
		// Player choose action 
		for (int i = 0; i < Allies_lvl2; i++) {
			bool ValidMove = false;

			//Get user input, WASD to move or J to attack 
			gotoxy(15, 25);
			color(0x0F);
			std::cout << "WASD to Move, J to Attack";

			char choice = 'Z';


			if (level2Allies[i] != nullptr) {
				//prevent from reading in console
				gotoxy(level2Allies[i]->PosXY.GetX(), level2Allies[i]->PosXY.GetY());
				color(0x0D);
				std::cout << level2Allies[i]->Draw_Icon();
				choice = _getch();
				//caps
				choice = toupper(choice);
			}

			//Check if Ally is alive  (prevent crashes)
			if (level2Allies[i] != nullptr) {

				//Movement 
				if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
					//Movement Code
					while (ValidMove == false) {

						//allow to check movement is valid 
						bool CanMove = true;

						//Check collison with borders
						if (level2Allies[i]->BorderCollision(choice) == true) {
							gotoxy(15, 20);
							std::cout << "Collided border";
							CanMove = false;
						}

						//Check collison between Allies and Enemies
						if (CanMove == true) {
							for (int j = 0; j < Enemy_lvl2; j++) {
								if (level2Enemy[j] != nullptr) {
									if (level2Allies[i]->Entitycollision(*level2Enemy[j], choice) == true) {
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
							for (int j = 0; j < Allies_lvl2; j++) {
								if (level2Allies[j] != nullptr) {
									if (level2Allies[i]->Entitycollision(*level2Allies[j], choice) == true) {
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
							if (CheckEnviroCollide(*level2Allies[i], choice) == true) {
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
							MoveEntity(*level2Allies[i], choice);
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
					bool CheckAtkWall = true;

					while (!(attackDir == 'w' || attackDir == 's' || attackDir == 'a' || attackDir == 'd')) {
						attackDir = _getch();
						gotoxy(15, 23);
						std::cout << "attack direction";
					}
					attackDir = toupper(attackDir);

					//Check if can attack any enemies 
					for (int j = 0; j < Enemy_lvl2; j++) {
						if (level2Enemy[j] != nullptr) {
							if (CheckAttack(*level2Allies[i], *level2Enemy[j], attackDir) == true) {
								level2Allies[i]->DamageDealt(*level2Enemy[j]);

								gotoxy(15, 25);
								std::cout << "attack Dealt";
								gotoxy(15, 26);
								std::cout << level2Enemy[j]->GetHealth() << " " << j << " " << i;
								CheckAtkWall = false;
								break;
							}
						}
					}

					//Check if wall is being attacked
					if (CheckAtkWall == true) {
						for (int j = 0; j < Amt_WallVer; j++) {
							if (wallver[j] != nullptr) {
								if (CheckWallsAttack(*level2Allies[i], attackDir) == true) {
									gotoxy(10, 27);
									int hp = wallver[j]->gethealth();
									std::cout << hp;

									gotoxy(15, 28);
									std::cout << "Attacking wall";

									//Deal damage
									//int newhealth = wallver[j]->gethealth() - level2Allies[i]->GetAttack();
									//wallver[j]->sethealth(newhealth);
									wallver[j]->sethealth(wallver[j]->gethealth() - level2Allies[i]->GetAttack());

									gotoxy(15, 27);
									hp = wallver[j]->gethealth();
									std::cout << hp;

									break;
								}
							}
						}
					}
				}
			}




			//Check if Enemy is alive 
			for (int j = 0; j < Enemy_lvl2; j++) {

				if (!(level2Enemy[j] == nullptr)) {
					if (level2Enemy[j]->isEntityAlive() == false) {
						enemycposx = level2Enemy[j]->PosXY.GetX();
						enemycposy = level2Enemy[j]->PosXY.GetY();


						gotoxy(enemycposx, enemycposy);
						std::cout << 'X';

						//kill enemy 
						enemiesdead = enemiesdead + 1;
						delete level2Enemy[j];
						level2Enemy[j] = nullptr;
					}
				}
			}
		}

		//UI 
		drawmap();
		//Update new position 
		for (int i = 0; i < Allies_lvl2; i++) {
			if (level2Allies[i] != nullptr) {
				gotoxy(level2Allies[i]->PosXY.GetX(), level2Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level2Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < Enemy_lvl2; i++) {
			if (level2Enemy[i] != nullptr) {//error is here
				gotoxy(level2Enemy[i]->PosXY.GetX(), level2Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level2Enemy[i]->Draw_Icon();
			}
		}

		////////// For enemy troops 
		for (int i = 0; i < Enemy_lvl2; i++) {

			//allow to check movement is valid 
			bool Moving = true;

			//Check if enemy is alive (prevent crashes) 
			if (level2Enemy[i] != nullptr) {

				//Attacking, Check if can attack first 
				for (int j = 0; j < Allies_lvl2; j++) {
					if (level2Allies[j] != nullptr) {
						if (EnemyCheckAtk(*level2Allies[j], *level2Enemy[i]) == true) {
							level2Enemy[i]->DamageDealt(*level2Allies[j]);
							gotoxy(50, 23);
							std::cout << "Enemy attacking " << i << " " << j << " " << level2Allies[j]->GetHealth();
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
					int num = level2Enemy[i]->RandomNum();
					//convert to char
					char input = num + '0';

					//Check collison with borders
					if (level2Enemy[i]->BorderCollision(input) == true) {
						gotoxy(15, 20);
						std::cout << "Enemy Collided border";
						ValidMove = false;
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < Allies_lvl2; j++) {
							if (level2Allies[j] != nullptr) {
								if (level2Enemy[i]->Entitycollision(*level2Allies[j], input) == true) {
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
						for (int j = 0; j < Enemy_lvl2; j++) {
							if (level2Enemy[j] != nullptr) {
								if (level2Enemy[i]->Entitycollision(*level2Enemy[j], input) == true) {
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
						if (CheckEnviroCollide(*level2Enemy[i], input) == true) {
							gotoxy(15, 22);
							std::cout << "Enemy Collided Environment";
							ValidMove = false;
							break;
						}
					}

					//reflect movement of entity on screen 
					if (ValidMove == true) {
						MoveEntity(*level2Enemy[i], input);
						Moving = false;

					}
					else if (ValidMove == false) {
						gotoxy(15, 23);
						std::cout << "Enemy Invalid Movement";
					}
				}
			}

			//Check if allies are alive 
			for (int j = 0; j < Allies_lvl2; j++) {
				if (level2Allies[j] != nullptr) {
					if (level2Allies[j]->isEntityAlive() == false) {
						gotoxy(level2Allies[j]->PosXY.GetX(), level2Allies[j]->PosXY.GetY());
						std::cout << 'X';

						//kill alliies
						alliesdead = alliesdead + 1;
						delete level2Allies[j];
						level2Allies[j] = nullptr;
					}
				}
			}
		}

		//UI
		drawmap();
		//Update new position 
		for (int i = 0; i < Allies_lvl2; i++) {
			if (level2Allies[i] != nullptr) {
				gotoxy(level2Allies[i]->PosXY.GetX(), level2Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level2Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < Enemy_lvl2; i++) {
			if (level2Enemy[i] != nullptr) {
				gotoxy(level2Enemy[i]->PosXY.GetX(), level2Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level2Enemy[i]->Draw_Icon();
			}
		}

		//check win or lose
		if (alliesdead == Allies_lvl2) {
			winloss.loss();
			map2game();
		}
		else if (enemiesdead == Enemy_lvl2) {
			winloss.win();
			test = true;
		}
		else {
			test = false;
		}
	}








	//Delete backlog
	for (int i = 0; i < Allies_lvl2; i++) {
		if (level2Allies[i] != nullptr) {
			delete level2Allies[i];
		}
	}
	for (int i = 0; i < Enemy_lvl2; i++) {
		if (level2Enemy[i] != nullptr) {
			delete level2Enemy[i];
		}
	}
	for (int i = 0; i < Amt_WallVer; i++) {
		if (wallver[i] != nullptr) {
			delete wallver[i];
		}
	}
	for (int i = 0; i < Amt_WallHor; i++) {
		if (wallhor[i] != nullptr) {
			delete wallhor[i];
		}
	}
	for (int i = 0; i < Amt_Barricade; i++) {
		if (barricade[i] != nullptr) {
			delete barricade[i];
		}
	}
	for (int i = 0; i < Amt_Tower; i++) {
		if (tower[i] != nullptr) {
			delete tower[i];
		}
	}
}





//Check attack
bool mapmain2::CheckAttack(Entity& main, Entity& other, char direction)
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
			for (int i = 0; i < Amt_Barricade; i++) {

				int xobj = barricade[i]->objPos.GetX();
				int yobj = barricade[i]->objPos.GetY();
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
bool mapmain2::EnemyCheckAtk(Entity& ally, Entity& Enemy)
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

			//check EVERY object to see if any is obstructing (barricade)
			for (int i = 0; i < Amt_Barricade; i++) {

				int xobj = barricade[i]->objPos.GetX();
				int yobj = barricade[i]->objPos.GetY();
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
			for (int i = 0; i < Amt_Barricade; i++) {

				int xobj = barricade[i]->objPos.GetX();
				int yobj = barricade[i]->objPos.GetY();
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
bool mapmain2::CheckEnviroCollide(Entity& main, char direction)
{
	//store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	bool result = false;

	//Check with EVERY object (barricade)
	for (int i = 0; i < Amt_Barricade; i++) {

		int XEnviro = barricade[i]->objPos.GetX();
		int YEnviro = barricade[i]->objPos.GetY();

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


	//Check with EVERY object (vertical walls) 
	if (result == false) {
		for (int i = 0; i < Amt_WallVer; i++) {

			int XEnviro = wallver[i]->objPos.GetX();
			int YEnviro = wallver[i]->objPos.GetY();

			//check if wall is destroyed 
			if (wallver[i] != nullptr) {

				//Find the range of wall from top to bottom
				int Walltop = YEnviro - 1;
				int WallBottom = YEnviro + 1;

				//Check if Entity is within range of walls
				if ((XEntity - 2 == XEnviro) || (XEntity + 2 == XEnviro)) {

					//Check if environemnt is aligned horizontally
					if ((YEntity <= WallBottom) || (YEntity >= Walltop)) {
						
						//if trying to move into the wall
						if (direction == 'A' || direction == 'D' || direction == '2' || direction == '3') {
							result = true;
							break;
						}
					}
				}
			}
		}
	}

	return result;

}

//Check if walls being destroyed
bool mapmain2::CheckWallsAttack(Entity& main, char direction)
{
	//store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	bool attacking = false;

	for (int i = 0; i < Amt_WallVer; i++) {

		int XEnviro = wallver[i]->objPos.GetX();
		int YEnviro = wallver[i]->objPos.GetY();

		//Check if wall arleady destroyed
		if (wallver[i] != nullptr) {
	
			int Walltop = YEnviro - 1;
			int WallBottom = YEnviro + 1;

			//Check Entity in range 
			if (XEntity - 2 == XEnviro) {

				//Check if player is trying to attack the wall
				if (direction == 'A') {

					//Check which wall to attack
					if ((YEntity <= WallBottom) && (YEntity >= Walltop)) {
						attacking = true;
						
						break;
					}
				}
			}
		}
	}



	return attacking;
}
