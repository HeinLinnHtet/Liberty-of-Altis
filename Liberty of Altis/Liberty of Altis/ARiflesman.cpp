#include "ARiflesman.h"

ARiflesman::ARiflesman()
{
	Health = 30;
	Attack = 10;
	Range = 3;
	Cost = 5;
}

char ARiflesman::Draw_Icon(void)
{
	return 'R';
}
std::string ARiflesman::Getname(void)
{
	return "Rifleman";
}
