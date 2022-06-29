#include "Player.h"
#include <iostream>

Player::Player()
{

}

Player::Player(float x, float y)
{
    
    // Load imageApe
    if (!(image.loadFromFile("images\\APE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);

    // declarate Shape
    playerShape.setSize(sf::Vector2(playerWidth, playerHeight));
    playerShape.setTexture(&texture);
    playerShape.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    
    // setcolor from spriteApe with RGB
    sprite.setColor(sf::Color(205, 102, 29));
    
    pos_x = 5;
    pos_y = 5;

}

Player::~Player()
{

}

void Player::increase_banana()
{
    
}

bool Player::move_detected(){
    return false;
}

bool Player::move_check()
{
    return false;
}

void Player::move()
{

}

void Player::change_lives(int value)
{

}

void Player::check_new_cmd()
{

}

int Player::get_Banana()
{
    return collected_banana;
}

int Player::get_Lives()
{
    return lives;
}