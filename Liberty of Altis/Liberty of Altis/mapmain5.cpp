#include "mapmain5.h"
#include <iostream>
#include "environmentalObjs.h"
#include "walls.h"

mapmain5::mapmain5()
{

}

void mapmain5::drawmap()
{
	bool objexist = false;

	environmentalObjs* props[356];
	for (int i = 0; i < 50; i++)
	{
		props[i] = new environmentalObjs(char(219), i, 0);
		props[i + 50] = new environmentalObjs(char(219), i, 17);
	}
	for (int i = 0; i < 6; i++)
	{
		props[i + 100] = new environmentalObjs(char(219), 49, i + 1);
		props[i + 106] = new environmentalObjs(char(219), 49, i + 11);
	}
	for (int i = 0; i < 18; i++)
	{
		props[i + 112] = new environmentalObjs(char(219), 0, i + 1);
	}

	//door
	props[130] = new environmentalObjs(char(219), 48, 5);
	props[131] = new environmentalObjs(char(219), 48, 6);

	props[132] = new environmentalObjs(char(219), 48, 11);
	props[133] = new environmentalObjs(char(219), 48, 12);

	//tables
	//middle table
	for (int i = 0; i < 28; i++)
	{
		props[i + 134] = new environmentalObjs(char(219), i + 9, 1);
		props[i + 162] = new environmentalObjs(char(219), i + 9, 3);
		props[i + 190] = new environmentalObjs(char(219), i + 9, 5);
		props[i + 218] = new environmentalObjs(char(219), i + 9, 12);
		props[i + 246] = new environmentalObjs(char(219), i + 9, 14);
		props[i + 274] = new environmentalObjs(char(219), i + 9, 16);
	}

	//table near the door
	for (int i = 0; i < 5; i++)
	{
		props[i + 302] = new environmentalObjs(char(219), 40, i + 1);
		props[i + 307] = new environmentalObjs(char(219), 41, i + 1);

		props[i + 312] = new environmentalObjs(char(219), 44, i + 1);
		props[i + 317] = new environmentalObjs(char(219), 45, i + 1);

		props[i + 322] = new environmentalObjs(char(219), 40, i + 12);
		props[i + 327] = new environmentalObjs(char(219), 41, i + 12);

		props[i + 332] = new environmentalObjs(char(219), 44, i + 12);
		props[i + 337] = new environmentalObjs(char(219), 45, i + 12);
	}

	//middle table
	//sides
	for (int i = 0; i < 5; i++)
	{
		props[i + 342] = new environmentalObjs(char(219), i + 5, 7);
		props[i + 347] = new environmentalObjs(char(219), i + 5, 10);
	}
	//middle
	props[352] = new environmentalObjs(char(219), 8, 8);
	props[353] = new environmentalObjs(char(219), 9, 8);

	props[354] = new environmentalObjs(char(219), 8, 9);
	props[355] = new environmentalObjs(char(219), 9, 9);

	walls* barricade[8];
	//top
	barricade[0] = new walls(100, char(219), 23, 2);
	barricade[1] = new walls(100, char(219), 23, 4);
	//bottom
	barricade[2] = new walls(100, char(219), 23, 13);
	barricade[3] = new walls(100, char(219), 23, 15);
	//middle
	barricade[4] = new walls(100, char(219), 18, 6);
	barricade[5] = new walls(100, char(219), 21, 6);
	barricade[6] = new walls(100, char(219), 24, 6);
	barricade[7] = new walls(100, char(219), 27, 6);

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

			//normal environmental objects
			for (int k = 0; k < 356; k++)
			{
				//outer wall color
				color(0x08);
				//check color for the door
				if (k > 129 && k < 134)
				{
					color(0x0F);
				}
				//check color for tables 
				if (k > 133)
				{
					color(0x0E);
				}
				if (props[k]->getx() == i and props[k]->gety() == j)
				{
					std::cout << props[k]->getsymbol();
					objexist = true;
				}
			}

			//barricade
			for (int k = 0; k < 8; k++)
			{
				if (barricade[k]->getx() == i and barricade[k]->gety() == j)
				{
					color(0x08);
					std::cout << barricade[k]->getsymbol();
					objexist = true;
				}
				//longer barricade
				if (k > 3)
				{
					for (int l = 0; l < 6; l++)
						if (barricade[k]->getx() == i and barricade[k]->gety() + l == j)
						{
							color(0x08);
							std::cout << barricade[k]->getsymbol();
							objexist = true;
						}
				}
			}

			if (!objexist)
			{
				color(0x0C);
				std::cout << char(219);
			}
		}
	}
}

