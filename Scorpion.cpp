#include "Scorpion.h"
#include <iostream>

/**
 * @brief Construct a new Scorpion:: Scorpion object
 * 
 */
Scorpion::Scorpion()
{

}

/**
 * @brief Construct a new Scorpion:: Scorpion object
 * 
 * @param x float x position of Scorpion
 * @param y float y position of Scorpion
 */
Scorpion::Scorpion(float x, float y) {
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
    sprite.setPosition(x, y);

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