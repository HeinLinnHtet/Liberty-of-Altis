#include "Backpack.h"
#include <iostream>
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

void Backpack::backpak()
{
	int jo;
	int jo1;
	int jo2;
	int jo3;
	int jo4;
	int jo5;
	int jo6;
	std::cout << "below shows the number of units you have from rifleman to IFV: ";
	std::cout << Troops[0] << Troops[1] << Troops[2] << Troops[3] << Troops[4] << Troops[5] << Troops[6];

	std::cout << "enter the riflemans you will bring: ";
	std::cin >> jo;
	Troop_broughtin[0] = jo;
	if (Troop_broughtin[0] > Troops[0]) {
		std::cout << "cannot!";
	}//validating can complete later
	std::cout << "enter the machinegunner you will bring: ";
	std::cin >> jo1;
	Troop_broughtin[1] = jo1;
	std::cout << "enter grenaiders: ";
	std::cin >> jo2;
	Troop_broughtin[2] = jo2;
	std::cout << "enter mortarman: ";
	std::cin >> jo3;
	Troop_broughtin[3] = jo3;

	std::cout << "enter artillery: ";
	std::cin >> jo4;
	Troop_broughtin[4] = jo4;

	std::cout << "enter Tanks: ";
	std::cin >> jo5;
	Troop_broughtin[5] = jo5;

	std::cout << "enter IFVs: ";
	std::cin >> jo6;
	Troop_broughtin[6] = jo6;

}

