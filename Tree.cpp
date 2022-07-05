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

    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    // declarate Sprite
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
}