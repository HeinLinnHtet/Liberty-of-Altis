#pragma once
#include "EnemyTroops.h"
class EMachinegunner : public EnemyTroops
{
public:
	EMachinegunner();

	char Draw_Icon(void) override;
};

