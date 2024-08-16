#pragma once
#include "Entity.h"

class AlliedTroops : public Entity
{


public:

	//Default
	AlliedTroops(void);

	//Override, from entity
	void Movement(char direction) override;
	
	//Check if can attack 
	bool AlliesAtk(Entity& other, environmentalObjs& obj, char direction);


};

