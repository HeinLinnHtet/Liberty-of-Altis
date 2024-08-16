#include "AlliedTroops.h"



AlliedTroops::AlliedTroops(void)
{
	Health = 0;
	Attack = 0;
	Range = 0;
	Cost = 0;
}

//Movement function for player 
void AlliedTroops::Movement(char direction)
{
	char dirinput = toupper(direction);

	if (dirinput == 'W') {
		PosXY.SetY(PosXY.GetY() - 1);
	}
	else if (dirinput == 'S') {
		PosXY.SetY(PosXY.GetY() + 1);
	}
	else if (dirinput == 'A') {
		PosXY.SetX(PosXY.GetX() - 1);
	}
	else if (dirinput == 'D') {
		PosXY.SetX(PosXY.GetX() + 1);
	}
}

bool AlliedTroops::canattack(Entity& other, Entity& second, environmentalObjs& obj)
{
    //a temp variable to store ture/false
    bool attackable = false;

    //check if any enemy entity(allied troops) within the range spaces of the entity(enemy troop)
    for (int i = 0; i < Range; i++) {
        if (PosXY.GetY() + Range - i == other.PosXY.GetY()) {
            //in front
            //check if theres any objects in the way
            if (PosXY.GetY() + Range - i == second.PosXY.GetY()) {
                //check for fellow enemies
                attackable == false;
            }
            else if (PosXY.GetY() + Range - i == obj.objPos.GetY()) {
                //check for any objects (trees etc.)
                attackable == false;
            }
            else {
                //if none then shoot
                attackable == true;
            }
        }
        else if (PosXY.GetY() - Range + i == other.PosXY.GetY()) {
            //behind
            //check if theres any objects in the way
            if (PosXY.GetY() - Range + i == second.PosXY.GetY()) {
                //check for fellow enemies
                attackable == false;
            }
            else if (PosXY.GetY() - Range + i == obj.objPos.GetY()) {
                //check for any objects (trees etc.)
                attackable == false;
            }
            else {
                //if none then shoot
                attackable == true;
            }
        }
        else if (PosXY.GetX() + Range - i == other.PosXY.GetX()) {
            //to the right
            //check if theres any objects in the way
            if (PosXY.GetX() + Range - i == second.PosXY.GetX()) {
                //check for fellow enemies
                attackable == false;
            }
            else if (PosXY.GetX() + Range - i == obj.objPos.GetX()) {
                //check for any objects (trees etc.)
                attackable == false;
            }
            else {
                //if none then shoot
                attackable == true;
            }
        }
        else if (PosXY.GetX() - Range + i == other.PosXY.GetX()) {
            //to the left
            //check if theres any objects in the way
            if (PosXY.GetX() - Range + i == second.PosXY.GetX()) {
                //check for fellow enemies
                attackable == false;
            }
            else if (PosXY.GetX() - Range + i == obj.objPos.GetX()) {
                //check for any objects (trees etc.)
                attackable == false;
            }
            else {
                //if none then shoot
                attackable == true;
            }
        }
    }

    //return the thing
    return attackable;
}


