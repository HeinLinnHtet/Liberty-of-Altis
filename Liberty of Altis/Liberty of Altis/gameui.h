#pragma once
#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>
class gameui
{
private:
    char unitname;
    int HP, attack, range, cost, size;
public:
    gameui();
    int unitcount = 0;
    void cutscene1();
    void stats();
    int choice;
    void gamestart(gameui& player);
    int getstats(int H, int a, int r, int c, int s);
    void getstats(std::string nameset,  int H, int a, int r, int c, int s);
    void turtorial();
    void gotoxy(int x, int y);
    void printdelay(const std::string& text, int delay);
};



