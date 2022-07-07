#include "Player.h"
#include <iostream>

/**
 * @brief Construct a new Player:: Player object
 * default constructor of Player
 */
Player::Player()
{

}

/**
 * @brief Construct a new Player:: Player object
 * constructor of Player with x and y variables
 * @param x float x variable of Player
 * @param y float y variable of Player
 */
Player::Player(float x, float y)
{
    itemWidth = 50.f;
    itemHeight = 70.f;

    /// Load imageApe and if it couldn`t load
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

/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{

}

/**
 * @brief this function return the amount of Bananas
 * 
 * @return int amount of Bananas
 */
int Player::getBanana()
{
    return collected_banana;
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

void Player::check_new_cmd()
{

}

/**
 * @brief this function increase banana if Player has collected one
 * 
 */
void Player::addBanana()
{
    std::cout << "Added Banana!" << std::endl;
    this->collected_banana++;
}

/**
 * @brief this function returns the amount of Lives
 * 
 * @return int amount of Lives
 */
int Player::get_Lives()
{
    return lives;
}

/**
 * @brief set new amount of lives
 * increase if Player collected one
 * decrease if hit scorpion or coconut
 * @param live amount of live to increase/decrease
 * @return int amount of new lives
 */
void Player::set_Lives(int live)
{
    lives = live;
    std::cout << lives << std::endl;
}