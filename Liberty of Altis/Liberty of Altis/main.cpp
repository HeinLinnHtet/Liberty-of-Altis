#include <iostream>
#include "Windows.h"
#include "shop.h"
#include "gameui.h"
#include "lobby.h"
#include "map.h"
#include "mapmain3.h"

int main(void) {

	//Making a seed value for real randomness
	srand((unsigned)time(NULL));
	gameui aus;
	aus.cutscene1();
	lobby das;
	das.welcomemessage();
}



