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

		//Check collision between entities 
		virtual	bool Entitycollision(Entity& other, char direction);

		//Check collision between border
		virtual bool BorderCollision(char direction);

		//Check if can attack 
		virtual bool canattack(Entity& other);

		//Damage dealt 
		void DamageDealt(Entity& other);


		//Generate random num between 0 to 3
		int RandomNum(void);
		
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

		void SetHealth(int a);

		int hitchance;

		bool hitcheck;

		void hitrate();
};

