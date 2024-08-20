#pragma once
#include "AlliedTroops.h"
class AGrenadier : public AlliedTroops
{
public:
	AGrenadier();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

