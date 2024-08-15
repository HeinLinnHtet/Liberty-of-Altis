#include "EnemyTroops.h"


EnemyTroops::EnemyTroops(void)
{
	Health = 0;
	Attack = 0;
	Range = 0;
	Cost = 0;
    godown = true;
}

void EnemyTroops::Movement(char direction)
{
    int moving = rand() % 4;

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

void EnemyTroops::Attacking(char direction)
{
	std::cout << "Enemy Attacking";

}

void EnemyTroops::M1Movement()
{
    //bool to determin current position
   

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


