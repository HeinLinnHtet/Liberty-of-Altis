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
	//[0] = riflesman
	//[1] = machinegunner
	//[2] = grenadier
	//[3] = motars
	//[4] = artillery
	//[5] = tank
	//[6] = IFV

	int jo;
	int jo1;
	int jo2;
	int jo3;
	int jo4;
	int jo5;
	int jo6;
	int trooplimit = 0;
	std::cout << std::endl << "Below shows the number of units you have from rifleman to IFV: " << std::endl;
	std::cout <<
		"Riflemen: " << Troops[0] << std::endl <<
		"McGunner: " << Troops[1] << std::endl <<
		"Grenader: " << Troops[2] << std::endl <<
		"Mortar:   " << Troops[3] << std::endl <<
		"Artilery: " << Troops[4] << std::endl <<
		"Tank:     " << Troops[5] << std::endl <<
		"IFV:      " << Troops[6] << std::endl;

	//Code will go on while the troop limit is less than 15

	if (trooplimit < 15) {
		std::cout << "enter the riflemans you will bring: ";
		std::cin >> jo;
		Troop_broughtin[0] = jo;
		if (Troop_broughtin[0] > Troops[0]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo;
		if (trooplimit > 15) {
			Troop_broughtin[0] = Troop_broughtin[0] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter the machinegunner you will bring: ";
		std::cin >> jo1;
		Troop_broughtin[1] = jo1;
		if (Troop_broughtin[1] > Troops[1]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo1;
		if (trooplimit > 15) {
			Troop_broughtin[1] = Troop_broughtin[1] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter grenaiders: ";
		std::cin >> jo2;
		Troop_broughtin[2] = jo2;
		if (Troop_broughtin[2] > Troops[2]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo2;
		if (trooplimit > 15) {
			Troop_broughtin[2] = Troop_broughtin[2] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter mortarman: ";
		std::cin >> jo3;
		Troop_broughtin[3] = jo3;
		if (Troop_broughtin[3] > Troops[3]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo3;
		if (trooplimit > 15) {
			Troop_broughtin[3] = Troop_broughtin[3] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter artillery: ";
		std::cin >> jo4;
		Troop_broughtin[4] = jo4;
		if (Troop_broughtin[4] > Troops[4]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo4;
		if (trooplimit > 15) {
			Troop_broughtin[4] = Troop_broughtin[4] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter Tanks: ";
		std::cin >> jo5;
		Troop_broughtin[5] = jo5;
		if (Troop_broughtin[5] > Troops[5]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo5;
		if (trooplimit > 15) {
			Troop_broughtin[5] = Troop_broughtin[5] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter IFVs: ";
		std::cin >> jo6;
		Troop_broughtin[6] = jo6;
		if (Troop_broughtin[6] > Troops[6]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo6;
		if (trooplimit > 15) {
			Troop_broughtin[6] = Troop_broughtin[6] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	else {
		std::cout << std::endl << std::endl << "No more space for units!" << std::endl;
	}

	std::cout << std::endl << "Your squad is ready, commander" << std::endl;

	std::cout << std::endl <<
		"Riflemen: " << Troop_broughtin[0] << std::endl << std::endl <<
		"McGunner: " << Troop_broughtin[1] << std::endl << std::endl <<
		"Grenader: " << Troop_broughtin[2] << std::endl << std::endl <<
		"Mortar:   " << Troop_broughtin[3] << std::endl << std::endl <<
		"Artilery: " << Troop_broughtin[4] << std::endl << std::endl <<
		"Tank:     " << Troop_broughtin[5] << std::endl << std::endl <<
		"IFV:      " << Troop_broughtin[6] << std::endl;

	for (int i = 0; i < 7; i++) {
		Troops[i] = Troops[i] - Troop_broughtin[i];
	}
}

void Backpack::bakpak()
{
	//[0] = riflesman
//[1] = machinegunner
//[2] = grenadier
//[3] = motars
//[4] = artillery
//[5] = tank
//[6] = IFV

	int jo;
	int jo1;
	int jo2;
	int jo3;
	int jo4;
	int jo5;
	int jo6;
	int trooplimit = 0;
	std::cout << std::endl << "Below shows the number of units you have from rifleman to IFV: " << std::endl;
	std::cout <<
		"Riflemen: " << Troops[0] << std::endl <<
		"McGunner: " << Troops[1] << std::endl <<
		"Grenader: " << Troops[2] << std::endl <<
		"Mortar:   " << Troops[3] << std::endl <<
		"Artilery: " << Troops[4] << std::endl <<
		"Tank:     " << Troops[5] << std::endl <<
		"IFV:      " << Troops[6] << std::endl;

	std::cout << "Vehicles are banned in this certain level." << std::endl;

	//Code will go on while the troop limit is less than 15

	if (trooplimit < 15) {
		std::cout << "enter the riflemans you will bring: ";
		std::cin >> jo;
		Troop_broughtin[0] = jo;
		if (Troop_broughtin[0] > Troops[0]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo;
		if (trooplimit > 15) {
			Troop_broughtin[0] = Troop_broughtin[0] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter the machinegunner you will bring: ";
		std::cin >> jo1;
		Troop_broughtin[1] = jo1;
		if (Troop_broughtin[1] > Troops[1]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo1;
		if (trooplimit > 15) {
			Troop_broughtin[1] = Troop_broughtin[1] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter grenaiders: ";
		std::cin >> jo2;
		Troop_broughtin[2] = jo2;
		if (Troop_broughtin[2] > Troops[2]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo2;
		if (trooplimit > 15) {
			Troop_broughtin[2] = Troop_broughtin[2] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	if (trooplimit < 15) {
		std::cout << "enter mortarman: ";
		std::cin >> jo3;
		Troop_broughtin[3] = jo3;
		if (Troop_broughtin[3] > Troops[3]) {
			std::cout << "cannot!";
		}
		trooplimit = trooplimit + jo3;
		if (trooplimit > 15) {
			Troop_broughtin[3] = Troop_broughtin[3] - (trooplimit - 15);
			trooplimit = 15;
			std::cout << std::endl << "Unable to create unit due to maximum unit limit";
		}
	}

	

	else {
		std::cout << std::endl << std::endl << "No more space for units!" << std::endl;
	}

	std::cout << std::endl << "Your squad is ready, commander" << std::endl;

	std::cout << std::endl <<
		"Riflemen: " << Troop_broughtin[0] << std::endl << std::endl <<
		"McGunner: " << Troop_broughtin[1] << std::endl << std::endl <<
		"Grenader: " << Troop_broughtin[2] << std::endl << std::endl <<
		"Mortar:   " << Troop_broughtin[3] << std::endl << std::endl <<
		"Artilery: " << Troop_broughtin[4] << std::endl << std::endl <<
		"Tank:     " << Troop_broughtin[5] << std::endl << std::endl <<
		"IFV:      " << Troop_broughtin[6] << std::endl;

	for (int i = 0; i < 7; i++) {
		Troops[i] = Troops[i] - Troop_broughtin[i];
	}
}
