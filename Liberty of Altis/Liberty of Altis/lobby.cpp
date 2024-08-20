#include "lobby.h"

#include <iostream>
void lobby::cleartext() {
	system("cls");
}

lobby::lobby()
{
	isunlock = true;
}
void lobby::welcomemessage()
{
	std::cout << "****************************************************************************\n";
	std::cout << "Welcome to Liberty Of Altis, a Military RPG and turn based stragetic game\n";
	std::cout << "****************************************************************************\n";
	std::cout << "Choices: \n";
	std::cout << "1: Story\n";
	std::cout << "2: Shop\n"; 
	std::cout << "Enter: ";
	std::cin >> playerchoose;
	cleartext();
	playchoice();

}

void lobby::playchoice()
{   
	
	if (playerchoose == 1){
		std::cout << "You choose story!";

		joe.turtorial();
		system("cls");
		hel.map1game();
		system("cls");

	}
	if (playerchoose == 2) {
		if (isunlock = false) {
			std::cout << "sorry! this feature will only be unlocked once mission two is completed";
		}
		else if (isunlock = true) {
			std::cout << "you choose shop!";
			hala.shopping();
		}
	}
}
