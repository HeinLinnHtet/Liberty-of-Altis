#include "ETank.h"

ETank::ETank()
{
	Health = 95;
	Attack = 30;
	Range = 8;
	Cost = 15;
}

char ETank::Draw_Icon(void)
{
	return 'T';
}
