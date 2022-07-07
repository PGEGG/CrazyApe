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

/**
 * @brief This function checks if the player has enough (3) bananas collected
 * 
 * @return true - when player has enough collected banana
 * @return false - when player has to collect more banana
 */
bool Player::checkWon(){
    if (this->getBanana() >= 3 && this->lives >= 0)
    {
        std::cout << "You have won!" << std::endl;
        return true;
    }else{
        std::cout << "You need " << 3 - this->getBanana() << " more banana to win the game!" << std::endl;
    }
    return false;
}

/**
 * @brief This function checks if the player has more live than 0
 * 
 * @return true - if the player has lost all its lieves
 * @return false - if the player has enough live to play
 */
bool Player::checkDeath(){
    
    if (this->get_Lives() <= 0) {
        std::cout << "Your Dead, try again!" << std::endl;
        return true;
    }else
    {
        std::cout << "You have " << this->get_Lives() << "lives left." << std::endl;
    }
    
    return false;
}