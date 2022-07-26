#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>
#include "Item.h"

#define STARTPOSX 40.f
#define STARTPOSY 550.f

class Player: public Item
{
private:
    int lives = 5;
    int collected_banana = 0;
    int won_games = 0;
<<<<<<< HEAD
    int isfinished =0;  //0=running; 1=won; 2=death
=======
    bool isfinished =false;
>>>>>>> 68738a9b206777fe45ec80ceca6739b32514fc25
    
    

public:
    Player();
    Player(float x, float y);
    ~Player();

    int getBanana();
    void addBanana();
    int get_Lives();
    void set_Lives(int live);
    int getWon();
    bool checkWon();
    bool checkDeath();
<<<<<<< HEAD
    int getIsfinished();
    void setIsfinished(int val);
=======
    bool getIsfinished();
    void setIsfinished();
>>>>>>> 68738a9b206777fe45ec80ceca6739b32514fc25
    void set_Banana(int banana);
};

#endif