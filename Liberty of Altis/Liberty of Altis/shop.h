#pragma once
#include <iostream>
class shop
{
private:

public:
	int cash = 1000;
	int unitbuy;
	int unitnum;
	int price;
	void cashearned(int MoneyGot);
	int cashlost(int MoneyLost);
	void shopping();
	void pricing(int p);
	void purchase(std::string unittype, int priceofunit);
	bool allen = false;
};
