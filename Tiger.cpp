#include "Tiger.h"
#include <iostream>

Tiger::Tiger()
{
}

Tiger::Tiger(float x, float y)
{
    if (!image.loadFromFile("images\\TIGER.png"));
    {
        std::cerr << "Can`t load image_tiger!" << std::endl;
    }

    itemWidth = 50.f;
    itemHeight = 80.f;
    scaleWidth = 0.3;
    scaleHeight = 0.3;
    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
    // declarate Sprite
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
 
}

Tiger::~Tiger()
{

}
