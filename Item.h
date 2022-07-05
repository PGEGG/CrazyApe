#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class Item
{
protected:
    float posX = 0;
    float posY = 0;

    // create Item
    sf::Image image;
    sf::Texture texture;

    sf::Time timePerFrame = sf::seconds(1.f/60.f);
    int speed = 100;
    float scaleWidth = 0.1;
    float scaleHeight = 0.1;

public: 
    Item();
    virtual ~Item()=0;
    
    sf::Sprite sprite;
    float itemWidth = 20.f;
    float itemHeight = 20.f;

    sf::Clock clock; 
    sf::Time framecounter = sf::Time::Zero; 
};