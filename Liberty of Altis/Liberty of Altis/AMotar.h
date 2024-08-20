#pragma once
#include "AlliedTroops.h"
class AMotar : public AlliedTroops
{
public:
	AMotar();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

