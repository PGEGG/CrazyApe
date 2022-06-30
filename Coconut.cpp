#include "Coconut.h"
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> distX(-1,-900);
std::uniform_real_distribution<> distY(1,380);

Coconut::Coconut()
{

}


Coconut::~Coconut()
{

}
Coconut::Coconut(float x, float y, int i)
{
    if(i==1){
    if (!(image.loadFromFile("images\\COCONUT.png")));
    {
        std::cerr << "Can`t load image!";
    }
    }else{
        if (!(image.loadFromFile("images\\red_coconut.png")));
    {
        std::cerr << "Can`t load image!";
    }
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

void Coconut::flyCoconut(){
    while(accumulator >= timePerFrame){
        itemShape.move(sf::Vector2f(speed*direction*timePerFrame.asSeconds(), 0));
        accumulator -= timePerFrame;
    }
     if(itemShape.getPosition().x >= 600.f){
        itemShape.setPosition(sf::Vector2f(distX(gen), distY(gen)));
    }
}