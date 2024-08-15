#include "gameui.h"
#include <iostream>
#include "Windows.h"
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
gameui::gameui()
{
}
void gameui::gotoxy(int x, int y) {
	COORD srcn;
	HANDLE userhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	srcn.X = x; srcn.Y = y;
	SetConsoleCursorPosition(userhandle, srcn);
}

void gameui::cutscene1()
{
	PlaySound(TEXT("C:\\Users\\tyler\\Downloads\\Not-Like-Us.wav"), NULL, SND_FILENAME | SND_ASYNC);

	std::string lines[] = {
	 "It is 2001, the military of the Republic Of Altis has siezed power after a coup on the democratic government of the island nation",

	 "Led by Rikyar(Leader) Adriaan Helt, the new government has begin suppressing internal dissent and opposition through force",

	 "Their suppression of opposition has led to formation of rebel forces, leading to a protracted insurgency that has killed many ",

	 "One day, a suppression mission by government forces leads to a village in the island's interior being destroyed",

	 "Only one person survived, he was Johan Heisenburg. Angered, he has vowed to punish the government and intends to do so by fighting with a militia....."


	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); // wait for 2 seconds before replacing the line
		std::cout << "\r" << std::string(70, ' ') << "\r"; // clear the line
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

}



void gameui::stats()
{
	std::cout << "Below are the stats of the units\n";
	std::cout << "from left to right, unit name, HP, attack, range, size, cost\n";

	getstats("Rifleman", 10, 5, 3, 1, 5);

	getstats("Machine Gunner", 10, 15, 3, 1, 7);

	getstats("Grenadier", 10, 20, 4, 1, 6);

	getstats("Mortar", 20, 20, 7, 1, 8);

	getstats("Artillery", 30, 40, 10, 4, 15);

	getstats("IFV", 60, 10, 5, 4, 10);

	getstats("Tank", 80, 30, 8, 9, 15);
}

void gameui::gamestart(gameui& player)
{
}

void gameui::getstats(std::string nameset, int H, int a, int r, int s, int c)
{
	if (unitcount < 7) {
		unitname[unitcount] = nameset;
		HP[unitcount] = H;
		attack[unitcount] = a;
		range[unitcount] = r;
		size[unitcount] = s;
		cost[unitcount] = c;
		std::cout
			<< unitname[unitcount] << ": "
			<< HP[unitcount] << ", "
			<< attack[unitcount] << ", "
			<< range[unitcount] << ", "
			<< size[unitcount] << ", "
			<< cost[unitcount] << "\n";
	}

	unitcount++;
}

void gameui::turtorial() {
	std::string liness[] = {
	 "You are Johan Heisenburg, your villiage was destroyed by government forces a few weeks ago, you have joined the New Boers, a militia fighting the government",
	 "you are in the jungle headquarters of the rebels, you are meeting your newly assigned commander, Major Jamal Musiala, to begin your training: ",
	 "Musiala: Welcome Johan, I am your commander and will be overseeing your training.",
	 "I heard you are a hunter, and that your father was a commander in the Altian Military, thus you will become a captain in our militia",
	 "To command your troops, use the WASD keys to move up, left, down, right.",
	 "To attack enemies, command your troops by pressing the J button to attack",
	 "That is all, good luck commander!"
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); // wait for 2 seconds before replacing the line
		std::cout << "\r" << std::string(70, ' ') << "\r"; // clear the line
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::printdelay(const std::string& text, int delay)
{
	for (char e : text) {
		std::cout << e;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	std::cout << std::endl;
	//refrenced code at the moment
}
