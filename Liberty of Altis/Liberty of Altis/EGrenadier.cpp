#include "EGrenadier.h"

EGrenadier::EGrenadier()
{
	Health = 25;
	Attack = 20;
	Range = 4;
	Cost = 6;
}

char EGrenadier::Draw_Icon(void)
{
	return 'G';
}
std::string EGrenadier::Getname(void)
{
	return "Grenadier";
}