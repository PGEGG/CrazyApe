#include "Item.h"
#include <iostream>

/**
 * @brief Construct a new Item:: Item object
 * 
 */
Item::Item(){
    
}

/**
 * @brief Destroy the Item:: Item object
 * 
 */
Item::~Item(){

}
/**
 * @brief This function generates a random value for the x koordinate, which still is inside the gamefield
 * 
 * @return float 
 */
float Item::setRandomPosX(){ 
    RANDOM;
    return distX2(geni);
}
/**
 * @brief This function generates a random value for the y koordinate, which still is inside the gamefield
 * 
 * @return float 
 */
float Item::setRandomPosY(){
    RANDOM;
    return distY2(geni);
}
void Item::newPosition() {
    this->sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY()));
}


