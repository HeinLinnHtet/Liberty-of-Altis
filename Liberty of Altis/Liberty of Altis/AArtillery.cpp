#include "AArtillery.h"

AArtillery::AArtillery()
{
	Health = 50;
	Attack = 40;
	Range = 10;
	Cost = 15;
}

char AArtillery::Draw_Icon(void)
{
	return 'A';
}
