#include "AlliedTroops.h"
#include <iostream>
#include "Windows.h"
#define CMath


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

void AlliedTroops::Attacking(Entity& other, char direction)
{
    char direction;
    std::cout << "Which direction would you like to attack?\n Enter W, A, S, D: ";
    std::cin >> direction;
    if (Attackable(other, direction) == true) {
        other.SetHealth(other.GetHealth() - Attack);
    }
    else {
        std::cout << "No enemies in range";
    }

}

bool AlliedTroops::Attackable(Entity& other, char direction)
{
    char dirinput = toupper(direction);

    for (int i = 0; i < Range; i++) {

        if (dirinput == 'W') {
            if (PosXY.GetY() - Range + i == other.PosXY.GetY()) {
                //behind
                return true;
            }
        }
        else if (dirinput == 'S') {
            if (PosXY.GetY() + Range - i == other.PosXY.GetY()) {
                //in front
                return true;
            }
        }
        else if (dirinput == 'A') {
            if (PosXY.GetX() + Range - i == other.PosXY.GetX()) {
                //to the right
                return true;
            }
        }
        else if (dirinput == 'D') {
            if (PosXY.GetX() - Range + i == other.PosXY.GetX()) {
                //to the left
                return true;
            }
        }
        else {
            return false;
        }
    }
}

