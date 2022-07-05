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
    
    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
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
