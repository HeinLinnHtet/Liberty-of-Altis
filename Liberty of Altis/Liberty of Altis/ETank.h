#pragma once
#include "EnemyTroops.h"
class ETank : public EnemyTroops
{
public:
	ETank();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

