#include <iostream>
#include "Windows.h"
#include "shop.h"
#include "gameui.h"
#include "map.h"
#include "mapmain1.h"
#include "mapmain2.h"
#include "mapmain3.h"
#include "mapmain4.h"
#include "mapmain5.h"

int main(void) {

	//Making a seed value for real randomness
	srand((unsigned)time(NULL));

	mapmain3 testlvl1;
	testlvl1.map3game();
}



