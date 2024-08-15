#include "AlliedTroops.h"



AlliedTroops::AlliedTroops(void)
{
	Health = 0;
	Attack = 0;
	Range = 0;
	Cost = 0;
}

//Movement function for player 
void AlliedTroops::Movement(char direction)
{
	char dirinput = toupper(direction);

	if (dirinput == 'W') {
		PosXY.SetY(PosXY.GetY() - 1);
	}
	else if (dirinput == 'S') {
		PosXY.SetY(PosXY.GetY() + 1);
	}
	else if (dirinput == 'A') {
		PosXY.SetX(PosXY.GetX() - 1);
	}
	else if (dirinput == 'D') {
		PosXY.SetX(PosXY.GetX() + 1);
	}
}

void AlliedTroops::Attacking(char direction)
{
	std::cout << "Attack Alliedtroop";
}

