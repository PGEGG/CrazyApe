#include "Animal.h"
#include <iostream>

/**
 * @brief Construct a new Animal:: Animal object
 * 
 */
Animal::Animal()
{
    timePerFrame = sf::seconds(1.f/5.f);
}

/**
 * @brief Destroy the Animal:: Animal object
 * 
 */
Animal::~Animal()
{
    
}

/**
 * @brief This function creates an random int number 
 * int number for up, down, left, right
 * @return int between 1-4
 */
int Animal::getDirection(){
    return std ::rand() % 4 + 1;
}// end getDirection

/**
 * @brief This function declares the direction of the object
 * calls the function getDirection then gets an int value that tells in which direction the animal sould move
 * 
 */
void Animal::move(bool gamebreak){
    float x = 0.0;
    float y = 0.0;
    int randomValue = getDirection();
    
    if (randomValue == 1)
    {
        x = -10.f;
    }else if (randomValue == 2)
    {
        x = +10.f;
    }else if (randomValue == 3)
    {
        y = -10.f;
    }else if (randomValue == 4)
    {
        y = +10.f;
    }else{
        this->move(gamebreak);
    }
    if (gamebreak) {
        clock.restart();
    }
    
    while(framecounter >= timePerFrame){
        this->sprite.move(sf::Vector2f(x,y));
        framecounter -= timePerFrame;
    }
    
}//end move