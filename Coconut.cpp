#include "Coconut.h"
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> distX(-1,-900);
std::uniform_real_distribution<> distY(50,580);

/**
 * @brief Construct a new Coconut:: Coconut object
 * default constructor of coconut 
 */
Coconut::Coconut()
{

}

/**
 * @brief Destroy the Coconut:: Coconut object
 * 
 */
Coconut::~Coconut()
{

}

/**
 * @brief Construct a new Coconut:: Coconut object
 * constructor with x and y values
 * @param x float x position of Coconut
 * @param y float y position of Coconut
 * @param i i=1 brown Coconut, i=0 red Coconut
 */
Coconut::Coconut(float x, float y, int i)
{
    if(i==1){
    if (!image.loadFromFile("images\\COCONUT.png"));
    {
        std::cerr << "Can`t load image_coconut!" << std::endl;
    }
    }else{
        if (!image.loadFromFile("images\\red_coconut.png"));
    {
        std::cerr << "Can`t load image_red_coconut!" << std::endl;
    }
    }
    
    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    scaleWidth = 0.15;
    scaleHeight = 0.15;

    /// declarate sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    /// Texture to Sprite
    sprite.setTexture(texture);
}

/**
 * @brief this function let the coconuts fly
 * 
 */
void Coconut::flyCoconut(bool gamebreak){
    
    if (gamebreak) {
        clock.restart();
    }
    
    while(framecounter >= timePerFrame){
        sprite.move(sf::Vector2f(speed*direction*timePerFrame.asSeconds(), 0));
        framecounter -= timePerFrame;
    }
     if(sprite.getPosition().x >= 1024.f){
        sprite.setPosition(sf::Vector2f(distX(gen), distY(gen)));
    }
}