#include "Heart.h"
#include <iostream>

Heart::Heart()
{
}

Heart::Heart(float x, float y)
{

    if (!image.loadFromFile("images\\HEART.png"));
    {
        std::cerr << "Can`t load image!";
    }
    
    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    // declarate Sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);

}

Heart::~Heart()
{
    
}
