#pragma once
#include "AlliedTroops.h"
class ARiflesman : public AlliedTroops
{
public:
	ARiflesman();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

