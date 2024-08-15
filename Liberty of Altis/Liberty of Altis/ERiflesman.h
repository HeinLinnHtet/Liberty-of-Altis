#pragma once
#include "EnemyTroops.h"
class ERiflesman : public EnemyTroops
{
public:
	ERiflesman();

	//Draw icon
	char Draw_Icon(void) override;

};

