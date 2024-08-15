#pragma once
#include "Entity.h"
class EnemyTroops : public Entity
{
private:
	bool godown;

public:
	//Default 
	EnemyTroops(void);

	//for Ai behavioural attacking and movement
	void Movement(char direction) override;

	//Ai attacking
	void Attacking(char direction) override;

	//map 1 movement (start)
	void M1Movement();
};

