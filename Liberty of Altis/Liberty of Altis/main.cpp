#include <iostream>
#include "Windows.h"
#include "shop.h"

#include "map.h"
#include "mapmain3.h"

int main(void) {

	//Making a seed value for real randomness
	srand((unsigned)time(NULL));

	mapmain3 testlvl1;
	testlvl1.map3game();
}



