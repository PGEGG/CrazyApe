#include "Heart.h"
#include <iostream>

/**
 * @brief Construct a new Heart:: Heart object
 * default constructor
 */

/**
 * @brief Construct a new Heart:: Heart object
 * constructor with x and y position
 * @param x float x position of heart
 * @param y float y position of heart
 */
Heart::Heart()
{
    /// if file couldn`t load
    if (!image.loadFromFile("images\\HEART.png"));
    {
        std::cerr << "Can`t load image!";
    }
    
    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    /// declarate Sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY())); 

    /// Texture to Sprite
    sprite.setTexture(texture);
}

/**
 * @brief Destroy the Heart:: Heart object
 * 
 */
Heart::~Heart()
{
    
}
