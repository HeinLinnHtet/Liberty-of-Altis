#include "EMachinegunner.h"

EMachinegunner::EMachinegunner()
{
	Health = 25;
	Attack = 15;
	Range = 3;
	Cost = 7;
}

char EMachinegunner::Draw_Icon(void)
{
	return 'M';
}
