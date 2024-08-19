#pragma once
#include "EnemyTroops.h"
class EArtillery : public EnemyTroops
{
public:
	EArtillery();

	char Draw_Icon(void) override;
};

