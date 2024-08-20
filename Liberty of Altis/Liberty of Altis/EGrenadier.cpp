#include "EGrenadier.h"

EGrenadier::EGrenadier()
{
	Health = 25;
	Attack = 15;
	Range = 4;
	Cost = 6;
}

char EGrenadier::Draw_Icon(void)
{
	return 'G';
}
