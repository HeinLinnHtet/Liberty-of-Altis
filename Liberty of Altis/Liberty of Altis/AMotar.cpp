#include "AMotar.h"

AMotar::AMotar()
{
	Health = 40;
	Attack = 20;
	Range = 7;
	Cost = 8;
}

char AMotar::Draw_Icon(void)
{
	return 'O';
}
std::string AMotar::Getname(void)
{
	return "Mortar  ";
}