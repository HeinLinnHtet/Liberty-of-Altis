#include "AIFV.h"

AIFV::AIFV()
{
	Health = 80;
	Attack = 10;
	Range = 5;
	Cost = 10;
}

char AIFV::Draw_Icon(void)
{
	return 'I';
}
std::string AIFV::Getname(void)
{
	return "IFV     ";
}