#include "Tiger.h"
#include <iostream>


/**
 * @brief Construct a new Tiger:: Tiger object
 * 
 * @param x float x value of Tiger
 * @param y float y value of Tiger
 */
Tiger::Tiger()
{
    /// load immage and print warning if it couldn`t load
    if (!image.loadFromFile("images\\TIGER.png"));
    {
        std::cerr << "Can`t load image_tiger!" << std::endl;
    }

    /// set correct sizes of object
    itemWidth = 50.f;
    itemHeight = 80.f;
    scaleWidth = 0.3;
    scaleHeight = 0.3;
    
    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
    /// declarate Sprite
    do{
        sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY()));
    }while((sprite.getPosition().x < 100.f) &&(sprite.getPosition().y > 450.f));

    /// Texture to Sprite
    sprite.setTexture(texture);
}

/**
 * @brief Destroy the Tiger:: Tiger object
 * 
 */
Tiger::~Tiger()
{

}
