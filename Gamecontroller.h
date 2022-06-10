#ifndef Gamecontroller_h
#define Gamecontroller_h

#define FIELDSIZEX 50
#define FIELDSIZEY 40

#include "Player.h"

class Gamecontroller
{
private:
    int runtime = 0;
    int field[FIELDSIZEY][FIELDSIZEX];

    Player ape;

    bool checkDeath();
    bool freePosition(int x, int y);
    int randomNumber(int size);
    int getfield();
public:
    Gamecontroller();
    ~Gamecontroller();

    void startGame();
    void reset();
    bool checkWon();
};

#endif