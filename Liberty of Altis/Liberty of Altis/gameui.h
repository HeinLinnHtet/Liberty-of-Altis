#pragma once
#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>
class gameui
{
private:
    std::string unitname[7];
    int HP[7], attack[7], range[7], cost[7], size[7];
public:
    gameui();
    int unitcount = 0;
    void cutscene1();
    void cutscene2();
    void cutscene3();
    void cutscene4();
    void cutscene5();
    void cutscence6();
    void stats();
    int choice;
    void gamestart(gameui& player);
    //int getstats(int H, int a, int r, int c, int s);
    void getstats(std::string nameset,  int H, int a, int r, int c, int s);
    void turtorial();
    void gotoxy(int x, int y);
    void color(int c);
    void printdelay(const std::string& text, int delay);
};