//void mapmain5::map5game()
//{
//
//	{
//		//draw out map 
//		drawmap();
//
//		///// #### NOT POLYMORHPHISM ####		
//		// instantiating objects	
//
//		//Spawn enemies 
//		EnemyTroops* level5Enemy[10];
//		//rifle man
//		for (int i = 0; i < 6; i++) {
//			level5Enemy[i] = new ERiflesman;
//		}
//		//Lmg
//		for (int i = 6; i < 8; i++) {
//			level5Enemy[i] = new EMachinegunner;
//		}
//		//Grenadier
//		for (int i = 8; i < 10; i++) {
//			level5Enemy[i] = new EGrenadier;
//		}
//
//
//		//Spawn allies 
//		AlliedTroops* level5Allies[7];
//		//rifle man 
//		for (int i = 0; i < 3; i++) {
//			level5Allies[i] = new ARiflesman;
//		}
//		//Lmg
//		for (int i = 3; i < 5; i++) {
//			level5Allies[i] = new AMachinegunner;
//		}
//		//Grenadier
//		for (int i = 5; i < 7; i++) {
//			level5Allies[i] = new AGrenadier;
//		}
//
//
//		//Set all troop positions
//		color(0x09);
//		SetStartPos(*level5Allies[0], 5, 2);
//		SetStartPos(*level5Allies[1], 5, 5);
//		SetStartPos(*level5Allies[2], 7, 5);
//		SetStartPos(*level5Allies[3], 7, 6);
//		SetStartPos(*level5Allies[4], 7, 8);
//		SetStartPos(*level5Allies[5], 7, 10);
//		SetStartPos(*level5Allies[6], 7, 12);
//
//		color(0x06);
//		SetStartPos(*level5Enemy[0], 25, 3);
//		SetStartPos(*level5Enemy[1], 30, 4);
//		SetStartPos(*level5Enemy[2], 28, 2);
//		SetStartPos(*level5Enemy[3], 40, 4);
//		SetStartPos(*level5Enemy[4], 30, 6);
//		SetStartPos(*level5Enemy[5], 40, 6);
//		SetStartPos(*level5Enemy[6], 28, 4);
//		SetStartPos(*level5Enemy[7], 35, 3);
//		SetStartPos(*level5Enemy[8], 23, 4);
//		SetStartPos(*level5Enemy[9], 35, 5);
//
//
//		////Check if all enemies have died  ### To change
//		bool test = false;
//
//		while (test == false) {
//
//			int enemycposx, enemycposy;
//
//			///////////STATS
//			{
//				//display the stats
//				//allied troops live stats
//				gotoxy(65, 1);
//				color(0x09);
//				std::cout << "Allied Troops";
//
//				//stats
//				gotoxy(65, 2);
//				std::cout << "Health  Attack  Range";
//
//				//for rifleman
//				for (int i = 0; i < 3; i++) {
//					if (level5Allies[i] != nullptr) {
//						gotoxy(55, 3 + i);
//						std::cout << "Rifleman " << i + 1 << ": " << level5Allies[i]->GetHealth() << " ";
//
//						gotoxy(75, 3 + i);
//						std::cout << level5Allies[i]->GetAttack();
//
//						gotoxy(83, 3 + i);
//						std::cout << level5Allies[i]->GetRange();
//					}
//				}
//
//				//machinegunner
//				for (int i = 3; i < 5; i++) {
//					if (level5Allies[i] != nullptr) {
//
//						gotoxy(55, 6 + (i - 3));
//						std::cout << "McGunner " << i - 2 << ": " << level5Allies[i]->GetHealth() << " ";
//
//						gotoxy(75, 6 + (i - 3));
//						std::cout << level5Allies[i]->GetAttack();
//
//						gotoxy(83, 6 + (i - 3));
//						std::cout << level5Allies[i]->GetRange();
//					}
//				}
//
//				//grenadier
//				for (int i = 5; i < 7; i++) {
//					if (level5Allies[i] != nullptr) {
//						gotoxy(55, 8 + (i - 5));
//						std::cout << "Grenader " << i - 4 << ": " << level5Allies[i]->GetHealth() << " ";
//
//						gotoxy(75, 8 + (i - 5));
//						std::cout << level5Allies[i]->GetAttack();
//
//						gotoxy(83, 8 + (i - 5));
//						std::cout << level5Allies[i]->GetRange();
//					}
//				}
//
//				//Enemy troops
//				gotoxy(65, 12);
//				color(0x06);
//				std::cout << "Enemy Troops";
//
//				//stats
//				gotoxy(65, 13);
//				std::cout << "Health  Attack  Range";
//
//				//rifleman
//				for (int i = 0; i < 6; i++) {
//					if (level5Enemy[i] != nullptr) {
//						gotoxy(55, 14 + i);
//						std::cout << "Rifleman " << i + 1 << ": " << level5Enemy[i]->GetHealth() << " ";
//
//						gotoxy(75, 14 + i);
//						std::cout << level5Enemy[i]->GetAttack();
//
//						gotoxy(83, 14 + i);
//						std::cout << level5Enemy[i]->GetRange();
//					}
//				}
//				//machine gunner
//				for (int i = 6; i < 8; i++) {
//					if (level5Enemy[i] != nullptr) {
//						gotoxy(55, 20 + (i - 6));
//						std::cout << "McGunner " << i - 5 << ": " << level5Enemy[i]->GetHealth() << " ";
//
//						gotoxy(75, 20 + (i - 6));
//						std::cout << level5Enemy[i]->GetAttack();
//
//						gotoxy(83, 20 + (i - 6));
//						std::cout << level5Enemy[i]->GetRange();
//					}
//				}
//				//Grenadier
//				for (int i = 8; i < 10; i++) {
//					if (level5Enemy[i] != nullptr) {
//						gotoxy(55, 22 + (i - 8));
//						std::cout << "Grenader " << i - 7 << ": " << level5Enemy[i]->GetHealth() << " ";
//
//						gotoxy(75, 22 + (i - 8));
//						std::cout << level5Enemy[i]->GetAttack();
//
//						gotoxy(83, 22 + (i - 8));
//						std::cout << level5Enemy[i]->GetRange();
//					}
//				}
//			}
//
//
//			////////For player troops
//			// Player choose action 
//			for (int i = 0; i < 7; i++) {
//				bool ValidMove = false;
//
//				//Get user input, WASD to move or J to attack 
//				gotoxy(15, 25);
//				color(0x0F);
//				std::cout << "WASD to Move, J to Attack";
//
//				char choice = 'Z';
//
//
//				if (level5Allies[i] != nullptr) {
//					//prevent from reading in console
//					gotoxy(level5Allies[i]->PosXY.GetX(), level5Allies[i]->PosXY.GetY());
//					color(0x0D);
//					std::cout << level5Allies[i]->Draw_Icon();
//					choice = _getch();
//					//caps
//					choice = toupper(choice);
//				}
//
//				//Check if Ally is alive  (prevent crashes)
//				if (level5Allies[i] != nullptr) {
//
//					//Movement 
//					if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
//						//Movement Code
//						while (ValidMove == false) {
//
//							//allow to check movement is valid 
//							bool CanMove = true;
//
//							//Check collison with borders
//							if (level5Allies[i]->BorderCollision(choice) == true) {
//								gotoxy(15, 20);
//								std::cout << "Collided border";
//								CanMove = false;
//							}
//
//							//Check collison between Allies and Enemies
//							if (CanMove == true) {
//								for (int j = 0; j < 10; j++) {
//									if (level5Enemy[j] != nullptr) {
//										if (level5Allies[i]->Entitycollision(*level5Enemy[j], choice) == true) {
//											gotoxy(15, 21);
//											std::cout << "Collided Entity";
//											CanMove = false;
//											break;
//										}
//									}
//								}
//							}
//
//							//Check collison between Allies and Allies
//							if (CanMove == true) {
//								for (int j = 0; j < 7; j++) {
//									if (level5Allies[j] != nullptr) {
//										if (level5Allies[i]->Entitycollision(*level5Allies[j], choice) == true) {
//											gotoxy(15, 21);
//											std::cout << "Collided Allies";
//											CanMove = false;
//											break;
//										}
//									}
//								}
//							}
//
//							//Check collison between Allies and environment 
//							if (CanMove == true) {
//								if (CheckEnviroCollide(*level5Allies[i], choice) == true) {
//									gotoxy(15, 22);
//									std::cout << "Collided Environment";
//									CanMove = false;
//								}
//							}
//
//							//reflect movement of entity on screen 
//							if (CanMove == true) {
//								gotoxy(15, 20);
//								std::cout << "                    ";
//								gotoxy(15, 21);
//								std::cout << "                    ";
//								gotoxy(15, 22);
//								std::cout << "                    ";
//								gotoxy(15, 23);
//								std::cout << "                    ";
//								MoveEntity(*level5Allies[i], choice);
//								ValidMove = true;
//							}
//							//reinput movement again
//							else if (CanMove == false) {
//								gotoxy(15, 23);
//								std::cout << "Invalid Movement";
//								choice = _getch();
//								choice = toupper(choice);
//							}
//						}
//					}
//					//Attacking 
//					else if (choice == 'J') {
//						gotoxy(16, 24);
//						std::cout << "going to attack";
//
//						//Grab attack direction 
//						char attackDir = 'Z';
//
//						while (!(attackDir == 'w' || attackDir == 's' || attackDir == 'a' || attackDir == 'd')) {
//							attackDir = _getch();
//							gotoxy(15, 23);
//							std::cout << "attack direction";
//						}
//						attackDir = toupper(attackDir);
//
//						//Check if can attack any enemies 
//						for (int j = 0; j < 10; j++) {
//							if (level5Enemy[j] != nullptr) {
//								if (CheckAttack(*level5Allies[i], *level5Enemy[j], attackDir) == true) {
//									level5Allies[i]->DamageDealt(*level5Enemy[j]);
//
//									gotoxy(15, 25);
//									std::cout << "attack Dealt";
//									gotoxy(15, 26);
//									std::cout << level5Enemy[j]->GetHealth() << " " << j << " " << i;
//									break;
//								}
//							}
//						}
//					}
//				}
//
//				//Check if Enemy is alive 
//				for (int j = 0; j < 10; j++) {
//
//					if (!(level5Enemy[j] == nullptr)) {
//						if (level5Enemy[j]->isEntityAlive() == false) {
//							enemycposx = level5Enemy[j]->PosXY.GetX();
//							enemycposy = level5Enemy[j]->PosXY.GetY();
//
//
//							gotoxy(enemycposx, enemycposy);
//							std::cout << 'X';
//
//							//kill enemy 
//							enemiesdead = enemiesdead + 1;
//							delete level5Enemy[j];
//							level5Enemy[j] = nullptr;
//						}
//					}
//				}
//			}
//
//			//UI 
//			drawmap();
//			//Update new position 
//			for (int i = 0; i < 7; i++) {
//				if (level5Allies[i] != nullptr) {
//					gotoxy(level5Allies[i]->PosXY.GetX(), level5Allies[i]->PosXY.GetY());
//					color(0x09);
//					std::cout << level5Allies[i]->Draw_Icon();
//				}
//			}
//			for (int i = 0; i < 10; i++) {
//				if (level5Enemy[i] != nullptr) {//error is here
//					gotoxy(level5Enemy[i]->PosXY.GetX(), level5Enemy[i]->PosXY.GetY());
//					color(0x06);
//					std::cout << level5Enemy[i]->Draw_Icon();
//				}
//			}
//
//			////////// For enemy troops 
//			for (int i = 0; i < 10; i++) {
//
//				//allow to check movement is valid 
//				bool Moving = true;
//
//				//Check if enemy is alive (prevent crashes) 
//				if (level5Enemy[i] != nullptr) {
//
//					//Attacking, Check if can attack first 
//					for (int j = 0; j < 7; j++) {
//						if (level5Allies[j] != nullptr) {
//							if (EnemyCheckAtk(*level5Allies[j], *level5Enemy[i]) == true) {
//								level5Enemy[i]->DamageDealt(*level5Allies[j]);
//								/*gotoxy(50, 23);
//								std::cout << "Enemy attacking " << i << " " << j << " " << level1Allies[0]->GetHealth();*/
//								Moving = false;
//								break;
//							}
//						}
//					}
//
//					//Movement 
//					while (Moving == true) {
//
//						gotoxy(20, 20);
//						std::cout << "Enemy moving....";
//
//						bool ValidMove = true;
//
//						//Random number generation
//						int num = level5Enemy[i]->RandomNum();
//						//convert to char
//						char input = num + '0';
//
//						//Check collison with borders
//						if (level5Enemy[i]->BorderCollision(input) == true) {
//							gotoxy(15, 20);
//							std::cout << "Enemy Collided border";
//							ValidMove = false;
//						}
//
//						if (ValidMove == true) {
//							//Check collison between Enemies and Allies
//							for (int j = 0; j < 7; j++) {
//								if (level5Allies[j] != nullptr) {
//									if (level5Enemy[i]->Entitycollision(*level5Allies[j], input) == true) {
//										gotoxy(15, 21);
//										std::cout << "Enemy Collided Entity";
//										ValidMove = false;
//										break;
//									}
//								}
//							}
//						}
//
//						if (ValidMove == true) {
//							//Check collison between Enemies and Enemies
//							for (int j = 0; j < 10; j++) {
//								if (level5Enemy[j] != nullptr) {
//									if (level5Enemy[i]->Entitycollision(*level5Enemy[j], input) == true) {
//										gotoxy(15, 21);
//										std::cout << "Enemy Collided Enemy";
//										ValidMove = false;
//										break;
//									}
//								}
//							}
//						}
//
//						if (ValidMove == true) {
//							//Check collison between Enemies and environment 
//							if (CheckEnviroCollide(*level5Enemy[i], input) == true) {
//								gotoxy(15, 22);
//								std::cout << "Enemy Collided Environment";
//								ValidMove = false;
//								break;
//							}
//						}
//
//						//reflect movement of entity on screen 
//						if (ValidMove == true) {
//							MoveEntity(*level5Enemy[i], input);
//							Moving = false;
//
//						}
//						else if (ValidMove == false) {
//							gotoxy(15, 23);
//							std::cout << "Enemy Invalid Movement";
//						}
//					}
//				}
//
//				//Check if allies are alive 
//				for (int j = 0; j < 7; j++) {
//					if (level5Allies[j] != nullptr) {
//						if (level5Allies[j]->isEntityAlive() == false) {
//							gotoxy(level5Allies[j]->PosXY.GetX(), level5Allies[j]->PosXY.GetY());
//							std::cout << 'X';
//
//							//kill alliies
//							alliesdead = alliesdead + 1;
//							delete level5Allies[j];
//							level5Allies[j] = nullptr;
//						}
//					}
//				}
//			}
//
//			//UI
//			drawmap();
//			//Update new position 
//			for (int i = 0; i < 7; i++) {
//				if (level5Allies[i] != nullptr) {
//					gotoxy(level5Allies[i]->PosXY.GetX(), level5Allies[i]->PosXY.GetY());
//					color(0x09);
//					std::cout << level5Allies[i]->Draw_Icon();
//				}
//			}
//			for (int i = 0; i < 10; i++) {
//				if (level5Enemy[i] != nullptr) {
//					gotoxy(level5Enemy[i]->PosXY.GetX(), level5Enemy[i]->PosXY.GetY());
//					color(0x06);
//					std::cout << level5Enemy[i]->Draw_Icon();
//				}
//			}
//
//			//check win or lose
//			if (alliesdead == Amt_Lvl2_Allies) {
//				test = true;
//			}
//			else if (enemiesdead == Amt_Lvl2_Enemy) {
//				test = true;
//			}
//			else {
//				test = false;
//			}
//		}
//
//
//		//Delete backlog
//		for (int i = 0; i < 7; i++) {
//			if (level5Allies[i] != nullptr) {
//				delete level5Allies[i];
//				level5Allies[i] = nullptr;
//			}
//		}
//		for (int i = 0; i < 10; i++) {
//			if (level5Enemy[i] != nullptr) {
//				delete level5Enemy[i];
//				level5Enemy[i] = nullptr;
//			}
//		}
//		for (int i = 0; i < Amt_Trees; i++) {
//			if (trees[i] != nullptr) {
//				delete trees[i];
//				trees[i] = nullptr;
//			}
//		}
//		for (int i = 0; i < Amt_House; i++) {
//			if (houses[i] != nullptr) {
//				delete houses[i];
//				houses[i] = nullptr;
//			}
//		}
//	}
//}
