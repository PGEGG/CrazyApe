#include "Tiger.h"
#include <iostream>

Tiger::Tiger()
{
}

Tiger::Tiger(float x, float y)
{
    if (!(image.loadFromFile("images\\TIGER.png")));
    {
        std::cerr << "Can`t load image_tiger!" << std::endl;
    }

    animalWidth = 50.f;
    animalHeight = 80.f;

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);

    // declarate Shape
    animalShape.setSize(sf::Vector2(animalWidth, animalHeight));
    animalShape.setTexture(&texture);
    animalShape.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    
    // setcolor from spriteApe with RGB
    sprite.setColor(sf::Color(205, 102, 29));
}

Tiger::~Tiger()
{

}
