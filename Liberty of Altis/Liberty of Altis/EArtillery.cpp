#include "EArtillery.h"

EArtillery::EArtillery()
{
	Health = 45;
	Attack = 40;
	Range = 10;
	Cost = 15;
}

char EArtillery::Draw_Icon(void)
{
	return 'A';
}
