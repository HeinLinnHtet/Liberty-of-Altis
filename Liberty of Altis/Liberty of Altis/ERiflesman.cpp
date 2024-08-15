#include "ERiflesman.h"

ERiflesman::ERiflesman()
{
	Health = 10;
	Attack = 5;
	Range = 3;
	Cost = 5;
}

char ERiflesman::Draw_Icon(void)
{
	return 'R';
}
