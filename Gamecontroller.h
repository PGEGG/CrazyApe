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

class Gamecontroller
{
private:
    int runtime = 0;

    int randomNumber(int size);
public:
    Gamecontroller();
    ~Gamecontroller();

    void startGame();
    bool checkWon();
    bool checkDeath();
};

#endif