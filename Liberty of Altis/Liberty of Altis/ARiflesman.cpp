#include "ARiflesman.h"

ARiflesman::ARiflesman()
{
	Health = 10;
	Attack = 5;
	Range = 3;
	Cost = 5;
}

char ARiflesman::Draw_Icon(void)
{
	return 'A';
}
