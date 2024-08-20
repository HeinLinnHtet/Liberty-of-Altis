#include "AMachinegunner.h"

AMachinegunner::AMachinegunner()
{
	Health = 30;
	Attack = 15;
	Range = 3;
	Cost = 7;
}

char AMachinegunner::Draw_Icon(void)
{
	return 'M';
}
std::string AMachinegunner::Getname(void)
{
	return "McGunner";
}