#include "Entity.h"


Entity::Entity(void)
{
    Health = 0;
    Attack = 0;
    Range = 0;
    Cost = 0;
}

bool Entity::isEntityAlive(void)
{
    //check if health below zero 
    if (Health <= 0) {
        //false if entity died
        return false;
    }
    //if alive return true
    return true;

}

//Check collisons
bool Entity::Entitycollision(Entity& other, char direction)
{
    direction = toupper(direction);

    int XEntity = PosXY.GetX();
    int YEntity = PosXY.GetY();
    int XOther = other.PosXY.GetX();
    int YOther = other.PosXY.GetY();

    bool result = false;

    //Check if entity is exiting the borders
    //Down 
    if ((YEntity == YOther - 1) && direction == 'S') {
        result = true;
    }
    //Up
    else if ((YEntity == YOther + 1) && direction == 'W') {
        result = true;
    }
    //Right
    else if ((XEntity == XOther - 1) && direction == 'D') {
        result = true;
    }
    //Left
    else if ((XEntity == XOther + 1) && direction == 'A') {
        result = true;
    }
    else
        result = false;

    ////check if other is UD direction of entity 
    //if ((XEntity == XOther) && ((YEntity == YOther - 1) || (YEntity == YOther + 1))) {
    //    //return true if collsion 
    //    result = true;
    //}
    ////check if other is LR direction of entity 
    //else if ((YEntity == YOther) && ((XEntity == XOther - 1) || (XEntity == XOther + 1))) {
    //    //return true if collsion 
    //    result = true;
    //}
    //else
    //    result = false;

    return result;
}

//Check border collison
bool Entity::BorderCollision(char direction)
{
    direction = toupper(direction);

    int result = false;

    //Up 
    if (direction == 'W') {
        if (PosXY.GetY() - 1 == 0) {
            result = true;
        }
    }
    //Down
    else if (direction == 'S') {
        if (PosXY.GetY() + 1 == 19) {
            result = true;
        }
    }
    //left
    else if (direction == 'D') {
        if (PosXY.GetX() + 1 == 54) {
            result = true;
        }
    }
    //right 
    else if (direction == 'A') {
        if (PosXY.GetX() - 1 == 3) {
            result = true;
        }
    }

    return result;
}

//set xy position
void Entity::SetPosition(int x, int y)
{
    PosXY.SetX(x);
    PosXY.SetY(y);
}

void Entity::Movement(char direction)
{

}

void Entity::Attacking(char direction)
{

}

int Entity::GetHealth(void)
{
    return Health;
}

int Entity::GetAttack(void)
{
    return Attack;
}

int Entity::GetRange(void)
{
    return Range;
}

int Entity::GetCost(void)
{
    return Cost;
}

char Entity::Draw_Icon(void)
{
    return 'E';
}