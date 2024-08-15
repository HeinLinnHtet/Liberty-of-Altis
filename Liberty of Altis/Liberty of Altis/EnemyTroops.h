#pragma once
#include "Entity.h"
class EnemyTroops : public Entity
{
private:
	bool godown;
	/*static bool active;*/

public:
	//Default 
	EnemyTroops(void);

	//for Ai behavioural attacking and movement
	void Movement(char direction) override;

	//Ai damage has been dealt
	void Attacking(Entity& other, char direction) override;

	//map 1 movement (start)
	void M1Movement();

	//check if can deal damage
	bool canattack(Entity& other);
};

