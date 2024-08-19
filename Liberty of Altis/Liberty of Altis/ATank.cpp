#include "ATank.h"

ATank::ATank()
{
	Health = 100;
	Attack = 30;
	Range = 8;
	Cost = 15;
}

char ATank::Draw_Icon(void)
{
	return 'T';
}
