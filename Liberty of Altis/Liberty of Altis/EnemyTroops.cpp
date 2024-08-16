#include "EnemyTroops.h"


EnemyTroops::EnemyTroops(void)
{
	Health = 0;
	Attack = 0;
	Range = 0;
	Cost = 0;
    godown = true;
    THealth = Health;
}

void EnemyTroops::Movement(char direction)
{
    
    //to move randomly
    if (direction == '0') {
        //up
        PosXY.SetY(PosXY.GetY() - 1);
    }
    else if (direction == '1') {
        //down
        PosXY.SetY(PosXY.GetY() + 1);
    }
    else if (direction == '2') {
        //right
        PosXY.SetX(PosXY.GetX() + 1);
    }
    else if (direction == '3') {
        //left
        PosXY.SetX(PosXY.GetX() - 1);
    }
}


//Enemy troops collided with other entities 
bool EnemyTroops::Entitycollision(Entity& other, char direction)
{

    int XEntity = PosXY.GetX();
    int YEntity = PosXY.GetY();
    int XOther = other.PosXY.GetX();
    int YOther = other.PosXY.GetY();

    bool result = false;

    //Check if entity is LR of each other 
    if (XEntity == XOther) {
        //Down 
        if ((YEntity == YOther - 1) && direction == '0') {
            result = true;
        }
        //Up
        else if ((YEntity == YOther + 1) && direction == '1') {
            result = true;
        }
        else
            result = false;
    }
    //Check if entity if UP of each other 
    if (YEntity == YOther) {
        //Right
        if ((XEntity == XOther - 1) && direction == '2') {
            result = true;
        }
        //Left
        else if ((XEntity == XOther + 1) && direction == '3') {
            result = true;
        }
        else
            result = false;
    }

    return result;
}

//Enemy troop border collision
bool EnemyTroops::BorderCollision(char direction)
{

    int result = false;
    //Check if UD position
    //Up 
    if (direction == '0') {
        if (PosXY.GetY() - 1 == 0) {
            result = true;
        }
    }
    //Down
    if (direction == '1') {
        if (PosXY.GetY() + 1 == 19) {
            result = true;
        }
    }
    //left
    if (direction == '2') {
        if (PosXY.GetX() + 1 == 54) {
            result = true;
        }
    }
    //right 
    if (direction == '3') {
        if (PosXY.GetX() - 1 == 3) {
            result = true;
        }
    }

    return result;
}


//Broken pls try fix 
void EnemyTroops::M1Movement()
{

    //walk menacingly until hit
    if (THealth == Health) {
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
    //else {
    //    //scatter and attack
    //    if (moving == 0) {
    //        //up
    //        PosXY.SetY(PosXY.GetY() - 1);
    //    }
    //    else if (moving == 1) {
    //        //down
    //        PosXY.SetY(PosXY.GetY() + 1);
    //    }
    //    else if (moving == 2) {
    //        //right
    //        PosXY.SetX(PosXY.GetX() - 1);
    //    }
    //    else {
    //        //left
    //        PosXY.SetX(PosXY.GetX() + 1);
    //    }
    //}
}

//check if can attack 
bool EnemyTroops::canattack(Entity& other, Entity& second, environmentalObjs& obj)
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
