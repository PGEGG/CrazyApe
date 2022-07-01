#ifndef Gamecontroller_h
#define Gamecontroller_h
#include "Player.h"
#include "Item.h"
#include "Banana.h"
#include "Heart.h"
#include "Gui.h"
#include "Animal.h"
#include "Tiger.h"
#include "Scorpion.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SFML/Audio.hpp>


#define FIELDSIZEX 50
#define FIELDSIZEY 40
using namespace std;
class Gamecontroller
{
private:
    int runtime = 0;
    int field[FIELDSIZEY][FIELDSIZEX];

    bool freePosition(int x, int y);
    int randomNumber(int size);
    int getfield();
public:
    Gamecontroller();
    ~Gamecontroller();

    void startGame();
    void reset();
    bool checkWon();
    bool checkDeath();
};

#endif