#include "Coconut.h"
#include <iostream>

Coconut::Coconut()
{

}


Coconut::~Coconut()
{

}
Coconut::Coconut(float x, float y)
{
    if (!(image.loadFromFile("images\\COCONUT.png")));
    {
        std::cerr << "Can`t load image!";
    }

    itemWidth = 20.f;
    itemHeight = 20.f;
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
    posY = y;


}

void Coconut::Fly(){
    posX++;
}
