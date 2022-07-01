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
    sf::Sprite sprite;

    sf::Time timePerFrame = sf::seconds(1.f/60.f);
    int speed = 100;

public: 
    Item();
    virtual ~Item()=0;
    //virtual void setField(int x, int y) = 0;
    
    sf::RectangleShape itemShape;
    float itemWidth = 20.f;
    float itemHeight = 20.f;

    sf::Clock clock; 
    sf::Time framecounter = sf::Time::Zero; 
};