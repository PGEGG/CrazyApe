#include "Animal.h"
#include <iostream>

Animal::Animal(){
    timePerFrame = sf::seconds(1.f/5.f);
}
Animal::~Animal(){
    
}

// This function creates an int number
//@returns int between 1-4
int Animal::getDirection(){
    return std ::rand() % 4 + 1;
}// end getDirection

// This function calls the function getDirection then gets an int value that tells in which direction the animal sould move
void Animal::move(){
    float x = 0.0;
    float y = 0.0;
    int randomValue = getDirection();
    
    if (randomValue == 1)
    {
        x = -5.f;
    }else if (randomValue == 2)
    {
        x = +5.f;
    }else if (randomValue == 3)
    {
        y = -5.f;
    }else if (randomValue == 4)
    {
        y = +5.f;
    }else{
        this->move();
    }
    
    while(framecounter >= timePerFrame){
        this->sprite.move(sf::Vector2f(x,y));
        framecounter -= timePerFrame;
    }
    
}//end move