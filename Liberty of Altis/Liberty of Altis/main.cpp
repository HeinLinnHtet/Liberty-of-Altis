#include <iostream>
#include "Windows.h"
#include "shop.h"
#include "gameui.h"
#include "map.h"
#include "Backpack.h"
#include "mapmain1.h"
#include "mapmain2.h"
#include "mapmain3.h"
#include "mapmain4.h"
#include "mapmain5.h"

int main(void) {

	//Making a seed value for real randomness
	srand((unsigned)time(NULL));

	Backpack maininventory;
	gameui cutscene;
	shop testshop;
	mapmain1 testlvl1;
	mapmain2 testlvl2;
	mapmain3 testlvl3;
	mapmain4 testlvl4;
	mapmain5 testlvl5;

	//cutscene.cutscene1();
	//system("CLS");

	//testlvl1.map1game();
	//system("CLS");

	//cutscene.cutscene2();
	//system("CLS");
	//testlvl2.map2game();
	//system("CLS");

	//cutscene.cutscene3();
	//system("CLS");

	testshop.shopping();

	//These are the values of what you bought from the shop
	
	maininventory.riflemansetter(testshop.inventory.riflemangetter());
	maininventory.artillerysetter(testshop.inventory.artillerygetter());
	maininventory.grenadiersetter(testshop.inventory.grenadiergetter());
	maininventory.IFVsetter(testshop.inventory.IFVgetter());
	maininventory.machinegunnersetter(testshop.inventory.machinegunnergetter());
	maininventory.motarsetter(testshop.inventory.motargetter());
	maininventory.tanksetter(testshop.inventory.tankgetter());

	//Level 3
	while (testlvl3.GetGameOver() == false) {
		maininventory.backpak();
		system("CLS");
		testlvl3.map3game(
			maininventory.Troop_broughtin[0],
			maininventory.Troop_broughtin[1],
			maininventory.Troop_broughtin[2],
			maininventory.Troop_broughtin[3],
			maininventory.Troop_broughtin[4],
			maininventory.Troop_broughtin[5],
			maininventory.Troop_broughtin[6]);
	}

	//pay day
	testshop.cashearned(500);

	cutscene.cutscene4();
	system("CLS");


	//Level 4
	while (testlvl4.GetGameOver() == false) {
		maininventory.backpak();
		system("CLS");
		testlvl4.map4game(
			maininventory.Troop_broughtin[0],
			maininventory.Troop_broughtin[1],
			maininventory.Troop_broughtin[2],
			maininventory.Troop_broughtin[3],
			maininventory.Troop_broughtin[4],
			maininventory.Troop_broughtin[5],
			maininventory.Troop_broughtin[6]);
	}

	//pay day 2
	testshop.cashearned(1000);

	//level 5
	while (testlvl5.GetGameOver() == false) {
		maininventory.bakpak();
		system("CLS");
		testlvl5.map5game(
			maininventory.Troop_broughtin[0],
			maininventory.Troop_broughtin[1],
			maininventory.Troop_broughtin[2],
			maininventory.Troop_broughtin[3],
			maininventory.Troop_broughtin[4],
			maininventory.Troop_broughtin[5],
			maininventory.Troop_broughtin[6]);
	}
}
