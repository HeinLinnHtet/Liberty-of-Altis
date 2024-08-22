#include "mapmain3.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"


environmentalObjs* mapmain3::trees[Amt_Trees];
environmentalObjs* mapmain3::houses[Amt_House];

int mapmain3::Amt_Lvl3_Enemy = 10;
int mapmain3::Amt_Lvl3_Allies = 7;
bool mapmain3::GameOver = false;


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

	for (int i = 0; i < Amt_Trees; i++) {
		trees[i]->setx(trees[i]->getx() + 4);
		trees[i]->sety(trees[i]->gety() + 1);
	}

	for (int i = 0; i < Amt_House; i++) {
		houses[i]->setx(houses[i]->getx() + 4);
		houses[i]->sety(houses[i]->gety() + 1);
	}

}

void mapmain3::map3game(
	int rifleamount,
	int mcgunamount,
	int grendamount,
	int motaramount,
	int artilamount,
	int tankamount,
	int ifvamount)
{
	//draw out map 
	drawmap();

	alliesdead = 0;
	enemiesdead = 0;

	const int Allies_Limit = 15;

	///// #### NOT POLYMORHPHISM ####		
	// instantiating objects	

	//Spawn enemies 
	EnemyTroops* level3Enemy[numberofenemies];
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
	AlliedTroops* level3Allies[Allies_Limit];
	for (int i = 0; i < Allies_Limit; i++) {
		level3Allies[i] = nullptr;
	}

	//rifle man
	for (int i = 0; i < rifleamount; i++) { 
		level3Allies[i] = new ARiflesman;
	}
	//Lmg    // rifleamount 
	for (int i = 0; i < mcgunamount; i++) {
		level3Allies[i + rifleamount] = new AMachinegunner;
	}
	//Grenadier
	for (int i = 0; i < grendamount; i++) {
		level3Allies[i + rifleamount + mcgunamount ] = new AGrenadier;
	}
	//Mortar	
	for (int i = 0; i < motaramount; i++) {
		level3Allies[i + rifleamount + mcgunamount + grendamount ] = new AMotar;
	}
	//Artillery	
	for (int i = 0; i < artilamount; i++) {
		level3Allies[i + rifleamount + mcgunamount + grendamount + motaramount ] = new AArtillery;
	}
	//Tank	
	for (int i = 0; i < tankamount; i++) {
		level3Allies[i + rifleamount + mcgunamount + grendamount + motaramount + artilamount ] = new ATank;
	}
	//IFV
	for (int i = 0; i < ifvamount; i++) {
		level3Allies[i + rifleamount + mcgunamount + grendamount + motaramount + artilamount + tankamount ] = new AIFV;
	}



	//Set all troop positions
	color(0x09);
	if (level3Allies[0] != nullptr){
		SetStartPos(*level3Allies[0], 37, 3);
	}
	if (level3Allies[1] != nullptr) {
		SetStartPos(*level3Allies[1], 35, 4);
	}
	if (level3Allies[2] != nullptr) {
		SetStartPos(*level3Allies[2], 33, 2);
	}
	if (level3Allies[3] != nullptr) {
		SetStartPos(*level3Allies[3], 45, 4);
	}
	if (level3Allies[4] != nullptr) {
		SetStartPos(*level3Allies[4], 35, 6);
	}
	if (level3Allies[5] != nullptr) {
		SetStartPos(*level3Allies[5], 45, 6);
	}
	if (level3Allies[6] != nullptr) {
		SetStartPos(*level3Allies[6], 33, 4);
	}
	if (level3Allies[7] != nullptr) {
		SetStartPos(*level3Allies[7], 40, 3);
	}
	if (level3Allies[8] != nullptr) {
		SetStartPos(*level3Allies[8], 28, 4);
	}
	if (level3Allies[9] != nullptr) {
		SetStartPos(*level3Allies[9], 40, 5);
	}
	if (level3Allies[10] != nullptr) {
		SetStartPos(*level3Allies[10], 41, 13);
	}
	if (level3Allies[11] != nullptr) {
		SetStartPos(*level3Allies[11], 41, 15);
	}
	if (level3Allies[12] != nullptr) {
		SetStartPos(*level3Allies[12], 32, 14);
	}
	if (level3Allies[13] != nullptr) {
		SetStartPos(*level3Allies[13], 33, 15);
	}
	if (level3Allies[Allies_Limit - 1] != nullptr) {
		SetStartPos(*level3Allies[Allies_Limit - 1], 29, 11);
	}

	color(0x06);
	SetStartPos(*level3Enemy[0], 5, 2);
	SetStartPos(*level3Enemy[1], 5, 5);
	SetStartPos(*level3Enemy[2], 7, 5);
	SetStartPos(*level3Enemy[3], 11, 6);
	SetStartPos(*level3Enemy[4], 10, 10);
	SetStartPos(*level3Enemy[5], 23, 13);
	SetStartPos(*level3Enemy[6], 20, 16);
	SetStartPos(*level3Enemy[7], 17, 9);
	SetStartPos(*level3Enemy[8], 23, 10);
	SetStartPos(*level3Enemy[9], 25, 11);


	////Check if all enemies have died  ### To change
	bool GameOver = false;

	while (GameOver == false) {

		int enemycposx, enemycposy;

		///////////STATS
		{
			//display the stats
			//Enemy troops live stats
			gotoxy(65, 1);
			color(0x06);
			std::cout << "Enemy Troops";

			//stats
			gotoxy(65, 2);
			std::cout << "Health  Attack  Range";

			//rifleman
			for (int i = 0; i < 6; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level3Enemy[i]->GetRange();
				}
			}
			//machine gunner
			for (int i = 6; i < 8; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "McGunner " << i - 5 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level3Enemy[i]->GetRange();
				}
			}
			//Grenadier
			for (int i = 8; i < 10; i++) {
				if (level3Enemy[i] != nullptr) {
					gotoxy(55, 3 + i);
					std::cout << "Grenader " << i - 7 << ": " << level3Enemy[i]->GetHealth() << " ";

					gotoxy(75, 3 + i);
					std::cout << level3Enemy[i]->GetAttack();

					gotoxy(83, 3 + i);
					std::cout << level3Enemy[i]->GetRange();
				}
			}

			//Allied troops
			gotoxy(65, numberofenemies + 3);
			color(0x09);
			std::cout << "Allied Troops";

			//stats
			gotoxy(65, numberofenemies + 4);
			std::cout << "Health  Attack  Range";

			//for rifleman
			for (int i = 0; i < rifleamount; i++) {   
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i + 1 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//machinegunner            
			for (int i = rifleamount; i < mcgunamount + rifleamount; i++) {  
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i - 2 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//grenadier
			for (int i = mcgunamount + rifleamount; i < grendamount + mcgunamount + rifleamount; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i - 4 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//mortar
			for (int i = grendamount + mcgunamount + rifleamount; i < motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i + 1 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//artillery
			for (int i = motaramount + grendamount + mcgunamount + rifleamount; i < artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i - 2 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//tank
			for (int i = artilamount + motaramount + grendamount + mcgunamount + rifleamount; i < tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i - 4 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}

			//ifv
			for (int i = tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i < ifvamount + tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level3Allies[i] != nullptr) {
					gotoxy(55, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->Getname() << i + 1 << ": " << level3Allies[i]->GetHealth() << " ";

					gotoxy(75, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetAttack();

					gotoxy(83, numberofenemies + 5 + i);
					std::cout << level3Allies[i]->GetRange();
				}
			}
		}


		////////For player troops
		// Player choose action 
		for (int i = 0; i < Allies_Limit; i++) {
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
						if (ABorderCollision(*level3Allies[i],choice) == true) {
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
							for (int j = 0; j < Allies_Limit; j++) {
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
		for (int i = 0; i < Allies_Limit; i++) {
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
				for (int j = 0; j < Allies_Limit; j++) {
					if (level3Allies[j] != nullptr) {
						if (EnemyCheckAtk(*level3Allies[j], *level3Enemy[i]) == true) {
							level3Enemy[i]->DamageDealt(*level3Allies[j]);
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
					if (EBorderCollision(*level3Enemy[i],input) == true) {
						gotoxy(15, 20);
						std::cout << "Enemy Collided border";
						ValidMove = false;
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < Allies_Limit; j++) {
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
			for (int j = 0; j < Allies_Limit; j++) {
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
		for (int i = 0; i < Allies_Limit; i++) {
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
		if (alliesdead == Amt_Lvl3_Allies) {
			GameOver = true;
		}
		else if (enemiesdead == Amt_Lvl3_Enemy) {
			winloss.win();
			GameOver = true;
		}
		else {
			GameOver = false;
		}
	}


	//Delete backlog
	for (int i = 0; i < Allies_Limit; i++) {
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

			//arty
			if (main.Draw_Icon() == 'A' || main.Draw_Icon() == 'O') {
				objectblocking = false;
			}
			else {
				//check EVERY object to see if any is obstructing player 
				for (int i = 0; i < Amt_Trees; i++) {

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

				if (objectblocking == true) {
					for (int i = 0; i < Amt_House; i++) {

						int xobj = houses[i]->objPos.GetX();
						int yobj = houses[i]->objPos.GetY();
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

bool mapmain3::EnemyCheckAtk(Entity& ally, Entity& Enemy)
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

		if (x == xother) {

			if (Enemy.Draw_Icon() == 'A' || Enemy.Draw_Icon() == 'O') {
				objectblocking = false;
			}
			else {
				//check EVERY object to see if any is obstructing  
				for (int i = 0; i < Amt_Trees; i++) {

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

				if (objectblocking == true) {
					//check EVERY object to see if any is obstructing  
					for (int i = 0; i < Amt_House; i++) {

						int xobj = houses[i]->objPos.GetX();
						int yobj = houses[i]->objPos.GetY();
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

			}
		}
		else if (y == yother) {
			if (Enemy.Draw_Icon() == 'A' || Enemy.Draw_Icon() == 'O') {
				objectblocking = false;
			}
			else {
				//check EVERY object to see if any is obstructing  
				for (int i = 0; i < Amt_Trees; i++) {

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

				if (objectblocking == true) {
					for (int i = 0; i < Amt_House; i++) {

						int xobj = houses[i]->objPos.GetX();
						int yobj = houses[i]->objPos.GetY();
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
			}

		}
		else
			objectblocking = true;

	}
	else
		objectblocking = true;

	//if no object obstruct, attack
	if (objectblocking == false) {
		attackable = true;
	}

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

	//for the houses
	if (result == false) {
		for (int i = 0; i < Amt_House; i++) {

			int XEnviro = houses[i]->objPos.GetX();
			int YEnviro = houses[i]->objPos.GetY();

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
	}

	return result;
}

bool mapmain3::GetGameOver(void)
{
	return GameOver;
}





