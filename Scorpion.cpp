#include "Scorpion.h"
#include <iostream>

Scorpion::Scorpion()
{

}

Scorpion::Scorpion(float x, float y) {
    if (!(image.loadFromFile("images\\SCORPION.png")));
    {
        std::cerr << "Can`t load image_scorpion!" << std::endl;
    }

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
    
    posX=x;
    posY=y;
}

Scorpion::~Scorpion()
{
}