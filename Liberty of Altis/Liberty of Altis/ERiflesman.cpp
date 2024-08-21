#include "ERiflesman.h"

ERiflesman::ERiflesman()
{
	Health = 25;
	Attack = 10;
	Range = 3;
	Cost = 5;
}

char ERiflesman::Draw_Icon(void)
{
	return 'R';
}

std::string ERiflesman::Getname(void)
{
	return "Rifleman";
}