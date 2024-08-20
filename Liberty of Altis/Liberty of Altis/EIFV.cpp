#include "EIFV.h"

EIFV::EIFV()
{
	Health = 75;
	Attack = 10;
	Range = 5;
	Cost = 10;
}

char EIFV::Draw_Icon(void)
{
	return 'I';
}
std::string EIFV::Getname(void)
{
	return "IFV     ";
}