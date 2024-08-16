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

    //Check if entity is LR of each other 
    if (XEntity == XOther) {
        //Down 
        if ((YEntity == YOther - 1) && direction == 'S') {
            result = true;
        }
        //Up
        else if ((YEntity == YOther + 1) && direction == 'W') {
            result = true;
        }
        else
            result = false;
    }
    //Check if entity if UP of each other 
    if (YEntity == YOther) {
            //Right
        if ((XEntity == XOther - 1) && direction == 'D') {
            result = true;
        }
        //Left
        else if ((XEntity == XOther + 1) && direction == 'A') {
            result = true;
        }
        else 
            result = false;
    }

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

int Entity::RandomNum(void)
{
    int num = rand() % 4;
    return num;
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

void Entity::DamageDealt(Entity& other)
{
    other.SetHealth(other.GetHealth() - Attack);
}

bool Entity::canattack(Entity& other)
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

void Entity::SetHealth(int a)
{
    Health = a;
}
void Entity::hitrate() {
    hitchance = rand()%20+1;
    if (hitchance < 15) {
        hitcheck = true;
    }
    else if (hitcheck >= 15) {
        hitcheck = false;
    }
}
