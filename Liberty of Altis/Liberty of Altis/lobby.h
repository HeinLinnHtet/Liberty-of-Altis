#pragma once
#include "gameui.h"
#include "shop.h"
class lobby : protected gameui
{
private:
	int playerchoose;
public:
	lobby();
	void welcomemessage();
	void playchoice();
	bool isunlock;
	shop hala;
	gameui joe;
	void cleartext();
};

