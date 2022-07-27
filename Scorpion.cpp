#include "Scorpion.h"
#include <iostream>


/**
 * @brief Construct a new Scorpion:: Scorpion object
 * 
 * @param x float x position of Scorpion
 * @param y float y position of Scorpion
 */
Scorpion::Scorpion() {
    if (!image.loadFromFile("images\\SCORPION.png"));
    {
        std::cerr << "Can`t load image_scorpion!" << std::endl;
    }

    itemWidth = 25.f;
    itemHeight = 25.f;

    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    /// declarate Sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    do{
        sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY()));
    }while((sprite.getPosition().x < 100.f) &&(sprite.getPosition().y > 450.f));

    /// Texture to Sprite
    sprite.setTexture(texture);
 
}

/**
 * @brief Destroy the Scorpion:: Scorpion object
 * 
 */
Scorpion::~Scorpion()
{
}