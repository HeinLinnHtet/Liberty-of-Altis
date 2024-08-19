#include "ARiflesman.h"

ARiflesman::ARiflesman()
{
	Health = 30;
	Attack = 5;
	Range = 3;
	Cost = 5;
}

char ARiflesman::Draw_Icon(void)
{
	return 'A';
}
