#pragma once
#include "Item.h"

class Coconut : public Item {
private:
    int deamage = 1;
    sf::Time timePerFrame = sf::seconds(1.f/60.f);
    int speed = 100;
    int direction = 1;
public:
   sf::Clock clock; 
    sf::Time accumulator = sf::Time::Zero; 
    Coconut();
    Coconut(float x, float y, int i);
    ~Coconut();
    void flyCoconut();


};
