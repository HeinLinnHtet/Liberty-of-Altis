#include "Position.h"

int Position::GetX(void)
{
	return x;
}

int Position::GetY(void)
{
	return y;
}

void Position::SetX(int xPos)
{
	x = xPos;
}

void Position::SetY(int yPos)
{
	y = yPos;
}

bool Position::attackrange(const Position& targetpos, int range)
{
    bool targetinrange = false;
    for(int i = 1; i <= range; i++)
    {
        if ((x == targetpos.x) &&
            ((y == targetpos.y - i) || (y == targetpos.y + i))) {
            targetinrange = true;
            return true;
        }
        if ((x == targetpos.y) &&
            ((y == targetpos.x - i) || (y == targetpos.x + i))) {
            targetinrange = true;
            return true;
        }
    }
    if (targetinrange == false)
        return false;
}
