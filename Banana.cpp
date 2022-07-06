#include "Banana.h"
#include <iostream>
/**
 * @brief Construct a new Banana:: Banana object
 * default constructor
 */


/**
 * @brief Construct a new Banana:: Banana object
 * constructor with x and y values
 * @param x float x position of banana
 * @param y float y position of banana
 */
Banana::Banana()
{
    /**
     * @brief if file couldn`t load
     * 
     */
    if (!image.loadFromFile("images\\BANANA.png"));
    {
        std::cerr << "Can`t load image_banana!" << std::endl;
    }

    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    scaleWidth = 0.075;

    // declarate sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY()));

    // Texture to Sprite
    sprite.setTexture(texture);  
}

/**
 * @brief Destroy the Banana:: Banana object
 * 
 */
Banana::~Banana()
{
}