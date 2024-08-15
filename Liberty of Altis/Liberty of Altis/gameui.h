#pragma once
class gameui
{
private:
    char unitname;
    int HP, attack, range, cost, size;
public:
    gameui();
    void cutscene1();
    void stats();
    int choice;
    void gamestart(gameui& player);
    int getstats(int H, int a, int r, int c, int s);
    void turtorial();
};

