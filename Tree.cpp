#include "Tree.h"
#include <iostream>




Tree::~Tree()
{

}
Tree::Tree()
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
    sprite.setPosition(sf::Vector2f(setRandomPosX(), setRandomPosY()));

    // Texture to Sprite
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
}

/**
 * @brief This Function blocks the tree on the Gamefield for the player
 * 
 * @param player 
 * @param tree 
 */
void Tree::treeCollision(Player *player, Tree *tree)
{
        if (player->sprite.getPosition().x <= tree->sprite.getPosition().x)
        {
            player->sprite.setPosition(player->sprite.getPosition().x -5.f, player->sprite.getPosition().y);
        }else if (player->sprite.getPosition().x >= tree->sprite.getPosition().x)
        {
            player->sprite.setPosition(player->sprite.getPosition().x +5.f, player->sprite.getPosition().y);
        }else if (player->sprite.getPosition().y >= tree->sprite.getPosition().y)
        {
            player->sprite.setPosition(player->sprite.getPosition().x, player->sprite.getPosition().y -5.f);
        }else if (player->sprite.getPosition().y <= tree->sprite.getPosition().y)
        {
            player->sprite.setPosition(player->sprite.getPosition().x, player->sprite.getPosition().y +5.f);
        }
}