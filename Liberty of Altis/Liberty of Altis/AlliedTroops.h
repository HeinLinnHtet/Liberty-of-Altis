#pragma once
#include "Entity.h"

class AlliedTroops : public Entity
{


public:

	//Default
	AlliedTroops(void);

	//Override, from entity
	void Movement(char direction) override;

	//Override, from entity
	void Attacking(char direction) override;

};

