#pragma once
#include "EnemyTroops.h"
class EMotar : public EnemyTroops
{
public:
	EMotar();

	char Draw_Icon(void) override;
	std::string Getname(void) override;
};

