#pragma once
#include "Entity.h"
class EnemyTroops : public Entity
{
private:
	bool godown;
	int THealth;

public:
	//Default 
	EnemyTroops(void);

	//for Ai behavioural attacking and movement
	void Movement(char direction) override;

	//Check if Entity collide with Entity
	bool Entitycollision(Entity& other, char direction) override;

	//Check if Entity border collide 
	bool BorderCollision(char direction) override;

	//check if can deal damage
	bool canattack(Entity& other, Entity& otherenemy, environmentalObjs& obj) override;

	//map 1 movement (start)
	void M1Movement();


};

