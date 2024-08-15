#include "shop.h"

void shop::cashearned(int MoneyGot)
{
	cash = MoneyGot + cash;

}
int shop::cashlost(int MoneyLost) {
	cash = cash - MoneyLost;
	return cash;
}

void shop::purchase(std::string unittype, int priceofunit)
{
	std::cout << "you are purchasing " << unittype << "!\n";
	std::cout << "it will cost " << priceofunit << " cash!\n";
	std::cout << "how many you want to purchase?: ";
	std::cin >> unitnum;
	if (cash >= (priceofunit * unitnum)) {
		std::cout << "you have " << cashlost(priceofunit * unitnum) << " cash left\n";
		std::cout << "you have purchased " << unitnum << " " << unittype << "!\n";

	}
	else if (cash < (price * unitnum)) {
		std::cout << "you don't have enough cash! come back when you're a little richer\n";
	}
}

void shop::shopping()
{
	
	while (allen == false) {
		int hello;
	
		std::cout << "Below you can purchase needed units for your missions\n";
		std::cout << "1. Rifleman\n2. Machinegunner\n3. Grenaider\n4. Mortarman\n5. Artillery\n6. Tank\n7. IFV\n\n";
		std::cout << "You have " << cash << " cash in your account. \n\n";
		std::cout << "Please choose which unit to purchase: ";
		std::cin >> unitbuy;

		if (unitbuy == 1) {
			purchase("Rifleman", 5);
		}

		else if (unitbuy == 2) {
			purchase("Machine Gunner", 7);
		}
		else if (unitbuy == 3) {
			purchase("Grenaiders", 6);
		}
		else if (unitbuy == 4) {
			purchase("Mortarman", 6);
		}
		else if (unitbuy == 5) {
			purchase("Artillery", 15);
		}
		else if (unitbuy == 6) {
			purchase("Tank", 15);
		}
		else if (unitbuy == 7) {
			purchase("IFV", 10);
		}
		else {
			std::cout << "I don't sell that here, bucko.\n";
		}
		std::cout << "do you want to buy more stuff?:(1 is yes/2 is no) ";
		std::cin >> hello;
		if (hello == 1) {
			std::cout << "\n";
			shopping();
		}
		else if (hello == 2) {
			allen = true;

		}
	;
	}

}

void shop::pricing(int p)
{
	price = p;
}
