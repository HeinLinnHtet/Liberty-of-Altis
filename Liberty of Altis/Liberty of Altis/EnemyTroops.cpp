#include "EnemyTroops.h"


EnemyTroops::EnemyTroops(void)
{
	Health = 0;
	Attack = 0;
	Range = 0;
	Cost = 0;
    godown = true;
    active = false;
}

void EnemyTroops::Movement(char direction)
{
    //to have a random movement
    int moving = rand() % 4;
    
    //to move randomly
    if (moving == 0) {
        //up
        PosXY.SetY(PosXY.GetY() - 1);
    }
    else if (moving == 1) {
        //down
        PosXY.SetY(PosXY.GetY() + 1);
    }
    else if (moving == 2) {
        //right
        PosXY.SetX(PosXY.GetX() - 1);
    }
    else {
        //left
        PosXY.SetX(PosXY.GetX() + 1);
    }
}

void EnemyTroops::Attacking(Entity& other, char direction)
{
    //deal the damage to the target
    other.SetHealth(other.GetHealth() - Attack);
}

void EnemyTroops::M1Movement()
{
    //to have a random movement
    int moving = rand() % 4;

    //check if enemy is at max health
    int THealth = Health;

    //change to active for all the troops if one got hit
    if (THealth != Health) {
        active = true;
    }

    //walk menacingly until hit
    if (active == false) {
        //move up and down
        //check if is it at top or bottom
        if (PosXY.GetY() + 1 == 19) {
            godown = false;
        }
        else if (PosXY.GetY() - 1 == 0) {
            godown = true;
        }

        //movement
        if (godown == true) {
            PosXY.SetY(PosXY.GetY() + 1);
        }
        else if (godown == false) {
            PosXY.SetY(PosXY.GetY() - 1);
        }
    }
    else {
        //scatter and attack
        if (moving == 0) {
            //up
            PosXY.SetY(PosXY.GetY() - 1);
        }
        else if (moving == 1) {
            //down
            PosXY.SetY(PosXY.GetY() + 1);
        }
        else if (moving == 2) {
            //right
            PosXY.SetX(PosXY.GetX() - 1);
        }
        else {
            //left
            PosXY.SetX(PosXY.GetX() + 1);
        }
    }
}

bool EnemyTroops::canattack(Entity& other)
{
    //check if any enemy entity(allied troops) within the range spaces of the entity(enemy troop)
    for (int i = 0; i < Range; i++) {
        if (PosXY.GetY() + Range - i == other.PosXY.GetY()) {
            //in front
            return true;
        }
        else if (PosXY.GetY() - Range + i == other.PosXY.GetY()) {
            //behind
            return true;
        }
        else if (PosXY.GetX() + Range - i == other.PosXY.GetX()) {
            //to the right
            return true;
        }
        else if (PosXY.GetX() - Range + i == other.PosXY.GetX()) {
            //to the left
            return true;
        }
        else {
            return false;
        }
    }
}
