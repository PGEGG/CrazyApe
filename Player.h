#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>
#include "Item.h"

#define STARTPOSX 50.f

class Player: public Item
{
private:
    int lives = 5;
    int collected_banana = 0;
    

public:
    Player();
    Player(float x, float y);
    ~Player();

    int getBanana();
    void addBanana();
    int get_Lives();
    void set_Lives(int live);
    bool checkWon();
    bool checkDeath();

        
};

#endif