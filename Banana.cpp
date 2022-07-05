#include "Banana.h"
#include <iostream>

Banana::Banana()
{
}

Banana::Banana(float x, float y)
{
    if (!image.loadFromFile("images\\BANANA.png"));
    {
        std::cerr << "Can`t load image_banana!" << std::endl;
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);
    scaleWidth = 0.075;

    // declarate sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);  
}

Banana::~Banana()
{
}