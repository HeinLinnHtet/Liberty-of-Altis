#pragma once
#include "gameui.h"
class lobby : protected gameui
{
private:
	int playerchoose;
public:
	lobby();
	void welcomemessage();
	void playchoice();
	bool isunlock;
};

