#include "Scorpion.h"
#include <iostream>

Scorpion::Scorpion()
{

}

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

    // declarate Sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
 
}

Scorpion::~Scorpion()
{
}