#include "EMotar.h"

EMotar::EMotar()
{
	Health = 35;
	Attack = 20;
	Range = 7;
	Cost = 8;
}

char EMotar::Draw_Icon(void)
{
	return 'O';
}
std::string EMotar::Getname(void)
{
	return "Motar   ";
}