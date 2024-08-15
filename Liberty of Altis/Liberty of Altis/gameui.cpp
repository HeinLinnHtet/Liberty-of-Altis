#include "gameui.h"
#include <iostream>
#include "Windows.h"
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
	std::cout << "from left to right, unit name, HP, attack, range, size, cost";
	getstats(HP, attack, range, cost, size);
}

void gameui::gamestart(gameui& player)
{
}

int gameui::getstats(int H, int a, int r, int c, int s)
{
	HP = H;
	attack = a;
	range = r;
	cost = c;
	size = s;
	std::cout << unitname << H << a << r << c << s;
	return 0;
}

void gameui::turtorial() {
	std::cout << "You are Johan Heisenburg, your villiage was destroyed by government forces a few weeks ago, angered and driven by revenge, you have joined the New Boers, a rebel force fighting the government\n";
	std::cout << "you are in the jungle headquarters of the rebels, you are meeting your newly assigned commander, Major Jamal Musiala, to begin your training:\n ";
	Sleep(2000);
	std::cout << "Musiala: Welcome Johan, I am your commander and will be overseeing your training. I heard you are a hunter, and that your father was a commander in the Altian Military, thus you will become a captain in our militia\n";
	Sleep(2000);
	std::cout << "Musiala: To command your troops, use the WASD keys to move up, left, down, right.\n";
	Sleep(2000);
	std::cout << "Musiala: To attack enemies, command your troops by pressing the J button to attack \n";
	Sleep(2000);
	std::cout << "Musiala: That is all, good luck commander!";
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
