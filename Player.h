#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>
#include "Item.h"

class Player: public Item
{
private:
    int lives=5;
    int collected_banana=0;
    

public:
    Player();
    Player(float x, float y);
    ~Player();

    void increase_banana();
    bool move_detected();
    bool move_check();
    void move();
    void change_lives(int value);
    void check_new_cmd();
    int get_Banana();
    int get_Lives();
    //changes
    const sf::Sprite Object;

        
};

#endif