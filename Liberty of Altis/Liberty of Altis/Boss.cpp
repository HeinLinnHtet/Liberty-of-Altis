#include "Boss.h"

Boss::Boss()
{
	Health = 100;
	Range = 3;
}

char Boss::Draw_Icon(void)
{
	return 'B';
}

std::string Boss::Getname(void)
{
	return "Boss";
}
