#pragma once
#include <SFML/Graphics.hpp>
#include <random>

//Randomizer
#define RANDOM std::random_device rdi; \
    std::mt19937 geni(rdi()); \
    std::uniform_real_distribution<> distX2(1,970); \
    std::uniform_real_distribution<> distY2(50,572);
    
class Item
{
protected:
    float posX = 0;
    float posY = 0;

    /// create Item
    sf::Image image;
    sf::Texture texture;

    int speed = 100;
    float scaleWidth = 0.1;
    float scaleHeight = 0.1;
    
public: 
    Item();
    virtual ~Item()=0;
    //Random Values
    float setRandomPosX();
    float setRandomPosY();
    
    /// declare sprite
    sf::Sprite sprite;
    float itemWidth = 20.f;
    float itemHeight = 20.f;

    sf::Clock clock; 
    sf::Time framecounter = sf::Time::Zero;
    sf::Time framecounterold = sf::Time::Zero; 
    sf::Time timePerFrame = sf::seconds(1.f/60.f);
};