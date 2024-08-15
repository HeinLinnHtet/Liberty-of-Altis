#include "Backpack.h"

Backpack::Backpack()
{
	//intialising the array
	for (int i = 0; i < 7; i++) {
		Troops[i] = 0;
	}
}

void Backpack::riflemansetter(int a)
{
	Troops[0] = Troops[0] + a;
}

int Backpack::riflemangetter()
{
	return Troops[0];
}

void Backpack::machinegunnersetter(int a)
{
	Troops[1] = Troops[1] + a;
}

int Backpack::machinegunnergetter()
{
	return Troops[1];
}

void Backpack::grenadiersetter(int a)
{
	Troops[2] = Troops[2] + a;
}

int Backpack::grenadiergetter()
{
	return Troops[2];
}

void Backpack::motarsetter(int a)
{
	Troops[3] = Troops[3] + a;
}

int Backpack::motargetter()
{
	return Troops[3];
}

void Backpack::artillerysetter(int a)
{
	Troops[4] = Troops[4] + a;
}

int Backpack::artillerygetter()
{
	return Troops[4];
}

void Backpack::tanksetter(int a)
{
	Troops[5] = Troops[5] + a;
}

int Backpack::tankgetter()
{
	return Troops[5];
}

void Backpack::IFVsetter(int a)
{
	Troops[6] = Troops[6] + a;
}

int Backpack::IFVgetter()
{
	return Troops[6];
}
