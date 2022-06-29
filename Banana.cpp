#include "Banana.h"
#include <iostream>

Banana::Banana()
{
}

Banana::Banana(float x, float y)
{
    if (!(image.loadFromFile("images\\BANANA.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);

    // declarate Shape
    itemShape.setSize(sf::Vector2(itemWidth, itemHeight));
    itemShape.setTexture(&texture);
    itemShape.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    
    // setcolor from spriteApe with RGB
    sprite.setColor(sf::Color(205, 102, 29));
    
    posX = x;
    posY = y;   
}

Banana::~Banana()
{
}