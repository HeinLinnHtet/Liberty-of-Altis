#pragma once
#include "AlliedTroops.h"
class ATank : public AlliedTroops
{
public:
	ATank();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

