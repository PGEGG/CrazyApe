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

    // declarate Sprite
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
}

