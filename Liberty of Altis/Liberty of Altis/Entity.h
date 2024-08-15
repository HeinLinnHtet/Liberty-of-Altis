#pragma once
#include "Position.h"
#include <iostream>

class Entity
{


protected:
		//Health, amount of health it before dying
		int Health;

		//Attack, amount of damage it deals
		int Attack;

		//Range, how far can it attack 
		int Range;

		//Cost, amount of inventory space it takes up
		int Cost;

public:
		//Composition relationship 
		Position PosXY;

		//Default
		Entity(void);

		//Check if entity is alive
		bool isEntityAlive(void);

		//Movement function, carries out movement (pure virtual function)
		virtual void Movement(char direction);

		//Attack function, carries out attack (pure virtual function)
		virtual void Attacking(char direction);

		//Check collision between entities 
		virtual	bool Entitycollision(Entity& other);
		
		//Set position of entity 
		void SetPosition(int x, int y);

		//hpgetter
		int GetHealth(void);

		//attack getter
		int GetAttack(void);

		//range getter
		int GetRange(void);

		//cost getter
		int GetCost(void);

		//Draw icon
		virtual char Draw_Icon(void);


};

