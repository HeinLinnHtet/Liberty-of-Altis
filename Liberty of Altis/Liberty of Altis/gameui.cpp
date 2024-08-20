#include "gameui.h"
#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <thread>
#include <chrono>

int houseroofxpos[331] =
{
	//house 1
	14,15,16,
	11,12,13,14,15,16,17,18,19,
	8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
	5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,
	4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
	3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
	2,3,5,6,7,10,11,14,17,18,20,22,23,25,26,28,

	//house 2
	41,42,
	37,38,39,40,41,42,43,44,45,
	36,37,38,39,40,41,42,43,44,45,46,47,48,
	33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
	32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,
	31,33,34,36,37,39,42,43,45,46,48,52,
	43,

	//house 3
	63,64,65,
	60,61,62,63,64,65,66,67,68,69,
	58,59,60,61,62,63,64,65,66,67,68,69,70,71,
	56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
	53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,
	52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,
	51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,
	51,53,56,57,60,63,65,66,69,71,73,74,78,
	60
};

int houseroofypos[331] =
{
	//house 1
	4,4,4,
	5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,

	//house 2
	4,4,
	5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,
	10,

	//house 3
	6,6,6,
	7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	13,13,13,13,13,13,13,13,13,13,13,13,13,
	14
};

int housexpos[156] =
{
	//house 1
	8,9,12,13,15,16,19,21,24,
	6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,   19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,   19,20,21,22,23,24,25,

	//house 2
	35,38,40,41,44,47,49,50,
	34,35,36,37,38,39,    44,45,46,47,48,49,50,
	34,35,36,37,38,39,    44,45,46,47,48,49,50,

	//house 3
	54,55,58,59,61,62,64,67,68,70,72,75,
	54,55,56,57,58,59,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,
	54,55,56,57,58,59,60,61,     68,69,70,71,72,73,74,75,
	54,55,56,57,58,59,60,61,     68,69,70,71,72,73,74,75
};

int houseypos[156] =
{
	//house 1
	10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	13,13,13,13,13,13,13,13,13,13,13,13,13,13,

	//house 2
	9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,

	//house 3
	13,13,13,13,13,13,13,13,13,13,13,13,
	14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16
};

int firexpos1[102]
{
	//house 1
	10,11,
	10,11,12,13,
	11,12,13,14,15,
	8,9,10,11,12,13,14,15,
	12,13,14,

	22,
	20,21,22,  25,26,
	20,21,22,23,24,25,
	20,21,22,23,24,25,
	23,24,
	24,

	//house 2
	39,
	40,41,
	37,38,39,40,41,
	38,42,43,44,45,46,

	//house 3
	67,
	66,67,
	63,64,65,66,
	62,63,64,65,66,67,68,  72,73,
	61,62,63,64,65,66,   71,72,
	64,65,66,69,70,71,72,3,74,75,76,
	64,65,66,67,68,69,
	65,66,67,    72


};
int fireypos1[102]
{
	//house 1
	3,3,
	4,4,4,4,
	5,5,5,5,5,
	6,6,6,6,6,6,6,6,
	7,7,7,

	3,
	4,4,4,4,4,
	5,5,5,5,5,5,
	6,6,6,6,6,6,
	7,7,
	9,

	//house 2
	3,
	4,4,
	5,5,5,5,5,
	6,6,6,6,6,6,

	//house 3
	4,
	5,5,
	6,6,6,6,
	7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,
	11,11,11,11
};

