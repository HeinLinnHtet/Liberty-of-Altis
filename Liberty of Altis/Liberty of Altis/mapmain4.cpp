#include "mapmain4.h"
#include <iostream>
#include "environmentalObjs.h"


environmentalObjs* mapmain4::buildings[Amt_Build];
bool mapmain4::GameOver = false;


mapmain4::mapmain4()
{
	alliesdead = 0;
	enemiesdead = 0;
}

void mapmain4::drawmap()
{
	bool objexist = false;

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


	//Move to correct positiion 
	for (int i = 0; i < Amt_Build; i++) {
		buildings[i]->setx(buildings[i]->getx() + 4);
		buildings[i]->sety(buildings[i]->gety() + 1);
	}
}


void mapmain4::map4game(int rifleamount,
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

	const int Amt_Lvl4_Allies = 15;
	const int Amt_Lvl4_Enemy = 10;

	///// #### NOT POLYMORHPHISM ####		
	// instantiating objects	

	//Spawn enemies 
	EnemyTroops* level4Enemy[Amt_Lvl4_Enemy];
	//rifle man
	for (int i = 0; i < 3; i++) {
		level4Enemy[i] = new ERiflesman;
	}
	//Machine gunner
	for (int i = 3; i < 4; i++) {
		level4Enemy[i] = new EMachinegunner;
	}
	//Grenadier 
	for (int i = 4; i < 6; i++) {
		level4Enemy[i] = new EGrenadier;
	}
	//Motar
	for (int i = 6; i < 7; i++) {
		level4Enemy[i] = new EMotar;
	}
	//IFV
	for (int i = 7; i < 9; i++) {
		level4Enemy[i] = new EIFV;
	}
	//Tank
	for (int i = 9; i < Amt_Lvl4_Enemy; i++) {
		level4Enemy[i] = new ETank;
	}





	//Spawn allies 
	AlliedTroops* level4Allies[Amt_Lvl4_Allies];
	for (int i = 0; i < Amt_Lvl4_Allies; i++) {
		level4Allies[i] = nullptr;
	}

	//rifle man
	for (int i = 0; i < rifleamount; i++) {
		level4Allies[i] = new ARiflesman;
	}
	//Lmg    // rifleamount 
	for (int i = 0; i < mcgunamount; i++) {
		level4Allies[i + rifleamount] = new AMachinegunner;
	}
	//Grenadier
	for (int i = 0; i < grendamount; i++) {
		level4Allies[i + rifleamount + mcgunamount] = new AGrenadier;
	}
	//Mortar	
	for (int i = 0; i < motaramount; i++) {
		level4Allies[i + rifleamount + mcgunamount + grendamount] = new AMotar;
	}
	//Artillery	
	for (int i = 0; i < artilamount; i++) {
		level4Allies[i + rifleamount + mcgunamount + grendamount + motaramount] = new AArtillery;
	}
	//Tank	
	for (int i = 0; i < tankamount; i++) {
		level4Allies[i + rifleamount + mcgunamount + grendamount + motaramount + artilamount] = new ATank;
	}
	//IFV
	for (int i = 0; i < ifvamount; i++) {
		level4Allies[i + rifleamount + mcgunamount + grendamount + motaramount + artilamount + tankamount] = new AIFV;
	}


	//Set all troop positions
	color(0x09);
	if (level4Allies[0] != nullptr) {
		SetStartPos(*level4Allies[0], 5, 2);
	}
	if (level4Allies[1] != nullptr) {
		SetStartPos(*level4Allies[1], 12, 6);
	}
	if (level4Allies[2] != nullptr) {
		SetStartPos(*level4Allies[2], 10, 5);
	}
	if (level4Allies[3] != nullptr) {
		SetStartPos(*level4Allies[3], 7, 5);
	}
	if (level4Allies[4] != nullptr) {
		SetStartPos(*level4Allies[4], 15, 8);
	}
	if (level4Allies[5] != nullptr) {
		SetStartPos(*level4Allies[5], 10, 9);
	}
	if (level4Allies[6] != nullptr) {
		SetStartPos(*level4Allies[6], 20, 13);
	}
	if (level4Allies[7] != nullptr) {
		SetStartPos(*level4Allies[7], 13, 15);
	}
	if (level4Allies[8] != nullptr) {
		SetStartPos(*level4Allies[8], 5, 16);
	}
	if (level4Allies[9] != nullptr) {
		SetStartPos(*level4Allies[9], 25, 17);
	}
	if (level4Allies[10] != nullptr) {
		SetStartPos(*level4Allies[10], 15, 18);
	}
	if (level4Allies[11] != nullptr) {
		SetStartPos(*level4Allies[11], 13, 21);
	}
	if (level4Allies[12] != nullptr) {
		SetStartPos(*level4Allies[12], 27, 21);
	}
	if (level4Allies[13] != nullptr) {
		SetStartPos(*level4Allies[13], 25, 6);
	}
	if (level4Allies[Amt_Lvl4_Allies - 1] != nullptr) {
		SetStartPos(*level4Allies[Amt_Lvl4_Allies - 1], 6, 12);
	}

	color(0x06);
	SetStartPos(*level4Enemy[0], 60, 4);
	SetStartPos(*level4Enemy[1], 50, 17);
	SetStartPos(*level4Enemy[2], 55, 8);
	SetStartPos(*level4Enemy[3], 53, 8);
	SetStartPos(*level4Enemy[4], 67, 4);
	SetStartPos(*level4Enemy[5], 37, 17);
	SetStartPos(*level4Enemy[6], 55, 10);
	SetStartPos(*level4Enemy[7], 60, 13);
	SetStartPos(*level4Enemy[8], 70, 9);
	SetStartPos(*level4Enemy[9], 60, 17);



	while (GameOver == false)  {
		
		int enemycposx, enemycposy;

		///////////STATS
		{
			//display the stats
			//Enemy troops
			gotoxy(95, 1);
			color(0x06);
			std::cout << "Enemy Troops";

			//stats
			gotoxy(95, 2);
			std::cout << "Health  Attack  Range";

			//rifleman
			for (int i = 0; i < 3; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "Rifleman " << i + 1 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			//machine gunner
			for (int i = 3; i < 4; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "McGunner " << i - 5 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			//Grenadier
			for (int i = 4; i < 6; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "Grenader " << i - 7 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			//Motar
			for (int i = 6; i < 7; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "Motar " << i - 7 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			//IFV
			for (int i = 7; i < 9; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "IFV " << i - 7 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			//Tank
			for (int i = 9; i < Amt_Lvl4_Enemy; i++) {
				if (level4Enemy[i] != nullptr) {
					gotoxy(85, 3 + i);
					std::cout << "Tank " << i - 7 << ": " << level4Enemy[i]->GetHealth() << " ";

					gotoxy(105, 3 + i);
					std::cout << level4Enemy[i]->GetAttack();

					gotoxy(113, 3 + i);
					std::cout << level4Enemy[i]->GetRange();
				}
			}
			
			//allied troops live stats
			gotoxy(95, Amt_Lvl4_Enemy + 3);
			color(0x09);
			std::cout << "Allied Troops";

			//stats
			gotoxy(95, Amt_Lvl4_Enemy + 4);
			std::cout << "Health  Attack  Range";

			//for rifleman
			for (int i = 0; i < rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i + 1 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//machinegunner            
			for (int i = rifleamount; i < mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i - 2 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//grenadier
			for (int i = mcgunamount + rifleamount; i < grendamount + mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i - 4 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//mortar
			for (int i = grendamount + mcgunamount + rifleamount; i < motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i + 1 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//artillery
			for (int i = motaramount + grendamount + mcgunamount + rifleamount; i < artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i - 2 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//tank
			for (int i = artilamount + motaramount + grendamount + mcgunamount + rifleamount; i < tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i - 4 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}

			//ifv
			for (int i = tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i < ifvamount + tankamount + artilamount + motaramount + grendamount + mcgunamount + rifleamount; i++) {
				if (level4Allies[i] != nullptr) {
					gotoxy(85, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->Getname() << i + 1 << ": " << level4Allies[i]->GetHealth() << " ";

					gotoxy(105, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetAttack();

					gotoxy(113, Amt_Lvl4_Enemy + 5 + i);
					std::cout << level4Allies[i]->GetRange();
				}
			}



			

		}



		//////For player troops
		//Player choose action 
		for (int i = 0; i < Amt_Lvl4_Allies; i++) {
			bool ValidMove = false;

			//Get user input, WASD to move or J to attack 
			gotoxy(15, 26);
			color(0x0F);
			std::cout << "WASD to Move, J to Attack";

			char choice = 'Z';


			if (level4Allies[i] != nullptr) {
				//prevent from reading in console
				gotoxy(level4Allies[i]->PosXY.GetX(), level4Allies[i]->PosXY.GetY());
				color(0x0D);
				std::cout << level4Allies[i]->Draw_Icon();
				choice = _getch();
				//caps
				choice = toupper(choice);
			}

			//Check if Ally is alive  (prevent crashes)
			if (level4Allies[i] != nullptr) {

				//Movement 
				if (choice == 'W' || choice == 'A' || choice == 'S' || choice == 'D') {
					//Movement Code
					while (ValidMove == false) {

						//allow to check movement is valid 
						bool CanMove = true;

						//Check collison with borders
						if (ABorderCollision(*level4Allies[i], choice) == true){
							gotoxy(15, 27);
							std::cout << "Collided border";
							CanMove = false;
						}

						//Check collison between Allies and Enemies
						if (CanMove == true) {
							for (int j = 0; j < Amt_Lvl4_Enemy; j++) {
								if (level4Enemy[j] != nullptr) {
									if (level4Allies[i]->Entitycollision(*level4Enemy[j], choice) == true) {
										gotoxy(40, 27);
										std::cout << "Collided Entity";
										CanMove = false;
										break;
									}
								}
							}
						}

						//Check collison between Allies and Allies
						if (CanMove == true) {
							for (int j = 0; j < Amt_Lvl4_Allies; j++) {
								if (level4Allies[j] != nullptr) {
									if (level4Allies[i]->Entitycollision(*level4Allies[j], choice) == true) {
										gotoxy(15, 28);
										std::cout << "Collided Allies";
										CanMove = false;
										break;
									}
								}
							}
						}

						//Check collison between Allies and environment 
						if (CanMove == true) {
							if (CheckEnviroCollide(*level4Allies[i], choice) == true) {
								gotoxy(40, 28);
								std::cout << "Collided Environment";
								CanMove = false;
							}
						}

						//reflect movement of entity on screen 
						if (CanMove == true) {
							gotoxy(15, 27);
							std::cout << "                                                   ";
							gotoxy(15, 28);
							std::cout << "                                                             ";
							gotoxy(15, 29);
							std::cout << "                                                            ";
							MoveEntity(*level4Allies[i], choice);
							ValidMove = true;
						}
						//reinput movement again
						else if (CanMove == false) {
							gotoxy(40, 29);
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
						gotoxy(70, 27);
						std::cout << "attack direction";
					}
					attackDir = toupper(attackDir);

					//Check if can attack any enemies 
					for (int j = 0; j < Amt_Lvl4_Enemy; j++) {
						if (level4Enemy[j] != nullptr) {
							if (level4Allies[i]->Draw_Icon() != 'A' || level4Allies[i]->Draw_Icon() != 'O'){
								if (CheckAttack(*level4Allies[i], *level4Enemy[j], attackDir) == true) {
									level4Allies[i]->DamageDealt(*level4Enemy[j]);

									gotoxy(70, 28);
									std::cout << "attack Dealt";
									gotoxy(75, 27);
									std::cout << level4Enemy[j]->GetHealth() << " " << j << " " << i;
									break;
								}
							}
							else{
								if (CheckAttack(*level4Allies[i], *level4Enemy[j], attackDir) == true) {
									level4Allies[i]->DamageDealt(*level4Enemy[j]);

									gotoxy(70, 28);
									std::cout << "attack Dealt";
									gotoxy(75, 27);
									std::cout << level4Enemy[j]->GetHealth() << " " << j << " " << i;
									break;
								}
							}
						}
					}
				}
			}
			//here for the null ptr part




			//Check if Enemy is alive 
			for (int j = 0; j < Amt_Lvl4_Enemy; j++) {

				if (!(level4Enemy[j] == nullptr)) {
					if (level4Enemy[j]->isEntityAlive() == false) {
						enemycposx = level4Enemy[j]->PosXY.GetX();
						enemycposy = level4Enemy[j]->PosXY.GetY();


						gotoxy(enemycposx, enemycposy);
						std::cout << 'X';

						//kill enemy 
						enemiesdead = enemiesdead + 1;
						delete level4Enemy[j];
						level4Enemy[j] = nullptr;
					}
				}
			}
		}

		//UI 
		drawmap();
		//Update new position 
		for (int i = 0; i < Amt_Lvl4_Allies; i++) {
			if (level4Allies[i] != nullptr) {
				gotoxy(level4Allies[i]->PosXY.GetX(), level4Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level4Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < Amt_Lvl4_Enemy; i++) {
			if (level4Enemy[i] != nullptr) {//error is here
				gotoxy(level4Enemy[i]->PosXY.GetX(), level4Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level4Enemy[i]->Draw_Icon();
			}
		}



		//////// For enemy troops 
		for (int i = 0; i < Amt_Lvl4_Enemy; i++) {

			//allow to check movement is valid 
			bool Moving = true;

			//Check if enemy is alive (prevent crashes) 
			if (level4Enemy[i] != nullptr) {

				//Attacking, Check if can attack first 
				for (int j = 0; j < Amt_Lvl4_Allies; j++) {
					if (level4Allies[j] != nullptr) {
						if (level4Enemy[i]->Draw_Icon() != 'A' || level4Enemy[i]->Draw_Icon() != 'O'){
							if (EnemyCheckAtk(*level4Allies[j], *level4Enemy[i]) == true) {
								level4Enemy[i]->DamageDealt(*level4Allies[j]);
								gotoxy(15, 28);
								std::cout << "Enemy attacking " << i << " " << j << " " << level4Allies[j]->GetHealth();
								Moving = false;
								break;
							}
						}
						else{
							if (EnemyCheckAtk(*level4Allies[j], *level4Enemy[i]) == true) {
								level4Enemy[i]->DamageDealt(*level4Allies[j]);
								gotoxy(15, 28);
								std::cout << "Enemy attacking " << i << " " << j << " " << level4Allies[j]->GetHealth();
								Moving = false;
								break;
							}
						}
					}
				}

				//Movement 
				while (Moving == true) {

					bool ValidMove = true;

					//Random number generation
					int num = level4Enemy[i]->RandomNum();
					//convert to char
					char input = num + '0';

					//Check collison with borders
					if (EBorderCollision(*level4Enemy[i],input) == true) {
						gotoxy(15, 27);
						std::cout << "Enemy Collided border";
						ValidMove = false;
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Allies
						for (int j = 0; j < Amt_Lvl4_Allies; j++) {
							if (level4Allies[j] != nullptr) {
								if (level4Enemy[i]->Entitycollision(*level4Allies[j], input) == true) {
									gotoxy(40, 27);
									std::cout << "Enemy Collided Entity";
									ValidMove = false;
									break;
								}
							}
						}
					}

					if (ValidMove == true) {
						//Check collison between Enemies and Enemies
						for (int j = 0; j < Amt_Lvl4_Enemy; j++) {
							if (level4Enemy[j] != nullptr) {
								if (level4Enemy[i]->Entitycollision(*level4Enemy[j], input) == true) {
									gotoxy(15, 28);
									std::cout << "Enemy Collided Enemy";
									ValidMove = false;
									break;
								}
							}
						}
					}

					if (ValidMove == true) {
						//Check collison between Enemies and environment 
						if (CheckEnviroCollide(*level4Enemy[i], input) == true) {
							gotoxy(40, 28);
							std::cout << "Enemy Collided Environment";
							ValidMove = false;
							break;
						}
					}

					//reflect movement of entity on screen 
					if (ValidMove == true) {
						MoveEntity(*level4Enemy[i], input);
						Moving = false;

					}
					else if (ValidMove == false) {
						gotoxy(40, 29);
						std::cout << "Enemy Invalid Movement";
					}
				}
			}

			//Check if allies are alive 
			for (int j = 0; j < Amt_Lvl4_Allies; j++) {
				if (level4Allies[j] != nullptr) {
					if (level4Allies[j]->isEntityAlive() == false) {
						gotoxy(level4Allies[j]->PosXY.GetX(), level4Allies[j]->PosXY.GetY());
						std::cout << 'X';

						//kill alliies
						alliesdead = alliesdead + 1;
						delete level4Allies[j];
						level4Allies[j] = nullptr;
					}
				}
			}
		}

		//UI
		drawmap();
		//Update new position 
		for (int i = 0; i < Amt_Lvl4_Allies; i++) {
			if (level4Allies[i] != nullptr) {
				gotoxy(level4Allies[i]->PosXY.GetX(), level4Allies[i]->PosXY.GetY());
				color(0x09);
				std::cout << level4Allies[i]->Draw_Icon();
			}
		}
		for (int i = 0; i < Amt_Lvl4_Enemy; i++) {
			if (level4Enemy[i] != nullptr) {
				gotoxy(level4Enemy[i]->PosXY.GetX(), level4Enemy[i]->PosXY.GetY());
				color(0x06);
				std::cout << level4Enemy[i]->Draw_Icon();
			}
		}

		//check win or lose
		if (alliesdead == Amt_Lvl4_Allies) {
			winloss.loss();
			GameOver = true;
		}
		else if (enemiesdead == Amt_Lvl4_Enemy) {
			winloss.win();
			GameOver = true;

		}
		else {
			GameOver = false;
		}
	}


	//Delete backlog
	for (int i = 0; i < Amt_Lvl4_Allies; i++) {
		if (level4Allies[i] != nullptr) {
			delete level4Allies[i];
			level4Allies[i] = nullptr;
		}
	}
	for (int i = 0; i < Amt_Lvl4_Enemy; i++) {
		if (level4Enemy[i] != nullptr) {
			delete level4Enemy[i];
			level4Enemy[i] = nullptr;
		}
	}
	for (int i = 0; i < Amt_Build; i++) {
		if (buildings[i] != nullptr) {
			delete buildings[i];
			buildings[i] = nullptr;
		}
	}



}


//Border checking 
bool mapmain4::CheckBorder(Entity& main, char direction)
{

	int result = false;
	//Check if UD position
	//Up 
	if (direction == '0' || direction == 'W') {
		if (main.PosXY.GetY() - 1 == 0) {
			result = true;
		}
	}
	//Down
	if (direction == '1' || direction == 'S') {
		if (main.PosXY.GetY() + 1 == 25) {
			result = true;
		}
	}
	//left
	if (direction == '3' || direction == 'D') {
		if (main.PosXY.GetX() + 1 == 84) {
			result = true;
		}
	}
	//right 
	if (direction == '2' || direction == 'A') {
		if (main.PosXY.GetX() - 1 == 3) {
			result = true;
		}
	}

	return result;
}

//Check collision
bool mapmain4::CheckEnviroCollide(Entity& main, char direction)
{
	//store position
	int XEntity = main.PosXY.GetX();
	int YEntity = main.PosXY.GetY();

	bool result = false;

	//Check with EVERY object
	for (int i = 0; i < Amt_Build; i++) {

		int XEnviro = buildings[i]->objPos.GetX();
		int YEnviro = buildings[i]->objPos.GetY();

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

///Check player attack
bool mapmain4::CheckAttack(Entity& main, Entity& other, char direction)
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
				for (int i = 0; i < Amt_Build; i++) {

					int xobj = buildings[i]->objPos.GetX();
					int yobj = buildings[i]->objPos.GetY();
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
							if ((Endy <= Range) && !(yother >= yobj)) {
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
							if ((Endy <= Range) && !(yother <= yobj)) {
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
							if ((Endx <= Range) && !(xother <= xobj)) {
								objectblocking = true;
								break;
							}
						}
					}
					//Left
					else if (direction == 'A') {
						//Check for any objects aligned and above player 
						if (yobj == y && (xobj < x)) {
							//Check if within range but enemy not infront of wall 
							if ((Endx <= Range) && !(xother >= xobj)) {
								objectblocking = true;
								break;
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

//Check if enemy can attack
bool mapmain4::EnemyCheckAtk(Entity& ally, Entity& Enemy)
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

			if (Enemy.Draw_Icon() == 'A' || Enemy.Draw_Icon() == 'O') {
				objectblocking = false;
			}
			else {
				//check EVERY object to see if any is obstructing (barricade)
				for (int i = 0; i < Amt_Build; i++) {

					int xobj = buildings[i]->objPos.GetX();
					int yobj = buildings[i]->objPos.GetY();
					int Endy = 0;

					//Store distance between enviromental objects
					Endy = abs(y - yobj);

					//If ally is above
					if (yother < y) {
						//check if enviroment obj above
						if ((x == xobj) && (yobj < y)) {
							//Check if object in range and allies not infront
							if ((Endy <= Range) && !(y >= yobj)) {
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
							if ((Endy <= Range) && !(y <= yobj)) {
								objectblocking = true;
								break;
							}
						}
					}
				}
			}
		}
		//Check if they are aligned
		//ally on x axis
		else if (y == yother) {

			if (Enemy.Draw_Icon() == 'A' || Enemy.Draw_Icon() == 'O') {
				objectblocking = false;
			}
			else {

				//check EVERY object to see if any is obstructing  
				for (int i = 0; i < Amt_Build; i++) {

					int xobj = buildings[i]->objPos.GetX();
					int yobj = buildings[i]->objPos.GetY();
					int Endx = 0;

					//Store distance between enviromental objects
					Endx = abs(x - xobj);

					//If ally is on the left
					if (xother < x) {
						//check if enviroment obj above
						if ((y == yobj) && (xobj < x)) {
							//Check if object is within range
							if ((Endx <= Range) && !(x >= xobj)) {
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
							if ((Endx <= Range) && !(x <= xobj)) {
								objectblocking = true;
								break;
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
		//means cant attack 
		objectblocking = true;


	//if no object obstruct, attack
	if (objectblocking == false) {
		attackable = true;
	}

	return attackable;
}


bool mapmain4::GetGameOver(void) {

	return GameOver;
}