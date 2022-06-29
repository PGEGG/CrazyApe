#include "Tree.h"
#include <iostream>
using namespace std;


Tree::Tree()
{

}


Tree::~Tree()
{

}
Tree::Tree(float x, float y)
{
    
    if (!(image.loadFromFile("images\\BANANATREE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    itemWidth = 80.f;
    itemHeight = 80.f;

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
    posX = x;
}

