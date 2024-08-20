#include "AGrenadier.h"

AGrenadier::AGrenadier()
{
	Health = 30;
	Attack = 20;
	Range = 4;
	Cost = 6;
}

char AGrenadier::Draw_Icon(void)
{
	return 'G';
}
std::string AGrenadier::Getname(void)
{
	return "Grenader";
}
