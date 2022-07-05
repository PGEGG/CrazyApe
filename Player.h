#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>
#include "Item.h"

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
    bool move_detected();
    bool move_check();
    void move();
    void check_new_cmd();
    void addBanana();
    int get_Lives();
    void set_Lives(int live);
    //changes
    const sf::Sprite Object;

        
};

#endif