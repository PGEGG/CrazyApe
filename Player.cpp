#include "Player.h"
#include <iostream>

Player::Player()
{

}

Player::Player(float x, float y)
{
    itemWidth = 50.f;
    itemHeight = 70.f;
    // Load imageApe
    if (!image.loadFromFile("images\\APE.png"));
    {
        std::cerr << "Can`t load image_ape!" << std::endl;
    }

    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    // declarate Sprite
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);

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