int firexpos2[309]
{
	//house 1
	16,
	15,16,
	12,13,14,15,
	6,  10,11,12,13,14,15,16,   22,
	6,7, 10,11,12,13,14,15,16,17,18,  20,21,22,  25,26,
	7,8,   11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
	5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,23,24,25,26,
	5,6,7,8,9,10,11,14,15,16,17,18,19,20,21,23,24,25,26,
	6,7,8,   17,18,19,   24,25,26,27,
	6,7,   15,

	//house 2
	44,
	42,43,44,
	39,40,41,42,43,44,
	37,38,39,40,41,42,43,44,45,  50,
	37,38,39,40,41,42,43,44,45,46,48,49,50,
	36,37,38,39,40,41,42,43,44,45,46,48,49,
	35,36,  40,  43,44,45,46,47,48,49,
	33,34,  37,38,39,40,  44,45,46,47,48,49,
	45,46,

	//house 3
	63,
	62,63,
	62,63,  67,  74,
	60,61,62,63,  66,67,  73,
	57,58,59,60,61,62,63,64,65,66,  73,74,
	56,57,58,59,60,61,62,63,64,65,66,67,68,  72,73,74,75,
	56,57,58,59,60,61,62,63,64,65,66,    71,72,73,74,75,
	57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,
	58,59,60,61,62,63,64,65,66,67,68,69,71,72,73,74,75,76,
	58,59,60,61,62,63,64,65,66,67,68,  71,72,73,75,
	58,59,60,61,62,  72,73
};

int fireypos2[309]
{
	//house 1
	0,
	1,1,
	2,2,2,2,
	3,3,3,3,3,3,3,3,3,
	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,
	10,10,10,

	//house 2
	1,
	2,2,2,
	3,3,3,3,3,3,
	4,4,4,4,4,4,4,4,4,4,
	5,5,5,5,5,5,5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,

	//house 3
	2,
	3,3,
	4,4,4,4,
	5,5,5,5,5,5,5,
	6,6,6,6,6,6,6,6,6,6,6,6,
	7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
	12,12,12,12,12,12,12
};

gameui::gameui()
{
}
void gameui::gotoxy(int x, int y) {
	COORD srcn;
	HANDLE userhandle = GetStdHandle(STD_OUTPUT_HANDLE);
	srcn.X = x; srcn.Y = y;
	SetConsoleCursorPosition(userhandle, srcn);
}
void gameui::color(int c) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
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
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	// Cutscene ends
	gotoxy(x, y);
	std::cout << "Cutscene ended. Press any key to start the game." << std::endl;
	_getch();

	// Game starts here
	std::cout << "Game is starting..." << std::endl;

}

