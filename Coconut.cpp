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
    if (!image.loadFromFile("images\\COCONUT.png"));
    {
        std::cerr << "Can`t load image_coconut!" << std::endl;
    }
    }else{
        if (!image.loadFromFile("images\\red_coconut.png"));
    {
        std::cerr << "Can`t load image_red_coconut!" << std::endl;
    }
    }
    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);
    scaleWidth = 0.15;
    scaleHeight = 0.15;

    // declarate sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setTexture(texture);
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
}

void Coconut::flyCoconut(){
    while(framecounter >= timePerFrame){
        sprite.move(sf::Vector2f(speed*direction*timePerFrame.asSeconds(), 0));
        framecounter -= timePerFrame;
    }
     if(sprite.getPosition().x >= 600.f){
        sprite.setPosition(sf::Vector2f(distX(gen), distY(gen)));
    }
}