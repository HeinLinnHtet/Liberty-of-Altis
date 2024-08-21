#include "PLayer.h"

char PLayer::Draw_Icon(void)
{
	return 'P';
}

std::string PLayer::Getname(void)
{
	return "Player";
}

PLayer::PLayer()
{
	Health = 100;
	Attack = 5;
	Range = 4;
}
