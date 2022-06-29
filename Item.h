#pragma once
#include <SFML/Graphics.hpp>


class Item
{
protected:
    float posX = 0;
    float posY = 0;

    // create Heart
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

public: 
    Item();
    virtual ~Item()=0;
    //virtual void setField(int x, int y) = 0;
    
    sf::RectangleShape itemShape;
    float itemWidth = 20.f;
    float itemHeight = 20.f;


};