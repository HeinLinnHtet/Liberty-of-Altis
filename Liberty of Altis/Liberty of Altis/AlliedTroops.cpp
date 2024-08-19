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

bool AlliedTroops::AlliesAtk(Entity& other, environmentalObjs& obj,char direction)
{

    //a temp variable to store ture/false
    bool attackable = false;

    //check if any enemy entity(allied troops) within the range spaces of the entity(enemy troop)
    direction = toupper(direction);

    for (int i = 0; i < Range; i++) {
        //attacking in up
        if (direction == 'W') {
            //check enemy present
            if (PosXY.GetY() + Range - i == other.PosXY.GetY()) {
                //Check if any objects in the way 
                if (PosXY.GetY() + Range - i == obj.objPos.GetY()) {
                    //check for any objects (trees etc.)
                    attackable = false;
                }
                else {
                    //if none then shoot
                    attackable = true;
                }
            }

        }
        else if (direction == 'S') {
            if (PosXY.GetY() - Range + i == other.PosXY.GetY()) {
                //behind
                //check if theres any objects in the way
                if (PosXY.GetY() - Range + i == obj.objPos.GetY()) {
                    //check for any objects (trees etc.)
                    attackable = false;
                }
                else {
                    //if none then shoot
                    attackable = true;
                }
            }
        }
        else if (direction == 'D') {
            if (PosXY.GetX() + Range - i == other.PosXY.GetX()) {
                //to the right
                //check if theres any objects in the way
                if (PosXY.GetX() + Range - i == obj.objPos.GetX()) {
                    //check for any objects (trees etc.)
                    attackable = false;
                }
                else {
                    //if none then shoot
                    attackable = true;
                }
            }
        }
        else if (direction == 'A') {
            if (PosXY.GetX() - Range + i == other.PosXY.GetX()) {
                //to the left
                //check if theres any objects in the way
                if (PosXY.GetX() - Range + i == obj.objPos.GetX()) {
                    //check for any objects (trees etc.)
                    attackable = false;
                }
                else {
                    //if none then shoot
                    attackable = true;
                }
            }
        }

    }
    return attackable;
}

void AlliedTroops::color(int c)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

