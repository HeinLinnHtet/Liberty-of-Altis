#include <iostream>
#include "Windows.h"
#include "shop.h"

#include "map.h"
#include "mapmain1.h"

int main(void) {

	//Making a seed value for real randomness
	srand((unsigned)time(NULL));

	shop test;

	test.shopping();
}