void gameui::cutscene2()
{
	std::string lines2[] = {
		"Musiala: Good job commander! Your forces have routed government units from the area, allowing us to breathe freely after months of heavy fighting ",
		"However, there is another pressing issue we must tackle. One of our most important suppliers, Virgil 'the shopkeeper' van dijk, has been captured and imprisoned",
		"Without him, our forces will be unable to carry out attacks as per normal, thus you are tasked to lead a armed unit to destroy the prision and bring Virgil to us",
		"Good luck Johan, this mission is crucial to our cause!, without Virgil we will be unable to purchase and replinish our forces."
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines2) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscene3()
{


	std::string lines3[] = {
		"Musiala: Good Job commander! with Virgil free, we can continue to recieve shipments from our external supporters",
		"We have amassed enough forces to launch our own offensive, an attack on the city of Basre.",
		"I will our spymaster, Komani Lungu, brief you on the attack",
		"Komani: Wait....Johan?! Its you, i haven't seen you in so long!",
		"Johan: What?! Komani I didn't know you were part of this militia",
		"Komani: Well...i was gulity of doing nothing and supporting the government, so i decided to switch sides and help the militia",
		"Johan: its good that we friends have reunited to fight againist the government that wants us dead",
		"Komani: yes!,now back to my briefing. We have gathered enough armor units to support this offensive, use it well and don't waste them."
        "The shop is unlocked now!, after every mission you may proceed to it to replinish your armed unit."
	};
	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : lines3) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscene4() {

	for (int i = 0; i < 331; i++)
	{
		gotoxy(houseroofxpos[i] + 20, houseroofypos[i]);
		color(0x08);
		std::cout << char(178);
	}

	for (int i = 0; i < 156; i++)
	{
		gotoxy(housexpos[i] + 20, houseypos[i]);
		color(0x0E);
		std::cout << char(178);
	}

	std::string cutscene4line1[] = {
		"Enemies are still hiding in the villages!",
		"They think a fake village as a hideout would work.",
		"BURN THEM ALL!!!!!!"
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : cutscene4line1) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

	for (int i = 0; i < 102; i++)
	{
		gotoxy(firexpos1[i] + 20, fireypos1[i]);
		color(0x0C);
		std::cout << char(177);
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));

	for (int i = 0; i < 309; i++)
	{
		gotoxy(firexpos2[i] + 20, fireypos2[i]);
		color(0x0C);
		std::cout << char(177);
	}

	std::string line4[] = {
		".................",
		"i......what have we done?",
		"this battle, it was a nightmare......",
		"aren't we a liberating force? aiming to overthrow the oppresive state? We are the voice of the people, but are we the voice if we hurt them?",
		"heh.....maybe we have been too careless, firing our rounds and driving our tanks everywhere.",
		"But...the amount of citizens we injuned and killed accidentally is horrible",
		"Did I do the right thing?......to join this militia?",
		"................",
		"Musiala: Good afternoon Johan, our offensive onto Basre was successful, however at the cost of many innocent lives.",
		"But we cannot harp on this misfortunte, with the government driven from the area, our Militia can finally advance onto the Capital",
		"You will be tasked with entering and subduing all enemy forces outside the parliment buliding and ensuring that government forces will not push us back again",
		"good luck"

	};
	for (const auto& text : line4) {
		color(0x07);
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscene5() {
	std::string line5[] = {
		"Gunfire is heard all over the wartorn city, with many bulidings damaged and destroyed.....",
		"With enemy forces routed and either destroyed or retreating back to the last government stronghold, the government parliment, the city is now liberates....",
		"Johan and his officers walk through the ruined city, looking upon the destruction caused",
		"As Johan walks, a medic runs to him...",
		"Sir! we have bad news, we have found the body of Komani Lungu, it looks to be that he was killed by government forces, most likely cause he was found out",
		"Johan: what?.....that can't be",
		"thats impossible.....no...no!"
		"It seems that in war, no one is immune from the scythe of death....."
		".............................."

	    "Musiala: Commander! our forces have routed the enemy, and their remaining forces are entrenched at the parliment buliding",
		"we have intel that Adriaan Helt remains there commanding, your goal is to capture him so as to end this conflict",
		"you must not kill him, good luck and godspeed"
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : line5) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::cutscence6()
{
	std::string line6[] = {
		"your forces stormed the parliment, successfully defeating the remmmants of the goverment forces",
		"The Rikyar, the main cause of this war, has been captured. He stares at your with a angered look, but stays silent",
		"With the parliment captured, you have forced the Rikyar to surrender his forces",
		"Rikyar: Urgh....fine",
		"The war had ended, while some forces may still resist, the period of oppression has ended...",
		"it seems, that liberty have finally come to Altis...."
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : line6) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
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

void gameui::win()
{
	std::string liness1[] = {
		"You have defeated the enemy",
		"good job!"
	};



	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness1) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
}

void gameui::loss()
{
	std::string liness2[] = {
		"The enemy has routed our forces",
		"terrible loss for us, we must regroup and strike back!",
		"try again......."
	};

	int delay = 50;
	int x = 20, y = 20;
	for (const auto& text : liness2) {
		gotoxy(x, y);
		printdelay(text, delay);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r";
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}

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
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "\r" << std::string(70, ' ') << "\r"; 
		gotoxy(x, y);
		std::cout << std::string(text.length(), ' ');
	}
	
}

void gameui::printdelay(const std::string& text, int delay)
{
	for (char e :text) {
		if (_kbhit()) {
			_getch();
			break;
		}
		std::cout << e;
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
	std::cout << std::endl;
 
}
