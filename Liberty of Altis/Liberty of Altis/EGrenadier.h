#pragma once
#include "EnemyTroops.h"
class EGrenadier : public EnemyTroops
{
public:
	EGrenadier();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

